//Gareth 21.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^WHITE%^%^BOLD%^Sendero de %^BLACK%^%^BOLD%^Muerte%^RESET%^");
	set_long(query_short()+"\n Caminas por un largo sendero que atraviesa todo el Inframundo. El camino es de hielo negro, como todo lo demas en este lugar, y a los lados todo esta lleno de llamas azules y estalactitas. En esta parte del camino, el sendero comienza a ascender hacia la cima de una montanya.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"Solo logras escuchar el susurro del viento.\n");
   	add_feel(({"fuego","llamas"}),"Tocas una de las multiples llamas azules y te das cuenta de que, sorprendentemente, no desprenden calor.\n");
   	add_exit("noreste",ROOMS+"sendero2","plain");
   	add_exit("oeste",ROOMS+"colina","plain");
   	add_clone(NPCS+"alma",1);
	set_zone("inframundo");
}