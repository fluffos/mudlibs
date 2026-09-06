/*--------------------------------------------------------------------------
 *  /p/daemons/dict.c --  Dict server for OSB
 *
 *  Copyright (C) 1997 by One Step Beyond.
 *  All Rights Reserved.
 *  Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 *  28-jun-97 [tune, mica]  Creation
 *  29-jun-97 [tune]        Added mega-logging to make sure sockets all get
 *                          closed & cleaned up properly. (temporary)
 *  25-jul-97 [mica]        Improved speed, timeout-handling
 *
 * NOTE: lambda callout is needed for selective callout removal
 *--------------------------------------------------------------------------
 * TODO: Think about a german/english dict.
 * Leo-G/E-Dict: http://wais.leo.org/cgi-bin/dict-search.pl
 *   Request: http://wais.leo.org/cgi-bin/dict-search.pl?search=<pattern>
 *   In <pattern> replace whitespace by +
 */

#include <properties.h>
#include <socket.h>
#include <macros.h>
#include <msgclass.h>
#include <daemons.h>

#define SCRIPT       ""
#define DICT_ADR     "206.74.122.3"
#define PORT         2628
#define DICT_LOG     "dict"
#define DICT_TIMEOUT 30

object s;

/* users mapping:
 *
 * key     : socket object for the query
 * value 0 : player-object that made the query
 * value 1 : stores received data
 * value 2 : the string to query
 * value 3 : the timeout lambda closure
 */

mapping users;

/* ------------------------------------------------------------
 *  Stores our user names
 */

void create()
{
  if(sizeof(explode(object_name(this_object()), "#")) != 1)
  {
    // send channel err msg
    raise_error("Cloning dict daemon is not supported!! Aborting\n");
    return;
  }
  seteuid(getuid(this_object()));
  users = ([]);
  log_file(DICT_LOG, ctime() + sprintf(" Creation: %O \n", this_object()) );
}

/*  ------------------------------------------------------------
 *   Parses out the html of the dict response
 */

private string parse_data(string f)
{
  int i, ix;

  if( (i = strstr(f, "DEFINE", 0)) == -1)
    return "Term not found in dict or dict isn't responding";

  if( (ix = strstr(f, "</pre>")) == -1)
    return f[i..] + "Dict entry may have been truncated\n";

  f = f[i..ix-1];
  return f;
}

/* ------------------------------------------------------------
 *  Called when we receive something
 */

private void read_callback( object skt, string data )
{
  if(!stringp(data)) return;

  users[skt, 1] += data;

}

/* ------------------------------------------------------------
 *   Called when the socket is ready to be used, i.e. connected
 */

private void ready_callback( object skt, mixed data )
{
  string request;
  string str;

  if ( ! users[skt] )
    return;

  str = users[skt,2];

  request = "GET " + SCRIPT + str
         + " HTTP/1.0\n"
         + "Accept: text/html\n"
         + "Accept: text/plain\n"
         + "User-Agent: OSB Godzilla/1.0b\n"
         + "Content-length:" + sizeof(str) + "\n\n";

  skt->send( request );
  log_file(DICT_LOG, ctime() + sprintf(" Request sent: %O \n", this_object()) );
}

/* ------------------------------------------------------------
 *  Called when the socket closes (irregulary with error maybe)
 */

public void close_callback( object skt, string err )
{
  object player;
  string data;

  if ( ! users[skt] )
    return;

  log_file(DICT_LOG, ctime() + sprintf(" Socket closed: %O \n", this_object()) );
  player = users[skt, 0];

  if(player)
  {
    data = parse_data(users[skt,1]);
    msg_object( player, CMSG_GENERIC|MMSG_MORE|MMSG_NOWRAP,
      (data) );
  }

  if ( closurep( users[skt,3] ) && to_object( users[skt,3] ) )
    while( remove_call_out( users[skt,3] ) != -1 ) ;
}

/* ------------------------------------------------------------
 *  The main dict function
 */

public void time_out( object skt)
{
  if ( skt )
  {
    if ( users[skt] )
      tell_object(users[skt, 0], "Dict timed out\n");

    log_file(DICT_LOG, ctime() + sprintf(" Timed out: %O \n", this_object()));
    skt->close();
  }
}

public mixed dict( string str )
{
  object ob;
  closure toc;

  if ( ! str )
    return "Usage: dict <word to look up>\n";


  s = clone_object( SOCKET );
  s->open( SKT_STYLE_CONNECT_STREAM, DICT_ADR, PORT,
	   SF( read_callback ),
	   SF( ready_callback ),
	   SF( close_callback ) );

  toc = lambda( ({ SYM(s) }), ({ SF( time_out ), SYM(s) }) );
  users += ([ s: this_player() ; ""; str; toc ]);

  call_out( toc, DICT_TIMEOUT, s );
  return 1;
}


/* ------------------------------------------------------------*/

public mapping query_users()
{
  return users;
}


/* --------------------------------------------------------
 *  Clean up functions
 */

reset()
{
  m_indices(users); // cleans out mapping of dead objects
  log_file(DICT_LOG, ctime() + sprintf(" Dict reset: %O \n", this_object()) );
}

remove()
{
  object *arr, player;
  int x;

  if ( arr = m_indices(users) )
  {
    for(x = 0; x < sizeof(users); x++)
    {
      if( player = users[arr[x], 0] )
      {
        tell_object(player,
          "Dict server shutting down, please try again in a few minutes.\n");
      }
      arr[x]->close();  // close the socket
      if ( closurep( users[arr[x],3] ) && to_object( users[arr[x],3] ) )
        while( remove_call_out( users[arr[x],3] ) != -1 ) ;
    }
    // map_objects(arr, "close");
    log_file(DICT_LOG, ctime() + " " + sizeof(arr) +
      " sockets forcefully closed.\n" );

  }
  log_file(DICT_LOG, ctime() + sprintf(" Dict destructed: %O \n", this_object()) );
  destruct( this_object() );
}

clean_up()
{
  log_file(DICT_LOG, ctime() +
    sprintf(" Dict cleaned up: %O \n", this_object()) );
  remove();
  return this_object() && 1;
}
