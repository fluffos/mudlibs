/*   Text upgrade and rewrite by Grimbrand 2-1-96                   */

#include "path.h"
inherit "/std/underground";

object *npcs;

/*
void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dmaster01");
  npcs[i]->move(this_object());
  }
 }
}
*/

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);
set_short("Reinado Duergar:  Oficina del Maestro de Minas");
set_long("\n   Reinado Duergar:  Oficina del Maestro de Minas.\n\n"
         "     Has entrado a la oficina del Maestro de Minas. "
	 "Por toda la habitacion puedes ver equipo para las minas y "	
         "el metal tipico que se puede extraer de las minas de Dendall. "
         "Detras del escritorio del Maestro una seleccion de picos , "
         "martillos y cunyas se puede ver cuidadosamente presentada. "
         "A lo largo de las otras tres paredes, dispuesto en forma  "
         "agradable, reposa diverso material tipico de Dendall.Entre  "
         "ello,algunas de las mas hermosas formaciones cristalinas que "
         "nunca habias visto. El Maestro Minero se sienta tras su mesa "
         "y observa orgulloso como miras atento su preciada coleccion. "
         "Seria una buena idea -escuchar- lo que tenga que decirte."
         "\n");
         
add_item("picos","   Miras los distintos tamanyos de picos de la pared "
	 "tras la mesa del Maestro,y te preguntas por que hay tantos. "
	 "Incluso hay alguno que no estas seguro de poder ni alzar.  "
         "Un detalle que te deja buena impresion es la excelente "
         "condicion en que parecen estar.\n");
         
add_item("martillos", "   Los martillos tras la mesa estan ordenados "
         "de acuerdo a su tamanyo. La variedad de estilos y tipos de"
         "estos es tan variada y rara que incluso te preguntas si "
         "alguno ellos sera un martillo realmente.Todos estan en un "
         "excelente estado.\n");

add_item("cunyas", "   En la pared siguiente a los martillos estan  "
          "las cunyas. Sin estas simples piezas de metal los martillos "
          "serian casi inutiles para propositos mineros. En general "
          "las cunyas son estandar en forma y solo varian en tamanyo. "
          "\n");

add_item(({"metal", "metales", "roca", "rocas"}),
         "   Los diverso metales estan colocados a lo largo de las  "
         "paredes de la habitacion.cada pared dedicada a un tema "
         "especifico,una pared tipos de metal, otra formaciones  "
         "cristalinas, y la otra preciosos tesoros naturales.\n");

add_item("gemas", "    Ves una amplia variedad de gemas de todas las "
          "clases conocidas en los reinos.Estan en una robusta caja"
          "de metal con un grueso cristal. Esta claro que reresentan "
          "la abundancia y maestria de la escuela minera.\n\n"
          "El Maestro te mira divertido.\n");

add_exit("arriba",NEWBIE+"main03","door");
add_exit("oeste",NEWBIE+"dlev1_01","door");
modify_exit("oeste",({"function","bouncer"}));
add_clone(DNPC+"dmaster01",1);
}

/*
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
*/
 
int bouncer() {
int lv,xp;
object me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv == 1 && xp <4000) {
write("   La puerta de abre facilmente cuando la empujas,dejandote "
      "entrar .\n\n");
tell_room(environment(me), me->query_cap_name()+" se dirige hacia la "
	 "puerta y esta se abre suavemente,dejando a "+me->query_cap_name()+
	 " entrar.\n",({this_player()}));
    return 1;
}
notify_fail("   Te diriges a la puerta intentando abrirla.\n\n");
tell_room(environment(me), me->query_cap_name()+" va hacia la puerta oeste "
          "y rebota con danyo quedandosele cara de tonto."
          ":-? .\n\n", ({ this_player() }));
return 0;
}

