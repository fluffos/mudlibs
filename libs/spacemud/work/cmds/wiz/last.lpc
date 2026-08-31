/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** last.c -- show last login information
**
** 960528, Deathblade: created.
**
** 2020-04-16 Tsath. Fixed call_out's on 0 values. and made it perty.
*/

//: COMMAND
// USAGE: ``last [-s] [-n count] [-d days] [-D days] [user1 user2 ...]``
//
//   |  -s       : be "silent" -- trim headers, displaying just the data
//   |  -n count : only display this many users (the most recent)
//   |  -d days  : display users logged in WITHIN this many days
//   |  -D days  : display users logged in OLDER than this many days
//
//   |  user...  : display login information for these users
//
// Note that the options can be combined, but you'll get an error if you
// use -d and -D to, say, ask for all users logged in during the past 30
// days and those logged in before 60 days ago.
//
// For each user found, their name is displayed, when they
// logged in, if they are still on or when they logged out, and where they
// connected from.
//
// .. TAGS: RST

inherit CMD;
inherit M_WIDGETS;

#define SECS_PER_DAY (24 * 60 * 60)

private
void main(mixed *arg, mapping flags)
{
   int minimum;
   int maximum;
   int count;
   mixed *times;
   int i;

   if (sizeof(arg[0]))
   {
      foreach (string user in arg[0])
      {
         mixed *last;

         user = lower_case(user);

         last = LAST_LOGIN_D->query_last(user);
         if (!last)
            outf("No information for: %s\n", user);
         else
         {
            int is_on = find_user(user) != 0;
            outf(is_on ? "%s logged on at %s from %s\n" : "%s logged out at %s from %s\n", user, ctime(last[0]),
                 last[1]);
         }
      }
      return;
   }

   minimum = 0;
   maximum = time();
   count = to_int(flags["n"]);

   if (flags["d"])
      minimum = time() - (to_int(flags["d"]) * SECS_PER_DAY);
   if (flags["D"])
      maximum = time() - (to_int(flags["D"]) * SECS_PER_DAY);

   if (minimum >= maximum)
   {
      outf("ERROR: invalid range.\n");
      return;
   }

   times = filter(LAST_LOGIN_D->query_times(), ( : $1[0] >= $(minimum) && $1[0] <= $(maximum) :));

   if (!flags["s"])
      outf("%d users. %s to %s.\n%s", sizeof(times), minimum == 0 ? "From the beginning of time" : ctime(minimum),
           ctime(maximum), simple_divider());

   if (!flags["s"] && count && sizeof(times) > count)
      outf("... skipping %d users.\n", sizeof(times) - count);

   i = count && (sizeof(times) - count);
   if (i < 0)
      i = 0;
   for (; i < sizeof(times); ++i)
   {
      int is_on = find_user(times[i][1]) != 0;

      if (times[i][1])
      {
         out(on_off_widget(is_on));
         outf("   %12-s %27-s %25-s\n", capitalize(times[i][1] || "<none>"), ctime(times[i][0]), times[i][2]);
      }
   }
   if (!flags["s"])

      outf(simple_divider());
}
