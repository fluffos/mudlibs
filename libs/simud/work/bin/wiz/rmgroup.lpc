#include <file_security.h>

int main(string param) {
   int i;
   string *glist, uid, grp;

   WIZ_CHECK

   if( !param || sscanf(param, "%s %s", uid, grp) != 2 ) {
      notify_fail("==> [Format] rmgroup uid group\n");
      return 0;
   }

   if( getuid(this_object()) != MASTER_UID ) {
      notify_fail("==> [Error] The rmgroup command does not work unless its UID is root.\n");
      return 0;
   }

   if( getuid(this_player()) != grp && this_player()->query_level() < ADMLEVEL ) {
      notify_fail("==> [Error] You are not allowed to control access for '"+grp+"'.\n");
      return 0;
   }

   msg("==> [Notice] Removing group '"+grp+"' from the access list for UID '"+uid+"'");
   "/secure/file_security"->remove_group_uid( uid, grp );

   glist = "/secure/file_security"->query_group_uid( uid );
   if( !glist ) {
      msg("==> [Rmgroup] That UID now has no additional groups.");
   }
   else {
      glist = ({ uid, "all" }) + glist;
      msg("==> [Rmgroup] The UID '"+uid+"' may still access groups " + comma_list(glist) + ".");
   }

   return 1;
}