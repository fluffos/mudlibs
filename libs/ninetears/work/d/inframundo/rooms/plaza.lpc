//Gareth 18.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^WHITE%^%^BOLD%^Plaza de %^BLACK%^%^BOLD%^Ejecuciones%^RESET%^");
	set_long(query_short()+"\n Tus pasos te llevan hasta una plaza redonda, con una gran horca situada en el centro que te llama mucho la atencion. Lo mas curioso es que toda la sala, incluida la horca, estan hechas de hielo, excepto unos bancos de piedra negra que la rodean.\n\n");
   	add_feel("bancos","Tocas uno de los multiples bancos que hay en la plaza, y notas que la piedra esta muy fria, pero bien pulida.\n");
   	add_item("verduras","Todo el suelo alrededor de la horca esta plagado de verduras y otros alimentos podridos y espachurrados.\n");
   	add_item("horca","Una gran horca, tallada en el mismo hielo con una habilidad sobrenatural.\n");
   	add_exit("noroeste",ROOMS+"sendero1","plain");
   	add_exit("sudoeste",ROOMS+"sendero2","plain");
          add_clone(NPCS+"ahorcado");
          add_clone(NPCS+"muchedumbre");
}
