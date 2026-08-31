#include <std.h>
#include <daemons.h>
#include <sindarii.h>
inherit VAULT;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The knight's bedroom");
    set("long",
	"This bedroom is devoid of any of the usual furnishings, "
	"making you aware of how impoverished its occupant must be. "
	"A door leads into the living room north. A glowing bubble "
        "of %^YELLOW%^yellow%^RESET%^ light covers a door leading west. "
        "Those whom have reaced level ten and wish to choose a subclass "
        "can <become knight> here.");
    set_items( ([ "door" : (: this_object(), "look_at_door" :) ]) );
    set_exits(([
      "north" : ROOMS "house",
      "west" : ROOMS "knight_sub"
    ]));
    set_door("door", ROOMS "house", "north", "honor key");
}

int go_west() {
   if (this_player()->query_subclass() != "knight" && !wizardp(this_player())) {
     write("You fear for your life and do not proceed.");
     return 1;
   }
   return 0;
}

int become(string str) {
   if (!str || str != "knight") return notify_fail("Become what?\n");
   if (this_player()->query_level() < 10 || this_player()->query_class() !=  
     "fighter" || this_player()->query_subclass() != "none")
     return notify_fail("You must be a level 10 fighter with no subclass.\n");
   write("%^BOLD%^You have become a %^RESET%^%^BLUE%^knight%^BOLD%^%^WHITE%^.");
   CHAT_D->do_raw_chat("fighter", "%^BOLD%^"+this_player()->query_cap_name()+
      " has become a %^RESET%^%^BLUE%^knight%^BOLD%^%^WHITE%^.");
   this_player()->set_subclass("knight");
   return 1;
}

void init() {
 ::init();
   add_action("go_west", "west");
   add_action("become", "become");
}

void look_at_door() {
    if(query_open("door")) write("It is open.");
    else write("It is closed.");
}

