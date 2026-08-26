// Last edited by deforce on 06-26-2008
#include <mudlib.h>
#include <config.h>

inherit CMD;

void format_stats(object body);
void format_stats_max(object body);
string format_stat_value(int real, int current);

private void main(string arg)
{
   object body;
   string name = arg;
   string flags = "";

   if (strlen(arg))
   {
      if (sscanf(arg, "%s %s", name, flags) != 2)
      {
         if (strsrch(arg, "-") > -1)
         {
            flags = arg;
         }
         else
         {
            name = arg;
         }
      }
   }

   out("\n\n");

   if (wizardp(this_body()) && strlen(name) && find_body(name))
   {
      body = find_body(name);
      name = body->query_title();

      out(name + (wizardp(body) ? (adminp(body) ? " (Admin Wizard)" : " (Wizard)") : "") + "\n");
      out(repeat_string("-", 79) + "\n");
   }
   else { body = this_body(); }

   body->refresh_stats();

   if (strsrch(flags, "-m") > -1)
   {
      format_stats_max(body);
   }
   else
   {
      format_stats(body);
   }

   out("\n");
}

void format_stats(object body)
{
   string format = "%-13s:%3s";

   outf(format + "    " + format + "\n",
      "Strength", format_stat_value(body->query_str_pure(), body->query_str()),
      "Intelligence", format_stat_value(body->query_int_pure(), body->query_int()));
   outf(format + "    " + format + "\n",
      "Constitution", format_stat_value(body->query_con_pure(), body->query_con()),
      "Charisma", format_stat_value(body->query_cha_pure(), body->query_cha()));
   outf(format + "    " + format + "\n",
      "Agility", format_stat_value(body->query_agi_pure(), body->query_agi()),
      "Luck", format_stat_value(body->query_luc_pure(), body->query_luc()));
   outf(format + "    " + format + "\n",
      "Dexterity", format_stat_value(body->query_dex_pure(), body->query_dex()),
      "Force", format_stat_value(body->query_for_pure(), body->query_for()));
   outf(format + "\n",
      "Perception", format_stat_value(body->query_per_pure(), body->query_per()));
}

void format_stats_max(object body)
{
   string format = "%-13s: %2s / %-2d";

   outf(format + "    " + format + "\n",
      "Strength", format_stat_value(body->query_str_pure(), body->query_str()), (body->query_race_str_max() / 5),
      "Intelligence", format_stat_value(body->query_int_pure(), body->query_int()), (body->query_race_int_max() / 5));
   outf(format + "    " + format + "\n",
      "Constitution", format_stat_value(body->query_con_pure(), body->query_con()), (body->query_race_con_max() / 5),
      "Charisma", format_stat_value(body->query_cha_pure(), body->query_cha()), (body->query_race_cha_max() / 5));
   outf(format + "    " + format + "\n",
      "Agility", format_stat_value(body->query_agi_pure(), body->query_agi()), (body->query_race_agi_max() / 5),
      "Luck", format_stat_value(body->query_luc_pure(), body->query_luc()), (body->query_race_luc_max() / 5));
   outf(format + "    " + format + "\n",
      "Dexterity", format_stat_value(body->query_dex_pure(), body->query_dex()), (body->query_race_dex_max() / 5),
      "Force", format_stat_value(body->query_for_pure(), body->query_for()), (body->query_race_for_max() / 5));
   outf(format + "\n",
      "Perception", format_stat_value(body->query_per_pure(), body->query_per()), (body->query_race_per_max() / 5));
}

string format_stat_value(int real, int current)
{
   if (current > real) { return sprintf("%%^BOLD%%^%%^GREEN%%^%3s%%^RESET%%^", sprintf("%d", (current / 5))); }
   else if (current < real) { return sprintf("%%^BOLD%%^%%^RED%%^%3s%%^RESET%%^", sprintf("%d", (current / 5))); }

   return sprintf("%d", (current / 5));
}