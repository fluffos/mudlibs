#ifndef __LW_H__

#define __LW_H__

#define SCREEN_WIDTH 78
#define lw(x) sprintf("%-=*s",SCREEN_WIDTH,x)
#define lwnl(x) sprintf("%-=*s\n",SCREEN_WIDTH,x)
#define writelw(x) printf("%-=*s",SCREEN_WIDTH,x)
#define writelwnl(x) printf("%-=*s\n",SCREEN_WIDTH,x)

#endif // __LW_H__
