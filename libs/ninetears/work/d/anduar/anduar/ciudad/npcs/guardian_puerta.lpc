// Pedasso guardian del finstro de la puerta.
// Gestur'97

#include "path.h"

inherit "/obj/monster";

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("guardias_anduar"))
   {
      if (ob->query_dead())
      {
         do_command("acuse "+ob->query_cap_name());
         do_command("'Eso te pasa por ser un delincuente.");
         ob->remove_timed_property("guardias_anduar");
      }
      else
      {
        this_object()->attack_ob(ob);
         do_command("say Eh, tu! Bastardo! Muere!!!!!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}/*event_enter*/

void setup()
{
   object objeto;
   set_name("guardian");
   set_short("Guardian de la puerta");
   set_al(-150);
   set_gender(1);
   set_main_plural("guardianes");
   add_plural("guardianes");
   add_alias("guardian");
   add_alias("guardia");
   add_plural("guardias");
   add_alias("human");
//   set_race_ob("Humano"); estaba tanto esta linea como la siguiente :?
   set_race_ob("/std/races/human");
//   set_guild_ob("/std/guilds/warriors/fighter");
   set_guild_ob("/std/guilds/warriors/warrior");
   set_wimpy(0);
   set_random_stats(14, 18);
   set_cha(14+random(4)); 
   set_str(19+random(11)); /* Fuerza extrema de los guerreros humanos :) */
                           /* 19 == 18/10 .................. 28 == 18/00 */
   set_level(25+random(10));
   set_long("Es el guardian de la puerta de Anduar. Parece muy fuerte, "
            "osea que no pienses mucho en atacarle. Va fijandose en la "
            "gente que entra y sale de la ciudad para ver si son "
            "delincuentes.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Oye, tu! Mas vale que respetes la ley!",
            1, ":te mira como si mirase a una cucaracha.",
            1, ":te ensenya el filo de su espada.",
            1, "'No ataque a nuestros ciudadanos o comerciantes. Si no "
               "sufrira las consecuencias",
            1, ":esta rigido como un cartel.",
       }));
       
   add_clone("/baseobs/weapons/bastard_sword",1);
   add_clone("/baseobs/armours/large_shield",1);
   add_clone("/baseobs/armours/platemail",1);
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
   ::attack_by(atacante);
}/*attack_by*/
