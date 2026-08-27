// Granjero. Gestur 19-6-97 (en lugar de estudiar para los examenes pierdo el
// tiempo con esto :)

#include "path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("granjero");
   set_short("granjero");
   set_al(-100);
   set_gender(1);
   set_main_plural("granjeros");
   add_alias("human");
   add_alias("humano");
   add_plural("granjeros");
   add_plural("humanos");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   set_random_stats(12, 16);
   set_cha(12+random(5));
   set_level(3+random(5));
   set_long("Parece un granjero normal y corriente, por lo visto va a ingresar"
            " sus beneficios.\n");
            
   set_aggressive(0);
   load_chat(15,
      ({
            1, "'Diablos! Ya nadie quiere leche de cabra.",
            1, "'Esperemos que no se ponga a llover."
       }));
   
   adjust_money(random(40), "silver");    
       
   add_clone("/baseobs/weapons/pitchfork",1);
   add_clone("/baseobs/armours/cloak",1);
   add_clone("/baseobs/armours/slippers",1);
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
   ::attack_by(atacante);
}/*attack_by*/
