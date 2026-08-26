// Serakii meditation room - LoKi 2022

#include <std.h>
#include "../../serakii.h"

inherit CROOM;

void create(){
   ::create();
    set_property("indoors",1);
    set_name("meditation room");
    set_short("%^C041%^meditation Room%^CRST%^");
set_long("%^C042%^This nearly empty room has multiple thick pillows around the room. The pillows form a circle around a simple pillar in the middle of the room, designed hold items such as focus points, incense, and other spiritual devices. This is a place for individuals to sit in their own presence, focusing on their inner focus and allowing for them to achieve introspection.%^CRST%^\n");

    set_items(([
       ({"pillows"}) : "%^C060%^These pillows are simple but comfortable pillows.%^CRST%^\n",
        ({"pillar"}) : "%^C102%^A simple stone pillar in the middle of the room.%^CRST%^\n",
        ({"incense"}) : "%^C142%^The incense has a few different smells to it, though, all simple and common in nature.%^CRST%^\n",

    ]));

set_smell("default","%^C064%^You smell incense.%^CRST%^");
set_listen("default","%^C138%^You hear training around you.%^CRST%^");

   set_exits(([

          "up" : TOWN"dojo",

   ]));

}
