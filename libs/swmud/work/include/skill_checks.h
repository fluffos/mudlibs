mixed can_use_skill(object user, string skill_name, string *guilds, string not_in_guild_message, string skill_not_learned_message, string skill_delay_message)
{
   if (sizeof(guilds))
   {
      int found_guild = 0;

      foreach (string guild in guilds)
      {
         if (user->query_guild_level(guild) && !found_guild)
         {
            found_guild = 1;
         }
      }

      if (!found_guild)
      {
         return not_in_guild_message + "\n";
      }
   }

   if (user->is_body() && !user->has_learned_skill(skill_name))
   {
      return skill_not_learned_message + "\n";
   }

   if (user->has_blocked_skill(skill_name))
   {
      return "Your ability to use this skill has been disabled.\n";
   }

   if (user->has_skill_delay())
   {
      return sprintf(skill_delay_message + "\n", convert_time(user->has_skill_delay()));
   }

   if (user->has_special_skill_delay(skill_name))
   {
      return sprintf(skill_delay_message + "\n", convert_time(user->has_special_skill_delay(skill_name)));
   }

   if (user->query_stunned())
   {
      return "You are stunned.\n";
   }

   return 1;
}