//This is a giant spider that lives inthe Spidey Caves.
//Coded by Tyran on 7/19/2000

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "tyran");
    set("short", "a Giant Spider");
    set ("long", @EndText
This giant spider sprawls across her web.  She is
a dark reddish-brown monstrous spider.  The color
fades to a light tan closer to where her spinnarets
are.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"spider"}) );
    set_size(5);
    set_name("spider");
    set("gender", "female");
    set("race", "spider");
    set("prevent_summon",1);
    set("undead", 0);
    set("damage", ({11,14}) );
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
    set("wealth", 500);
    set_level(20);
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