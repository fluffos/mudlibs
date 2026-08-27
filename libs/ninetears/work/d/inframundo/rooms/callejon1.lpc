//Gareth 3.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("Camino al %^BOLD%^Callejon del %^RED%^%^BOLD%^Estrangulamiento%^RESET%^");
	set_long(query_short()+"\n Te diriges al noroeste por un sendero de unos dos metros de anchura. El suelo del camino esta muy bien pulido, todo liso, cubierto en los lados por paredes de hielo y fuegos azules. Este camino te llevara al Callejon del Estrangulamiento.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"Solo logras escuchar el susurro del viento.\n");
   	add_feel(({"fuego","llamas"}),"Tocas una de las multiples llamas azules y te das cuenta de que, sorprendentemente, no desprenden calor.\n");
   	add_exit("norte",ROOMS+"callejon2","plain");
   	add_exit("sudeste",ROOMS+"torre","plain");
   	add_clone(NPCS+"alma",1);
	set_zone("inframundo");
}
