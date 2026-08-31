#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    object ob;
 ::create();
    set_short("South Xelan Road.");
    set_long(
      "South Xelan Road is lightly traveled.  Houses line the road to the "
      "east and west.  The ancient stones underfoot running north and "
      "south make the road easy to follow. "
);
    set_night_long(
      "South Xelan is peaceful at night.  Shadows to the east and west "
      "show themselves to be buildings.  The stones underfoot are hard "
      "to make out in the darkness. "
);
    set_exits( 
              (["north" : ROOMS"sxelan1",
                "south" : ROOMS"sxelan3",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
    ob = new(OBJECT);
    ob->set_name("manhole");
    ob->set_id(({"manhole", "manhole cover", "cover"}));
    ob->set_short("a manhole");
    ob->set_long("This manhole looks like it leads down to the sewers of tirun."
                 "  Perhaps if you tried to open it, you could enter.");
    ob->set_prevent_get("How would you take a hole?");
    ob->move(this_object());
}

void init() {
  ::init();
    add_action("open","open");
}

int open(string str) {
   if(!str) {
     notify_fail("Open what?\n");
     return 0;
   }
   if(str != "manhole") {
     notify_fail("You cannot open that.\n");
     return 0;
   }
   if(this_player()->query_level() < 5) {
     notify_fail("You pull and tug but cannot budge the cover.\n");
     return 0;
   }
   write("As you open the cover, you slip and fall inside!");
   say("As "+this_player()->query_cap_name()+" opens the "
        "cover, they slip and fall inside!");
   this_player()->add_hp(-random(50));
   this_player()->move_player("/d/sewers/rooms/1");
   message("info", "A concerned citizen notices the open manhole"
                   " and replaces the cover.", this_object());
   return 1;
}
