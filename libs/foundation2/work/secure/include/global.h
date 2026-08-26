#ifndef __GLOBAL_H
#define __GLOBAL_H

#define __foundation__     2.0
#define __foundation2__

#define SEFUN              "/secure/sefun/sefun"
#define OB_SIMUL_EFUN      SEFUN

/*
 * Define SUB_REALMS if you want your realms dirs broken into sub-dirs
 */

//#define SUB_REALMS

/*
 * Define PLAYERS if you have created a player object 
 */

#undef PLAYERS

#define DEBUG

#ifdef debug
#undef debug
#endif /* debug */

#ifdef DEBUG
#define debug(x, y)      message("system", y, find_player(x))
#endif /* DEBUG */

#endif /* GLOBAL_H */
