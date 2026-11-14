/* generic map (GEMA) server object - header files
 * __________________________________________(i) Anatol@Silberland (2012) */

#ifndef _GEMA_H_
#define _GEMA_H_


#define GEMA_SERVER "/d/nacht/region/master/gema"
#define GEMA_CLIENT "/d/nacht/region/tools/karte"

// Property Handling (to be set in room or container objects)

#define P_GEMA "generic_map"
#define GEMA_COORDINATES 0
#define GEMA_ZONE 1

// calling the Map() ....

#define GEMA_MAP_FLAG_NOANSI        1
#define GEMA_MAP_FLAG_MARKEDMAP     2
#define GEMA_MAP_FLAG_COORDINATES   4
#define GEMA_MAP_FLAG_NO_OVERLAY    8

#endif
