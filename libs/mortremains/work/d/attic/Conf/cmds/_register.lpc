// Written by Pallando 93-02-17
// Lots of hard wired references to /d/Conf I'm afraid./

#include <config.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: register <user>[ <group>\n"+\
  "Eg \"register pallando\" or \"register pallando of TMI-II LPmud\"\n"

int cmd_register( string a )
{
  object badge, member;
  string name, rep;

  seteuid( geteuid() );
  if( !member_group( geteuid( this_player() ), "conveners" ) )
  {
    notify_fail( "Sorry, you must find an convener to register you.\n" );
    return 0;
  }
  if( !a ) { notify_fail( SYNTAX ); return 0; }
  if( sscanf( a, "%s %s", name, rep ) > 1 ) member = find_player( name );
  if( !member )
  {
    name = a;
    rep = 0;
    if( !( member = find_player( name ) ) )
      { notify_fail( SYNTAX ); return 0; }
  }
  badge = present( "conference_badge", member );
  if( !badge )
  {
    badge = new( "/d/Conf/obj/badge" );
    badge-> move( member );
  }
  badge-> register( member, rep );
  member-> save_me();
  write( "You register " + capitalize( geteuid( member )  ) +
    ( rep ? (" "+rep) : "" ) + "\n" );
  tell_object( member, "You are now registered for the conference.\n" );
  write_file( "/d/Conf/logs/registered.t",
    ctime( time() ) + " : " + capitalize( geteuid( this_player() ) ) + " registered \t" +
    capitalize( geteuid( member )  ) + ( rep ? (" "+rep) : "" ) + "\n" );
  return 1;
}

int help()
{
  write( ""+
"Syntax: register <user>[ <group>]\n"+
"Effect: Register user <user> for the conference.\n"+
"        Gives them a badge, the con channel and does their title.\n"+
"eg  \"register pallando\" or \n"+
"    \"register pallando of TMI-II LPmud\"\n"+
  "" );
  return 1;
}
