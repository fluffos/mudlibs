//Gareth 21.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("Entrada a la %^WHITE%^%^BOLD%^Caverna del %^RESET%^%^ORANGE%^Yeti%^RESET%^");
	set_long(query_short()+"\n Te encuentras ante la entrada de una gran caverna, excavada en una colina de hielo muy alta. Hay un agujero redondo, de unos tres metros de alto, que parece ser la entrada a la cueva, pero esta tapado por un bloque de piedra gigante.\n\n");
	add_item("piedra","Un gran bloque de piedra gris, de unos tres metros de alto y dos de ancho, que obstruye la entrada a la caverna. A lo mejor podrias moverlo.\n");
   	add_sound(({"habitacion","sala","aire"}),"Procedentes de la caverna se oyen unos berridos.\n");
   	add_exit("oeste",ROOMS+"sendero3","plain");
        set_zone("inframundo");
}

void init() {
	::init();
	add_action("mover_piedra","mover"); }
int mover_piedra(string str) {
   	if(str == "piedra") {
	tell_object(TP,"Te plantas en un lado del bloque de piedra, te preparas y empiezas a empujar con todas tus fuerzas. Se te hinchan las venas de cuello y brazos, y despues de un gran esfuerzo consigues moverla y dejar la entrada libre.\n");
	tell_room(TO,this_player()->query_cap_name()+" empieza a empujar el bloque de piedra y despues de un rato, consigue moverla.\n",TP);
	add_exit("dentro",ROOMS+"caverna2","door");
	renew_exits();
	return 1;
		return notify_fail("Mover que?\n");
}
}
