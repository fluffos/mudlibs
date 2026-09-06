/*--------------------------------------------------------------------------
 * INETD_CMD_DIR who.c -- The intermud who reply module
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * Originally written by Nostradamus@Zebedee
 * Developed from an original concept by Alvin@Sushi
 *--------------------------------------------------------------------------
 */

#include <secure/wizlevels.h>
#include <inetd.h>
#include <properties.h>
#include <daemons.h>

#define FLAG_CAP     1
#define FLAG_LEFT    2
#define FLAG_CENTER  4
#define FLAG_COLUMN  8

/*
******************************************************************************
** some functions that can be used inside RWHO_BANNER with @@...@@
**  all functions are varargs, the parameters are handled by format_result,
**  the flag defines the formatting( see defines ), width is the field width
**  and pad is the string used to pad the result to width.
******************************************************************************
*/

string format_result( string str, mixed flag, mixed width, string pad, string pre, string post ) {
  string fmt;

  flag = to_int( flag );
  width = to_int( width );

  fmt = "%";
  if ( flag & FLAG_LEFT )
    fmt += "-";
  if ( flag & FLAG_CENTER )
    fmt += "|";
  if ( flag & FLAG_COLUMN )
    fmt += "=";
  if ( pad == "" )
    fmt += "' '";
  else if ( pad )
    fmt += "'"+pad+"'";
  if ( width )
    fmt += to_string( width );
  fmt += "s";

  if ( flag & FLAG_CAP )
    str = capitalize( str );

  if ( pre )
    str = pre + str;
  if ( post )
    str += post;

  return sprintf( fmt, str );
}

varargs string hostuptime( mixed flag, mixed width, string pad, string pre, string post ) {
  return format_result( implode(map(({mixed *})GAMECLOCK->QueryUptime(), #'to_string/*'*/), " "),
			flag, width, pad, pre, post );
}

varargs string hostname_long( mixed flag, mixed width, string pad, string pre, string post ) {
  return format_result( MUDNAME, flag, width, pad, pre, post );
}

varargs string hostname_short( mixed flag, mixed width, string pad, string pre, string post ) {
  return format_result( MUDSHORT, flag, width, pad, pre, post );
}

varargs string hostip( mixed flag, mixed width, string pad, string pre, string post ) {
  return format_result( __HOST_IP_NUMBER__, flag, width, pad, pre, post );
}

varargs string hostport( mixed flag, mixed width, string pad, string pre, string post ) {
  return format_result( to_string(query_mud_port()), flag, width, pad, pre, post );
}

varargs string hostudp( mixed flag, mixed width, string pad, string pre, string post ) {
  return format_result( to_string(query_udp_port()), flag, width, pad, pre, post );
}

varargs string hostdriver( mixed flag, mixed width, string pad, string pre, string post ) {
  string s;
  if (-1 == member(__VERSION__, '@'))
    s = "LDMud " __VERSION__;
  else
    s = "Amylaar " __VERSION__;
  return format_result( s, flag, width, pad, pre, post );
}

varargs string hostlib( mixed flag, mixed width, string pad, string pre, string post ) {
  return format_result( MUDSHORT" "+(({string})LIBVERSION_D->MudlibVersion()), flag, width, pad, pre, post );
}

varargs string hostlocation( mixed flag, mixed width, string pad, string pre, string post ) {
  return format_result( ({string})COUNTRY_D->GetCountry(__HOST_IP_NUMBER__, 1),
			flag, width, pad, pre, post );
}

/*
******************************************************************************
** make_rwho: create the rwho message
**  sort-closure: sorts players and wizards based on the realname, but first
**                all players and then all wizards
******************************************************************************
*/

private int who_sort( object a, object b ) {
  return ( (({string})a->QueryRealName()||"") > (({string})b->QueryRealName()||"" ) );
}

string make_rwho() {
  object * u;
  int i, uc, ic;
  string ret, tx, ty, rhb;

  u = sort_array( users(), #'who_sort /* ' */ );

  if ( rhb = read_file( "/etc/RWHO_BANNER" ) ) {
    ret = process_string( rhb );
  }
  else
    ret = "";

  ret += sprintf( "%78'-'s\n", "" );

  for( i = 0; i < sizeof( u ); i++ ) {
    if ( ({int})u[i]->QueryInvis() )
      continue;
    if ( query_user_level( u[i] ) )
      ty = "- " + query_user_tag( u[i] ) + " -";
    else if ( IS_HLP( u[i] ) )
      ty = "- Hlp -";
    else
      ty ="";
    tx = ({string})u[i]->Short();
    if ( ! tx || ( tx == "" ) )
      continue;
    tx = capitalize(tx);

    ret += sprintf( "%c%-=47s %|10s [%s]\n", tx[0], tx[1..], ty, ({string})COUNTRY_D->GetCountry(u[i], 0) );
    uc++;
    if ( query_idle(u[i]) > 300 )
      ic++;
  }

  ret += sprintf( "%|'-'78s\n", sprintf(" %d user%s online, %d idle ",uc, ( ( uc == 0 ) || ( uc > 1 ) ) ? "s" : "", ic ) );

  return ret;
}

void udp_who(mapping data) {
  INET_D->send_packet( data[I2H_NAME],
		    ([
		      I2H_REQUEST: I2R_REPLY,
		      I2H_RECIPIENT: data[I2H_SENDER],
		      I2H_ID: data[I2H_ID],
		      I2H_DATA: make_rwho()
		     ])
		    );
}

void create() {
  seteuid(getuid());
}

