// Leto hack :)

#include <mudlib.h>
#include <commands.h>

inherit DAEMON ;

int cmd_redoc() {

rm("/data/adm/daemons/doc_d/Root.o");
CMD_UPDATE->cmd_update("/adm/daemons/doc_d");
return 1;
}

string help() {

return  ("The redoc command forces the doc_d to rebuild the doc database.\n");
}
