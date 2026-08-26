//This is the Widowof the Web, a Giant Black Widow Spider
//Coded by Tyran on 7/12/2000

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "tyran");
    set("short", "The Widow of the Web");
    set ("long", @EndText
This huge black spider has a large red hourglass on her back.
Her long spindly legs  gently tap the strands of her web checking
the vibrations for prey
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"spider", "widow"}) );
    set_size(6);
    set_name("spider");
    set("gender", "female");
    set("race", "spider");
    set("prevent_summon",1);
    set("undead", 0);
    set("damage", ({10,15}) );
    set("damage_type","poison");
    set("weapon_name", "bite");
    set_verbs( ({ "bite", "madden" }) ) ;
    set("chat_chance", 30);
    set("chat_output", ({
      "The Widow of the Web hisses at you.\n",
      "The Widow of the Web clacks her mandibles at you.\n",
      "The Widow of the Web taps on her web.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("wealth", 750);
    set_level(25);
    arm("?", "?");
    wear("?", "?");
}

void die() {
    say(wrap(
        "With a final hiss the Widow of the Web falls back\n"+
        "onto her web ripping it as she falls\n"));
    ::die() ;
    return ;
}

/* End of File */