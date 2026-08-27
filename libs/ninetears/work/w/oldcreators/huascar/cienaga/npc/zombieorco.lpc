inherit "/obj/monster";
void setup()
{
set_name("orco");
add_alias("zombie");
set_short("Zombie de ORCO");
set_long("Es un no muerto que vaga atormentado por estas tierras buscando "
	 "victimas para aplacar su ira. En su anterior vida fue un poderoso "
	 "guerrero y parece ser que no ha olvidado el arte de la guerra.\n");
set_race("orc");
set_guild("warrior");
add_property("undead",1);
set_random_stats(40,45);
set_level(35+random(5));
set_gender(1);
set_al(-100);
set_aggressive(4);
set_wimpy(0);
adjust_money(10,"gold");
load_chat (100,
  ({
  1,"' GROOOOAKKKKKKK.\n",
  2,"Zombie se lame unas llagas.\n",
  }));
}
