/* The separee for Douglas (Mateese, 10-Dec-92)
*/

inherit "/std/room";  /* since we derive from this one */

#include <properties.h>
#include <rooms.h>

varargs void create() {

  ::create();  /* Initialize the /std/room */

    /* Set the short description */
  SetIntShort("Douglas' Separee");

    /* Set a nice long description */
  SetIntLong (
 "This is a small cosy room, dimly lit by some candles delicately scattered\n"
"around. On the floor are some mattresses, placed beneath some relaxing\n"
"people. Else there is just a sofa here, inhabited by a famous human author.\n"
"From the west you hear the noises of something which could be a bigger\n"
"restaurant.\n"
            );
  AddExit ("west", "/room/restroom");
  AddDetail ("sofa",
 "It is a velvet paisley-covered Chesterfield sofa, silently moving through\n"
"the room along its own complex mathematical topography.\n");
  AddDetail (({"human", "author"}),
 "As you look closer, you recognize him as Douglas - _the_ Douglas.\n");
  AddDetail (({"mattress", "mattresses"}),
 "The mattresses are dry and comfortable, and all are named `Zem'.\n");
  SetIntSmell ("You smell candlewax and fresh petunias.\n");
  SetIntNoise ("The hear the agreeable voice of Douglas' narrating.\n");

//  AddItem ("/obj/douglas",   REFRESH_DESTRUCT);
  Set(P_TPORT, TPORT_NO);
}

/*---------------------------------------------------------------------------*/
