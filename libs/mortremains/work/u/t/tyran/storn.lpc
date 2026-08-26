/*
** File: storn.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    // These first three lines are important. Any monster should
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "guess");
    set("short", "Storn");
    set ("long", @EndText
Storn is an ass hole who dared to talk shit about Ty's lady.
He deserves to die !!!!!
EndText
    );   // EndText should be on a line all by itself, with NO SPACES

    set("id", ({ "storn" }) );
    set_size(6);
    set_name("storn");
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
