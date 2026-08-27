//Gareth 21.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^WHITE%^%^BOLD%^Lago de %^BOLD%^%^BLUE%^Fuego%^RESET%^");
	set_long(query_short()+"\n Sigues el curso de la lava, y llegas hasta su desembocadura, en un lago de lava. El lago no parece ser muy profundo, pero produce un calor abrasador. La lava burbujea y provoca pequenyas llamaradas.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"La lava produce un sonido burbujeante.\n");
   	add_item(({"lago","lava"}),"Un pequenyo lago de lava.\n");
   	add_exit("noreste",ROOMS+"sendero5","plain");
   	add_clone(NPCS+"basilisco");
}