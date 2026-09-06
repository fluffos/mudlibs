/* The garden of Mistral and Joan */
/* added tree 09/08/97 - Joan */
/* edited 09/08/97 - Joan */

#include <stdrooms.h>
#include <properties.h>
#include <rooms.h>

inherit "/std/room";
inherit "/p/houses/common/room/meadow";

varargs void create() {
::create();

  SetIntShort("in Joan and Mistral's garden.");

  SetIntLong("You are in Joan and Mistral's garden. "
  "To the south and east you can go deeper into the garden. "
  "The wind whispers softly. The smell of fresh flowers drifts around you.\n" );

  SetIntSmell("The garden smells fresh with flowers!");
  SetIntNoise("You hear the wind whistling softly through the trees.\n");

  AddNoise(({"wind","whistling","trees"}),
 "You hear the wind whistling softly though the trees.\n");

  AddItem("/players/mistral/obj/tree",REFRESH_NONE);

  AddExit("south","./garden3");
  AddExit("east","./garden1");


 //  AddHerb("/d/avalon/common/obj/fruits/dandilion",2);
}

