inherit "/obj/weapon";

void setup() {
  set_min_level(33);
	//set_base_weapon("hacha de oneex");
	set_base_weapon("bastard sword");
	set_name("%^BOLD%^Espada %^RED%^Sangrienta%^RESET%^");
	// el set name no se usa con colores normalmente, pero aparece si se
	// usan mensajes de hostias con el nombre de la arma
	set_short("%^BOLD%^Espada %^RED%^Sangrienta%^RESET%^");
	set_long("Esta poderosa arma fue creada por el propio Drakull "
	         "durante su asedio a los Reinos.\n");
	add_alias(({"espada", "espada sangrienta", "sangrienta"}));
	//add_adjective("sangrienta");
	set_main_plural("%^BOLD%^Espadas %^RED%^Sangrientas%^RESET%^");
	add_plural(({"espadas", "espadas sangrientas", "sangrientas"}));
	set_twohanded(0);
	set_enchant(1);
	set_weight(3500);
	add_property("no_slice", 1);
//	add_property("guild", {"warrior", "paladin"});
}

int query_damage_roll()
{
	return ::query_damage_roll() + 6;
}
