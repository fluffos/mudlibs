/* Do not remove the headers from this file! see /USAGE for more info. */

#define AUTO_LEVEL
#undef TRAIN_FOR_LEVEL

void save_me();
varargs int query_level_for_xp(int xp);
int query_xp_for_level(int lev);
string query_body_style();
void update_body_style(string);
void do_game_command(string str);

private
int level;
private
int experience = 0;
private
int xp_modifier;
private
nosave int guild_xp_buff;
#ifdef USE_KARMA
int karma = 100; // Karma goes from -1000 to 1000.
#endif

void set_level(int x)
{
#ifdef TRAIN_FOR_LEVEL
   level = x;
#endif
#ifdef AUTO_LEVEL
   experience = query_xp_for_level(x);
   level = x;
   // Refresh the body with new abilities after changing level.
   update_body_style(query_body_style());
#endif
}

int query_level()
{
#ifdef AUTO_LEVEL
   level = query_level_for_xp();
#endif
   return level == 0 ? 1 : level;
}

#ifdef TRAIN_FOR_LEVEL
void raise_level()
{
   set_level(query_level() + 1);
   write("Congratulations! You gained a level!\n");
}
#endif

int query_experience()
{
   return experience;
}

void set_guild_xp_buff(int buff)
{
   if (buff > guild_xp_buff)
   {
      guild_xp_buff = buff;
      tell(this_object(), "%^COMBAT_CONDITION%^You received an XP buff of " + buff + "%%^RESET%^.\n");
   }
}

void clear_guild_xp_buff(int buff)
{
   guild_xp_buff = 0;
   tell(this_object(), "%^COMBAT_CONDITION%^Your XP buff fades.%^RESET%^\n");
}

int query_guild_xp_buff()
{
   return guild_xp_buff;
}

void set_experience(int x)
{
   experience = x;
   if (this_body()->query_link())
      this_body()->save_me();
}

void remove_experience(int x)
{
   int old_level, min_xp, old_xp;
   old_level = query_level();
#ifdef CAN_LOSE_LEVELS
   min_xp = 0;
#elif
   min_xp = query_xp_for_level(old_level);
#endif
   old_xp = experience;

   experience -= x;
   if (experience < min_xp)
      experience = min_xp;

   if ((old_xp - experience) > 0)
      tell(this_object(), "%^RED%^You lost " + (old_xp - experience) + " xp.%^RESET%^\n");

#ifdef CAN_LOSE_LEVELS
   level = query_level_for_xp();
   if (level != old_level)
   {
      tell(this_object(), "\n>>>>> %^B_RED%^LEVEL LOST!%^RESET%^ You're now just level " + level + "! <<<<<\n");
      do_game_command("pout");
   }
#endif

   if (this_object()->query_link())
      save_me();
}

void add_experience(int x)
{
   int old_level;
   old_level = query_level();
   //   TBUG("Adding XP to" + this_object() + ": " + x + " / Link: " + this_object()->query_link());
   experience += x;
   tell(this_object(), "%^YELLOW%^You gained " + x + " xp.%^RESET%^\n");

#ifdef AUTO_LEVEL
   level = query_level_for_xp();
   if (level != old_level)
   {
      tell(this_object(), "\n>>>>> %^B_GREEN%^LEVEL UP!%^RESET%^ You're now level " + level + "! <<<<<\n");
      do_game_command("flex");
   }
#endif

   if (this_object()->query_link())
      save_me();
}

int skill_xp_plus()
{
   int total;
   foreach (int skill in values(this_object()->query_skills()))
      total += skill;
   return total;
}

//: FUNCTION calc_xp_for
// int calc_xp_for(int player_level, int monster_level)
// Decoupled function to allow external XP calculation.
int calc_xp_for(int player_level, int monster_level)
{
   int callerLevel = player_level > 0 ? player_level : 1;
   int xp;
   float multFactor = (((0.0 + monster_level) / callerLevel));
   if (multFactor > 1.0)
      multFactor = ((multFactor - 1) * 2) + 1;
   xp = to_int(floor((1.0 + (monster_level / 1.0)) * ((XP_FACTOR / 15)) * (multFactor > 2.0 ? 2.0 : multFactor)));
   // TBUG("***: "+multFactor);
   // handling global xp modifier
   // xp = to_int(xp * GAME_D->query_global_xp_mult());
   return xp > 0 ? xp : 1;
}

//: FUNCTION xp_value
// int xp_value()
// Calculate XP value for monsters (and players). The function reduces XP for monsters if the player
// is too high level compared to the monster. It rewards players up to 20% if the monster is higher than
// their level. The function always returns 1 point as a minimum (sad).
varargs int xp_value(object xp_for)
{
   int xp;
   if (!xp_for)
      xp_for = previous_object();
   xp = calc_xp_for(xp_for->query_could_be_level(), this_object()->query_could_be_level());
   xp = to_int(xp * (1.0 + (xp_for->query_guild_xp_buff() / 100.0)));

   // Only needed for debug
   // int callerLevel = previous_object()->query_could_be_level() > 0 ? previous_object()->query_could_be_level() : 1;
   // TBUG("Caller level:" + callerLevel + " This level: " + this_object()->query_level());
   return xp;
}

int query_xp_modifier()
{
   return xp_modifier;
}

void set_xp_modifier(int n)
{
   xp_modifier = n;
}

int query_xp_for_level(int lev)
{
   int level = query_level() - 1;
   if (lev)
      level = lev;
   return XP_FACTOR * pow(level, 2) - XP_FACTOR * level;
}

int query_next_xp()
{
   return query_xp_for_level(query_level() + 1);
}

varargs int query_level_for_xp(int xp)
{
   if (!xp)
      xp = experience;
   return to_int(XP_FACTOR + sqrt(XP_FACTOR * XP_FACTOR - 4 * XP_FACTOR * (-xp))) / (2 * XP_FACTOR);
}

int query_could_be_level()
{
   return (this_object()->is_body() ? query_level_for_xp(experience) : query_level());
}

//: FUNCTION query_karma
// int query_karma()
// Returns the raw karma between -1000 and 1000.
int query_karma()
{
   return CLAMP(karma, -1000, 1000);
}

void set_karma(int k)
{
   karma = k;
}

//: FUNCTION modify_karma
// int modify_karma(int modifier)
// Modifies karma with a modifer from -5 to 5.
// The closer to 0 the more impact the karma modification will have.
// This also means that the more good or evil you are, the harder
// it will become to change it.
// Returns the new karma. Karma is between -1000 and 1000.
int modify_karma(int modifier)
{
   float karma_mod = 0;
   modifier = CLAMP(modifier, -5, 5);
   karma_mod = modifier * ((1100 / (200.0 + abs(karma))));
   karma = karma + karma_mod;

   karma = CLAMP(karma, -1000, 1000);
   return karma;
}