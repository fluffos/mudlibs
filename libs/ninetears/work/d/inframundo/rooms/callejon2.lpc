//Gareth 3.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("Puertas del %^BOLD%^Callejon del %^RED%^%^BOLD%^Estrangulamiento%^RESET%^");
	set_long(query_short()+"\n Sigues andando por el camino hasta que llegas a un imponente muro de hielo, que solo puede ser traspasado por una puerta en medio. La puerta es alta y ancha, de unos 2 metros de altura. Es de color azul oscuro, casi no se diferencia de la pared.\n\n");
   	add_item("puerta","Una doble puerta de 2 metros de altura. Esta hecha de madera, con una capa de pintura azul oscura. No tiene cerraduras. y esta medio abierta, sin nadie custodiandola.\n");
   	add_sound(({"habitacion","sala","aire"}),"La puerta produce un fuerte sonido que te retumba en los oidos al moverse a causa del viento.\n");
   	add_exit("este",ROOMS+"callejon3","door");
   	add_exit("sur",ROOMS+"callejon1","plain");
   	add_clone(NPCS+"guardian");
}