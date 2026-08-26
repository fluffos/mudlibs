// File     :  badge.c
// Purpose  :  Conference badge
// 94-03-02 :  Pallando removed channel stuff since you can make a channel
//             for conference users by doing:
//               call /adm/daemons/channels;register_channel;"con";me;3;0

#define log( x )
// #define log( x ) write_file( "/d/Conf/text/debug_badge.t", wrap( x ) )
#define CONF_HELP_DIR "/d/Conf/text/help/"
#define CMD_LOGCON "/d/Conf/cmds/_logcon"

#include <uid.h>
#include <move.h>
#include <mudlib.h>

inherit OBJECT; 

string name, rep, old_title;
int rmcon;

varargs int is_convener( mixed a )
{
  if( !a ) a = previous_object();
  a = ( objectp( a ) ? geteuid( a ) : a );
  if( a == getuid() || member_group( a, "conveners" ) ||
      a == ROOT_UID || adminp(a)   ) return 1;
  return 0;
}

void create()
{
  log( "create : " + identify( previous_object() ) + " [" +
    geteuid( previous_object() ) + "]" );
  if( !is_convener() && ( base_name( previous_object() ) != USER ) ) remove();
  seteuid( getuid() );
  set( "long",
"A shiny mithril badge, with your name etched on it in actinic blue fire.\n"+
"Type \"help conf.help\" for a list of conference help files.\n"+
"To leave the conference, \"discard badge\".\n"+
  "" );
  set( "short", "A blank conference badge" );
  set( "id", ({ "badge", "conference badge", "conference_badge" }) );
}

void init()
{
  add_action( "cmd_discard", "discard" );
  add_action( "cmd_help", "help" );
}

void set_short()
{
  set( "short", "A badge saying: " + capitalize( name ) +
    (rep ? (" "+rep) : "" ) );
}

void set_title( object member )
{
  member-> setenv( "TITLE",
    "$N" + ( rep ? (" "+rep) : "" ) + " (conference " +
    ( member_group( name, "conveners" ) ? "convener" : "member" ) +
    ")" );
}

int register( object user, string group )
{
  if( !is_convener() ) return 0;
  name = geteuid( user );
  rep = group;
  set_short();
  if( !old_title ) old_title = this_player()-> getenv( "TITLE" );
  set_title( user );
  return 1;
}

string query_rep() { return rep; } 

int rmcon( int a )
{
  if( is_convener() ) rmcon = a;
}

int move( object a )
{
  if( environment() && living( environment() ) )
  {
    notify_fail( "The badge is fixed on firmly.\n" ); 
    return MOVE_NOT_ALLOWED;
  }
  return ::move( a );
}

int cmd_discard( string a )
{
  if( !id( a ) ) { notify_fail( "Discard what?\n" ); return 0; }
  write( "You discard your conference badge.\n" );
  if( old_title ) this_player()-> setenv( "TITLE", old_title );
  remove();
  return 1;
}


mixed query_auto_load()
{
  return ({ base_name( this_object() ), ({
    name,
    rep,
    old_title,
    rmcon,
  }) });
}

void init_arg( mixed a )
{
  log( "init_arg : " + identify( a ) );
  name = a[0];
  rep = a[1];
  old_title = a[2];
  rmcon = a[3];
  set_short();
}

int cmd_help( string a )
{
  if( a && file_size( CONF_HELP_DIR + a ) > 0 )
  {
    write( read_file( CONF_HELP_DIR + a ) );
    return 1;
  }
  return 0;
}
