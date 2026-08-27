
#include "money.h"
#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
}

int cmd (string str, object me)
{
if (!me) me = this_player();

	if(sizeof(me->query_attacker_list())) {
		notify_fail("Este comando es para evitar rooms sin salidas, no para huir como un cobarde!!\n"+
		            "Espera a detener tus peleas para poder ejecutarlo.\n");
	return 0;
}

if (sizeof(me->query_call_outed()))
	
{
	notify_fail("MATA a tus enemigos o MUERE en el intento!!\n"+
        	    "Luego podras usar el transporte a la Plaza.\n");
	return 0;
}

me->move_player("X","/room/entryroom");
return 1;
}
