//Standard Monster file created by Mobydick.
//Nightmask made this monster for his area on Friday april 25th
//This monster is the first in many to see just how interactive
//I can get these fucker :)

#include <mudlib.h>
#include "shit.h"

inherit MONSTER ;

void create () {
  ::create();
  seteuid(getuid());
   set ("short", "Thrudd, the skeletal champion");
   set ("long", @Foo
Standing before you is the legandary Thrudd. He was once a great 
warrior untill the evil of the ArchLich corrupted this man into what
stands before you now. His eyes glow with a harsh red light, his armor
is blackened with the foul sent of death, he wields the weapon he did
as a warrior. From the looks of what you see, he used to be quite a 
large man.
Foo
);
   set ("id", ({ "thrudd", "skeleton", "warrior", "skeletal warrior", "champion" }) );
   set ("volume", 500);
   set ("capacity", 5000);
   set ("max_cap", 5000);
   set ("max_vol", 500);
   set ("mass", 3000);
   set ("bulk", 300);
   set_level(20);
   set ("resist_type", ([ "cold":0, "negative":0, "electrical":50]));
   set_name("Thrudd");
   set ("gender", "neuter");
   set ("race", "undead");
   enable_commands() ;
   set ("armour_class", -3);
   set ("armor_class", 13);
   set ("attack_strength", 5);
   set ("damage", ({ 4,10 }) );
   set ("weapon_name", "skeletal fists");
   set ("stat/strength", 18);
   set ("stat/dexterity", 16);
	set_verbs( ({ "punch at", "swing at" }) ) ;
	set_verbs2( ({ "punches at", "swings at" }) ) ;
   set ("chat_chance", 10);
   set ("chat_output", ({
        "Thrudd grunts at you.\n",
        "Thrudd asks: Got any candy?\n",
        "Thrudd polishes his skull.\n",
   }) );
   set ("att_chat_output", ({
        "Thrudd asks: Why you do dis?\n",
   }) );
}

void heart_beat () {
  object ob;
    ::heart_beat();

   ob = this_object()->query_current_attacker();
     if (random(10) == 0) {
     say(TPN+" grabs "+ ob->query("cap_name") +"and kicks "+
       objective(ob->query("gender")+" in the groin.\n") );
     tell_object(ob, TPN+" kicks you in the groin.\n");
   ob->recieve_damage((random(10)+1), "bludgeoning");
 }
}
