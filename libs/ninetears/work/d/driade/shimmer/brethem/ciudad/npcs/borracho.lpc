/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup() {
      set_name("borracho");
      set_short("borracho");

  switch(random(10)){
     case 0:      
      set_race_ob("/std/races/human");      
      set_race("humano");
     break;
     case 1:      
      set_race_ob("/std/races/dwarf");      
      set_race("enano");
     break;
     case 2:      
      set_race_ob("/std/races/elf");      
      set_race("elfo");
     break;
     case 3:      
      set_race_ob("/std/races/lizard-man");      
      set_race("hombre-lagarto");
     break;
     case 4:      
      set_race_ob("/std/races/halfling");      
      set_race("halfling");
     break;
     case 5:      
      set_race_ob("/std/races/lizard");      
      set_race("hombre-lagarto");
     break;
     case 6:      
      set_race_ob("/std/races/drow");      
      set_race("drow");
     break;
     case 7:      
      set_race_ob("/std/races/orc");      
      set_race("orco");
     break;
     case 8:      
      set_race_ob("/std/races/goblin");      
      set_race("goblin");
     break;
     case 9:      
      set_race_ob("/std/races/duergar");      
      set_race("duergar");
     break;}


      set_main_plural("borracho");
      set_al(-100);
      set_random_stats(5, 12);
      set_cha(6+random(8));
      set_level(1+random(2));
      set_wimpy(10);
      adjust_money(random(10),"copper");

      set_long("Es un borracho que pasea por las calles dando tumbos y insultando a la gente, "
      "su aspecto es asqueroso, muy sucio y desharapado.\n");




      add_clone(BRETHEM + "items/jarra",1);
      add_clone(BRETHEM + "equipo/capa",1);
      ::init_equip();



} 
