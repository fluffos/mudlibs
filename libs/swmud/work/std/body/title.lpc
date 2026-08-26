// Last edited by deforce on 03-22-2010
// Title handling for the player
// Designed to be removed from the player object if necessary.
// Created by Deathblade 05-01-1995
private string title;

string query_userid(); // In /std/player

string query_title()
{
   // Ensure the player has a title. set it if none (yet)
   if (!title)
   {
      title = sprintf("%s the title-less", capitalize(query_userid()));
   }

   return title;
}

int set_title(string str)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("change " + this_object()->short() + "'s title", previous_object(-1)); }

   if (str && (strsrch(str, "$N") == -1))
   {
      error("bad title -- needs to contain $N\n");
   }

   if (!strlen(str))
   {
      title = sprintf("%s the title-less", capitalize(query_userid()));
   }
   else
   {
      title = replace_string(str, "$N", capitalize(query_userid()));
   }
}