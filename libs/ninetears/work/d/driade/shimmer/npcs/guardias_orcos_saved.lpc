/* Guardia de Zhyrkh by Shimmer */

inherit "/obj/monster";

void setup() {
      set_name("Guardia de Zhyrkh");
      set_short("Guardia de Zhyrkh");
      set_main_plural("Guardias de Zhyrkh");
      add_alias("guardia");
      add_plural("guardias");
      set_long("Es un guardia orco de la ciudad de Zhyrkh, su cometido es vigilas tanto las cercanias de la ciudad "
               "como el interior de la misma, es un orco inmenso, y no dudara en atacar a cualquier enemigo que se "
               "cruce o intente entrar en la ciudad.\n");
      set_al(60);
      set_race_ob("/std/races/orc");      
      set_race("orc");
      set_gender(1);
      set_max_hp(500);
      set_hp(500);
      set_max_gp(300);
      set_gp(300);
      set_random_stats(20, 22);      
      set_level(25+random(10));
      set_wimpy(0);
      set_al(-100+random(201));
      adjust_money(10+random(5), "gold");
      set_guild("barbaro");
      set_guild_ob("/std/guilds/warriors/barbaro");      
      load_chat(30,
         ({
               1, "@sonrrie al verte llegar.",
               1, "'La ciudad es peligrosa, hay muchos seres malignos ahi dentro. ",
               1, "'Estoy aqui para vigilar la ciudad.",
               1, "'Las minas del norte son conocidas por sus laberinticos tuneles, dicen que hay salidas ocultas en ellos. ",
               1, "'Me encantaria tener un par de humanos o elfos aqui ahora mismo para oir el crujido de sus craneos al hundirles mi cimitarra."
          }));
    
      add_clone("/d/driade/shimmer/npcs/equipo/cimitarra_orca",2);
      ::init_equip();

}

int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   return 0;
}

void event_enter(object ob, string mess)
{
  string raza  = ob->query_race();
  string guild = ob->query_guild_name();
  
  if (((raza == "elfo" || raza == "enano" || raza == "halfling" || raza == "humano" || raza == "drow" )))
   {
     do_command("speak common");
     do_command("say Que hace un bastardo como tu por aqui !!  Moriras !!!!!!");
     this_object()->attack_ob(ob);       
   }
   else
   {
  if (((raza == "orco" || raza == "duergar" || raza == "goblin" )))
  {
     do_command("say Bienvenido a Zhyrkh muchacho !!!!!!");
  }
  else
  {
    if (((guild == "barbaro")))
    {
    do_command("say Bienvenido joven barbaro, seguro que has destrozado muchos craneos en tu viaje.");
    }
  }
   }
  ::event_enter(ob, mess);
}

