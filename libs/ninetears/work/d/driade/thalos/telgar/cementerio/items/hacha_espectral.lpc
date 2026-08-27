inherit "/obj/weapon";

void setup() {
	set_base_weapon("hacha de oneex");
	set_name("hacha espectral");
	set_short("hacha espectral");
	set_long("Es una especie de hacha de guerra duergar, pero parece estar hecha del mismo materia que "
	         "el propio espectro duergar que la empunyaba.\n");
	add_alias("hacha");
	set_main_plural("hachas");
	add_plural("hachas");
add_property("race",({"no muerto"}));
}
int query_damage_roll()
{
  if (TP->query_race() == "no muerto") {
    return ((4*random(8)+4)+(2* (random(TP->query_level())/2) ));
  }
    return (random(13) + 1) * ((random(20) <= 1) ? 2:1);
}
