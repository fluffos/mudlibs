/* A flying dragon for the Nightfall Flightdragon Airways */

#define COLOR "green"
#define ALIAS "dragon"
#define SPEED 19

#include "/d/archwiz/randyandy/dragon/planevar.h"

buildnames() {
	stationnames = ({
		// BEGONE "/d/halfling/common/room/dwarf/up2",
		// BEGONE "/d/archwiz/common/room/city/airport2",
		// BEGONE "/d/woodland/common/city/airport2"
	});
	numstations = sizeof(stationnames);
}

get_direction(nr) {
	if (nr < numstations)
	     return "Wooden City";
	else
	     return "Miner's Airport";
}

get_stationlist() {
	return "-- Nightfall Flightdragon Airways Green Line --\n"+
	       "currently flying: Wooden City - Nightfall City - Miner's Airport\n";
}

#include "/d/archwiz/randyandy/dragon/plane.h"
