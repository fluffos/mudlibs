// Last edited by deforce on 04-22-2010
mapping guild_specializations = ([ ]);
mapping guild_specialization_ranks = ([ ]);

//:FUNCTION query_guild_specialization
//Returns string with the specified guild's specialization, or blank string if none
string query_guild_specialization(string guild)
{
   if (guild_specializations[guild])
   {
      return guild_specializations[guild];
   }

   return "";
}

//:FUNCTION set_guild_specialization
//Sets specialization rank for the specified guild and specialization
void set_guild_specialization(string guild, string specialization, int rank)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s " + guild + " guild specialization to " + specialization + ", rank " + rank, previous_object(-1)); }

   if (rank < 1) { rank = 1; }
   else if (rank > 10) { rank = 10; }

   guild_specializations[guild] = specialization;
   guild_specialization_ranks[guild] = rank;
}

//:FUNCTION add_guild_specialization
//Adds 1 to specialization rank for the specified guild and specialization
void add_guild_specialization(string guild, string specialization)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("increment " + this_object()->short() + "'s " + guild + " guild specialization in " + specialization, previous_object(-1)); }

   if (guild_specializations[guild] && guild_specialization_ranks[guild]
      && (specialization == guild_specializations[guild]))
   {
      if (guild_specialization_ranks[guild] < 10)
      {
         guild_specialization_ranks[guild]++;
      }
   }
}

//:FUNCTION remove_guild_specialization
//Removes specialization for the specified guild
void remove_guild_specialization(string guild)
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("remove " + this_object()->short() + "'s " + guild + " guild specialization", previous_object(-1)); }

   if (guild_specializations[guild])
   {
      map_delete(guild_specializations, guild);
   }

   if (guild_specialization_ranks[guild])
   {
      map_delete(guild_specialization_ranks, guild);
   }
}

//:FUNCTION query_guild_specialization_rank
//Returns integer of the effective rank for the given specialization in the given guild
int query_guild_specialization_rank(string guild, string specialization)
{
   if (guild_specializations[guild] && guild_specialization_ranks[guild])
   {
      if (guild_specialization_ranks[guild] < 1) { guild_specialization_ranks[guild] = 1; }
      else if (guild_specialization_ranks[guild] > 10) { guild_specialization_ranks[guild] = 10; }

      if (specialization == guild_specializations[guild])
      {
         return guild_specialization_ranks[guild];
      }

      return guild_specialization_ranks[guild] - 10;
   }

   return 0;
}

//:FUNCTION query_guild_specializations
//Returns a mapping of all the player's guild specializations
mapping query_guild_specializations()
{
   return guild_specializations;
}

//:FUNCTION query_guild_specialization_ranks
//Returns a mapping of all the player's guild specialization ranks
mapping query_guild_specialization_ranks()
{
   return guild_specialization_ranks;
}

//:FUNCTION reset_guild_specializations
//Clears all of the current guild specializations
void reset_guild_specializations()
{
   if (this_object()->is_body()) { this_object()->check_wizard_set("reset " + this_object()->short() + "'s guild specializations", previous_object(-1)); }

   guild_specializations = ([ ]);
   guild_specialization_ranks = ([ ]);
}