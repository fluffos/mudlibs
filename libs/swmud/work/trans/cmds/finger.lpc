#include <mudlib.h>
#include <commands.h>

inherit CMD;
inherit M_COMPLETE;
inherit M_GRAMMAR;
inherit CLASS_FINGER;

#include <guild_plurals.h>
#include <wizards.h>

private nomask string format_idle_time(int time);
private nomask string format_age(int time);

private void main(string who)
{
   class finger info;
   string output = "";
   string idle;
   string sex;
   string team = "";
   string mailstring;
   string character_age = "";

   if (!who)
   {
      if (wizardp(this_user()))
      {
         out(FINGER_D->show_big_finger());

         return;
      }
      else
      {
         out("Usage: finger <user>\n");

         return;
      }
   }

   who = lower_case(trim_spaces(who));

   info = FINGER_D->get_finger_data(who);

   if (!info)
   {
      out("There is no record of " + capitalize(who) + ".\n");

      return;
   }

   if (!info->sex) { sex = "Neuter"; }
   else if (info->sex == 1) { sex = "Male"; }
   else { sex = "Female"; }
   if (info->team == 1) { team = "Rebel"; }
   else if (info->team == -1) { team = "Imperial"; }
   else { team = "Neutral"; }
   if (!info->spouse) { info->spouse = "Single"; }
   else { info->spouse = "Married to " + capitalize(info->spouse); }
   if (!info->real_name) { info->real_name = ""; }
   if (!info->email) { info->email = ""; }
   if (!info->position) { info->position = ""; }
   else { info->position = " Position: " + info->position; }

   if (info->home_page) { info->home_page = "Website: " + info->home_page + "\n"; }
   else { info->home_page = ""; }

   if (info->idle > -1)
   {
      character_age = "Age: " + format_age(find_body(who)->query_total_connected_time() + (time() - LAST_LOGIN_D->query_last(who)[0])) + "\n";
   }

   if (info->connect_from) { info->connect_from = " from " + info->connect_from; }
   else { info->connect_from = ""; }

   if (info->idle == -1) { idle = ""; }
   else if (info->idle == -2) { idle = " (linkdead)"; }
   else { idle = format_idle_time(info->idle); }

   if (info->mail_unread > 0)
   {
      mailstring = capitalize(who) + " has " + info->mail_unread + " unread message";
      mailstring += (info->mail_unread > 1 ? "s" : "") + ".";
   }
   else { mailstring = capitalize(who) + " has no unread mail."; }

   output += (info->title ? info->title : capitalize(who)) + "\n";
   if (info->describe) { output += info->describe + "\n"; }
   if (!wizardp(who)) { output += sprintf("%-45s Level: %i\n", sprintf("%s %s of the %s", sex, title_capitalize(info->race), (strlen(info->primary_guild) ? title_capitalize(get_guild_plural(info->primary_guild)) : "Players")), info->primary_level); }
   else
   {
      int wizard_level = SECURE_D->query_is_wizard(who);
      string wizard_title = title_capitalize(get_wizard_title(wizard_level));

      output += sprintf("%-45s Level: %s\n", sprintf("%s %s of the %s", sex, title_capitalize(info->race), "Wizards"), wizard_title);
   }
//   output += sprintf("Team: %s %s\n", team, info->position);
//   if (!wizardp(who)) { output += sprintf("Team: %s\n", team); }
   output += sprintf("In real life: %-31s %s\n", info->real_name[0..31], info->spouse);
   if (strlen(info->home_page)) { output += info->home_page[0..70]; }
   if (strlen(info->email)) { output += sprintf("E-mail: %s\n", info->email[0..71]); }
   output += character_age;
   output += sprintf("%s %s%s%s\n", (info->idle == -1 ? "Left at" : "On since"),
      (info->last_login ? ctime(info->last_login) : "<unknown>"), idle, info->connect_from);
   output += sprintf("%s\n", mailstring);

   if (info->project) { output += "Project:\n" + info->project; }
   if (info->plan) { output += "Plan:\n" + info->plan; }
//   else { output += "No plan.\n"; }

   out(output);
}

private nomask string format_idle_time(int time)
{
   string output = "";

   if (time > 59)
   {
      output += " (idle ";

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

      if (wizardp(this_user()) && (time > 0)) { output += ", " + (time % 60) + "s"; }

      output += ")";
   }
   else if (time > 0) { output += " (idle " + (time % 60) + "s)"; }

   return output;
}

private nomask string format_age(int time)
{
   string output = "";

   if (time > 59)
   {
      if (time > 3599)
      {
         if (time > 86399)
         {
            output += (time / 86400) + " days, ";

            time = time % 86400;
         }

         output += (time / 3600) + " hours, ";

         time = time % 3600;
      }

      output += (time / 60) + " minutes, ";
   }

   output += (time % 60) + " seconds.";

   return output;
}

nomask int valid_resend(string ob)
{
   return ob == CMD_OB_FINGER;
}