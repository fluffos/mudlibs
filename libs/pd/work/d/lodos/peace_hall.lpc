#include <std.h>
#include <lodos.h>

inherit ROOM;

int goWest() {
   if (this_player()->query_subclass() != "monk" &&
       !wizardp(this_player())) {
      write("A magical force holds you back.");
      return 1;
   }
   this_player()->move_player(ROOMS"monk_wing", "west");
   return 1;
}

int goEast() {
   if (this_player()->query_subclass() != "cleric" &&
       !wizardp(this_player())) {
      write("A magical force holds you back.");
      return 1;
   }
   this_player()->move_player(ROOMS"cleric_wing", "east");
   return 1;
}

void create() {
    object ob;

    ::create();
    set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
    set_property("no attack",1);
    set_short("The Hall of Peace");
    set_property("light", 2);
    set("long",
         "Welcome to The Hall of Peace!\n"
        "Both Monks and Clerics come here to protect and heal "
        "both the four lands and Lodos itself. It is here that "
        "both of these classes come to gather together and discuss "
        "the ways of light and of peace.");
    set_exits( 
              (["down" : ROOMS"temple6",
              "east" : ROOMS"cleric_wing",
              "west" : ROOMS"monk_wing"]) );

    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({ "board", "peace board" }) );
    ob->set_board_id("peace_board");
    ob->set_max_posts(75);
    ob->set_edit_ok("inferno");
    ob->set_location(ROOMS"peace_hall");
    ob->set("short", "the board of peace");
    ob->set("long", "Both monks and clerics come here to post "
            "about their experiences and concerns.");
}

void init() {
    ::init();
    add_action("goWest", "west");
    add_action("goEast", "east");
  }
