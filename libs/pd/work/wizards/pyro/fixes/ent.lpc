#include <std.h>
#include <daemons.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "Entrance to the cave");
    set("long",
        "The great western highway leading east-west through Tirun is north of "
        "this place. This is the opening to a rocky cave. The cave walls are not "
        "too far apart, giving it a cramped feel."
    );
    set_items(([
        "highway" : "It is located right to the north.",
        "cave" : "A cave is just within this opening.",
        "walls" : "Looks like a tight fit.."
    ]));
    set_exits(([
        "north" : ROOMS"highway3",
        "south" : ROOMS"cult/cave1",
    ]));
}

void reset() {
 ::reset();
   if (!present("extremist")) {
     new(ROOMS "cult/mob/extremist")->move(this_object());
     new(ROOMS "cult/mob/extremist")->move(this_object());
   }
}

void init() {
  ::init();
  add_action("climb_it","climb");
}

int climb_it(string str) {
  if(!str) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if(str != "up") {
    notify_fail("You can't climb that!\n");
    return 0;
  }
  else {
    if(GUILD_D->query_guild(this_player()->query_name()) != "dw" &&
         !wizardp(this_player())){
       say(this_player()->query_cap_name()+" tries to climb up, but falls on their rear.",this_player());
       this_player()->add_hp(-5);
       return notify_fail("You can't climb that!\n");
    }
    else {
      this_player()->move_player("/d/guilds/dw/entrance", "climbs the cliff face.");
      return 1;
    }
  }

}
