#include <std.h>
inherit OBJECT;

create() {
   ::create();
   set_name("teleporter");
   set_short("");
   set_long("Something");
   set_value(0);
   set_property("no drop", 1);
   set_property("no bury", 1);
   set_property("no give", 1);
}
init(){
 ::init();
    add_action("teleport","teleport");
}
int teleport(string str) {  
    object ob;
    object loc;
    if(!str)
        return notify_fail("teleport where?");
    write("The world around you snaps like a rubberband, and you are somewhere else.\n");
   if (!this_player()->query_invis())                             
    say("Reality around "+this_player()->query_cap_name()+" is turned,
into nothing, and "+this_player()->query_cap_name()+" is gone.\n");
    this_player()->move("/wizards/slinker/workroom");
    return 1;
} 
int query_auto_load() { return 1; }
