/*  -*- LPC -*-  */
// fingerd.c:  Written by Tim in fall 1995
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
//   This handles all finger requests; local and remote.
//
// 01.21.96  Tim McIntosh  Added support for mail checking
// 08.24.96  Tim McIntosh  Changed to use repeat_string(); fixed to get
//                         cap_name on remote finger

#include <mudlib.h>
#include <daemons.h>
#include <login.h>
#include <time.h>

inherit DAEMON;
inherit INHERIT_DIR "/time";

string GetFinger(string username);

void
create()
{
  daemon::create();
}

string
GetFinger(string username)
// pre: call anytime; if username == 0, then finger for all users is returned
// modifies: nothing
// post:  returns a string with the finger information requested
{
  string line = repeat_string("-=",
			      (this_interactive() ?
			       this_interactive()->get_env("WIDTH") / 2 : 40)
			      - 1) + "\n";
  string ret = "", tmp;
  int idle, num_users, mail_size;
  object user, conn, *list;

  // If no username is given, this part produces the string that contains
  // finger info for all presently logged in users

  if(!username) {
    list = users();
    num_users = sizeof(list);

    ret += sprintf("%d users on %s at %s.\n"
		   "upsince %s (%d days), load avg %s\n",
		   num_users,
		   mud_name(),
		   get_date(time(), DATESTR_ALL),
		   get_date(time() - uptime(), DATESTR_DATE),
		   uptime() / 86400,
		   query_load_average());

    ret += line + sprintf("%-10s   %-20s  %6s  %-12s  %-20s\n",
			  "Login", "Name", "Idle", "Login Time", "From Host")
           + line;

    foreach (user in list) {
      conn = (object)user->query_connection();

      idle = query_idle(user);
      ret += sprintf("%-10.10s   %-20.20s  %3.0d:%2.0'0'd  %-12.12s"
		     "  %-22.22s\n",
		     user->query_cap_name(),
		     conn->query_real_name(),
		     idle/60, idle%60,
		     get_date(conn->query_login_time(), DATESTR_SHORT),
		     conn->query_login_from());
    }
    return ret;                                 // return the finger info
  }

  //   If a username is given, this part clones their connection object, and
  // queries it for information pertaining to the player.
  //   If the player is logged on, there are a few differences in the string
  // that finger returns

  conn = new(CONNECTION_OB);

  if( unguarded((: call_other, conn, "restore_connection", username :), 1) ) {
    ret += sprintf("Login: %:-10s                    Name: %:-20s\n"
		   "Shell: %:-25s     Body: %:-25s\n"
		   "Email: %:-65s\n",
		   username,
		   conn->query_real_name(),
		   conn->query_login_shell(),
		   conn->query_body(),
		   conn->query_email_addr());
    //
    // Do this if the player is logged on
    //
    if(user = find_player(username)) {
      ret += sprintf("On since %s", ctime(conn->query_login_time()));
      ret += sprintf(" from %s", conn->query_login_from());
      //
      // user must be interactive to call query_idle()
      //
      if(interactive(user)) {
	idle = query_idle(user);
	ret += ((idle) ? ", idle " + idle/60 + ":" + idle%60 + "\n" : ".\n");
      } else {
	ret += ", link-dead.\n";
      }
    } else {
      idle = conn->query_login_time();
      ret += sprintf("Last login: %s", ctime(idle));
      idle = conn->query_logout_time() - idle;
      ret += sprintf(" (%d:%2.0'0'd)", idle/3600, (idle%3600)/60);
      ret += sprintf(" from %s\n", conn->query_login_from());
    }

    if(mail_size = (int) MAIL_D->check_mail(username, 1))
      ret += sprintf("This user has %d pieces of unread mail.\n", mail_size);
    else
      ret += "No unread mail.\n";

    // Plan & Project
    tmp = unguarded((: read_file, user_path(username)+".project", 1, 1 :), 1 );
    if( tmp )
      ret += "Project: "+ tmp;
    else
      ret += "No Project.\n";

    tmp = unguarded((: read_file, user_path(username)+".plan", 1, 17 :), 1);
    if( tmp )
      ret += "Plan:\n"+ tmp;
    else
      ret += "No Plan.\n";
  }
  else
    ret = sprintf("finger: %s: no such user.\n", username);  // no such user

  destruct(conn);                              // destruct the conn we cloned

  return ret;                                // return the finger info
}

mixed *GetRemoteFinger(string who)
// pre: true
// modifies: nothing
// post: returns a finger packet for Intermud3
{
  string RealName, CapName, HomeDir, Email,
         Project = user_path(who) + ".project";
  int LoginTime;
  mixed *tmp;
  object conn, player;

  conn = new(CONNECTION_OB);

  if( unguarded((: call_other, conn, "restore_connection", who :), 1))
  {
    RealName = conn->query_real_name();
    CapName = conn->query_cap_name();
    HomeDir = conn->query_home_dir();
    LoginTime = conn->query_login_time();
    Email = conn->query_email_addr();

    if(file_exists(Project))
      Project = "Project: " + read_file(Project, 1, 1);
    else
      Project = 0;

    player = find_player(who);

    tmp = ({ CapName, CapName, RealName, Email, ctime(LoginTime),
	     (player ? query_idle(player) : -1), 0, 0, Project});
    return tmp;
  } else {
    return 0;
  }
}
