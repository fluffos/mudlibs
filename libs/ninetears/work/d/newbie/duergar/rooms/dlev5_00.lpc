/*  Text alterations and additions by Grimbrand 2-4-96                  */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dmaster04");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
   add_property("no_undead",1); set_light(10);
   npcs = allocate(1);
   
   set_short("Reinado Duergar:  Oficina del Maestro de ciencias");

   set_long("\n   Reinado Duergar:  Oficina del Maestro de Ciencias.\n\n"
	    "     Entras a la oficina del Maestro en Ciencias y comprendes "
	    "que el esta aqui para explicar a los jovenes estudiantes como "
	    "identificar a las diferentes razas que habitan los reinos.  "
	    "Con una decoracion espartana, el cuarto esta amueblado con "
	    "tan solo una mesa y una silla para uso del maestro.  Deberias "
	    "escuchar con atencion sus consejos."
	    "\n\n");

   add_item("mesa",
	    "   Es una mesa hecha de una madera oscura. Sobre ella hay "
	    "unos pocos papeles esparcidos de forma desordenada. Intentas "  
	    "leerlos un poco de reojo, tal vez tenga notas sobre tus "
	    "avances, tal vez resulta que eres una gran promesa y el "
	    "maestro te escoje para una gran mision tal vez..."
	    " mejor te despiertas y atiendes al maestro."
	    "\n\n");

   add_item("sila",
	    "   La silla que hay tras la mesa aparenta ser realmente "
	    "confortable."
	    "\n\n");

   add_item(({"papeles","papel"}),
	    "   Mirando los papeles esparcidos sobre la mesa, te fijas "
	    "en lo que parece una lista de nombres.  Algun nombre esta "
	    "subrayado con una tinta de color rojo oscuro. Acercandote "
	    "un poco comienzas a leer el primer nombre que figura "
	    "en la lista\n\n"
	    "Girthwer coje rapido el papel de la mesa y lo dobla y "
	    "guarda en su bolsillo.\n\n"
	    "Girthwer dice: porque no te preocupas de tus asuntos!"
	    "\n\n");

   add_exit("norte",NEWBIE+"dlev5_01","door");
   add_exit("sur",NEWBIE+"main03","door");
   modify_exit("norte",({"function","bouncer"}));
}

void dest_me() {
int i;
/* if we kill off the room, kill off the contents as well */
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
 
int bouncer() {
int lv,xp;
object me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv == 4 && xp < 20500) {
write("   La pesada puerta se abre silenciosamente, dejante libre el paso al "
	 "siguiente cuarto.\n\n");
tell_room(environment(me), me->query_cap_name()+" camina hacia la "
	 "puerta, que se abre dejandole "+me->query_objective()+
	 " el paso libre.\n\n",
	 ({this_player()}));
return 1;
}
notify_fail("   Intentas pasar al area de entrenamiento, pero la puerta " 
	    "no se abre.\n\n");
tell_room(environment(me), me->query_cap_name()+
	 " no consigue pasar al area de entrenamiento.\n\n",
	 ({this_player()}));
return 0;
}
