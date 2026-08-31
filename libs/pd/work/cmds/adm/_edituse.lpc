#include <daemons.h>
#include <security.h>

inherit DAEMON;

string *emd_edituse()
{
 seteuid(UID_USERACCESS);
write("uid is "+geteuid());
 return find_player("vicissitude")->query_history();
}
