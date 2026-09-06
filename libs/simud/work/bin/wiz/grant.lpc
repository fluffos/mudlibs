#include <file_security.h>
#include <const.h>

// Grants file access between UID's. Wizards may grant access to their
// own UID, arch-wizards to any UID they own.

int main(string param) {
   string dir, uid, type;
   int req_type;

   WIZ_CHECK

   if( getuid() != MASTER_UID ) {
      notify_fail("==> [Error] The grant command does not work unless its UID is root\n");
      return 0;
   }

   // Valid formats are:
   // grant [view/read/create/modify for] <dir> to <uid>
   // Grant type defaults to modify.

   type = "modify";
   if( !param || (sscanf(param, "%s for %s to %s", type, dir, uid) != 3 &&
       sscanf(param, "%s to %s", dir, uid) != 2) ) {
      notify_fail("==> [Format] grant [view/read/create/modify for] dir to uid\n");
      return 0;
   }

   dir = this_player()->make_path_absolute(dir);

   if( file_size(dir) != -2 ) {
      notify_fail("==> [Error] Directory "+dir+" not found.\n");
      return 0;
   }

   dir += "/";

   // Access rules: Archwizards may grant access to directories which they
   // have query_modify access to from their UID list. Normal wizards
   // may only grant access to directories they own.
   if( this_player()->query_level() < ADMLEVEL ) {
      if( this_player()->query_level() >= WIZ2LEVEL ) {
         string *group_uids;

         group_uids = "/secure/file_security"->query_group_uid(getuid(this_player()));
         if( !group_uids ) group_uids = ({ });
         group_uids += ({ getuid(this_player()) });
         if( member(group_uids, "/secure/file_security"->query_dir_owner(dir)) < 0 ) {
            notify_fail("==> [Error] You may not grant access to this directory.\n");
            return 0;
         }
      }
      else {
         if( getuid(this_player()) != "/secure/file_security"->query_dir_owner(dir) ) {
            notify_fail("==> [Error] You may not grant access to this directory.\n");
            return 0;
         }
      }
   }

   if( !(req_type = "/secure/file_security"->to_req_type(type)) ) {
      notify_fail("==> [Error] Not a valid access type\n");
      return 0;
   }

   if("/secure/file_security"->add_dir_group(dir, uid, req_type))
      msg("==> [Grant] UID '"+uid+"' now has "+type+" access to "+dir);
   else {
      notify_fail("==> [Error] Invalid access grant\n");
      return 0;
   }
   return 1;
}