inherit CMD;

#include <toggles.h>

private void main(string guild_search)
{
   int color = 0;

   foreach (string toggle in sort_array(keys(toggle_data), 1))
   {
      mapping data = toggle_data[toggle];
      int found = 0;
      mixed value = this_body()->query_toggle(toggle);

      foreach (string guild in keys(data))
      {
         if ((guild == "general") || (this_body()->query_guild_level(guild) && this_body()->has_learned_skill(data[guild])))
         {
            found = 1;
         }
      }

      if (found)
      {
         if (value == 0)
         {
            value = "off";
         }

         outf((color ? "%%^BOLD%%^" : "") + "%-20s  %s%%^RESET%%^\n", title_capitalize(toggle), value);
         color = !color;
      }
   }
}