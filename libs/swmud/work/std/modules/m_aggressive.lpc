// Inheritable for aggressive monsters
// 12 May, 1998: Iizuka updated to support the new adversary code.
int is_aggressive_to(object who);
void start_fight(object who);

private int aggression_chance = 100;
private mapping jedi_aggression_chance = ([ "light" : 0, "neutral" : 0, "dark" : 0 ]);

//:FUNCTION is_aggressive_to
// This function can be overloaded in the monster file.  Lower priority than is_friendly_to()
int is_aggressive_to(object who)
{
   return 0;
}

//:FUNCTION is_friendly_to
// This function can be overloaded in the monster file.  Higher priority than is_aggressive_to()
int is_friendly_to(object who)
{
   return 0;
}

// It checks to see which objects in the room are players and attacks them.
// By default, this compares a random number to aggression_chance. 
void check_aggressive(object who)
{
   if (wizardp(who) && (who->query_shell_ob()->get_variable("god mode") == "on"))
   {
      return;
   }

   if (this_object()->is_friendly_to(who))
   {
      return;
   }

   if (this_object()->is_aggressive_to(who))
   {
      start_fight(who);

      return;
   }

   if (random(100) < aggression_chance)
   {
      start_fight(who);

      return;
   }

   if (who->query_guild_level("jedi"))
   {
      int alignment = who->query_jedi_alignment();
      int chance = 0;

      if ((alignment > 0) && (jedi_aggression_chance["light"] > 0))
      {
         chance = jedi_aggression_chance["light"];
      }
      else if ((alignment < 0) && (jedi_aggression_chance["dark"] > 0))
      {
         chance = jedi_aggression_chance["dark"];
      }

      if (random(100) < chance)
      {
         start_fight(who);

         return;
      }
   }
}

//:FUNCTION set_aggressive_chance
// This function is used to set the aggression chance of a monster in the
// range of 0 (never aggressive) to 100 (completely aggressive).
void set_aggressive_chance(int percent_chance)
{
   aggression_chance = percent_chance;

   if (aggression_chance < 0)
   {
      aggression_chance = 0;
   }
   else if (aggression_chance > 100)
   {
      aggression_chance = 100;
   }
}

//:FUNCTION query_aggressive_chance
// This function returns 0 for unaggressive monsters, or the chance of
// aggression for aggressive monsters.
int query_aggressive_chance()
{
   return aggression_chance;
}

//:FUNCTION set_jedi_aggressive_chance
// This function is used to set the aggression chance of a monster in the
// range of 0 (never aggressive) to 100 (completely aggressive) for jedi alignments.
void set_jedi_aggressive_chance(string alignment, int percent_chance)
{
   jedi_aggression_chance[alignment] = percent_chance;

   if (jedi_aggression_chance[alignment] < 0)
   {
      jedi_aggression_chance[alignment] = 0;
   }
   else if (jedi_aggression_chance[alignment] > 100)
   {
      jedi_aggression_chance[alignment] = 100;
   }
}

//:FUNCTION query_jedi_aggressive_chance
// This function returns 0 for unaggressive monsters, or the chance of
// aggression for aggressive monsters, for the specified jedi alignment.
int query_jedi_aggressive_chance(string alignment)
{
   return jedi_aggression_chance[alignment];
}

//:FUNCTION query_jedi_aggressive_chance_alignments
// This function returns the mapping of jedi alignments and aggressiveness.
mapping query_jedi_aggressive_chance_alignments()
{
   return jedi_aggression_chance;
}