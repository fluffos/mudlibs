//Gareth 1.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^BOLD%^Acantilado de los %^RED%^%^BOLD%^Muertos%^RESET%^");
	set_long(query_short()+"\n Llegas a un gran acantilado, con un gran precipicio que baja hasta un pequenyo mar casi congelado, hay muchas estalactitas afiladas y puntiagudas. A este acantilado llegan las almas de los que se suicidaron en vida.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"Escuchas el chapoteo del agua al caer los cuerpos en ella, y las olas chocando contra el acantilado.\n");
   	add_item(({"acantilado","precipicio"}),"Te asomas al precipicio y te entra mucho vertigo, pero logras controlarte y mirar hacia abajo. Ves un grupo de estalactitas puntiagudas debajo tuya, y las olas chocando contra ellas.\n");
   	add_exit("este",ROOMS+"sendero1","plain");
   	add_clone(NPCS+"suicida",4);
   	add_clone(NPCS+"demonio");
}
