#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a temple to Omicron");
   set_property("light", 2);
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_long("You stand below the hall of peace. Only those of "
            "great faith may go up. The tiles along the walls "
            "are a light green here. The hall of peace is the "
            "gathering place of both monks and clerics for the "
            "protection and healing of the four lands and Lodos.");
   set_exits(([ "down" : ROOMS"temple5",
                "up" : ROOMS"peace_hall" ]));
}

int goUp() {
   if (this_player()->query_class() != "clergy" &&
       !wizardp(this_player())) {
      write("You dare not enter the hall of peace.");
      say(this_player()->query_cap_name()+" is stopped by a magical green aura.");
      return 1;
   }
   this_player()->move_player(ROOMS"peace_hall", "up");
   return 1;
}

void init() {
 ::init();
   add_action("goUp", "up");
}
