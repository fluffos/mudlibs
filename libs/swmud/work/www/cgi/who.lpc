// Last edited by deforce on 03-09-2010
#include <daemons.h>
#include <ports.h>

inherit M_GRAMMAR;
inherit CLASS_FINGER;

private nomask string get_idle(int i)
{
   if (i > 3600)
   {
      return " (idle " + (i/3600) + "h)";
   }

   if (i > 60)
   {
      return " (idle " + (i/60) + "m)";
   }

   return "";
}

string main(string userid)
{
   class finger info;
   string s;
   string mailstring;
   string idle;
   string first_line;

   userid = lower_case(trim_spaces(userid));

   if (userid == "")
   {
      return FINGER_D->show_big_html_finger();
   }

   info = FINGER_D->get_finger_data(userid);

   if (!info)
   {
      return sprintf("<h2><em>%s</em>: No such player.\n</h2>", userid);
   }

   if (!info->real_name)
   {
      info->real_name = "(private or none given)";
   }

   if (!info->email)
   {
      info->email = "(private or none given)";
   }
   else
   {
      info->email = sprintf("<a href=\"mailto:%s\">%s</a>", info->email, info->email);
   }

#ifdef USE_WIZ_POSITION
   if (!info->position)
   {
      info->position = "(none)";
   }

   info->position = " Position: " + info->position;
#else
   info->position = "";
#endif

   if (!info->home_page && is_directory(sprintf(WIZ_DIR "/%s/WWW", userid)))
   {
      info->home_page = sprintf("http://%s:%d/~%s", __HOST__, PORT_HTTP, userid);
   }

   if (info->home_page)
   {
      info->home_page = sprintf("Homepage: <a href=\"%s\">%s</a>\n", info->home_page, info->home_page);
   }
   else
   {
      info->home_page = "";
   }

   if (info->connect_from)
   {
      info->connect_from = " from " + info->connect_from;
   }
   else
   {
      info->connect_from = "";
   }

   if (info->idle == -1)
   {
      idle = "";
   }
   else if (info->idle == -2)
   {
      idle = " (linkdead)";
   }
   else
   {
      idle = get_idle(info->idle);
   }

   if (info->mail_count == 0)
   {
      mailstring = capitalize(userid) + " has no mail.";
   }
   else
   {
      mailstring = sprintf("%s has %s.", capitalize(userid), number_of(info->mail_count, "message"));

      if (info->mail_unread)
      {
         mailstring[<1..] = sprintf(", %d of which %s unread.", info->mail_unread, info->mail_unread > 1 ? "are" : "is");
      }
   }

   first_line = info->title ? info->title : capitalize(userid);

   s = sprintf(
      "<title>Finger info for %s@%s</title>\n"
      "<h2>Finger info for %s@%s</h2>\n"
      "<em><font size=+2>%s</font></em>\n"
      "Level: %s\n"
      "In real life: %-25s\n"
      "%s\n"
      "%s %s%s%s\n"
      "%s\n"
      "Email Address: %s\n"
      "%s",
      capitalize(userid), MUD_NAME,
      capitalize(userid), MUD_NAME,
      first_line,
      info->primary_level,
      info->real_name,
      info->position,
      info->idle == -1 ? "Left at" : "On since",
      info->last_login ? ctime(info->last_login) : "<unknown>",
      idle,
      info->connect_from,
      mailstring,
      info->email,
      info->home_page);

   if (info->plan)
   {
      s += "Plan:\n" + info->plan + "\n";
   }

   return replace_string(s, "\n", "<br>\n");
}