#include <login.h>
#include <clubs.h>

inherit COMMAND_BASE;

int cmd(string str) {
   string ret;

   add_failed_mess("Refer is disabled for the moment.\nHave a nice day.\n");
   return 0;

/*   
   if (str) {
      str = lower_case(str);
      str = (string)this_player()->expand_nickname(str);
   } else {
      return 0;
   }

   if (!LOGIN_OB->test_user(str)) {
      return 0;
   }
 */
   ret = (string)FINGER_H->refer_info(str);
   if (ret) {
      this_player()->more_string( this_player()->fit_message(ret),
                                  "refer: "+str );
      return 1;
   }
   add_failed_mess("No one by the name of " + str + " has "
                   "ever visited Divided Sky.\n");
   return 0;
} /* cmd() */

mixed *query_patterns() {
   return ({"<string'name'>", (: cmd($4[0]) :) });
} /* query_patterns() */
