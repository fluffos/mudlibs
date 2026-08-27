#include "money.h"
#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
}
int cmd (string str, object me)
{
if (!str)
{
		notify_fail("\nSintaxis: nuevo <texto>\n\n");
		return 0;
}
write_file("/doc/helpdir/nuevo","%^BOLD%^RED%^"+me->query_cap_name()+" "+ ctime(time())+" - %^RESET%^"+str+".\n");

write("\nEl texto introducido en %^BOLD%^help nuevo queda introducido como sigue:\n%^BOLD%^RED%^"+
	me->query_cap_name()+" "+ ctime(time())+" - %^RESET%^"+str+".\n");
return 1;
}
