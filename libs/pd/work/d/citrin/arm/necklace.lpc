//  Created by Whit
#include <citrin.h>
#include <std.h>
inherit ARMOUR;
int rt;
void create() {
    ::create();
    set_name("necklace");
    set_short("gemmed necklace");
    set_id(({"gemmed necklace", "necklace"}));
    set_long("The necklace is encrusted with gems from the far reaches "
      "of the world.  You wonder how it got here.\n");
    set_type("necklace");
    set_ac(1);
    set_limbs(({"torso"}));
}
/*
void reset() {
    ::reset();
    rt = 0;
}
void heart_beat() {
    int i;
    if(!this_object()->query_worn()) return;
    if(this_player()->query_alignment() < 0) {
        i = random( 100-this_player()->query_stats("dexterity")+query_idle(this_player()) );
        if(i > 1 < 30) {
            write("The necklace glows.  \nYou feel better.\n");
            say(this_player()->query_cap_name()+"'s necklace glows.\n");
            this_player()->add_sp(30);
        }
    }
}
*/
