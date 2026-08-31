//Pyro's workroom

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([
      "no spam" : 1,
      "no steal" : 1,
      "no teleport" : 1,
     ]) );
    //set_property("indoors", 1);

    set("short", "%^RED%^Pyro's workroom%^RESET%^");
    set("night long", "%^BOLD%^%^BLACK%^Pyro's Workroom.%^RESET%^\n%^RED%^You are standing in a large, dome-shaped room. The craggy walls seem to be made of some sort of black volcanic rock. Lava flows inbetween the crags in the rocks and collects in a pool in the middle of the room. The lava pulses a dull red and casts a cool light over the room. There is a small hole in the wall that some moonlight shines through.");
   set("day long", "%^BOLD%^%^BLACK%^Pyro's Workroom.%^RESET%^\n%^BOLD%^%^RED%^You are standing in a large, dome-shaped room. The craggy walls seem to be made of some sort of black volcanic rock. Lava flows inbetween the crags in the rocks and collects in a pool in the middle of the room. The lava pulses a bright red and casts a warm light over the room. There is a small hole in the wall that some sunlight shines through.");

      set_exits(( [
    ]));


    set_items( ([
      ({"workroom", "room", "lair"}) : "Pyro carved himself this lair with some powerful raw magic that is unknown to you.",
       "hole" : "The lava flowing through the crags in the rocks flow around the hole, leaving the rocks on the bottom of the hole cool to the touch. Through the hole you can see Tirun square, you just may be able to <escape> through here if you choose.",
       "lava" : "The lava flows through the crags in the rocks on the walls, floor and ceiling and collects in a pool in the center of the room.",
       ({"ceiling", "roof"}) : "Lava appears to be flowing from a point in the center of the dome-shaped ceiling.",
      ({"wall", "walls"}) : "Technically, as this is a giant dome, there are no walls, only a floor and a ceiling. The ceiling, however, is made out of some sort of black rocks with lava flowing inbetween the crags in the rocks.",
      ({"rock", "rocks"}) : "The rocks that make up this room are interlocked and cobbled together. Lava flows through the spaces inbetween the rocks.",
       "pool" : "The pool of lava in the middle of the room is very real, and very hot. The lava bubbles and boils over, daring you to wade into it. At first that doesn't seem like such a good idea, but upon closer inspection you see what appears to be a tunnel in the center of the pool of lava.",
       "tunnel" : "It's definitely a tunnel, and it definitely leads somewhere. It's also definitely in the middle of a pool of definite lava, and you would definitely be a fool to wade into the pool to reach it.",
      ]) );

    set_smell("default", "Warm steam enters your nostrils and calms you down.");
    set_listen("default", "You can hear lava bubbling and boiling over.");
}

int do_pray() {
    if(!this_player()->query_ghost()) {
        notify_fail("The living do not need to pray for revival.\n");
        return 0;
    }
    this_player()->revive();
    this_player()->fix_vital_bonus();
    this_player()->set_hp(10);
    this_player()->set_heart_beat(1);
    this_player()->set_heal_rate(2);
    return 1;
}

int init() {
  ::init();
  add_action("cmd_escape", "escape");
  add_action("do_wade", "wade");
  add_action("do_pray", "pray");
  return 1;
}

int cmd_escape(string str) {
  write("You carefully crawl through the hole in the dome wall and "
       +"find yourself back in Tirun square. As you turn around to get "
       +"your bearings, you find that you have no idea where you crawled "
       +"out of and are unable to see a way back.");
  this_player()->move_player("/d/nopk/tirun/square", "through the hole in the wall.");
  return 1;
}


int do_wade(string str) {
  if(str != "pool" && str != "into pool" && str != "into tunnel" && str != "towards tunnel")
    return notify_fail("Wade where?\n");
  write("You wade into the pool of lava and can feel it %^RED%^BURNING%^RESET%^ your skin.");
  message("info", this_player()->query_cap_name()+" wades into the pool of lava, burning "+this_player()->query_objective()+"self in the process.", environment(this_player()), this_player());
  this_player()->add_hp(-1500);
  if(this_player()->query_hp() < 10) this_player()->set_hp(10);
  if(!wizardp(this_player())) {
    write("You are not strong enough to withstand the intense pain and jump back out of the pool.");
    message("info", this_player()->query_cap_name()+" screams in pain and retreats from the pool.", environment(this_player()), this_player());
    return 1;
  }
  write("You grit your teeth and dive through the tunnel in the middle of the pool.");
  message("info", this_player()->query_cap_name()+" disappears under the lava.", environment(this_player()), this_player());
  this_player()->move_player("/wizards/pyro/personal/workroom_main", "into the pool of lava.");
  return 1;
}

