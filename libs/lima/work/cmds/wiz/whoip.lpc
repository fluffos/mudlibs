/* Do not remove the headers from this file! see /USAGE for more info. */

//  Yaynu@Lima Bean 950723
//  Prints out a list of IP connections.
//  Arguments: <none> - Reports all players IP names+numbers.
//             <ipname,ipnum> - Reports all who are from that address.
//             <name> - Reports out players ip name and number.

//: COMMAND
// USAGE: whoip
//        whoip <ip address>
//        whoip <ip number>
//        whoip <player name>
//
// This command is very similar to who, however it shows
// the ip name and number from which each player connected,
// and is only available to wizards.
//
// The command also reports historical data of people who logged in from
// a given ip given as an argument, or alternatively a list of IPs that
// the player logged in from.
//
// whoip
//
// Lima Bean:  (Local Time is: Tue Sep 19 07:09:15 1995)
//-------------------------------------------------------------------------
// Name         IP number                 IP name
//-------------------------------------------------------------------------
// Ohara        137.92.12.102             student.canberra.edu.au
// Wegster      204.57.174.131            wegster.telebyte.com
// Valodin      204.254.197.7             exinos.ms.com
// Zifnab       129.188.154.108           maniac1t.mot.com
//-------------------------------------------------------------------------
// Currently there are 4 players.
//
//
//  whoip 129.188.154.108
//
// There is 1 user from maniac1t.mot.com (129.188.154.108):
// Zifnab
//
// The following 3 users have been logged in from 129.188.154.108:
// Zifnab
// Beek
// Tsath

#include <playerflags.h>
#define DIVIDER "-------------------------------------------------------------------------\n"

inherit CMD;

private
void main(string arg)
{
   object user;
   int x;
   object ob;
   string *n, ip, str;
   object *userlist; // User logged on
   string *users;    // Users from a given IP
   string *ips;      // IPs for a given user
   int output = 0;

   if (!arg)
   {
      outf("%s:  (Local Time is: %s)\n%s", mud_name(), ctime(time()), DIVIDER);
      out("Name         IP number                 IP name\n" + DIVIDER);

      foreach (user in users())
      {
         string userid = user->query_userid();

         if (!userid)
            userid = "(login)";
         else
            userid = capitalize(userid);

         outf("%-12s %-25s %-25s\n", userid, query_ip_number(user), query_ip_name(user));
      }
      x = sizeof(users());
      outf("%sCurrently there %s %d player%s.\n", DIVIDER, (x > 1 ? "are" : "is"), x, (x > 1 ? "s" : ""));
      return;
   }

   ips = LAST_LOGIN_D->ips_for_login(arg);
   if (ob = find_user(arg))
   {
      ip = query_ip_number(ob);
      userlist = filter(users(), ( : query_ip_number($1) == $2:), ip);
   }
   else if (sscanf(implode(explode(arg, "."), ""), "%d", x) == 1)
   {
      userlist = filter(users(), ( : query_ip_number($1) == $2:), arg);
      users = LAST_LOGIN_D->logins_from_ip(arg);
   }
   else if (sscanf(implode(explode(arg, "."), ""), "%s", x) == 1)
   {
      userlist = filter(users(), ( : query_ip_name($1) == $2:), arg);
      users = LAST_LOGIN_D->logins_from_ip(arg);
   }
   else
   {
      arg = lower_case(arg);
      userlist = filter(users(), ( : query_ip_number($1) == $2:), arg);
      users = LAST_LOGIN_D->logins_from_ip(arg);
   }

   if ((x = sizeof(userlist)) > 0)
   {
      n = map(userlist->query_userid(), ( : $1 ? capitalize($1) : "(login)" :));
      str = query_ip_name(userlist[0]);
      if (str != query_ip_number(userlist[0]))
         str += " (" + query_ip_number(userlist[0]) + ")";

      outf("There %s %d user%s from %s right now:\n", (x > 1 ? "are" : "is"), x, (x > 1 ? "s" : ""), str);
      outf("%-=78s", implode(n, ", ") + "\n");
      output = 1;
   }

   if ((x = sizeof(users)) > 0)
   {
      outf("\nThe following " + x + " users have been logged in from %s:\n", arg);
      foreach (string u in users)
      {
         outf("%-=78s", capitalize(u) + "\n");
      }
      output = 1;
   }

   if ((x = sizeof(ips)) > 0)
   {
      outf("\nThe following " + x + " IP" + (x == 1 ? "" : "s") + " have been used by %s:\n", arg);
      foreach (string i in ips)
      {
         outf("%-=78s", i + "\n");
      }
      output = 1;
   }

   if (!output)
      out("No login data returned based on '" + arg + "'.\n");
}