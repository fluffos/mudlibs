/*
#define DEBUG
#define AUTOLOAD "players/balowski/quicktyper/quicktyper"
*/
#define AUTOLOAD "obj/quicktyper"

#define MAX_HISTORY 20
#define LIST_SIZE 20
#define NO_HISTORY_ADD 1
#define REFRESHING 2
#define NEEDS_REFRESH 4
#define IN_SPEEDSTER 8

#define MAX_ALIAS 24
#define COUNT_UNTIL_REFRESH 40
/*
#define REARRANGE 400000
 */
#define VERSION "Nirvana quicktyper version 3.05-B&B(nd) created 950301\n"
/*
#define LOGALIASRECURSION
 */
#define LOGBADALIASCHAR
#define SPEEDSTER 3

#ifdef DEBUG
#define DWRITE(ARG) write(ARG);
#else
#define DWRITE(ARG)
#endif
