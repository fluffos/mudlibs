/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** last_login_d.c -- last login tracking daemon
**
** Manages tracking of the login times.  This is managed specially rather
** than with each user object so that we can review the information as a
** list without restoring a zillion objects.
**
//### no security has been implemented.  Is any needed?
**
** 950930, Ranma@Koko Wa: log players entering and quitting the game
** 950608, Deathblade:  created
** 2023, Tsath: Extended to carry more information about previous IPs.
*/

#include <log.h>
#include <security.h>

inherit M_DAEMON_DATA;

private
mapping lastdata = ([]);
private
mapping logins_from_ip = ([]);
private
mapping ips_for_login = ([]);

nomask void register_last(string userid, string addr)
{
   string s;

   if (!addr && lastdata[userid])
   {
      s = sprintf("%s leaves the game [%s]\n", userid, ctime(time()));
      LOG_D->log(LOG_QUIT, s);
      lastdata[userid][0] = time();
   }
   else
   {
      s = sprintf("%s enters the mud from %s [%s]\n", userid, addr, ctime(time()));
      LOG_D->log(LOG_LOGIN, s);
      if (!ips_for_login[userid])
         ips_for_login[userid] = ({});
      if (!logins_from_ip[addr])
         logins_from_ip[addr] = ({});

      if (member_array(addr, ips_for_login[userid]) == -1)
         ips_for_login[userid] += ({addr});
      if (member_array(userid, logins_from_ip[addr]) == -1)
         logins_from_ip[addr] += ({userid});

      if (!lastdata[userid])
      {
         s = sprintf("%s created from %s [%s]\n", userid, addr, ctime(time()));
         LOG_D->log(LOG_NEW_PLAYERS, s);
      }
      ips_for_login[userid] -= ({0});
      lastdata[userid] = ({time(), addr});
   }
   save_me();
}

string *logins_from_ip(string addr)
{
   return logins_from_ip[addr] ? logins_from_ip[addr] : ({});
}

string ips_for_login(string userid)
{
   return ips_for_login[userid] ? ips_for_login[userid] : ({});
}

nomask mixed *query_last(string userid)
{
   return lastdata[userid];
}

nomask mixed *query_times(int skip_sort)
{
   mixed *times = allocate(sizeof(lastdata));
   int i = 0;

   foreach (string userid, mixed * info in lastdata)
   {
      times[i++] = ({info[0], userid, info[1]});
   }

   if (skip_sort)
      return times;

   return sort_array(times, 1);
}

nomask void remove_user(string userid, int skip_save)
{
   if (!check_previous_privilege(1))
      error("security: illegal attempt to remove user.\n");
   userid = lower_case(userid);
   map_delete(lastdata, userid);

   if (!skip_save)
      save_me();
}
