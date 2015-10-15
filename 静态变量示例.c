/* Note:Your choice is C IDE */
#include "stdio.h"
 int abc()
 {
 	static  vs=1;
 	printf("static= %d\n",vs);
 	++vs;
 	}
void main()
{
   int i;
   for(i=0;i<4;i++)
   abc();
    
}