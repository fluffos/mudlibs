inherit "/obj/weapon";

void setup() {
	set_base_weapon("daga");
	set_name("daga oxidada");
	set_short("daga oxidada");
	add_alias("daga");
	add_adjective("oxidada");
	set_long("Esto es una daga oxidada, util para producir incisiones.\n");
	set_main_plural("dagas oxidadas");
	add_plural("dagas");
	set_enchant(6);
}

int query_damage_roll()
{
	return (random(13) + 6) * ((random(20) <= 1) ? 2:1);
}
