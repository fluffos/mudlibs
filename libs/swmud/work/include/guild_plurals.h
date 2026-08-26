mapping guilds = ([
   "assassin" : "assassins",
   "bounty hunter" : "bounty hunters",
   "diplomat" : "diplomats",
   "engineer" : "engineers",
   "mercenary" : "mercenaries",
   "merchant" : "merchants",
   "physician" : "physicians",
   "pilot" : "pilots",
   "slicer" : "slicers",
   "smuggler" : "smugglers",
]);

string get_guild_plural(string guild_name)
{
   if (guilds[guild_name]) { return guilds[guild_name]; }

   return guild_name;
}