#include <mudlib.h>

void report( object attacker, object victim )
{
   string message, c_message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   c_message= "/adm/daemons/statsd"->c_status_string(victim);
   tell_object( victim,
     sprintf("( 你 %s )\n",c_message) );
}
