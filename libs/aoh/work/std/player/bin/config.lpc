/*--------------------------------------------------------------------------
 * /std/player/bin/config.c  --  The config command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * The config command replaces 'stty', 'email', 'pagewidth', 'pagesize' and
 * 'buffering'
 * TODO:  ansi.h should not be used, but currently ANSI_BOLD is needed for
 * TODO:: vt100
 * [tune] 25-Apr-98  added time options
 */

#include <properties.h>
#include <msgclass.h>
#include <ansi.h>

public int main( string arg ) {
  string what, how;
  int n;

  if ( ! arg || arg == "show" ) {
    what = "Current settings:\n";
    what += sprintf( "%-15'.'s : %s\n", "tty ", ({string})this_player()->Query(P_TTY) );
    what += sprintf( "%-15'.'s : %s\n", "email ",
                     ({string})this_player()->Query( P_MAILADDR ) );
    what += sprintf( "%-15'.'s : %d\n", "pagesize ",
                     ({int})this_player()->Query( P_PAGESIZE ) );
    what += sprintf( "%-15'.'s : %d\n", "pagewidth ",
                     ({int})this_player()->Query( P_PAGEWIDTH ) );
    what += sprintf( "%-15'.'s : %s\n", "buffering ",
                     ({int})this_player()->QueryNoBuffering()?"off":"on" );
    what += sprintf( "%-15'.'s : %s\n", "channel style ",
                     ({int})this_player()->QueryNewChannelStyle()?"new":"old" );
    what += sprintf( "%-15'.'s : %s\n", "time style ",
                     ({string})this_player()->Query(P_TIME_OPTIONS) );
    msg_write( CMSG_GENERIC, what );
    return 1;
  }

  if ( ( sscanf( arg, "%s %s", what, how ) != 2 ) &&
       ( sscanf( arg, "%s=%s", what, how ) != 2 ) )
    return notify_fail( "Use 'help config' to get the usage.\n" ), 0;

  /* norm what */
  what = norm_id( what );

  /* and strip spaces from how, we cannot use norm_id because of case for
   * email
   */
  while( how[0] == ' ' )
    how = how[1..];
  while( how[<1] == ' ' )
    how = how[0..<2];

  switch( what ) {
  case "buffering":
    if ( how == "on" )
      this_player()->SetNoBuffering( 0 );
    else if ( how == "off" )
      this_player()->SetNoBuffering( 1 );
    else {
      msg_write( CMSG_GENERIC, "Usage: config buffering on|off\n" );
      return 1;
    }

    msg_write( CMSG_GENERIC, "Buffering is now "+
               (({int})this_player()->QueryNoBuffering()?"dis":"en")+
               "abled.\n" );
    break;
  case "tty":
    switch( how ) {
    case "vt100":
      msg_write( CMSG_GENERIC, "\e[0m" ); /* reset da term */
      this_player()->Set( P_TTY, "vt100" );
      msg_write( CMSG_GENERIC,
                 "This should be "+ANSI_BOLD+" bold%^RESET%^\n");
      break;
    case "ansi":
      msg_write( CMSG_GENERIC, "\e[0m" ); /* reset da term */
      this_player()->Set( P_TTY, "ansi" );
      msg_write( CMSG_GENERIC, "This should be %^RED%^red%^RESET%^\n");
      break;
    case "dumb":
      msg_write( CMSG_GENERIC, "\e[0m" ); /* reset da term */
      this_player()->Set( P_TTY, "dumb" );
      msg_write( CMSG_GENERIC, "How boring! Get a new terminal!\n");
      break;
    default:
      msg_write( CMSG_GENERIC,
                 "Usage: config tty ansi|vt100|dumb.\n" );
      break;
    }
    break;
  case "pagesize":
    if ( sscanf( how, "%d", n) && n+"" == how ) {
      this_player()->Set( P_PAGESIZE, (n > 5) ? n : 16 );
      msg_write( CMSG_GENERIC,
                 "Pagesize is "+({int})this_player()->Query( P_PAGESIZE )+
                 " lines.\n" );
    }
    else
      msg_write( CMSG_GENERIC,
                 "Usage: config pagesize <number>.\n" );

    break;
  case "pagewidth":
    if ( sscanf( how, "%d", n) && n+"" == how ) {
      this_player()->Set( P_PAGEWIDTH, (n > 30) ? n : 80 );
      msg_write( CMSG_GENERIC,
                 "Pagewidth is "+({int})this_player()->Query( P_PAGEWIDTH )+
                 " characters per line.\n" );
    }
    else
      msg_write( CMSG_GENERIC,
                 "Usage: config pagewidth <number>.\n" );

    break;

  case "email":
    this_player()->Set( P_MAILADDR, how );
    msg_write( CMSG_GENERIC, "Your email address is now: '"+
               ({string})this_player()->Query(P_MAILADDR)+"'\n" );
    return 1;
    break;

  case "channel-style":
    if ( how == "old" )
      this_player()->SetNewChannelStyle(0);
    else if ( how == "new" )
      this_player()->SetNewChannelStyle(1);
    else {
      msg_write( CMSG_GENERIC, "Usage: config channel-style old|new\n" );
      return 1;
    }

    msg_write( CMSG_GENERIC, "Channel-style is now set to "+
               (({int})this_player()->QueryNewChannelStyle()?"new style":"old style")+
               ".\n" );
    break;

  case "time":
    switch( lower_case(how) )  {
    case TIME_OSB:
      this_player()->Set(P_TIME_OPTIONS, TIME_OSB);
      msg_write( CMSG_GENERIC,
                 "Time command set to display OSB time.\n" );
      break;
    case TIME_RL:
      this_player()->Set(P_TIME_OPTIONS, TIME_RL);
      msg_write( CMSG_GENERIC,
                 "Time command set to display real world time.\n" );
      break;
    case TIME_ALL:
      this_player()->Set(P_TIME_OPTIONS, TIME_ALL);
      msg_write( CMSG_GENERIC,
                 "Time command set to display OSB and real world time.\n" );
      break;
    default:
      msg_write( CMSG_GENERIC,
                 "Usage: config time <osb | rl | all>.\n" );
    }
    break;

  default:
    return notify_fail( "Unsupported config option, please read 'help config'.\n" ), 0;
  }

  return 1;
}
