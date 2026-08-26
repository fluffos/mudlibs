//This is a little spider that lives inthe Spidey Caves.
//Coded by Tyran on 7/17/2000

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "tyran");
    set("short", "a Small Spider");
    set ("long", @EndText
This small brown spider skitters around nervously on its eight
thin legs.  There's a small white patch on its head creating a
mottled effect.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"spider"}) );
    set_size(2);
    set_name("spider");
    set("gender", "female");
    set("race", "spider");
    set("prevent_summon",1);
    set("undead", 0);
    set("damage", ({10,12}) );
    set("weapon_name", "bite");
    set_verbs( ({ "bite", "madden" }) ) ;
    set("chat_chance", 30);
    set("chat_output", ({
      "The Spider hisses at you.\n",
      "The Spider clacks her mandibles at you.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("wealth", 250);
    set_level(15);
    arm("?", "?");
    wear("?", "?");
}

void die() {
    say(wrap(
        "The spider hisses evilly one last time and collapses."));
    ::die() ;
    return ;
}

/* End of File */