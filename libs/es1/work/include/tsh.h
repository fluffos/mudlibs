/*
// tsh.h: files required by the TMI shell
// author: Truilkan@TMI
// last modified: 1993/04/03 by Watcher to move alias and wild_card to
//		   the base /std/body.c file so ghosts and other shells
//		   can use these tsh systems.
*/

#ifdef 0
inherit "/std/user/alias";
inherit "/std/user/wild_card";
#endif
 
inherit "/std/user/history";
inherit "/std/user/nicknames";
