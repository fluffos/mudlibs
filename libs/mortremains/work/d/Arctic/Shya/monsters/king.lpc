

#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set ("short", "King Jared ");
    set ("long", "King Jared is one cold hearted man.\n");
    set ("id", ({"king", "king jared", "jared"}) );
    set_name("king jared");
    set("prevent_summon", 1);
    set ("gender", "male") ;
    set ("race", "human");
    enable_commands() ;
    set_living_name("king jared");
    set ("stat/constitution", 40);
    set ("stat/strength", 24);
    set ("base_ac", 0);
    set ("armor_class", -1);
    set ("damage", ({ 5,15 }) ) ;
    set ("weapon_name", "ice blade");
    set ("armour_name", "frost shield");
    set ("CLASS", "warrior");
    set_verbs( ({ "stabs at", "swings at", "swipes at" }) ) ;
    set ("weap_resist", 3);
    set("resist_type", ([ "fire":0 ]));
    set("magic_resist", 500);
    set_size(12);
    set_level(24);
    set ("moving", 0);
    set ("speed", 10);
    set ("chat_chance", 10);
    set ("chat_output", ({
      "King Jared stares at you with a frozen stare.\n",
      "Jared shouts, 'Who do you think you are barging in here?'\n",
      "Jared shouts, 'Guards! Remove this garbage from my castle NOW!'\n",
    }) );
    set ("att_chat_output", ({
      "Jared glares at you.\n",
    }) );
}
