/*  Text alterations and additions by Grimbrand 2-11-96                 */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dhalfling");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);
   
  set_short("Reinado Duergar:  Entrenamientos con razas");

   set_long("\n   Reinado Duergar:  Entrenamientos con razas.\n\n"
	    "     Este cuarto esta totalmente desnudo y sencillo.  Solo "
	    "ves unas manchas en el suelo y marcas estriadas en las paredes "
	    ", ves tambien un gran charco de sangre en el suelo."
	    "\n\n");

   add_item(({"suelo", "mancha", "manchas"}),
	    "   Examinando el suelo ves que la piedra esta manchada por la "
	    "sangre de muchas batallas pasadas, y las que pasaran, imaginas."
	    "  Ves tambien un charco de sangre que se coagula poco a poco "
            "en el frio suelo."
	    "\n\n");

   add_item(({"sangre", "charco", "charco de sangre"}),
	    "   Es un charco de sangre aun fresca, parece que la batalla se "
	    "produjo hace poco, se esta empezando a coagular lentamente "
	    "en el frio y humedo suelo."
	    "\n\n");

   add_item(({"muro", "pared", "paredes"}),
	    "   Las paredes tienen varias marcas, dejadas por distintas "
	    "armas, en las luchas que suelen tener lugar en esta zona."
	    "\n\n"); 

   add_exit("norte",NEWBIE+"dlev5_07","path");
}
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
 

