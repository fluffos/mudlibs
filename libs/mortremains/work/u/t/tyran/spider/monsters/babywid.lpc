//This is the baby black widow that gets created in
//the room after the widoe of the web.
//Coded by Tyran on 7/16/2000

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "tyran");
    set("short", "Baby Spider");
    set ("long", @EndText
This small spider, newly hatched, is black with a
small white hourglass on her back.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"spider", "widow", "baby"}) );
    set_size(1);
    set_name("spider");
    set("gender", "female");
    set("race", "spider");
    set("prevent_summon",1);
    set("undead", 0);
    set("damage", ({8,10}) );
    set("damage_type","poison");
    set("weapon_name", "bite");
    set_verbs( ({ "bite", "madden" }) ) ;
    set("chat_chance", 20);
    set("chat_output", ({
      "The baby spider hisses at you.\n",
      "The baby spider clacks her mandibles at you.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("wealth", 200);
    set_level(10);
    arm("?", "?");
    wear("?", "?");
}

void die() {
    say(wrap(
        "With a final hiss the baby spider falls back\n"+
        "into the egg sac and dies."));
    ::die() ;
    return ;
}

/* End of File */