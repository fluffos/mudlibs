//Gareth 21.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^WHITE%^%^BOLD%^Sendero de %^BLACK%^%^BOLD%^Muerte%^RESET%^");
	set_long(query_short()+"\n Desciendes por un largo sendero que baja desde la Colina de %^BOLD%^%^BLUE%^Fuego%^RESET%^. El camino es de hielo negro. Rios de lava corren veloces a los lados del camino. A lo lejos logras divisar un lago donde desembocan todos los chorros de lava que expulsa el crater.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"La lava produce un sonido burbujeante al descender por la colina.\n");
   	add_exit("este",ROOMS+"colina","plain");
   	add_exit("sudoeste",ROOMS+"lago","plain");
   	add_clone(NPCS+"alma",1);
	set_zone("inframundo");
}