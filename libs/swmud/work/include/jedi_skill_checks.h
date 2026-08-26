mixed can_use_jedi_skill(object user, string skill_alignment)
{
   if (!user->can_feel_force())
   {
      return "You are unable to feel the Force.\n";
   }

   if ((skill_alignment == "light") && user->has_effect("Light side abandonment"))
   {
      return "You feel disconnected from the Light side of the Force.\n";
   }
   else if ((skill_alignment == "dark") && user->has_effect("Dark side abandonment"))
   {
      return "You feel disconnected from the Dark side of the Force.\n";
   }

   return 1;
}