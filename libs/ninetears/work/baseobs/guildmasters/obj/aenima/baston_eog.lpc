inherit "/obj/weapon";

void setup() {
	set_base_weapon("twohanded_staff");
	set_name("%^BOLD%^Baston de %^BLACK%^EOG%^RESET%^");
	set_short("%^BOLD%^Baston de %^BLACK%^EOG%^RESET%^");
	set_long("Esta poderosa arma fue creada por los dioses "
	         "mediante unas tecnicas traidas del futuro mediante metodos desconocidos.\n");
	add_alias(({"baston", "baston de eog","eog"}));
	set_main_plural("%^BOLD%^Bastones de %^BLACK%^EOG%^RESET%^");
	add_plural(({"bastones", "bastones de eog"}));
	set_twohanded(0);
	set_enchant(15);
	set_weight(1);
	add_property("noslice",1);
	add_property("guild", "mago de agband");
}

int query_damage_roll()
{
	return ::query_damage_roll() + random(5);
}
