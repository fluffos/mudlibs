inherit "/obj/armour"; 

int extr = 0;

void setup()
  {
  set_base_armour("bracers");

  set_name("brazalete de ogro");
  add_alias("brazalete");
  set_short("%^BOLD%^%^BLUE%^Brazalete de %^RESET%^%^BLUE%^Ogro%^RESET%^");

  set_main_plural("%^BOLD%^%^BLUE%^Brazaletes de %^RESET%^%^BLUE%^Ogro%^RESET%^");
  add_plural("brazaletes");
  set_long("Este brazalete ha sido bendecido por una magia arcana para "
	"que su duenyo incremente notoriamente su fuerza.\n");
	//set_enchant(1);
}

void set_owner(object pl)
{
	//add_property("duenyo", pl->QCN);
	// en las omiqs continuas no mola tener que ir a por
	// tu ogro otra vez cada vez que te lo quitan
	// por ahora deja de ser personal
}

int set_in_use(int i, object miamo)
{
	if (!miamo) {
		tell_object(TP, "Avisa a un inmortal sobre el objeto "+query_short()+".\n");
		return ::set_in_use(i);
	}
	if (i) {
	// si ponemos esto en un npc y entramos en su room,
	// SI no estaba cargado y DEBIDO a nuestra entrada se equipa,
	// TP es el player no el npc.
	// por ello habra que usar el parametro extra de set_in_use()
	// que sera el objeto que esta haciendo el equip realmente.

	/* DEJA DE SER PERSONAL
	if (query_property("duenyo") != miamo->QCN) {
		tell_object(miamo, "El "+TO->query_short()+" arde en tu brazo.\n");
		miamo->really_adjust_hp(-random(10) - 2);
		return 0;
	}
	*/

	// no sera lo mismo y mejor aumentar y disminuir solo la extrema?
		if (miamo->query_extreme_str() < 10) {
			miamo->adjust_tmp_extreme_str(1);
			extr = 1;
		}
		else {
			miamo->adjust_tmp_str(1);
			extr = 0;
		}
	}
	else
	{
		if (extr)
			miamo->adjust_tmp_extreme_str(-1);
		else
			miamo->adjust_tmp_str(-1);
	}
	return ::set_in_use(i, miamo);
}
