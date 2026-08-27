//Gareth 30.10.02
inherit "/obj/armour";

void setup() {
	set_base_armour("pendiente");

	set_name("pendiente vital");
	set_short("%^BOLD%^Pendiente %^CYAN%^Vital%^RESET%^");  
	set_long("Un pendiente en forma de esfera de color celeste. Tiene un brillo luminoso por dentro.\n");
	add_alias("pendiente");
	add_alias("vital");
  	set_main_plural("pendientes vitales"); 
  	add_plural("pendientes");
 	set_enchant(10);
  	add_property("no_steal",1);
}

void init() {
	::init();
	add_action("curar","vida");
}

int curar(string str) {
		TP->adjust_hp(999999999); 
		TP->adjust_gp(999999999);
		TP->adjust_ep(999999999);
		return 1;
	}
