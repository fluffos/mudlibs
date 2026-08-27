/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("sacerdote");
   set_short("sacerdote");
   set_al(-100);
   set_gender(0);
   set_main_plural("sacerdotes");



   add_alias("human");
   add_alias("humano");
   add_plural("humanos");

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



   set_wimpy(0);
   set_random_stats(10, 14);
   set_level(2+random(3));   
   set_long("Es un sacerdote "+this_object()->query_race()+". Camina de un lado para otro con la cabeza "
            "gacha rezando oraciones.\n");
            
   set_aggressive(0);
   
   do_command("speak common");
   load_chat(30,
      ({
            1, "'Saludos buena persona, rezare por usted y su espiritu.",
            1, ":interrumpe sus oraciones para saludarte.",
       }));
       

   add_clone(BRETHEM+"equipo/tunica_sacerdote",1);
  ::init_equip();
}

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_brethem", 1, 300);
   ::attack_by(atacante);
}
