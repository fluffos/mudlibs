#include <config.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: restorecon <user>\n"

int cmd_restorecon( string a )
{
  string path;
  object user, badge;
  mixed tmp;

// First check the previous object has permission to use this command.
  if( !member_group( geteuid( previous_object() ), "conveners" ) )
  {
    notify_fail( "Only conference conveners may use this commands.\n" );
    return 0;
  }
// Second check they specified a user who is on
  if( !a || !( user = find_player( a ) ) )
  {
    notify_fail( SYNTAX );
    return 0;
  }
// Third check the user has a conference badge
  if( !( badge = present( "conference_badge", user ) ) )
  {
    notify_fail( a + " isn't wearing a badge.\n" );
    return 0;
  }
  badge-> rmcon( 0 );
  write( capitalize( a ) + " may now use \"con\" again.\n" );
  return 1;
}

int help()
{
  write( SYNTAX+
    "Effect: Reverses the effect of \"rmcon\".\n"+
  "" );
  return 1;
}
