#include <sindarii.h>
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("mountain",1);
    set_property("light", 1);
    set_property("no castle", 1);
    set("short", "Mountain pass");
    set("long",
        "This small path curves north around the Daroq Mountains.  "
        "A forest begins just to the north.  Some small %^BOLD%^%^GREEN%^shrubs%^RESET%^ grow along the side of the "
        "trail.  The forest to the north has a dark and sinister look.  The trail continues north and southeast.");
    set_items(
        (["point" : "From here it looks like you can see the entire world.",
          "pass" : "It winds around from the west to the southeast.",
          "mountains" : "A huge mountain range separating the fertile "
            "lands of the east from the desert.",
          "valley" : "A huge forested valley.",
          "avalanche" : "The boulders that have fallen are very large, "
            "and could not be moved.",
({"shrubs","bushes","plants"}) : "They make out a strange circular pattern, perhaps you should search the %^BOLD%^%^GREEN%^shrubs%^RESET%^.",
          "mountain" : "It is one of the lower ones, guarding the pass."]) );
    set_exits( (["southeast" : ROOMS "pass1",
                 "north" : "/d/forest/nwvforest1/erooms/room2"]) );
}
void init() {
   ::init();
   add_action("search","search");
}
int search(string str) {
   if(str != "shrubs"){
     notify_fail("You find nothing unusual.\n"); return 0; }
   write("As you approach a shrub the ground caves in.\n");
   this_player()->move("/d/aekari/room/ca1");
   tell_object(this_player(), "You hit the ground with a thump.\n");
   this_player()->add_hp(-30);
   return 1;
}
