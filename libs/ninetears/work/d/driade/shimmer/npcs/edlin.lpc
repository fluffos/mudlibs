inherit "/obj/monster";
void setup() {
      set_name("edlin");
      set_race_ob("/std/races/human");
      add_alias("edlin");
      set_main_plural("edlins");
      add_plural("edlins");
      set_al(-10);
      set_level(query_level()+random(20));  
      set_wimpy(0);
      set_max_hp(query_level() * 10 + 2000);
      set_hp(query_max_hp()+1000);
      set_max_gp(1000);
      set_gp(1000);
      set_language("common");
      set_gender(1);
      set_random_stats(20, 22);
      adjust_money(random(300),"gold");
      set_short("edlin");
      set_long("Ante ti tienes a un hombre anciano, vestido con un extranyo ropaje, es Edlin, el que fuera mano derecha "
      "del Rey Hahn, hechicero de Reino. Se ve muy mayor, mucho mas de lo que te puedes imaginar, y su cara denota la "
      "tristeza que le inunda el alma. Desde la gran batalla de Hahn, no ha hecho otra cosa mas que vagar por las cienagas "
      "y suele subir a lo alto de estas rocas, desde donde se divisa toda la muralla, para intentar recordar como era antes "
      "de la destruccion del reino, su vida no tiene ya sentido.\n");
      load_chat(50, ({ 1, "'Vaya, que te trae por aqui?, hace muchos anyos que no tenia visitas aqui en la cienaga.", 
                       1, "'Quien eres y que es lo que buscas en mi, yo no tengo nada que ofrecer",
                       1, "'Desde aqui se puede contemplar lo que antes era un gran y prospero reino, ahora solo hay mal y destruccion.",
                       1, "'Si tubiera otra oportunidad."}));
      set_guild("Mago");
      set_guild_ob("/std/guilds/wizards/magobueno");
      add_attack_spell(40, "tormenta acida", ({"/std/spells/mago/tormenta_acida", "cast_spell",1,0}));
      add_attack_spell(20, "horrible marchitamiento", ({"/std/spells/mago/horrible_marchitamiento", "cast_spell",1,0}));
      add_attack_spell(40, "cono de frio", ({"/std/spells/mago/cono_frio", "cast_spell",0,0}));
      set_heart_beat(1);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/capa_edlin",1);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/amuleto_edlin",1);
      add_clone("/d/driade/shimmer/hahn/npcs/equipo/brazaletes_edlin",1);
      ::init_equip();
}

