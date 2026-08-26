#include <mudlib.h>
#include <config.h>
#include <classes.h>

inherit CMD;
inherit CLASS_SKILL_DATA;

object body;

private void main(string arg)
{
   string skill_name;
   int skill_value;
   int pure_skill_value;

   if (!arg)
   {
      out("Usage: skill <skill name>\n");

      return;
   }

   skill_name = SKILL_D->query_internal_skill_name(lower_case(arg));
   body = this_body();
   skill_value = body->query_skill(skill_name);
   pure_skill_value = body->query_skill_pure(skill_name);

   if (pure_skill_value > 0)
   {
      int rank = to_int(floor(skill_value / 100));
      int to_next = skill_value - (rank * 100);
      mixed data = SKILL_D->get_skill_data(skill_name);
      string output = sprintf("Rank %i", rank);
      string capname = skill_name;

      if (data) { capname = data->proper_name; }

      if (rank < 10) { output += sprintf(", %i%% to next rank", to_next); }

      if (pure_skill_value > skill_value)
      {
         output = "%^BOLD%^%^RED%^" + output + "%^RESET%^";
      }
      else if (skill_value > pure_skill_value)
      {
         output = "%^BOLD%^%^GREEN%^" + output + "%^RESET%^";
      }

      output = capname + " : " + output;

      out(output);

      return;
   }

   if (!sizeof(body->get_skills()))
   {
      out("You have no skills.\n");

      return;
   }

   out("You have no skill in " + arg + ".\n");
}