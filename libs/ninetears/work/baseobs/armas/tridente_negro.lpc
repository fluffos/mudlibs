inherit "/obj/weapon";

void setup() {
        set_base_weapon("tridente");
        set_name("Tridente %^BOLD%^BLACK%^Negro%^RESET%^");
	add_alias("tridente");
        set_short("Tridente %^BOLD%^BLACK%^Negro%^RESET%^");
        set_long("Es un tridente normalito, un palo y un hierro al final con tres puntas.\n");
        set_main_plural("Tridentes %^BOLD%^BLACK%^Negros%^RESET%^");
	add_plural("tridentes");
        add_property("no_slice", 1);
        //add_property("no_hunt", 1); puesta dinamicamente al ser empunyado por un player
}



int weapon_attack(object defdr, object atckr)
{
::weapon_attack(defdr,atckr);

return ::weapon_attack(defdr,atckr);
}


// mods by Tyrael, para dejar que Rebaneitor cace con el. (dopin time)

int set_in_use(int i, object miamo)
{
	if (i) {
		if (interactive(miamo))
			add_property("no_hunt", 1);
	}
	return ::set_in_use(i);
}

/* NO HACE FALTA PONER ESTO SI VA A SER ASI
int query_damage_roll()
{
return (::query_damage_roll());
} */
