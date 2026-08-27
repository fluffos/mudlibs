inherit "/obj/monster";

void setup() {
      
      set_name("guardian");
      set_short("guardian de la Cripta");
      set_gender(1);
      set_main_plural("guardianes de la Cripta");
      add_plural("guardianes");
      add_alias("guardian");
      add_alias("guardia");
      add_plural("guardias");
      set_al(60);
      set_race_ob("/std/races/human");      
      set_race("human");
      set_gender(1);
      set_level(35+random(10));
      set_wimpy(0);
      set_max_hp(1200);
      set_hp(1200);
      set_max_gp(1000);
      set_gp(1000);
      set_cha(14+random(4));
      set_random_stats(20, 22);
      set_long("Es un guardian de la cripta de la cienaga. Tiene aspecto humano, pero su cara palida y su cuerpo corroido "
               "te hacen pensar que llevan aqui muchisimo tiempo, como si estubieran bajo algun hechizo.\n\n");
      load_chat(20,
         ({
               1, "'llevo aqui desde hace mucho tiempo",
               1, ":te mira.",
               1, ":se pone en guardia y te mira de arriba abajo",
               1, "'Si quieres entrar a la cripta sera por encima de mi cadaver!",
               1, "'Estoy aqui para evitar que entreis a la cripta",
          }));
      set_guild("paladin");
      set_guild_ob("/std/guilds/warriors/paladin");
      add_attack_spell(60, "cargar", ({"/std/commands/carga", "carga",0,1}));
      add_property("NO_BUDGE", 1);
      add_clone("/baseobs/weapons/bastard_sword",1);
      add_clone(EQUIPO+"escudo_hagn",1);
      add_clone(EQUIPO+"armadura_hagn",1);
      add_clone(EQUIPO+"yelmo_hagn",1);
      ::init_equip();
}
int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   return 0;
}

