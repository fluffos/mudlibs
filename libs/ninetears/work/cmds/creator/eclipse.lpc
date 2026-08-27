#include <standard.h>
#include <cmd.h>
#include <tiempo.h>
inherit CMD_BASE;

void setup() { position = 1; }

int cmd(string arg, object me) {
  	int tim;
  	//string str;

  	if( !arg || arg == "" ) return notify_fail("Se requiere argumento.\n");
  	if (CICLO_HANDLER->query_noche()) return notify_fail("Es de noche y un eclipse no tendria sentido.\n");

  	sscanf(arg, "%d %s", tim, arg);
  	CICLO_HANDLER->init_eclipse(tim*5);
  
  	return 1;
	}
