#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 3);
   set_property("night light", 2);
   set_property("no castle", 1);
   set_short("a small clearing");
   set_long("This part of the orc fortress has been built in a "
           "clearing in the forest. The crude, jagged-edged clearing "
           "has been cut out by goblins who have been enslaved by "
           "the orcs. A small hut has been built here as a makeshift "
           "slave quarters.");
   set_items(([
          "slaves" : "Several goblins slave are working here.",
          "hut" : "A small hut has been built for slaves to live.",
          "goblins" : "The orcs have goblin slaves to do their work."
          ]));
   set_exits((["north" : ROOMS"south_orcs/path2",
             "enter" : ROOMS"south_orcs/hut2",
             "east" : ROOMS"south_orcs/forest1",
             "south" : ROOMS"south_orcs/path4"]));
}
