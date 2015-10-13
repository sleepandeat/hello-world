//Microsoft Developer Studio generated resource script.
//
#include "resource.h"

#define APSTUDIO_READONLY_SYMBOLS
/////////////////////////////////////////////////////////////////////////////
//
// Generated from the TEXTINCLUDE 2 resource.
//
#include "afxres.h"

/////////////////////////////////////////////////////////////////////////////
#undef APSTUDIO_READONLY_SYMBOLS

/////////////////////////////////////////////////////////////////////////////
// Chinese (中国) resources

#if !defined(AFX_RESOURCE_DLL) || defined(AFX_TARG_CHS)
#ifdef _WIN32
LANGUAGE LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED
#pragma code_page(936)
#endif //_WIN32

#ifdef APSTUDIO_INVOKED
/////////////////////////////////////////////////////////////////////////////
//
// TEXTINCLUDE
//

1 TEXTINCLUDE DISCARDABLE 
BEGIN
    "resource.h\0"
END

2 TEXTINCLUDE DISCARDABLE 
BEGIN
    "#include ""afxres.h""\r\n"
    "\0"
END

3 TEXTINCLUDE DISCARDABLE 
BEGIN
    "\r\n"
    "\0"
END

#endif    // APSTUDIO_INVOKED


/////////////////////////////////////////////////////////////////////////////
//
// Dialog
//

IDD_MAIN DIALOG DISCARDABLE  0, 0, 188, 152
STYLE DS_MODALFRAME | DS_CENTER | WS_MINIMIZEBOX | WS_POPUP | WS_CAPTION | 
    WS_SYSMENU
CAPTION "2048"
FONT 10, "微软雅黑"
BEGIN
    PUSHBUTTON      "重新开始",IDC_OK,71,30,50,11
    CTEXT           "2",IDC_item1,22,48,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item2,63,48,27,16,SS_CENTERIMAGE
    CTEXT           "4",IDC_item3,104,48,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item4,145,48,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item5,22,72,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item7,104,73,27,16,SS_CENTERIMAGE
    CTEXT           "4",IDC_item8,145,73,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item9,22,98,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item10,63,98,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item11,104,98,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item12,145,98,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item13,22,123,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item14,63,123,27,16,SS_CENTERIMAGE
    CTEXT           "16",IDC_item15,104,123,27,16,SS_CENTERIMAGE
    CTEXT           "",IDC_item16,145,123,27,16,SS_CENTERIMAGE
    CTEXT           "2048",IDC_item0,13,8,44,33,SS_CENTERIMAGE
    CTEXT           "当前分数",IDC_STATIC,71,8,50,20
    CTEXT           "24",IDC_now_score,71,18,50,8
    CTEXT           "最高分数",IDC_STATIC,133,8,50,20
    CTEXT           "24",IDC_max_score,133,18,50,8
    PUSHBUTTON      "关于",IDC_about,133,30,50,11
    CTEXT           "",IDC_item6,63,72,27,16,SS_CENTERIMAGE
END

IDD_about DIALOG DISCARDABLE  0, 0, 159, 99
STYLE DS_MODALFRAME | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "关于"
FONT 10, "微软雅黑"
BEGIN
    LTEXT           "        本程序使用C语言写的，各种想要效果达不到，所以不想写了。。。\n                虽然做的丑，还是不忘签名\n\t\t\t\tmade by：sleepandeat",
                    IDC_STATIC,7,7,145,56
    PUSHBUTTON      "确定",IDC_open_down,55,72,50,14
END


/////////////////////////////////////////////////////////////////////////////
//
// DESIGNINFO
//

#ifdef APSTUDIO_INVOKED
GUIDELINES DESIGNINFO DISCARDABLE 
BEGIN
    IDD_about, DIALOG
    BEGIN
        LEFTMARGIN, 7
        RIGHTMARGIN, 152
        TOPMARGIN, 7
        BOTTOMMARGIN, 92
    END
END
#endif    // APSTUDIO_INVOKED


/////////////////////////////////////////////////////////////////////////////
//
// Icon
//

// Icon with lowest ID value placed first to ensure application icon
// remains consistent on all systems.
IDI_ICON1               ICON    DISCARDABLE     "icon.ico"

#ifndef _MAC
/////////////////////////////////////////////////////////////////////////////
//
// Version
//

VS_VERSION_INFO VERSIONINFO
 FILEVERSION 1,0,0,1
 PRODUCTVERSION 1,0,0,1
 FILEFLAGSMASK 0x3fL
#ifdef _DEBUG
 FILEFLAGS 0x1L
#else
 FILEFLAGS 0x0L
#endif
 FILEOS 0x40004L
 FILETYPE 0x1L
 FILESUBTYPE 0x0L
BEGIN
    BLOCK "StringFileInfo"
    BEGIN
        BLOCK "080404b0"
        BEGIN
            VALUE "Comments", "\0"
            VALUE "CompanyName", "made by：sleepandeat\0"
            VALUE "FileDescription", "2048\0"
            VALUE "FileVersion", "1, 0, 0, 1\0"
            VALUE "InternalName", "2048\0"
            VALUE "LegalCopyright", "版权所有(C) 2014\0"
            VALUE "LegalTrademarks", "\0"
            VALUE "OriginalFilename", "2048.exe\0"
            VALUE "PrivateBuild", "\0"
            VALUE "ProductName", "made by：sleepandeat 2048\0"
            VALUE "ProductVersion", "1, 0, 0, 1\0"
            VALUE "SpecialBuild", "\0"
        END
    END
    BLOCK "VarFileInfo"
    BEGIN
        VALUE "Translation", 0x804, 1200
    END
END

#endif    // !_MAC

#endif    // Chinese (中国) resources
/////////////////////////////////////////////////////////////////////////////



#ifndef APSTUDIO_INVOKED
/////////////////////////////////////////////////////////////////////////////
//
// Generated from the TEXTINCLUDE 3 resource.
//


/////////////////////////////////////////////////////////////////////////////
#endif    // not APSTUDIO_INVOKED

