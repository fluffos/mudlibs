#include "/players/llew/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
   ::reset(arg);
   if(arg) return;

   set_name("A "+BOLD+BLK+"Dire Wolf"+NORM);
   set_level(10);
   set_wc(15);
   set_ac(7);
   set_hp(150);
   set_alias("wolf");
   set_alt_name("dracula dire wolf");
   set_long("A huge grey wolf. Standing almost waist high, it snarls\n"+
            "and growls, ready to rip into the nearest flesh. Summoned\n"+
            "by Prince Vlad, they are bound to his will.\n");
   set_al(-500);
   set_chat_chance(8);
   set_race("wolf");
   set_can_kill(1);
   load_chat("The Wolf growls deeply, baring its razor sharp teeth.\n");
   load_chat("The Wolf froths.\n");
   set_chance(15);
   set_spell_mess1("The "+BOLD+BLK+"Wolf"+NORM+" tears at its attacker's throat, it looks painful.\n");
   set_spell_mess2("The "+BOLD+BLK+"Wolf"+NORM+" tears at your throat...\n\n"+
                    BOLD+" P   A   I   N"+NORM+"   lances through you.\n");
   set_spell_dam(20);
}

heart_beat() { 
   ::heart_beat();
   if(!random(5) && !attacker_ob && present("vlad")) {
      if(present("vlad")->query_attack()) 
         attack_object(present("vlad")->query_attack());
   }
   else if(!present("vlad") && !random(3)) {
      tell_room(environment(),name+" lopes away.\n");
      call_out("des",1);
   }
}

des() {
   destruct(this_object());
}
