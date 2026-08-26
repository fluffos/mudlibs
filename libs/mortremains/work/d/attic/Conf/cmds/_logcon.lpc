#include <mudlib.h>

inherit DAEMON;

#define CON_LOG_DIR "/d/Conf/logs/"

string logcon;

int cmd_logcon( string a )
{
  if( !member_group( geteuid( previous_object() ), "conveners" ) )
  {
    notify_fail( "Sorry - only conveners may use this command.\n" );
    return 0;
  }
  if( !a )
  {
    if( !logcon ) write( "The con channel is not being logged.\n" );
    else write( "Logging of the con channel now stopped.\n"+
                "The record is in " + logcon + "\n" );
    logcon = 0;
    return 1;
  }
  logcon = resolv_path( CON_LOG_DIR, a );
  if( logcon != ( CON_LOG_DIR + a ) )
  {
    notify_fail( "You do not have write permission to " + logcon + "\n" );
    return 0;
  }
  write( "Now logging con to " + logcon + "\n" );
  write( ""+
"NB It is strongly advised that you prevent people (using rmcon if necessary)\n"+
"   from making remarks on con that should be commented.\n"+
  "" );
  return 1;
}

int logcon( string a )
{
  string text;

  if( !logcon ) return 0;
  text = capitalize( geteuid( this_player() ) );
  text += " cons: " + a;
  write_file( logcon, wrap( text ) );
  return 1;
}

int help()
{
  write( ""+
"Syntax: logcon <file>\n"+
"Effect: Logs the con channel to " + CON_LOG_DIR + "<file>\n"+
"        To stop logging, type just \"logcon\".\n"+
  "" );
  return 1;
}
