// for banishing players
// by Tim (simple for now)

#include <cmdline.h>
#include <daemons.h>

#define USAGE "ban [-u] <player_name>\n"

int
main(string* argv, string* argv2)
{
  string who;

  if( sizeof(argv2) != 1 )
    return notify_fail(USAGE);

  if( !adminp(this_interactive()) )
    return notify_fail("Insufficient Privileges.\n");

  who = lower_case(argv2[0]);

  if( flag("u") )
  {
    if( BANISH_D->unban(who) )
      write(capitalize(who) + " has been unbanished.\n");
    else
      return notify_fail(capitalize(who) + " is not banished!\n");
  }
  else
  {
    if( BANISH_D->banish(who, 0) )
      printf("%s has been banished from %s.\n", capitalize(who), mud_name());
    else
      return notify_fail("Failed to banish " + capitalize(who) + ".\n");
  }

  return 1;
}
