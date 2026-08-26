private mapping guild_colors = ([
   "assassin" : "%^RED%^",
   "bounty hunter" : "%^CYAN%^",
   "diplomat" : "%^ORANGE%^",
   "engineer" : "%^BLUE%^",
   "jedi" : "%^BOLD%^%^CYAN%^",
   "mercenary" : "%^BOLD%^%^MAGENTA%^",
   "merchant" : "%^GREEN%^",
   "physician" : "%^YELLOW%^",
   "pilot" : "%^BOLD%^%^GREEN%^",
   "slicer" : "%^MAGENTA%^",
   "smuggler" : "%^BOLD%^%^RED%^",
]);

string get_guild_color(string guild)
{
   if (guild_colors[guild])
   {
      return guild_colors[guild];
   }

   return "%^BOLD%^%^BLUE%^";
}

string get_guild_color_printf(string guild)
{
   if (guild_colors[guild])
   {
      return replace_string(guild_colors[guild], "%^", "%%^");
   }

   return "%%^BOLD%%^%%^BLUE%%^";
}