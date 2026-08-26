inherit "/std/board/bboard";

#define GUILD "driver"
#define POSITION "sage"

int valid_post()
{
   if ((string)this_player()->query_guild_level(GUILD) != POSITION) {
      notify_fail("The bulletin board resists your approach.\n");
      return 0;
   }
   return 1;
}

int valid_assign()
{
   return valid_post();
}
