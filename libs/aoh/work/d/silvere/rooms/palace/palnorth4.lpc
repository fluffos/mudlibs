// Some room inside the palace
// created:       Sonic    [21-Jul-1997]
// last changed:

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
#include <doors.h>
inherit BASEROOM;

void reset()
{
   object door;

   /* the door is closed during reset anyways, but that happens
    * silently. Now, a message is printed to the room and the
    * door is closed manually. Closing the door is probably not
    * really necessary, but is done anyways :-)
    */
   door=present("wooden door",TO);
   if(door)
   {
      string otherroom;

      otherroom=({string})door->Query(P_OTHERROOM);
      switch(({int})door->Query(P_LOCKSTATE))
      {
         case LOCK_OPEN:
            tell_room(TO,"One of the guards closes the door again.\n");
            tell_room(otherroom,"The door is closed by a guard.\n");
            break;
         case LOCK_LOCKED:
            tell_room(TO,"There is a sudden sound from the door.\n");
            tell_room(otherroom,"There is a sudden sound from the door.\n");
            break;
      }
      door->Set(P_LOCKSTATE,LOCK_CLOSED);
   }
   ::reset();
}

varargs void create()
{
   room::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"A hall in the palace");
   Set(P_INT_LONG,
"A high passage continues from east to west. A door leads here to the "
"south into the private rooms of the Lu'meyn. Two guards are standing "
"to the left and right of it, protecting the room against unwanted "
"guests. Ceremonial guards are standing here at the wall and look in "
"full attention at you, just as they have to protect something very "
"valuable to them.\n");

   Set(P_INT_WIZMSG,
" East:  To the eastern part of the palace, private room of the Lu'meyna.\n"
" West:  To the western part of the palace.\n"
" South: Enter the private room of the Lu'meyn.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -10,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west",  SIL_PALACE("palnorth5"));
   AddExit("east",  SIL_PALACE("palnorth3"));

   AddDoor("south", SIL_PALACE("private2"),
      ([ P_DOORCODE:"wooden door",
         P_SHORT:"a wooden door",
         P_LONG:
            "This is a wooden door, that leads to the south. "
            "On the door are some intricate carvings, laid in "
            "with gold and silver. Guards are standing to the "
            "left and right of it, their spears readied. They "
            "are watching you closely.\n",
         P_SUB_DETAILS:
            ([ ({"carving","carvings","intricate carvings"}):
               "The carvings can be found on the door. They are just "
               "some patterns in the door, that are laid in with gold "
               "and silver. It looks very nice.\n",

               ({ "gold","silver"}):
               "No, you can't take that.\n",

               ({ "pattern","patterns"}):
               "The pattern is carved into the door. The carvings "
               "was then filled again with some gold and silver.\n",
            ]),
         P_HIDEEXIT:HIDE_ALWAYS,
         P_LOCKSTATE:LOCK_CLOSED,
      ]) );
}
