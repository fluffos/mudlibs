// default function for spells. Create by Kyoko.
//#include "echobomber.h"
#include <mudlib.h>

void report( object attacker, object victim )
{
   string message, c_message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   c_message= "/adm/daemons/statsd"->c_status_string(victim);
  // tell_object( attacker, !can_read_chinese(attacker) ?
  //   "( " + victim->query("name") + message+" )\n" 
  //   :
  //   "( " + victim->query("c_name") + c_message+" )\n"  
  //     );
   tell_object( victim,!can_read_chinese(victim) ? 
     "( you "+message+" )\n" : "( 你 "+c_message+" )\n"
     
     );
}
