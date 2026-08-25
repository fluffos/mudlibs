#include "path.h"
inherit "/obj/monster";
string *colors = ({"scrawny","mangy","black","fat","albino","brown"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("drole");
    set_short("Drole");
    set_long("  A wary "+colors[i]+" Drole. "
    "Short, squat and whiskery, the drole looks like a hairy brick. "
    "It seems to feed on insects and \"stuff\" it finds around here. "
    "A mouth full of sharp teeth seem to indicate that it's a match "
    "for most things round here. "
    "\n");

    set_random_stats(2,5);
    load_chat(10,
       ({
        1,":squeeks",
        1,":preens it's whiskers.",
        1,":snuffles around in the dirt.",
        1,":crunches through something disgusting."
       }));
    load_a_chat(100,
      ({
       1,":bites you!",
       1,":chitters at you.",
       1,":spits at you."
    }));
    set_level(i-3);
}





