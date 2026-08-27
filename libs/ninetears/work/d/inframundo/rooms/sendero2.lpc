//Gareth 18.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^WHITE%^%^BOLD%^Sendero de %^BLACK%^%^BOLD%^Muerte%^RESET%^");
	set_long(query_short()+"\n Caminas por un largo sendero que atraviesa todo el Inframundo. El camino es de hielo negro, como todo lo demas en este lugar, y a los lados todo esta lleno de llamas azules y estalactitas.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"Solo logras escuchar el susurro del viento.\n");
   	add_feel(({"fuego","llamas"}),"Tocas una de las multiples llamas azules y te das cuenta de que, sorprendentemente, no desprenden calor.\n");
   	add_exit("noreste",ROOMS+"plaza","plain");
   	add_exit("este",ROOMS+"sendero3","plain");
   	add_exit("sudoeste",ROOMS+"sendero4","plain");
   	add_clone(NPCS+"alma",1);
	set_zone("inframundo");
}