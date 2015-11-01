//这个是过TX游戏自我保护驱动的源代码。可以过qq堂、DNF、寻仙等QQ游戏。

#include <ntddk.h>
#include <windef.h>
#include <ntimage.h>
#include <Common.h>

typedef struct _KAPC_STATE 
{
        LIST_ENTRY ApcListHead[2];
        PVOID Process;
        BOOLEAN KernelApcInProgress;
        BOOLEAN KernelApcPending;
        BOOLEAN UserApcPending;
} KAPC_STATE, *PKAPC_STATE;

ULONG g_nOpenIndex                                                = 0;
ULONG g_nThreadIndex                                        = 0;
ULONG g_nReadIndex                                                = 0;
ULONG g_nWriteIndex                                                = 0;

ULONG g_NtOpenProcess                                        = 0;
ULONG g_NtOpenThread                                        = 0;
ULONG g_NtReadVirtualMemory                                = 0;
ULONG g_NtWriteVirtualMemory                        = 0;
ULONG g_KiAttachProcess                                        = 0;
ULONG g_PsCreateSystemThread                        = 0;

ULONG g_PsCreateSystemThreadAddr                = 0;

BYTE g_NtOpenProcessSave[0x300];
BYTE g_NtOpenThreadSave[0x300];
BYTE g_NtReadVirtualMemorySave[0x10];
BYTE g_NtWriteVirtualMemorySave[0x10];
BYTE g_KiAttachProcessSave[0x10];

INLINEHOOK g_hPsCreateSystemThread;

VOID NTAPI MyThread(PVOID pContext)
{


        __asm
        {
                push        eax
                cli
                mov                eax, cr0
                and                eax, not 0x10000
                mov                cr0, eax
                pop                eax
        }

        if (g_NtOpenProcess)
        {
                memcpy((PVOID)g_NtOpenProcess, (PVOID)g_NtOpenProcessSave, sizeof(g_NtOpenProcessSave));
        //        DbgPrint("恢复NtOpenProcess成功");
        }

        if (g_NtOpenThread)
        {
                memcpy((PVOID)g_NtOpenThread, (PVOID)g_NtOpenThreadSave, sizeof(g_NtOpenThreadSave));
        //        DbgPrint("恢复NtOpenThread成功");
        }

        if (g_NtReadVirtualMemory)
        {
                memcpy((PVOID)g_NtReadVirtualMemory, (PVOID)g_NtReadVirtualMemorySave, sizeof(g_NtReadVirtualMemorySave));
        //        DbgPrint("恢复NtReadVirtualMemory成功");
        }

        if (g_NtWriteVirtualMemory)
        {
                memcpy((PVOID)g_NtWriteVirtualMemory, (PVOID)g_NtWriteVirtualMemorySave, sizeof(g_NtWriteVirtualMemorySave));
        //        DbgPrint("恢复NtWriteVirtualMemory成功");
        }

        if (g_KiAttachProcess)
        {
                memcpy((PVOID)g_KiAttachProcess, (PVOID)g_KiAttachProcessSave, sizeof(g_KiAttachProcessSave));
        //        DbgPrint("恢复KiAttachProcess成功");
        }

        __asm
        {
                push        eax
                mov                eax, cr0
                or                eax, 0x10000
                mov                cr0, eax
                sti
                pop                eax
        }
        DbgPrint("恢复成功");
        PsTerminateSystemThread(STATUS_SUCCESS);
}

__declspec(naked) NTSTATUS MyPsCreateSystemThread_(PHANDLE ThreadHandle,ULONG DesiredAccess,POBJECT_ATTRIBUTES ObjectAttributes,HANDLE ProcessHandle,PCLIENT_ID ClientId,PKSTART_ROUTINE StartRoutine,PVOID StartContext)
{
        __asm
        {
                jmp                dword ptr [g_PsCreateSystemThreadAddr]
        }
}

NTSTATUS MyPsCreateSystemThread(PHANDLE ThreadHandle,ULONG DesiredAccess,POBJECT_ATTRIBUTES ObjectAttributes,HANDLE ProcessHandle,PCLIENT_ID ClientId,PKSTART_ROUTINE StartRoutine,PVOID StartContext)
{
        PDWORD Addr = (PDWORD)StartRoutine;
        HANDLE hThread = NULL;
        if ( (*Addr == 0x81EC8B55 && *(Addr + 1) == 0x94EC) || (*Addr == 0x0149F6E9 && *(Addr + 1) == 0xB2120100) || (*Addr == 0x01F1DFE9 && *(Addr + 1) == 0x13A5F300) || (*Addr == 0x02120FE9 && *(Addr + 1) == 0x6E800) )
        {
                DbgPrint("创建内核线程:%X\n",StartRoutine);
        //        MyPsCreateSystemThread_(&hThread, (ACCESS_MASK)0, NULL,(HANDLE)0, NULL, MyThread, NULL);
        //        ZwClose(hThread);
                StartRoutine = MyThread;
        }
        return MyPsCreateSystemThread_(ThreadHandle, DesiredAccess, ObjectAttributes, ProcessHandle, ClientId, StartRoutine, StartContext);
}

