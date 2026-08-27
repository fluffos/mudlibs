// Mmm, este npc al cambiar el define, incluso ponerlo
// literalmente, no se updatea por mucho ke le des xD

#define ESPEJISMO "/d/gremios/hechizos/mago/espejismo"

inherit "/obj/monster";

void setup() {
      set_name("discordia");
     set_short("Discordia, Archimaestra de Brujeria");
      set_al(60);
      set_main_plural("Discordias, Archimaestras de Brujeria");
      add_alias("archimaestra");
      set_race("human");
	set_language("common");
	set_gender(2);
      set_level(70);
      set_wimpy(0);
	set_max_hp(query_level() * 10 + 1000);
	set_hp(query_max_hp());
	set_max_gp(1000);
	set_gp(1000);
      set_random_stats(20, 22);
      set_long("Discordia, la Archimaestra de Brujeria.\n\n");
      set_guild("brujo de urghak");
      set_guild_ob("/d/gremios/miscs/testmago");
	add_attack_spell(40, "tormenta acida", ({"/d/gremios/hechizos/mago/tormenta_acida", "cast_spell",1,0}));
	add_attack_spell(20, "horrible marchitamiento", ({"/d/gremios/hechizos/mago/horrible_marchitamiento", "cast_spell",1,0}));
	add_attack_spell(40, "cono de frio", ({"/d/gremios/hechizos/mago/cono_frio", "cast_spell",0,0}));
	set_heart_beat(1);
}



