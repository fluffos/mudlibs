//Gareth 12.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^BOLD%^Foso del Festin%^RESET%^");
	set_long(query_short()+"\n Desciendes por las escaleras y llegas al foso. Un gran comedor, con una mesa tan larga que casi no ves el final, con sillas altas de madera negra tapizadas en rojo sangre, y platos y cubiertos relucientes. La mesa esta llena tambien de ollas que desprenden un aroma a comida que te abre el apetito. A lo largo del techo cuelgan varias lamparas que iluminan todo el gran comedor.\n\n");
   	add_item("mesa","Una gran mesa que ocupa toda la sala, muy larga, con sillas a los lados y cubierta por un mantel negro ribeteado en oro.\n");
   	add_item("lamparas","Unas grandes lamparas de cristal cuelgan del techo, iluminando toda la sala.\n"),
   	add_smell(({"habitacion","sala","aire","comida","ollas"}),"Hay un aroma a comida que te abre el apetito.\n");

          add_clone(NPCS+"gulimico",random(4));
   	add_exit("arriba",ROOMS+"foso1","door");
}
