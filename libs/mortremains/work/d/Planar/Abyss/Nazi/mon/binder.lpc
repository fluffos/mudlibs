/*
**File: binder.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    // These first three lines are important. Any monster should
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "Book Binder demon");
    set ("long", @EndText
A powerful demon of enormous proportions. Its head is 
as big as it's body. Has big horns, and sharp teeth.
It has long sharp claws that can slash you easily.
Scares the shit out of you...!!
EndText
    );
    set("id", ({ "Book binder", "binder", "demon" }) );
    set_size(10);
    set_name("Book binder");
    set("gender", "neuter");
    set("race", "demon");
    set("lore_type", "demon lore");
    set("undead", 0);
    set("damage", ({15, 30}) );
    set("damage_type", "slashing");
    set("armor_class", 1);
    set("CLASS", "warrior");
    set("magic_resist", 30);
    set("resist_type", ([ "cold" : 50, "electricity" : 8, "poison" : 3 ]));
    set("weapon_name", "sharp claws") ;
    set_verbs( ({ "swing at", "peer at", "attack", "cut" }) ) ;
    set("natt", 2);
    set("chat_chance",5);
    set ("chat_output", ({
      "Book binder cackles demonically...\n",
      "Book binder goes: MUHAHAHAHAHAHAHA.....\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
      "Book binder cackles demonically...\n",
      "Book binder goes: MUHAHAHAHAHAHAHA.....\n",
    }) );
    set_level(30);

    set("aggressive", 30);
    set("prevent_summon",1);
}

/* End of File */
