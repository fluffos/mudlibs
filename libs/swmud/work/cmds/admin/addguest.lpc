// Add Guest Command for Admins
// Vette 04-04-1997

//:COMMAND
// This command adds a guest to the guestlist for when the mud
// does not allow new players
// Syntax: addguest <name>

#include <mudlib.h>
#include <log.h>

inherit CMD;

#define USAGE "Usage: addguest <name>\n"

private void main(string arg)
{
   if (!arg)
   {
      out(USAGE);

      return;
   }

   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 3))
   {
      out("You need to be a Wizard Master or Teacher in order to add guests.\n");

      return;
   }

   GUEST_D->add_guest(arg);
   write(capitalize(arg) + " has been added as a guest.\n");
}