ULONG GetKiAttachProcessAddr()
{
        ULONG DisassemblerLen = 0, Size = 0;
        PBYTE FunctionAddr = (PBYTE)GetFunctionAddr(L"KeStackAttachProcess");
        do 
        {
                DisassemblerLen = GetOpCodeSize(FunctionAddr);
                FunctionAddr =  FunctionAddr + DisassemblerLen;
                Size = Size + DisassemblerLen;
                if (Size > 0x100 || *(PWORD)FunctionAddr == 0x8C2)
                {
                        return 0;
                }
        } while ( *FunctionAddr != 0xE8 );

        return (LONG)FunctionAddr + *(PLONG)(FunctionAddr + 1) + 5;
}

VOID Hook()
{
        g_nOpenIndex                                        = GetFunctionIndex("NtOpenProcess");
        g_nThreadIndex                                        = GetFunctionIndex("NtOpenThread");
        g_nReadIndex                                        = GetFunctionIndex("NtReadVirtualMemory");
        g_nWriteIndex                                        = GetFunctionIndex("NtWriteVirtualMemory");

        g_NtOpenProcess                                        = KeServiceDescriptorTable->ServiceTableBase[g_nOpenIndex];
        g_NtOpenThread                                        = KeServiceDescriptorTable->ServiceTableBase[g_nThreadIndex];
        g_NtReadVirtualMemory                        = KeServiceDescriptorTable->ServiceTableBase[g_nReadIndex];
        g_NtWriteVirtualMemory                        = KeServiceDescriptorTable->ServiceTableBase[g_nWriteIndex];
        g_KiAttachProcess                                = GetKiAttachProcessAddr();


        g_PsCreateSystemThread                        = GetFunctionAddr(L"PsCreateSystemThread");

        if (g_NtOpenProcess)
        {
                memcpy((PVOID)g_NtOpenProcessSave, (PVOID)g_NtOpenProcess, sizeof(g_NtOpenProcessSave));
                DbgPrint("NtOpenProcess 地址:%08X", g_NtOpenProcess);
        }
        else
        {
                DbgPrint("获取NtOpenProcess地址失败");
        }

        if (g_NtOpenThread)
        {
                memcpy((PVOID)g_NtOpenThreadSave, (PVOID)g_NtOpenThread, sizeof(g_NtOpenThreadSave));
                DbgPrint("NtOpenThread 地址:%08X", g_NtOpenThread);
        }
        else
        {
                DbgPrint("获取NtOpenThread地址失败");
        }

        if (g_NtReadVirtualMemory)
        {
                memcpy((PVOID)g_NtReadVirtualMemorySave, (PVOID)g_NtReadVirtualMemory, sizeof(g_NtReadVirtualMemorySave));
                DbgPrint("NtReadVirtualMemory 地址:%08X", g_NtReadVirtualMemory);
        }
        else
        {
                DbgPrint("获取NtReadVirtualMemory地址失败");
        }

        if (g_NtWriteVirtualMemory)
        {
                memcpy((PVOID)g_NtWriteVirtualMemorySave, (PVOID)g_NtWriteVirtualMemory, sizeof(g_NtWriteVirtualMemorySave));
                DbgPrint("NtWriteVirtualMemory 地址:%08X", g_NtWriteVirtualMemory);
        }
        else
        {
                DbgPrint("获取NtWriteVirtualMemory地址失败");
        }


        if (g_KiAttachProcess)
        {
                memcpy((PVOID)g_KiAttachProcessSave, (PVOID)g_KiAttachProcess, sizeof(g_KiAttachProcessSave));
                DbgPrint("KiAttachProcess 地址:%08X", g_KiAttachProcess);
        }
        else
        {
                DbgPrint("获取KiAttachProcess地址失败");
        }

        HookFunction(g_PsCreateSystemThread, (ULONG)MyPsCreateSystemThread, &g_hPsCreateSystemThread, &g_PsCreateSystemThreadAddr);
}

VOID UnHook()
{
        UnHookFunction(&g_hPsCreateSystemThread);
}
void OnUnload(PDRIVER_OBJECT pDriverObj)
{
        UnHook();
        DbgPrint("卸载成功");
}

//        驱动程序加载时调用DriverEntry例程
NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObj, PUNICODE_STRING pRegistryString)
{
        pDriverObj->DriverUnload = OnUnload;
        DbgPrint("加载成功");
        Hook();
        return STATUS_SUCCESS;
}X
