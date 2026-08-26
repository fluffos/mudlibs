

#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set ("short", "Knight");
    set ("long", "This knight is one tough guy.\n");
    set ("id", ({"knight"}) );
    set_name("knight");
    set ("gender", "male") ;
    set ("race", "human");
    enable_commands() ;
    set_living_name("knight");
    set ("stat/constitution", 40);
    set ("stat/strength", 24);
    set ("base_ac", 0);
    set ("armor_class", -1);
    set ("damage", ({ 5,15 }) ) ;
    set ("weapon_name", "axe");
set ("armour_name", "chainmail");
    set ("CLASS","warrior");
    set_verbs( ({ "smashes at", "swings at", "swipes at" }) ) ;
    set ("weap_resist", 3);
    set("resist_type", ([ "fire":0 ]));
    set("magic_resist", 500);
    set_size(12);
    set_level(24);
    set ("moving", 0);
    set ("speed", 10);
    set ("chat_chance", 10);
    set ("chat_output", ({
         "The knight stares at you with a steel glare.\n",
	   "The knight shouts, 'Halt! Who goes there?'\n",
       }) );
    set ("att_chat_output", ({
         "The knight glares at you with a steely look.\n",
       }) );
}
