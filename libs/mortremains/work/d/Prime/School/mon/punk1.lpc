// 28 May 2000   Cyanide created the file.

#include "central.h"

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("short", "a young punk");
    set("long",  @EndText
This is a little punk with big glassy eyes and a more than slightly 
stoned expression on his face.
EndText
    );
    set("prevent_summon", 1);
    set("id", ({ "earl", "guard" }) );
    set_name("the punk-ass kid");
    set("race", "human");   
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set("damage", ({ 1, 4 }) );
    credit(random(4) + 1);
    set("gender", "male");
    set_level(8);

    set("chat_chance", 8);
    set("chat_output", ({
    "The punk says: Hey, you!   You don't belong here!\n",
    "Earl says: Got any donuts?\n"
    }) );
    set("att_chat_output", ({
    "Earl exclaims: You bastard!\n"
    }) );
    set("attrib1", "overconfident");
    set("attrib2", "overweight");

    // Give him a baggie of weed
}                                                            