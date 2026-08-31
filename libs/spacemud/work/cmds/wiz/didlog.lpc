/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** didlog.c -- print out a portion of the DID_D log
**
** Aug 1995, Deathblade: created
** Feb 2024, rewritten by Tsath to support versions and both a LIMA log and MUD log.
*/

//: COMMAND
//$$ see: I, lima
// USAGE:
//
//    |  ``didlog``
//    |  ``didlog -a|-all``                   - Show entire didlog.
//    |  ``didlog <number>``                  - Show didlog for last <number> days.
//    |  ``didlog -on|-off``                  - Turn didlog on login on/off.
//    |  ``didlog -vs|-versions``             - Show the versions stored.
//    |  ``didlog -h|-help``                  - This help text.
//    |  ``didlog -newversion [param]``       - Set a new version (admin only).
//    |  ``didlog -v|-ver|-version [param]``  - Select this version>.
//    |  ``didlog -p|-pattern [param]``       - Match pattern.
//
//  Examples:\n"
//    |  ``didlog 100``                       - Find all changes in current version 100 days back.
//    |  ``didlog -v 1.0 -a``                 - Show entire version 1.0 didlog.
//    |  ``didlog -v 1.0 -a -p limb``         - Find all places in version 1.0 with 'limb'.
//    |  ``didlog -v 1.0 200 -p limb``        - Find places in version 1.0 days 200 back with 'limb'.
//
// Shows you the "did" log (ie log of changes recorded by wizards).
// With no arguments it shows the log for the past day.
// With an integer argument it will show the log for that many days back.
// didlog -off turns didlog notification on login off.
// didlog -on turns it back on again.
//
// .. TAGS: RST

#include <daemons.h>

inherit CMD;

private
void print_help()
{
   out("didlog:\n"
       "  didlog -a|-all                   - Show entire didlog.\n"
       "  didlog <number>                  - Show didlog for last <number> days.\n"
       "  didlog -on|-off                  - Turn didlog on login on/off.\n"
       "  didlog -vs|-versions             - Show the versions stored.\n"
       "  didlog -h|-help                  - This help text.\n\n"
       "  didlog -newversion [param]       - Set a new version (admin only).\n"
       "  didlog -v|-ver|-version [param]  - Select this version>.\n"
       "  didlog -p|-pattern [param]       - Match pattern.\n\n"
       "Examples:\n"
       "  didlog 100                       - Find all changes in current version 100 days back.\n"
       "  didlog -v 1.0 -a                 - Show entire version 1.0 didlog.\n"
       "  didlog -v 1.0 -a -p limb         - Find all places in version 1.0 with 'limb'.\n"
       "  didlog -v 1.0 200 -p limb        - Find places in version 1.0 days 200 back with 'limb'.\n\n"
       "Arguments can be given in any order.\n");
}

private
void main(string str)
{
   int ndays = 1;
   string days;
   string header;
   string pattern;
   string version;
   string newversion;
   string *args = explode(str || "", " ");

   for (int location = 0; location < sizeof(args); location++)
   {
      string a = args[location];
      string parameter;
      string next_param = (location + 1) < sizeof(args) ? args[location + 1] : 0;
      if (strlen(a) > 1 && a[0] == '-')
         parameter = a[1..];
      switch (parameter)
      {
         // Dirty returning statements up here.
      case "versions":
      case "vs":
         out("The following versions are known: \n\t" + implode(sort_array(DID_D->versions(), 1), "\n\t") + "\n");
         return;
      case "newversion":
      case "nw":
         newversion = next_param;
         if (mud_name() == "LIMA")
         {
            out("Error: Set version in secure/simul_efun/misc.c for LIMA library.");
            DID_D->set_version(0);
            return;
         }
         DID_D->set_version(newversion);
         out("Version set to '" + newversion + "'.");
         return;
      case "on":
         this_user()->set_didlog_off(0);
         out("You will now receive didlog notifications.\n");
         return;
      case "off":
         this_user()->set_didlog_off(1);
         out("You will no longer receive didlog notifications.\n");
         return;
      case "help":
      case "h":
         print_help();
         return;
         // End of dirt
      case "version":
      case "v":
      case "ver":
         version = next_param;
         if (member_array(version, DID_D->versions()) == -1)
         {
            out("Unknown version '" + version + "'.");
            version = 0;
            return;
         }
         location++;
         break;
      case "all":
      case "a":
         ndays = -1;
         break;
      case "pattern":
      case "p":
         pattern = next_param;
         location++;
         break;
      default:
         if (to_int(a) > 0)
            ndays = to_int(a);
         break;
      }

      parameter = 0;
   }

   if (ndays == 1)
      header = "DID_D report for the past day" + (version ? " for " + version : "");
   if (ndays == -1)
   {
      header = "Complete DID_D report" + (version ? " for " + version : "");
   }
   else
      header = sprintf("DID_D report for the past %d days" + (version ? " for " + version : ""), ndays);

   if (strlen(pattern) > 0)
      header += " matching '" + pattern + "'";

   out(DID_D->get_did_info(time() - ndays * 24 * 60 * 60, ({header, repeat_string("-", sizeof(header)), ""}), pattern,
                           0, version));
}
