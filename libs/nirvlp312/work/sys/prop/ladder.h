/*
 *  <prop/ladder.h>
 */

#ifndef _sys_prop_ladder_h
#define _sys_prop_ladder_h

#define P_LADDER_EXIT   "ladder_exit" /* array of size 4 */

/* Example: set_property ( P_LADDER_EXIT, ({ dest, flag, id, len }) ); */

#define LA_DEST 0 /* room to enter from this room with `climb ladder' */
#define LA_FLAG 1 /* 1 - ladder must be held by a second player   */
#define LA_ID 2 /* array of items to lean the ladder against
         ("down" to allow `lower ladder') */
#define LA_LEN  3 /* the minimum length of the required ladder
         in feet (the maximum length of a ladder
         is LA_MAX_LENGTH and the minimum is 3)
         or the filename of an object in which to call
         ladder_exit_hook (0, item) when the ladder
         is leaned or lowered and ladder_exit_hook (1, item)
         when sombody is climbing the ladder. When the
         return value is non-zero the actions succeed. */
#define LA_MAX_LENGTH 16

#endif /* _sys_prop_ladder_h */

