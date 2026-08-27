// Vilat 29.10.2002
// Ultimo paso para creadores novatos: fabricar una armadura.
// Sin embargo el termino "armadura" engloba cualquier cosa vestible, como ya vereis.

// Las armaduras heredan /obj/armour.c
inherit "/obj/armour";

// En realidad no es muy diferente de un arma
void setup() {
	// set_base_armour() para elegir el tipo de armadura, que podeis encontrar una lista de tipos en /table/armour_table.c
   	set_base_armour("cinta");
   	set_name("cinta");
   	set_short("%^BOLD%^RED%^Cinta %^WHITE%^Kamikaze%^RESET%^");
   	add_alias("kamikaze");
   	add_plural("cintas");
   	add_plural("kamikazes");
   	set_main_plural("%^BOLD%^RED%^Cintas %^WHITE%^Kamikaze%^RESET%^");
   	set_long(query_short()+"\nEsta es la legendaria Cinta Kamikaze, el distintivo del Clan <insert nombre chulo here>, por medio de la cual sus miembros se reconocen entre si.\n");
	}

// Pues no, no tiene mucha complicacion... De momento xD
