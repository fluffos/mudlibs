inherit "/obj/monster";

void setup() {
      
      set_name("Espadero");
      set_short("Espadero de Zhyrkh");
      set_gender(1);
      set_main_plural("Espaderos de Zhyrkh");
      add_plural("espaderos");
      add_alias("guardian");
      add_alias("espadero");
      add_alias("guardia");
      add_plural("guardias");
      set_al(60);
      set_race_ob("/std/races/orc");      
      set_race("orc");
      set_gender(1);
      set_level(30+random(5));
      set_wimpy(0);
      set_max_hp(1000);
      set_hp(1000);
      set_max_gp(300);
      set_gp(300);
      set_cha(14+random(4));
      set_random_stats(20, 22);
      set_long("Es un espadero orco, guardian de la ciudad de Zhyrkh. Su tamanyo es enorme y su fuerza "
               "descomunal, su rango es elevado, un capitan de las ordas barbaras de Zhyrkh.\n\n");
      load_chat(20,
         ({
               1, "'si ves algun humano o elfo, avisame",
               1, ":te mira.",
               1, ":se pone en guardia y te mira de arriba abajo",
               1, "'Si quieres entrar a la ciudad ten cuidado, aqui dentro la unica ley es la fuerza",
               1, "'Estoy aqui para evitar que entren buenos en la ciudad",
          }));
      set_guild("barbaro");
      set_guild_ob("/std/guilds/warriors/barbaro");
      add_attack_spell(60, "golpear", ({"/std/commands/golpear", "golpear",0,1}));
      add_property("NO_BUDGE", 1);
      add_clone("/d/driade/shimmer/npcs/equipo/gran_cimitarra_orca",1);
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
     do_command("say Que hace un bastardo como tu por aqui ??  Moriras !!!!!!");
     this_object()->attack_ob(ob);       
   }
   else
   {
  if ((( raza == "duergar" || raza == "goblin" )))
  {
  do_command("say Bienvenido a Zhyrkh muchacho.!!!!!!");
  }
  else
  {
    if (((raza == "orco" || guild == "barbaro")))
    {
    do_command("say Bienvenido joven orco, seguro que has destrozado muchos craneos en tu viaje.");
    }
  }
   }
  ::event_enter(ob, mess);
}
