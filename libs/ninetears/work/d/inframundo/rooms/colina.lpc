//Gareth 21.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^WHITE%^%^BOLD%^Colina de %^BOLD%^%^BLUE%^Fuego%^RESET%^");
	set_long(query_short()+"\n El ascenso por el sendero te lleva hasta la cima de una colina, con un crater en su pico, que no para de vomitar rios de lava que descienden hasta la falda de la montanya. El hielo del suelo, sorprendentemente, no se derrite al juntarse con la lava, sino que se conserva intacto.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"El sonido del crater al echar la lava se confunde con unos gritos.\n");
   	add_item(({"fuego","lava"}),"Rios de lava descienden por la colina, hasta que desembocan en un lago de fuego y lava.\n");
   	add_exit("oeste",ROOMS+"sendero5","plain");
   	add_exit("este",ROOMS+"sendero4","plain");
   	add_clone(NPCS+"alma",1);
	set_zone("inframundo");
}