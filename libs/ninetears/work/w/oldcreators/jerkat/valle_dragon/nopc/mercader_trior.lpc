// Mercader de Trior. Jerkat '2002.
// #include "path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("mercader");
   set_short("mercader");
   set_gender(random(1));
   set_main_plural("mercaderes");
   set_race_ob("Humano");
   set_race_ob("/std/races/human");
   //   set_al(-750);
   // set_wimpy(25);
   set_random_stats(12, 16);
   set_level(3+random(6));     
   set_long("Es un mercader que ha venido a la fortificacion para vender"
            " todos sus productos que son de primera calidad.\n");
   // set_aggressive(0);
   load_chat(30,
      ({
            1, "'Buenos dias, senyor",
            1, ":sonrie.",
       }));
   add_clone("/baseobs/weapons/dagger",1);
   add_clone("/baseobs/armours/cape",1);
   ::init_equip();
}/*setup*/
