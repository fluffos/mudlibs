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
   set_name("brujo guardian");
   set_short("%^ORANGE%^Brujo Guardian%^RESET%^");
   set_al(-100);
   set_gender(1);
   set_main_plural("%^ORANGE%^Brujos Guardianes%^RESET%^");
   add_alias("brujo");
   add_alias("guardian");
   add_alias("guardia");
   add_plural("guardias");
   add_plural("guardianes");
   add_alias("human");
   add_plural("brujos");
   set_race_ob("/std/races/human");
   set_guild_ob("/d/gremios/misc/testmago");
   set_wimpy(0);
   set_random_stats(18, 20);
   set_con(10+roll(3,3));   
                           /* 19 == 18/10 .................. 28 == 18/00 */
   set_level(35+random(10));
   
   set_long("Es un Brujo que esta a punto de terminar sus estudios en la "
           "Torre y que ha sido destinado a vigilar la entrada del Gremio "
           "de posibles intrusos. Viste una tunica negra que le cubre todo el "
           "cuerpo, excepto la cabeza, que esta cubierta por una capucha marron.\n");
            
   set_aggressive(0);
       
   ::init_equip();
}/*setup*/
