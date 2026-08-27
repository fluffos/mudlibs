/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("ciudadana");
      set_short("ciudadana");
      set_al(-60);
      set_gender(2);
      set_main_plural("ciudadanas");
      add_alias("humano" "ciudadana" "mujer");
      add_plural("humanos" "ciudadanas" "mujer");

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
      set_wimpy(10);
      set_random_stats(12, 18);
      set_level(6+random(8));
      set_long("Una joven ciudadana "+this_object()->query_race()+" que que pasa el rato paseando por las calles de la ciudad.\n");
      adjust_money(random(5), "copper");
      set_aggressive(0);
      
      add_clone(BRETHEM+"/equipo/camisa",1); 
      add_clone(BRETHEM+"/equipo/goma_pelo",1);
      add_clone(BRETHEM+"/equipo/falda",1);
      ::init_equip();
}
