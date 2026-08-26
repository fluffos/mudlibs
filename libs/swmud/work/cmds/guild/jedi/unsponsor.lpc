inherit CMD;

#include <jedi_ranks.h>

void unsponsor(string player_name);

void main(string player_name)
{
   if (this_body()->query_guild_level("jedi"))
   {
      if (strlen(player_name))
      {
         if (JEDI_SPONSOR_D->query_sponsor(player_name) == this_body()->query_userid())
         {
            unsponsor(player_name);
         }
         else
         {
            out("You are not currently sponsoring " + capitalize(player_name) + ".\n");
         }
      }
      else
      {
         out("Unsponsor whom?\n");
      }
   }
   else
   {
      out("Only Jedi can unsponsor a Padawan or apprentice.\n");
   }
}

void unsponsor(string player_name)
{
   string force_message = "%^BOLD%^%^RED%^You sense the " + (this_body()->query_jedi_alignment() < 0 ? "Light" : "Dark") + " Side of the Force grow stronger, as " + get_jedi_rank_title(this_body()->query_guild_rank("jedi"), this_body()->query_jedi_alignment()) + " " + capitalize(this_body()->query_userid()) + " unsponsors " + capitalize(player_name) + " as " + this_body()->query_possessive() + " " + get_jedi_rank_title(1, this_body()->query_jedi_alignment()) + ".%^RESET%^\n";

   JEDI_SPONSOR_D->add_unsponsored(player_name, this_body()->query_userid());

   this_body()->simple_action("$N $vunsponsor " + capitalize(player_name) + " as your " + (this_body()->query_jedi_alignment() > 0 ? "Padawan" : "apprentice") + ".");

   foreach (object jedi in filter_array(bodies(), (: $1->query_toggle("sense disturbance") == "on" :) ))
   {
      tell(jedi, force_message);
   }
}