/*
**File: inifes.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    // These first three lines are important. Any monster should
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "guess");
    set("short", "Inifes");
    set ("long", @EndText
Inifes is the most idiot creature someone can deal with.
If you want to be mad all the time, just deal with him.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES

    set("id", ({ "inifes" }) );
    set_size(6);
    set_name("inifes");
    set("gender", "male");
    set("race", "human");
    set("alive", 0);
    set("damage", ({ 1,2 }) );
    set("damage_type", "poison");
    set("weapon_name", "butt");
    set_verbs( ({ "hit", "fart", "lap dance" }) ) ;
    set("nat", 1);
    set("chat_chance", 0);
    wear("?", "?");
    set_level(130);
    set("prevent_summon", 1);
}

/* End of File */
