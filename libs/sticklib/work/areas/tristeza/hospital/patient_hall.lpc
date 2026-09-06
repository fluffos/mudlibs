#include <room.h>
#include <areas.h>
#include <city_name.h>

#define TP this_player()

/* Diseases are set_recover() by the doctor; so in this place the
   patients won't infect each other. Only patients are allowed to
   be here - the caretaker or the nurse will try to throw others
   out.
*/

/* todo: a sexy, young female nurse for male players, and a handsome
   male nurse for female players. */

void
create_room() 
{
    set_short("Patients' Hall");
    set_long(
      "You are in the hall of the patients of " CITY_NAME " Sanatorium.\
 People who are recovering from a disease, examination, or\
 or an operation can rest here.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);
    set_exits(([ "north" : AREA_TRISTEZA+"hospital/hall" ]));
    replace_program(ROOM_FILE);
}

