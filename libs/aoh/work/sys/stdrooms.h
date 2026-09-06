#ifndef _STDROOMS_H_
#define _STDROOMS_H_ 1

/*--------------------------------------------------------------------------
 * /sys/stdrooms.h -- Standard room paths to use
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

// The default place to move players to on login or after rescues.
#define STARTROOM    "/d/silvere/rooms/harbour/quay1_2"

// The default place to move wizards to on login or after rescues.
#define WSTARTROOM   STARTROOM

// The place to move new players to start their creation
#define NEWBIEROOM   "/d/login/entrance"

// Where to move players on a shutdown.
// TODO: Remove SHUTSHOP when full autoloading is in effect.
// TODO:: This also affects /obj/armageddon.
#define SHUTSHOP  "/room/shutshop"

// The default Healer. 
// TODO: Make me better and remove this entry.
#define HEALER    "/room/healer"

// The restaurant at the end of the universe.
// TODO: Keep Milliways?
#define RESTROOM  "/room/restroom"

#endif
