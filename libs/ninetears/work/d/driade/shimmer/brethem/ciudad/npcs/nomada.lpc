/* By Shimmer */

#define CREATOR "shimmer";

inherit "/obj/monster";

void setup() {
      set_name("nomada");

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

      set_main_plural("nomadas");
      add_plural("nomadas");
      add_plural("humans");
      set_al(-10);
      set_random_stats(10, 17);
      set_cha(6+random(10));
      set_level(5+random(5));
      set_wimpy(10);
   add_move_zone("anduar");
      adjust_money(random(100),"silver");
      set_short("nomada");
      set_long("Es un nomada "+this_object()->query_race()+" de algun remoto desierto que parece haber venido "
      "a comprar o intercambiar bienes.\n");
      load_chat(50, ({ 1, "'Demonios de ciudad hace mucho frio.", 
                       1, "'Anyoro mi hogar.",
                       1, "'Que Shimmer este con vos buen senyor.",
                       1, "'Vos venis de muy lejos buen senyor?."}));
      add_clone("/baseobs/armours/cape",1);
      ::init_equip();
} 