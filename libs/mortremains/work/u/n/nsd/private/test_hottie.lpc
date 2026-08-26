/*
** File: test_hottie.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;
object the_key;

void create () {
    // These first three lines are important. Any monster should
    ::create();
    seteuid(getuid());
    set("prevent_summon", 1);
    enable_commands() ;
    set("author", "NSD");
    set("short", "A red-head hottie");

    set ("long", @EndText
A beautiful red-head woman, with straight hair and
aqua-blue eyes. She's got the athlethic build
and turns every man on. No male can refuse her.
She eyes men like a hungry wolf...
EndText
    );  //EndText should be on a line all by itself, with NO SPACES
    set("id", ({ "hottie"  }) );
    set_size(6);
    set_name("hottie");
    set("gender", "female");
    set("race", "human");
    set("alive", 0);
    set("prevent_summon", 1);
    set("natt", 2);
    set("chat_chance", 0);
    set("weapon_name", "?");
    set("damage", ({0, 0}) );
    set("damage_type", "fire");
    set_verbs( ({"?"}) );
    set_level(0);
    set("smell", "She smells like Passion perfume...\n");
    set("no_attack", 1);

}

/* End of File */
