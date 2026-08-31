// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit OBJECT;
int rt;

void create() {
::create();
set_name("tracker");
set_short("an animal tracker");
set_long("This is an animal tracker.  You can use this to find a specific animal.  "
"4 crystals lay apon the flat surface.  Who knows how this works.  Must be magic!");
rt=0;
}

void init() {
::init();
add_action("on", "on");
add_action("off", "off");
add_action("track", "track");
}

int on() {
if(rt==0) {
write("You turn the tracker on.");
write("The 4 crystals light up.");
rt=1;
return 1;
}
write("It is already on!");
}

int off() {
if(rt==1) {
write("You turn the tracker off.");
rt=0;
return 1;
}
write("It is already off!");
}
