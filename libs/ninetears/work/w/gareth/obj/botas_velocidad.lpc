//Gareth 30.10.02
inherit "/obj/armour";

void setup() {
	set_base_armour("botas");

	set_name("botas de velocidad");
	set_short("%^BOLD%^Botas de Velocidad%^RESET%^");  
	set_long("Unas botas altas de cuero negro. Al ponertelas sientes que tus movimientos son mucho mas veloces y agiles.\n");
	add_alias("botas");
	add_alias("velocidad");
  	set_main_plural("botas de velocidad"); 
  	add_plural("botas");
 	set_enchant(5);
 	add_timed_property("dex",20,9999);
  	add_property("no_steal",1);
}
  	
void init() {
	::init();
	add_action("equipar","poner");
	}

int equipar(string str) {
	if(str == "botas") {
	if (TP->query_cap_name()!="Gareth") return notify_fail("Solo Gareth el Creador puede hacer uso de este equipo.\n");
}
}