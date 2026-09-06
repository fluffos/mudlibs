#include <file_security.h>

int main(string param) {
   int i;
   string *glist;

   WIZ_CHECK

   if( !param ) param = this_player()->query_name();

   if( getuid(this_object()) != MASTER_UID ) {
      notify_fail("==> [Error] The groups command does not work unless its UID is root.\n");
      return 0;
   }

   glist = "/secure/file_security"->query_group_uid(param);
   if( !glist ) {
      msg("==> [Groups] No additional groups have been set for that UID");
   }
   else {
      glist = ({ param, "all" }) + glist;
      msg("==> [Groups] The UID '"+param+"' may access groups " + comma_list(sort_array(glist, #'>)) + ".");
   }

   return 1;
}
