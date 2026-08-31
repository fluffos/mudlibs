#include <std.h>
#include <rest.h>

inherit DAEMON;

int cmd_stand() {
object tp;
       tp=this_player();
       if(tp->query_rest_type() == 0)
         return notify_fail("You are already standing.\n");

       if(tp->query_rest_type()== REST ) {
               write("You stop your little nap and stand up.");
               tp->set_rest_type(0);
               say((string)tp->query_cap_name()+" stops resting and stands up.");
               return 1;
       }
       if(tp->query_rest_type() == SIT) {
               write("You stand up.");
               say((string)tp->query_cap_name()+" stands up.");
               tp->set_rest_type(0);
               return 1;
       }
       write("You get up off the ground.");
       say((string)tp->query_cap_name()+" gets up off the ground.");
       tp->set_rest_type(0);
       return 1;
}
int help()
{
  write( @EndText
Syntax: stand
Effect: allows you to stand from sitting or resting.
See also: sit, rest
EndText
  );
  return 1;
}