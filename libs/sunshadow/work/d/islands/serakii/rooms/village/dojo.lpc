// Serakii Dojo - LoKi 2022

#include <std.h>
#include "../../serakii.h"

inherit CROOM;

void create(){
   ::create();
    set_property("indoors",1);
    set_name("dojo");
    set_short("%^C064%^dojo%^CRST%^");
set_long("%^C101%^You stand in a fairly simple training area dedicated to simple martial arts, commonly known as a %^C107%^dojo%^C101%^. Along the walls are various weapons designed for training purposes - a sickle, quarterstaff, hand-carved spear, kitchen knife, and other simple tools are seen. The walls are made of a simple plaster and have been painted a %^C185%^dark yellow %^C101%^with a few torches which %^C228%^illuminate %^C101%^the room. The floor is made of hard-packed soil with a few heavy wool blankets rolled out for sitting and instruction.%^CRST%^\n");

    set_items(([
        ({"walls"}) : "%^C216%^These plaster walls are hard and well constructed, the builder clearly seeking simplicity but functionality.\n%^CRST%^",
        ({"floor"}) : "%^C216%^Hard packed but clay, designed for ease of use and limiting injuries while practicing.%^CRST%^\n",
        ({"blankets"}) : "%^C216%^These wool blankets are in a variety of simple earthen colors.%^CRST%^\n",
    ]));

set_smell("default","%^C064%^You smell incense.%^CRST%^");
set_listen("default","%^C138%^You hear training around you.%^CRST%^");

   set_exits(([

          "south" : TOWN"fight_ring",
          "down" : TOWN"meditation",
          "east" : TOWN"4"

   ]));


}
