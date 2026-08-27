// Guldan Sep'98

#include "path.h"
inherit NPCS+"wizard";

void event_enter(object ob, string mess)
{
    string raza  = ob->query_race();
    string guild = ob->query_guild_name();

    if (raza == "Goblin" || raza == "Orco" || raza == "Duergar" ||
      raza == "Hombre-Lagarto" || raza == "Humano" || raza == "Gnomo" ||
      raza == "Halfling" || raza == "Elfo" || raza == "Enano" ||
      raza == "Medio-Orco" )
    {
	this_object()->attack_ob(ob);
    }
    else
    {
	if (ob->query_dead())
	{
	    do_command("risa "+ob->query_name());
	}
    }
    ::event_enter(ob, mess);
}
setup()
{
    GRADO=8;
    ::setup();
    set_name("marvik");
    set_short("Marvik");
    add_alias("mago");
    set_long("Marvik, el guardian del gremio de Magos Drow. Su cara indica una "
      "seriedad a base de toda prueba y con sus escudrinyadores ojos observa a todo "
      "aquel que intenta pasar, denegandole la entrada si no es un mago drow. Su "
      "alma es negra como lo es su tunica, y muchas veces al impedir entrar "
      "a matado a mas de uno. Yo de ti tendria cuidado.\n");
    set_gender(1);
    set_int(21);
    set_dex(19);
    set_str(18);
    set_con(36);
    set_cha(18);
    set_wis(18);
    set_race("Drow");
    set_race_ob("/std/races/drow");
    set_guild_ob("/std/guilds/wizards/drowwizard");
    set_al(6000);
    set_max_hp(1200);
    set_level(NIVEL);
    adjust_money(roll(4,query_level()/2),"platinum");

    load_chat(30,
      ({
	1, "'Los Magos Drow, son el mas antiguo y poderoso guild de Reinos de Leyenda.",
	1, "@amablemente.",
      }));

    load_a_chat(20,
      ({
	1, "'Ahora conoceras la furia de la magia Drow.",
      }));

    add_clone(WEAPONS+"ba_stonefall",1);
    add_clone(ARMOURS+"tu_stonefall",1);
    add_clone(ARMOURS+"ca_stonefall",1);
    add_clone(ARMOURS+"cp_stonefall",1);
    add_clone(ARMOURS+"am_stonefall",1);
    add_clone(ARMOURS+"an_stonefall",1);
    add_clone(ARMOURS+"br_stonefall",1);
    init_equip();
}
