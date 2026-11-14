/* A flying dragon for the Nightfall Flightdragon Airways */

#define COLOR "pink"
#define ALIAS "dragon"
#define SPEED 29

#include "/d/archwiz/randyandy/dragon/planevar.h"

buildnames() {
  stationnames = ({
  // BEGONE   "/d/ireland/common/forest/airport",
  // BEGONE   "/d/avalon/common/village/dragon_port",
  // BEGONE   "/d/avalon/common/paris/aeroport"
    });
  numstations = sizeof(stationnames);
}

get_direction(nr) {
	if (nr < numstations)
	     return "Paris";
	else
	     return "Ireland";
}

get_stationlist() {
	return "-- Nightfall Flightdragon Airways Pink Line --\n"+
	       "currently flying: Paris - England - Ireland\n";
}

#include "/d/archwiz/randyandy/dragon/plane.h"




