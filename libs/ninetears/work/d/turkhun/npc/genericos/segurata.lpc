inherit "/obj/monster";

#include "/d/turkhun/path.h"
#define TIEMPO 5000
int ataque=0;

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("guardias_anduar") || (int)ob->query_timed_property("guardias_zumelzu"))
   {
      if (ob->query_dead())
      {
         do_command("acuse"+ob->query_cap_name());
         do_command("'Eso te pasa por ser un delincuente.");
         ob->remove_timed_property("guardias_anduar");
      }
      else
      {
         this_object()->attack_ob(ob);
         do_command("say Fuera de aqui, delincuente!!!!!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}/*event_enter*/

void init()
{
   ::init();
   add_attack_spell(50, "slice",
   ({"/std/commands/slice","slice", 1}));
   add_action("do_steal", "robar");
}

void event_fight_in_progress(object ob1, object ob2)
{
   if (ob1->query_cap_name()=="Banquero"
    || ob1->query_cap_name()=="Senyor gordo"
    || ob1->query_cap_name()=="Noble"
    || ob1->query_cap_name()=="Guardia"
    || ob1->query_cap_name()=="Dimsdale"
    || ob1->query_cap_name()=="Granjero")
      call_out("atacar", random(3), ob2);
   
   else if (ob2->query_cap_name()=="Banquero"
         || ob2->query_cap_name()=="Senyor gordo"
         || ob2->query_cap_name()=="Noble"
         || ob2->query_cap_name()=="Guardia"
         || ob2->query_cap_name()=="Dimsdale"
         || ob2->query_cap_name()=="Granjero")
      call_out("atacar", random(3), ob1);
   
   else call_out("echar", random(3), ob1, ob2);
   
   ::event_fight_in_progress(ob1, ob2);
}

void atacar(object quien)
{
   if (!ataque)
   {
      do_command("'Pero que veo, una pelea. Empieza a rezar, "+
                 quien->query_cap_name()+".");
      ataque=1;
   }
   attack_ob(quien);
}

void echar(object ob1, object ob2)
{
   do_command("'Aqui no queremos peleas callejeras, fuera!");
   ob1->run_away();
   ob2->run_away();
}

void do_steal(string quien)
{
   if (!quien) return 0;
   if (this_player()->query_cha()<random(21))
   {
      if (random(4)==random(4))
      {
         this_object()->attack_ob(this_player());
         do_command("say Fuera de aqui, delincuente!!!!!!.\n");
         this_player()->add_timed_property("guardias_anduar", 1, TIEMPO);
      }
      else
      {
         write(this_object()->query_cap_name()+" se fija en ti, parece "
               "que ha estado a punto de pillarte.\n");
         do_command("say Oye, tu, mas vale que no te pille haciendo nada "
                    "extranyo.");
      }
   }
   return 0;
}         

void setup()
{
   object objeto;
   set_name("guardia");
   set_short("Guardia de seguridad");
   set_al(-100);
   set_gender(1);           /* Macho iberico (no soy sexista) */
   set_main_plural("guardianes");
   add_alias("guardian");
   add_alias("guardia");
   add_alias("segurata");
   add_plural("guardias");
   add_alias("human");
   set_race_ob("/std/races/human");
   set_guild("fighter");
   set_wimpy(0);
   set_random_stats(12, 18);
   set_cha(12+random(6));   
   set_str(19+random(11)); /* Fuerza extrema de los guerreros humanos :) */
                           /* 19 == 18/10 .................. 28 == 18/00 */
   set_level(20+roll(5,10));
   set_long("Es un guardia de seguridad de Anduar. Parece fuerte y dispuesto "
   "a mantener el orden. Si vas a robar ten cuidado ya que a los guardias no "
   "les gustan los delincuentes.\n");
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Por favor, respeten la cola.",
            1, ":se fija en ti.",
            1, ":te mira de forma desconfiada.",
       }));
   add_clone("/baseobs/weapons/bastard_sword",1);
   add_clone("/baseobs/weapons/bastard_sword",1);
   add_clone("/baseobs/armours/chainmail",1);
   ::init_equip();
       
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_anduar", 1, TIEMPO);
   ::attack_by(atacante);
}/*attack_by*/
