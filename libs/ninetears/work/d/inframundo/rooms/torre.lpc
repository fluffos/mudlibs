//Gareth 30.10.02
#include "/d/inframundo/path.h"

inherit "/std/inframundo";

void setup() {
	set_short("%^BOLD%^Torre de %^BLACK%^%^BOLD%^Vilat%^RESET%^");
	set_long(query_short()+"\n Te encuentras ante la entrada de la Torre Negra, donde llegan las almas de los muertos despues de ser juzgados por Vilat, el Senyor del Inframundo, para mas tarde sufrir los castigos que este les impone. La Torre tiene un aspecto siniestro, toda ella construida en hielo negro. Es tan alta que su cuspide se pierde en el cielo, cubierta por una masa de nubes anaranjadas en continuo movimiento.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"Escuchas el grave sonido de los truenos que rodean la Torre.\n");
   	add_feel(({"hielo","torre"}),"Tocas el hielo en que esta construida la Torre, y notas que no esta frio. Mas bien se diria que es piedra, y no hielo.\n");
   	
   	add_exit("dentro",ROOMS+"x","door");
   	modify_exit("dentro",({"function","sur"}));
   	add_exit("sur",ROOMS+"sendero1","plain");
   	add_exit("noreste",ROOMS+"foso1","plain");
   	add_exit("noroeste",ROOMS+"callejon1","plain");
   	
   	add_clone(NPCS+"alma",1);
	set_zone("inframundo");
}

void init() {
	::init(); {
}
}
int sur(string str) {
	tell_object(TP,"Te diriges hacia la puerta, pero lo piensas mejor y decides no volver ahi.\n");
   	tell_room(TO,this_player()->query_cap_name()+" se dirige hacia la puerta, pero da media vuelta y se queda donde estaba.\n",TP);
   	return notify_fail("");
}
