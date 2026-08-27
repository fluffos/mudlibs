/* Gareth 14.1.2002
Bosque de Wayreth, quest Khurgar */

inherit "/std/bosque";
#define ROOMS "/w/gareth/comandos/"
#include <tiempo.h>

void setup() {
	set_short("%^GREEN%^Bosque de Wayreth%^RESET%^");
	set_long(query_short()+"\n\n    Te encuentras en un bosque muy denso, "
		"repleto de arboles con aspecto retorcido y de copas altas"
		" y puntiagudas. Los arboles no dejan pasar ni un rayo de"
		" sol, lo que hace que el bosque este sumido en la oscuridad."
		" Los ruidos y movimientos de los arbustos y la maleza te "
		"producen una sensacion de peligro que te hace estar alerta."
		" Hay una pequenya abertura en las copas de los arboles, que"
		" deja pasar algo de luz.\n\n");
   	add_sound(({"bosque","animales","aire"}),"El sonido de los pajaros y "
   		"animales que habitan el bosque en la oscuridad le da un aire"
   		" siniestro que te pone los pelos de punta.\n");
   	add_exit("sudeste",ROOMS+"bosque15","plain");
}

void event_enter(object ob, string message, object *foll) {
	
	if(CICLO_HANDLER->query_noche()==1)
{
	add_exit("dentro",ROOMS+"cripta01","plain");
	renew_exits();
	tell_room(TP,"La luz de la luna entra por la abertura en las copas"
		     " de los arboles y descubre la entrada oculta a lo que"
		     " parece ser una cripta muy antigua. Dos columnas "
		     "franquean la entrada, con runas y gemas incrustadas"
		     " en ellas.\n\n");
	::event_enter();
} 
} 
		