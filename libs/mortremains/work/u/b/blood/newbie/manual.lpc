#include <mudlib.h>
    
inherit OBJECT;
 
void create() {

    seteuid(getuid());
    set("name", "manual");
    set("long", @EndText
This is an instruction manual, small by most standards. Perhaps you
should read it to find out what instructions it provides?
EndText
);
    set("short", "An Instruction Manual");
    set("id", ({ "manual", "instruction manual" }) );

}

void init() {
add_action("read_manual", "read");
}
int read_manual(string str) {
if (!str || str!="manual") {
write("Read what?\n");
return 1;
}

say(TPN+" reads the instruction manual.\n");
write(@EndWrite
This is the prized instruction manual for the flute of home.  This flute
contains six destinations accessed by playing the six songs available
with the magics from the flutes previous player.  Simply play the song
number that you want, and poof, off you go..

EndWrite
);
return 1;
}
