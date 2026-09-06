#include <room.h>
#include "../DEFS.h"

void
create_room()
{
    set_short("Tanssilava (Dance Hall)");
    set_long(
      "You are at a genuine \
Finnish \"tanssilava\", an open floor outdoors, used for \
traditional finnish summer dances. People pay to get in. \
There is often a band, which plays for example \"humppa\" and \
\"jenkka\", and other finnish folk dances, and - of course - tango. \
There are many singers that are very popular among the countrymen \
(you could call them rednecks...), \
for example \"Reijo Taipale\", \"Isto Hiltunen\", \"Eija Kantola\", \
\"Joel Hallikainen\", just to name a few. \
At the summer dances, \
people will drink too much, fight - with fists or knives, depending \
on the area and people's ethnic background, \
puke and piss around, and try to get laid. Ah, forgot, some \
actually come to dance. They are a minority.");
    set_exits(([ "south" : CITY_PATH+"finnclub/shore" ]));

    set(ROOM_WD, WD_NONE);
    set_light_level(LT_LIGHTS);
    // Yes PK - this is a violent place :)
    // set(NO_PK);
    /* Not in city! This is in Finland, behind a magical teleport...
	    set(IN_CITY);
    */
    replace_program(ROOM_FILE);
}
