#include <toggles.h>

private mapping toggles = ([ ]);

mixed query_toggle(string toggle)
{
   if (strlen(toggle) && toggle_data[toggle] && toggles[toggle])
   {
      mapping data = toggle_data[toggle];
      int found = 0;

      foreach (string guild in keys(data))
      {
         if (this_body()->query_guild_level(guild) && this_body()->has_learned_skill(data[guild]))
         {
            found = 1;
         }
      }

      if (found)
      {
         return toggles[toggle];
      }
   }

   return 0;
}

varargs void set_toggle(string toggle, mixed value)
{
   if (!toggle_data[toggle])
   {
      error(toggle + " is not a valid toggle.");
   }

   if (strlen(toggle) && value)
   {
      toggles[toggle] = value;
   }
   else
   {
      toggles[toggle] = 0;
   }
}