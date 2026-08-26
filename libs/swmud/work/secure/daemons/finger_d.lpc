// Last edited by deforce on 03-09-2010
// Rust 08-15-1994

#include <security.h>
#include <ports.h>

inherit M_ACCESS;
inherit M_GRAMMAR;
inherit CLASS_FINGER;

void create()
{
   set_privilege(1);
}

private nomask string format_idle_time(object user_object)
{
   int time = query_idle(user_object);

   string output = "";

   if (time > 59)
   {
      if (time > 3599)
      {
         if (time > 86399)
         {
            output += (time / 86400) + "d, ";

            time = time % 86400;
         }

         output += (time / 3600) + "h, ";

         time = time % 3600;
      }

      output += (time / 60) + "m";
   }

   return output;
}

class finger get_finger_data(string userid)
{
   class finger result;
   object user;
   string * info;
   mixed last;
   object mbox;

   info = unguarded(1, (: call_other, USER_D, "query_variable", userid,
      ({ "real_name", "email", "url", "wiz_position", "title", "gender", "race_name", "spouse", "team_alignment", "describe", "primary_guild", "primary_level" }) :));

   if (!info) { return 0; }

   result = new(class finger, real_name: info[0], email: info[1],
      home_page: info[2], position: info[3], title: info[4], sex: info[5], race: info[6],
      spouse: info[7], team: info[8], describe: info[9], primary_guild: info[10], primary_level: info[11]);

   if (result->real_name == "") { result->real_name = 0; }
   if (result->email == "") { result->email = 0; }
   if (result->home_page == "") { result->home_page = 0; }

   if (result->team > 25) { result->team = 1; }
   else if (result->team < -25) { result->team = -1; }
   else { result->team = 0; }

   if (result->position == "") { result->position = 0; }

   if (!this_user() || (userid != this_user()->query_userid()) && (wizardp(this_user()->query_userid()) < 3))
   {
      if (result->email && result->email[0] == '#') { result->email = 0; }
      if (result->real_name && result->real_name[0] == '#') { result->real_name = 0; }
      if (result->home_page && result->home_page[0] == '#') { result->home_page = 0; }
   }

   mbox = MAILBOX_D->get_mailbox(userid);
   result->mail_count = mbox->query_message_count();
   result->mail_unread = mbox->query_unread_count();

   last = LAST_LOGIN_D->query_last(userid);

   user = find_user(userid, 1); // Find even linkdead users

   if (!user) { result->idle = -1; }
   else if (!interactive(user)) { result->idle = -2; }
   else { result->idle = query_idle(user); }

   if (wizardp(this_user())) { result->connect_from = last ? last[1] : 0; }

   result->last_login = last ? last[0] : 0;

   if (is_file(WIZ_DIR + "/" + userid + "/.project"))
   {
      result->project = read_file(WIZ_DIR + "/" + userid + "/.project");
   }

   if (is_file(WIZ_DIR + "/" + userid + "/.plan"))
   {
      result->plan = read_file(WIZ_DIR + "/" + userid + "/.plan");
   }

   return result;
}

string show_big_finger()
{
   object * u = users();

   return implode(u, (: $1 + sprintf("%-15s%-12s%-16s%s\n",
      find_body( $2->query_userid()) ? capitalize( $2->query_userid()):"Login",
      "level", format_idle_time($2), query_ip_name($2)) :),
      sprintf("\n%s: %d user%s presently connected (%s)\n%s\n", mud_name(),
      sizeof(u), sizeof(u) == 1 ? "" : "s", ctime(time()), repeat_string("-", 75)));
}

string show_big_html_finger()
{
   object * u = users();
   string retval;

   retval = sprintf("<META HTTP-EQUIV=\"Refresh\" CONTENT=30>"
"<center><TABLE BORDER=5><caption><font size=+2>%s</font></caption>"
"<TR><TH>Name</TH><TH>Position</TH><TH>Idle</TH></TR>", mud_name());

   foreach (object user in u)
   {
      retval += sprintf("<TR><TD>%s</TD><TD>%s</TD><TD>%s</TD></TR>",
         find_body( user->query_userid()) ? sprintf("<font size=+2><a href=/cgi/who.c?=%s>%s</a></font>",
         user->query_userid(), capitalize( user->query_userid())) :"Login",
         "level", format_idle_time(user));
   }

   return retval + "</TABLE></center>";
}

void clean_up()
{
   destruct(this_object());
}