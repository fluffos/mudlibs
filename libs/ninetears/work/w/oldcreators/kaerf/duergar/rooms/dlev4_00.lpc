/*  Text alterations and additions by Grimbrand 2-3-96                  */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dmaster03");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
   add_property("no_undead",1); set_light(10);
   npcs = allocate(1);

   set_short("Reinado Duergar:  Oficina del Maestro de cavernas");
   
   set_long("\n   Reinado  Duergar:  Oficina del Maestro de cavernas.\n\n"
	    "     Esta oficina esta decorada con muchos y variados "
	    "tipos de trofeos de caza, todos ellos han sido colgados "
	    "poer las paredes con orgullo.  El Maestro de cavernas "
	    "es bien conocido por su valia en la lucha, ahora esta "
	    "retirado de sus dias de aventurero para dedicarse a "
	    "ejercer de profesor y ensenyar a jovenes duergar,como "
	    "tu el arte de sobrevivir en el mundo. Muchos vienen a "
	    "el para \"escuchar\" lo que el dice, ya que en ello "
	    "puede estribar la diferencia entre la vida y la muerte. "
	    "Puedes ver una mesa y una silla, obviamente para uso de "
	    "el Maestro. Al noreste una puerta esperando ser usada.\n"
	    "\n");

   add_item("trofeos",
	    "   Examinando los trofeos ves algunas garras con forma "
	    "de garfio, y unas cuantas cabezas.\n\n");

   add_item(({"garfio", "garra"}),
	    "   Miras el enorme garfio que cuelga de la pared,es como "
	    "un enorme gancho bestial, lo reconoces como lo que fue "
	    "la garra de un Hook Horror.  A juzgar por el tamanyo de "
	    "la garra, el tamanyo del Hook debio ser 5 o 6 veces el de "
	    "un duergar y seria extremadamente poderoso.\n\n");

   add_item(({"cabeza", "cabezas"}),
	    "   Al mirar las cabezas de las paredes reconoces un Humber "
	    "Hulk y un Hell Hound.  Se dice que un Humber Hulk es un "
	    "terrible demonio, que te ataca inesperadamente a traves de "
	    "muros solidos.  El  Hell Hound por otra parte, es un enemigo "
	    "invocado a este mundo desde  los niveles bajos del infierno. "
	    "  Los  Drow han adaptado estas criaturas a vivir en la "
	    "suboscuridad en un intento de hacerles guardar sus hogares"
	    "del submundo de cualquier intruso.\n\n");

   add_item("mesa",
	    "   La mesa del Maestro de cavernas se hace realmente "
	    "dificil de describir.  Esta construida a base de varios "
	    "elementos,tendones garras colmillos... de las criaturas "
	    "que ha ido capturando y matando.\n\n");

   add_item("silla",
	    "   La unica silla del cuarto esta tras la mesa del Maestro "
	    "de cavernas.  Esta hecha de algun tipo de madera desconocida "
	    "para ti.\n\n");

   add_exit("noreste",NEWBIE+"dlev4_01","door");
   add_exit("sudoeste",NEWBIE+"main03","door");
   modify_exit("noreste",({"function","bouncer"}));
}

void dest_me() {
   int i;
   for(i=0;i<sizeof(npcs);i++)
   if(npcs[i]) npcs[i]->dest_me();
   ::dest_me();
}
 
int bouncer() {
   int lv,xp;
   object me = this_player();
   lv = (int)me->query_level();
   xp = (int)me->query_xp();

   if(lv == 3 && xp < 10000) 
     {
      write("   Das un suave empujon y la puerta se abre, dejando "
	    "el espacio justo para que puedas pasar.\n\n");
      tell_room(environment(me), me->query_cap_name()+" da a la puerta "
		"un suave empujon,abriendose esta lo suficiente para que "
		+this_player()->query_objective()+" pueda "
		" cruzarla.\n",({this_player()}));
      return 1;
     }
      notify_fail("   Empujas la puerta con firmeza, pero simplemente "
		  "mo se abre.\n\n");
      
      tell_room(environment(me), me->query_cap_name()+" empuja firmemente "
                "la puerta...  parece que "+this_player()->query_possessive()+
		" aun no es capaz de abrirla.\n\n",
		({this_player()}));
      return 0;
}
