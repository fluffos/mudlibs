#include <std.h>

inherit OBJECT;

void create() {
   ::create();
   set_name("portal");
   set_id(({ "portal", "town portal" }));
   set_short("a town portal");
   set_long("This is a portal that will take you back to lodos.");
   set_prevent_get("You can't grab it.");
}

void init() {
   ::init();
   add_action("enter_portal", "enter");
}

int enter_portal(string s) {
   if(!s || s != "portal") return notify_fail("Enter what?\n");
   write("You enter the portal.");
   this_player()->move_player("/d/nopk/tirun/portal_room");
   return 1;
}

