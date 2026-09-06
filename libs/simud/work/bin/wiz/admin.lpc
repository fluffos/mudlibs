#include <const.h>

int main(string str) {
   object who;

   if (this_player()->query_level() != ADMLEVEL)
      return 0;
   else if( !str ) {
      notify_fail("What do you want to shout?\n");
      return 0;
   }

   str = "~CDRK[~CWRNAdmin~CDRK] ~CTIT"+this_player()->query_cap_name()+"~CDRK: ~CDEF"+str+"~CDEF";

   foreach (who : users())
      if (who->query_level() == ADMLEVEL)
         msg_object(who,str,10+sizeof(this_player()->query_name()));

   return 1;
}
