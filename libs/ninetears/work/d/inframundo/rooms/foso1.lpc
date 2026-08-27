//Gareth 12.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("Entrada al %^BOLD%^Foso del Festin%^RESET%^");
	set_long(query_short()+"\n Te encuentras en una gran sala rectangular, con techo muy alto, de unos cinco metros de altura. Toda ella esta llena de hielo negro, con salientes puntiagudos por todas partes. En el centro de la habitacion hay una tapa circular y muy pesada.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"Escuchas unos gritos siniestros que te ponen los pelos de punta.\n");
   	add_feel("tapa","Te agachas y tocas la tapa. Es un gran circulo de hierro liso, con una argolla en el centro. Esta muy fria.\n");
   	add_exit("sudoeste",ROOMS+"torre","plain");
     add_clone(NPCS+"gulimico",random(4));
}

void init() {
	::init();
	add_action("levantar_tapa","levantar");
}
int levantar_tapa(string str) {
   	if(str == "tapa") {
	tell_object(TP,"Te inclinas, agarras la argolla con ambas manos y tiras hacia arriba. Despues de un gran esfuerzo, la tapa cede y logras quitarla.\n");
	tell_room(TO,this_player()->query_cap_name()+" agarra la argolla y levanta la tapa.\n",TP);
	add_exit("abajo",ROOMS+"foso2","door");
	renew_exits();
	return 1;
		return notify_fail("Levantar que?\n");
}
}
