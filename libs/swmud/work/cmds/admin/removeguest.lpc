// Remove Guest Command for Admins
// Vette April 4, 1997
//

//:COMMAND
// This command removes a guest from to the guestlist for when the mud
// does not allow new players
// Syntax: removeguest [name]
#include <mudlib.h>
#include <log.h>

inherit CMD;

#define SYNTAX  "Usage: removeguest <name>\n"

void create()
{
   ::create();
   no_redirection();
}

private void main(string arg)
{
   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 3))
   {
      out("You need to be a Wizard Master or Teacher in order to remove guests.\n");

      return;
   }

   if (!sizeof(arg))
   {
      write(SYNTAX);

      return;
   }

   GUEST_D->remove_guest(arg);
   write("Guest " + arg + " has been removed.\n");
}