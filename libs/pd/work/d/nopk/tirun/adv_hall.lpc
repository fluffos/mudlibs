#include <config.h>
#include <std.h>
#include <tirun.h>
#include <daemons.h>
#include <rooms.h>

inherit HALL;

void create() {
  object ob;
  
  ::create();
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
                    "indoors"     : 1,
                    "no steal"    : 1 ]) );
  set_short("Adventurer's Hall");
  set_long( 
        "%^CYAN%^Tirun adventurer's hall.%^RESET%^\n"
        "People that are not a member of a class meet here to discuss "
        "their adventuring, train their stats and skills, and to level.  "
        "The Colleseum entrance is to the south.  Against the "
        "east wall is a staircase leading down."  );
    set_exits( ([
                   "down" : ROOMS"ombud_hall",
                  "west" : ROOMS"adv_enter",
                  "south" : "/d/arena/bet",
		  "up" : ROOMS"portal_room",
             ]) );
  set_items( ([
        "hall" : "One of the exits leading out of this place.",
        "stairs" : "Cut from marble, they lead down.",
        "staircase" : "Cut from marble, they lead down."
           ]) );

  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "bulletin board", "adventure board" }) );
  ob->set_board_id("adv_board");
  ob->set("short", "The Adventure Board");
  ob->set("long", "An old cork board where the adventurers "
          "who pass through Tirun post information on the "
          "things they have discovered.\n");
  ob->set_max_posts(99);
  ob->set_location(ROOMS"adv_hall");

}

int go_down() {
  if(!wizardp(this_player())) {
    write("%^BLUE%^%^BOLD%^You cannot penetrate the force of the blue light.");
    say(this_player()->query_cap_name()+" tries to get through the "
        "passage, but fails.", this_player());
    return 0;
  }
  return 1;
}
