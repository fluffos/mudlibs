
#include "money.h"
int a;
int plaza(string str,object me)
{
	if (!me) me = this_player();
	//if(fixer->query_fighting()) {
	
	if(sizeof(me->query_attacker_list())) {
		notify_fail("%^BOLD%^RED%^Este comando es para evitar rooms sin salidas, no para huir como un cobarde!!\n"+
				"%^RESET%^Espera a detener tus peleas para poder ejecutarlo.\n");
		return 0;
	}

	if (me->query_fighting()) {
		notify_fail("%^BOLD%^RED%^MATA %^RESET a tus enemigos o %^BLACK%^BOLD%^MUERE%^RESET%^ en el intento!!\n"+
				"Luego podras usar el transporte a la Plaza.\n");
		me->set_gp(me->query_max_gp(), me);
		return 0;
	}
	if (!me->query_hidden())
		tell_room(environment(me), me->query_short() + " empieza a elevarse sobre el suelo.. cuando repentinamente una rafaga de viento se lo lleva en direccion a la Plaza.\n", me);
	
	return 1;
}
