/*
**File: test_hunk.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    // These first three lines are important. Any monster should
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "nsd");
    set("short", "A long-haired hunk");

    // This is the text you get when you look at the monster.
    set ("long", @EndText
This hunk is a really tall man of nordic ancesters.
He's irressistably handsome, with long-straight
black hair and light gray eyes. He has a broad back
and shoulders. Definitely, no woman could refuse
him. He's strong, and merciless.
EndText
    );
    set("id", ({ "hunk"  }) );
    set_size(7);
    set_name("hunk");
    set("gender", "male");
    set("race", "human");
    set("alive", 0);
    set("prevent_summon", 1);
    set("natt", 2);
    set("chat_chance", 0);
    set ("chat_output", ({
    }) );
    set_level(0);
    set("damage", ({0, 0}) );
    set("damage_type", "fire");
    set("weapon_name", "?");
    set_verbs( ({"?"}) );
    set("smell", "He smells like Nautica perfume...\n");
    set("no_attack", 1);

}

/* End of File */
