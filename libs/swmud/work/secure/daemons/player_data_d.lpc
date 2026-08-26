#include <security.h>

inherit M_ACCESS;
inherit CLASS_PLAYER_GUILD_DATA;

void create()
{
   set_privilege(1);
}

class player_guild_data get_player_guild_data(string userid)
{
   class player_guild_data result;
   object user;
   string * info;

   info = unguarded(1, (: call_other, USER_D, "query_variable", userid,
      ({ "guild_levels", "guild_ranks", "primary_guild", "primary_level", "jedi_alignment" }) :));

   if (!info) { return 0; }

   result = new(class player_guild_data, guild_levels: info[0], guild_ranks: info[1],
      primary_guild: info[2], primary_level: info[3], jedi_alignment: info[4]);

   return result;
}

void clean_up()
{
   destruct(this_object());
}