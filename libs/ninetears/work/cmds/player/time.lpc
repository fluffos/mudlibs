#include <cmd.h>
#include <tiempo.h>
inherit CMD_BASE;

int cmd(string str, object me){
   	tell_object(me,CICLO_HANDLER->query_fecha()+"\n");
   	tell_object(me,"Son las "+CICLO_HANDLER->query_hora()+".\n");
	if (!environment(me)->query_outside()) return 1;
   	if (CICLO_HANDLER->query_noche()) tell_object(me,CICLO_HANDLER->query_hora_name()+" y ves "+CICLO_HANDLER->query_luna_name()+" en el cielo.\n");
   	else tell_object(me,CICLO_HANDLER->query_hora_name()+".\n");
	tell_object(me,CLIMA->query_clima_name(environment(me)->query_ajuste_humedad(),environment(me)->query_ajuste_temperatura(),environment(me)->query_ajuste_humedad(),environment(me)->query_no_llover())+"\n");
   return 1;
}
