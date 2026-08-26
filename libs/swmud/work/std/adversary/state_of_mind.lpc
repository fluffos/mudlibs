// Last edited by deforce on 05-10-2010
int query_ghost();
void simple_action(string);

private nosave int stunned, slowed, asleep, chance;

int query_stunned()
{
   if ((stunned > time()) || this_object()->has_buff("/d/buffs/force_stun")) { return 1; }

   return 0;
}

int query_slowed()
{
   if (slowed > time()) { return 1; }

   return 0;
}

int query_asleep()
{
   return asleep;
}

void stun(int value)
{
   int time = time();

   if ((stunned + 2) <= time)
   {
      stunned = time + value;
   }
   else
   {
      simple_action("$N $vrecover from paralysis!");

      stunned = 0;
   }
}

void slow(int value)
{
   int time = time();

   if ((slowed + 2) <= time)
   {
      slowed = time + value;
   }
}

void wake_up()
{
   if (asleep)
   {
      asleep = 0;
      stunned = time() + 2;
   }
}

void knock_out()
{
   asleep = 1;
   chance = 0;
}

mixed check_condition(int urgent)
{
   if (query_ghost())
   {
      stunned = 0;
      asleep = 0;
      return 0;
   }

   if (urgent && (stunned > time()))
   {
      return "$N $vare paralyzed";
   }

   if (asleep)
   {
      if (urgent)
      {
         if (random(5) <= chance++)
         {
            wake_up();
         }
         else
         {
            return "You try desperately to wake up, but fail.\n";
         }
      }
      else
      {
         return "But you are asleep!\n";
      }
   }

   return 0;
}