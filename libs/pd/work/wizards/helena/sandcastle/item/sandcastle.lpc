#include <sandcastle.h>
#include <std.h>

inherit OBJECT;

void create() {
::create();
set_name("Sandcastle");
set_id( ({ "castle", "sandcastle"}) );
set_short("A Sandcastle");
set_long("It is a four foot tall sandcastle, made out of sand and water, and standing fairly stable. It has it's own moat and drawbridge. You can see little footprints on the sand-drawbridge, as if someone has %^BOLD%^%^WHITE%^entered%^RESET%^ the sandcastle before.");
set_weight (100000);
}

void init() {
::init();
add_action("enter", "enter");
}

int enter(string str) {
if(!str)
if(str != "sandcastle") return 0;
write("As you walk towards the drawbridge, you seem to shrink in size! Smaller and smaller...");
this_player()->move(ROOMS "sandcastle1");
return 1;
}
