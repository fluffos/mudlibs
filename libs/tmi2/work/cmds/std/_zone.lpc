/*
// File:       /cmds/std/_zone.c
// Date V1.0:  93-05-23
// Author:     Douglas Reay (Pallando @ most muds)
// Mudlib:     TMI-2
// NB 1440 = Number of minutes in a day = 60 * 24
*/
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

#define SYNTAX "Syntax: zone <zone_wanted> <time_got> <zone_got>\n"

int cmd_zone( mixed a )
{
  string zone_want, zone_got, time_want, time_got;
  int o_want, o_got;  // time zone offsets (in seconds)
  int hours, minutes;

  notify_fail( SYNTAX );
  if( !a ) return 0;

  if( sscanf( a, "%s %s %s", zone_want, time_got, zone_got ) < 3 ) return 0;
  if( !( o_got = TIME_D-> query_tzone( zone_got ) ) )
  {
    notify_fail( zone_got + " is not a time zone I recognise.\n" );
    return 0;
  }
  if( !( o_want = TIME_D-> query_tzone( zone_want ) ) )
  {
    notify_fail( zone_want + " is not a time zone I recognise.\n" );
    return 0;
  }
  if( sscanf( time_got, "%d:%d", hours, minutes ) < 2 )
  {
    notify_fail( time_got + " is not in the form \"<hours>:<minutes>\".\n" );
    return 0;
  }

  minutes += ( 60 * hours );
  minutes += ( o_want - o_got ) / 60;
  minutes += 1440;
  minutes = ( minutes % 1440 );
  hours = minutes;
  minutes = ( minutes % 60 );
  hours -= minutes;
  hours = hours / 60;
  time_want = ( ( hours < 10 ) ? ( "0" + hours ) : ( "" + hours ) );
  time_want += ( ( minutes < 10 ) ? ( ":0" + minutes ) : ( ":" +minutes ) );

  write( time_got  + " " + zone_got  + " == " +
         time_want + " " + zone_want + "\n"     );
  return 1;
}

int help()
{
  write( SYNTAX + @HelpText
Effect: Converts <time_got> in time zone <zone_got> to time in <zone_wanted>
Example: zone GMT 23:10 PST   would convert 11:10pm Pacific Standard Time
                              into the equivalent Greenwich Mean Time time.
Recognised abbreviations are:
HelpText
  );
  TIME_D-> show_tzone_list();
  return 1;
}

/* EOF */
