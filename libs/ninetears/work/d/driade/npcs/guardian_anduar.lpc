// Guardian de anduar

#include "path.h"

inherit "/obj/monster";

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("guardias_anduar"))
   {
      if (ob->query_dead())
      {
         do_command("laugh "+ob->query_cap_name());
         do_command("'Eso te pasa por ser un delincuente.");
         ob->remove_timed_property("guardias_anduar");
      }
      else
      {
 this_object()->attack_ob(ob); /* viendo los abusos contra los tenderos, meto de nuevo que ataquen, en caso de que ataquen a nobles y/o tenderos */
         do_command("say Eh, tu! Bastardo! Fuera de aqui!!!!!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}/*event_enter*/

void setup()
{
   object objeto;
   set_name("guardian");
   set_short("guardian");
   set_al(-100);
   set_gender(1);
   set_main_plural("guardianes");
   add_alias("guardian");
   add_alias("guardia");
   add_plural("guardias");
   add_plural("guardianes");
   add_alias("human");
   set_race_ob("/std/races/human");
   set_guild_ob("/d/gremios/guerreros/fighter");
   add_move_zone("anduar");
   set_wimpy(0);
   set_random_stats(10, 18);
   set_cha(10+random(8));
   set_con(10+roll(3,3));   
   set_str(19+random(10)); /* Fuerza extrema de los guerreros humanos :) */
                           /* 19 == 18/10 .................. 28 == 18/00 */
   set_level(10+random(10));
   
   set_long("Es un guardian de la ciudad de Anduar. Parece fuerte, "
            "osea que no pienses mucho en atacarle. Va fijandose en la "
            "gente que ronda por estas calles.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Oye, tu! Mas vale que respetes la ley!",
            1, ":se fija en ti.",
            1, ":te ensenya el filo de su espada.",
            1, "'Oye, tu no eras el que robo la semana pasada?",
            1, ":al desfilar tropieza con una piedra y recupera el "
               "equilibrio disimulando.",
       }));
       
   add_clone("/baseobs/weapons/long_sword",1);
   add_clone("/baseobs/armours/med_shield",1);
   add_clone("/baseobs/armours/chainmail",1);
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
   ::attack_by(atacante);
}/*attack_by*/
