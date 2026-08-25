#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  High Forest");
set_long("\n   Realm of the Elf:  High Forest.\n\n"
         "     This looks like a very gloomy and unsecure part of the "
         "forest.  There are a lot of large trees and bushes around "
         "here."
         "\n\n");

 add_item("tree","The trees are covering the sky above you.\n");
 add_item("bush","The bushes are covering the view in all directions.\n");
 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
    "Everywhere you look, you see small animals moving around.\n");

 add_exit("east", ROOM+"fo19", "road");
 add_exit("north", ROOM+"fo12", "road");
 add_exit("south", ROOM+"fo23", "road"); 

 set_zone("forest");
}
