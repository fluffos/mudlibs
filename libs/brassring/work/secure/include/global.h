/*    /lib/secure/include/global.h
 *    from the Dead Souls Mud library
 *    mainted by Cratylus http://ww.dead-souls.net
 *
 *    modifed by lash (ccoker) for use in
 *    The Brass Ring mud
 *     - added this header
 *     - changed DAY_ONE define
 *     last modified 20/05/20
 */

#ifndef __GLOBAL_H
#define __GLOBAL_H

#define CONFIG_H "/secure/include/config.h"
#define NETWORK_H "/secure/include/network.h"
#define ROOMS_H "/secure/include/rooms.h"
#define SECRETS_H "/secure/include/secrets.h"

#include CONFIG_H
#include "lib.h"

#if COMPAT_MODE
#include "compat.h"
#endif

#define DAY_ONE           1449853200 //Dec 11, 2015 12:00:00

#define SEFUN             "/secure/sefun/sefun"

#define DEBUG

#ifdef debug
#undef debug
#endif /* debug */

//#ifdef DEBUG
//#define debug(x, y)      (find_player(x) || master())->eventPrint(x)
//#endif /* DEBUG */

#endif /* GLOBAL_H */
