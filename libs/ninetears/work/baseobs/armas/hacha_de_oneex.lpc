inherit "/obj/weapon";

void setup() {
	set_base_weapon("hacha de oneex");
	//set_name("%^BOLD%^Hacha de %^RESET%^%^RED%^Oneex%^RESET%^");
	set_name("hacha de oneex");
	// el set name no se usa con colores normalmente, pero aparece si se
	// usan mensajes de hostias con el nombre de la arma
	set_short("%^BOLD%^Hacha de %^RESET%^%^RED%^Oneex%^RESET%^");
	set_long("Esta es la mas poderosa hacha jamas vista "
	         "en los reinos.\n");
	add_alias(({"hacha", "oneex"}));
	set_main_plural("%^BOLD%^Hachas de %^RESET%^%^RED%^Oneex%^RESET%^");
	add_plural("hachas");
	add_adjective("de oneex");
	set_twohanded(0);
	set_enchant(1);
//	add_property("guild", {"warrior", "paladin"});
/* se pasa los messon y off por el forro, usar set_in_use */
	add_property("messon", "Te sientes infinitamente poderoso al empunyar"
				" esta hacha de la muerte.\n");
	add_property("messoff", "Tu sensacion de poder se diluye cuando"
				" envainas esta poderosa arma.\n");
	/* CON ESTA HACHA NO NO NO NO SE PUEDE REBANAR! */
	// aun he de saber pq si sliceo con un inmortal rula...
	add_property("no_slice", 1);
        add_property("no_hunt", 1);
}

/* No rulaaaaaa usar int set_in_use(int x) blabla; return ::set_in_use(x);
int do_hold() {
	write("Mmm, esta arma mola...\n");
	::do_hold();
}
*/

/* BUG, cuando el ke la lleva palma, this_player es el asesino y le sale a
el el msg... */
/* Workaround: ponemos propiedad estatica en la hacha con el nombre
	del ke la empunya. */

// ADAPTAR A NUEVO set_in_use(int i, object duenyo) o usar ETO
int set_in_use(int i, object miamo)
{
	if (i) {
		tell_object(miamo,
		"Te sientes infinitamente poderoso al empunyar esta"
		" hacha de la muerte.\n");
	}
	else
	{
			tell_object(miamo,
			"Tu sensacion de poder se diluye cuando envainas esta"
			" poderosa arma.\n");
	}
	return ::set_in_use(i);
}

/* esto se llama cuando se pone set_heart_beat(tiempo?)
para lo ke keremos, mejor? usar weapon_attack()
void heart_beat() {
	add_attack("tyrael", "fire", 1,20);
	tell_object(this_player(), "Tu %^BOLD%^Hacha de %^RESET%^%^RED%^Oneex %^RESET%^se enfurece!");
}*/

int query_damage_roll()
{
	int res;

	if (TP->query_guild_name() == "asesino" && TP->query_spell_effect("emboscando")) {
		//res = ::query_damage_roll() / 2 - random(10) - 3;
		res = random(20) + 9;
		if (res > 15) res = 15;
		//tell_object(TP, "res = "+ res+ "\n");
		return (res > 0) ? res : 1;
	}
	return ::query_damage_roll();
}
