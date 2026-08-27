/*  Text alterations and additions by Grimbrand 2-2-96                   */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dogre");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
  add_property("no_undead",1); set_light(85);
  npcs = allocate(1);
set_short("Reinado Duergar:  Simulacion de Superficie");

set_long("\n   Reinado Duergar:  Simulacion de Superficie.\n\n"
	 "     Al entrar al cuarto,una intensa luminosidad lo inunda "
	 "todo,hiriendote con dolor en los ojos. Te quedas casi "
	 "ciego y no puedes ver apenas a tu alrededor.\n\n"
	 "     Al acostumbrarte poco a poco, notas que esto no se "
	 "parece en nada a tus queridas cavernas,donde te criaste, "
	 "aqui hay tanta luz... y que son todos esos  colores?!?!  "
	 "Cuanto mas miras alrededor, mas te convences de que debes "
	 "de encontrarte en el mundo de superficie, con todos sus "
	 "arboles, el cielo abierto, y la luz de fuego brillando en "
	 "alguna parte del cielo. Segun te mueves hacia otra zona "
	 "te das de bruces contra un muro! es solo entonces cuando "
	 "puedes ver el debil contorno del cuarto.  Esta ilusion "
	 "ha de ser obra de un gran clerigo Duergar sin duda.\n"
	 "\n");

add_item("sol",
	 "   Intentas mirar hacia arriba, donde solo deberia haber "
	 "el techo de la caverna, pero lo unico que ves es un vasto "
	 "e infinito cielo azul.\n\n");

add_item("cielo",
	 "   Intentas mirar hacia arriba, donde solo deberia haber "
	 "el techo de la caverna, pero lo unico que ves es un vasto "
	 "e infinito cielo azul.\n\n");
	 
add_item("colores",
	 "   Miras a tu alrededor, todo el area esta cubierta con "
	 "grandes plantas de multitud de colores.  Obviamente el "
	 "motivo es tratar de confundirte con esos colores y asi "
	 "favorecer a las criaturas escondidas en alguna parte.\n\n");


add_exit("norte", NEWBIE+"dlev3_04", "path");
add_exit("sur", NEWBIE+"dlev3_15", "path");
add_exit("oeste", NEWBIE+"dlev3_11", "path");
add_exit("noreste",NEWBIE+"dlev3_01","path");
}
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
 

