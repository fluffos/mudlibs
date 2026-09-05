#include "/players/llew/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name(MAG+"TERROR"+NORM);
   set_level(21);
   set_alt_name("terror");
   set_alias("fear");
   set_long("The Incarnation of Terror, to be described later.\n");
   set_race("dragon");
   set_wc(35);
   set_ac(20);
   set_hp(500+random(150));
   set_al(-1000);
   set_aggressive(1);
   set_can_kill(1);
}

heart_beat() { 
   ::heart_beat();
   if(!random(5) && !attacker_ob && present("fear")) {
      if(present("fear")->query_attack()) 
         attack_object(present("fear")->query_attack());
   }
}

