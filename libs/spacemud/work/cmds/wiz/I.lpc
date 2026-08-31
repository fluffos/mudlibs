/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
//$$ see: didlog
// USAGE
//       ``I <string>``
//
// This command produces the "did" log when you first log on.
// The use of this command allows you to let other wizards
// know about any changes or additions that you made to the mud.
//
//     ``I started adding help files for some wiz cmds``
//
// When logging in next time you (and other wizards) will see:
//
// Wed Apr 3 17:48:49 2024: Asmerian started adding help files for some wiz cmds
//
// .. TAGS: RST

#include <daemons.h>

inherit CMD;

void create()
{
   ::create();
   no_redirection();
}

private
void main(string str)
{
   if (!str || str == "")
   {
      out("I <whatever you did>\n");
      return;
   }
   if (DID_D->someone_did(str))
      out("Reported.  (Thank you!)\n");
}
