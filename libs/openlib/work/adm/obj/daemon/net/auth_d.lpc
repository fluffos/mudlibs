//  -*- LPC -*-
// authd.c:  authentication daemon
//           keeps track of session keys for this mud and to other muds
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
// created 12.8.95 by Tim@Dysfunctional Mud
//

#include <mudlib.h>
#include <net/daemons.h>

// Debug stuff.  Does what you think it does.
#undef DEBUG

// Debug file passed to log_file()
#ifdef DEBUG
#define DBFILE "authd"
#endif

class key {
  int key;
  int timestamp;
}

inherit DAEMON;

private mapping client_keys;
private mapping server_keys;

void
create()
{
  ::create();
  client_keys = ([]);
  server_keys = ([]);
}

#ifdef DEBUG
mixed*
dump_keys()
{
  return ({ "client", client_keys, "server", server_keys });
}
#endif

/*
 * clean up keymaps periodically, removing muds which have expired keys here
 * _and_ when our key to them has probably expired also
 */
void
cleanup_keys()
{
  int t = time(), shut_down = 1;

  foreach(string mud, class key k in server_keys) {
    if( (t - k->timestamp) > 600 )
      map_delete(server_keys, mud);   // key expired, discard
    else
      shut_down = 0;                  // key valid
  }

  if( shut_down ) OOB_D->close_oob_port();

  foreach(string mud, class key k in client_keys) {
    if( (t - k->timestamp) > 600 )
      map_delete(client_keys, mud);   // discard key
  }
}

/*
 * generate a new key to give to a mud with a timestamp
 */
int
generate_key(string mudname)
{
  int keyval;

  /*
   * code that sets keyval (a big number)
   */
  keyval = random(46340) * random(46340);

  if( !server_keys[mudname] ) {
    class key newkey = new(class key);

    newkey->key = keyval;
    newkey->timestamp = time();

    server_keys[mudname] = newkey;
  } else {
    ((class key) server_keys[mudname])->key = keyval;
    ((class key) server_keys[mudname])->timestamp = time();
  }

#ifdef DEBUG
  log_file(DBFILE, sprintf("generate_key: %s, %d\n", mudname, keyval));
#endif
  return keyval;
}

/*
 * store a key recieved from another mud used to connect there
 */
void
store_key(string mudname, int keyval)
{
#ifdef DEBUG
  log_file(DBFILE, sprintf("store_key: %s, %d\n", mudname, keyval));
#endif
  
  if( !client_keys[mudname] ) {
    class key newkey = new(class key);

    newkey->key = keyval;
    newkey->timestamp = time();

    client_keys[mudname] = newkey;
  } else {
    ((class key) client_keys[mudname])->key = keyval;
    ((class key) client_keys[mudname])->timestamp = time();
  }
}

/*
 * Authenticate a mud that is trying to connect
 * 1 = pass, 0 = fail
 */
int
authenticate_mud(string mudname, int keyval)
{
  /*
   * no class key on record
   */
  if( !server_keys[mudname] ) return 0;

  /*
   * 10min expiration check
   */
  if( time() - ((class key) server_keys[mudname])->timestamp > 600 ) return 0;

  /*
   * check for match
   */
  if( ((class key) server_keys[mudname])->key == keyval ) {
#ifdef DEBUG
    log_file(DBFILE, sprintf("authenticate_mud: %s, %d, ret=1\n",
			     mudname, keyval));
#endif
    map_delete(server_keys, mudname); // discard one-time-key
    return 1;
  } else {
#ifdef DEBUG
    log_file(DBFILE, sprintf("authenticate_mud: %s, %d, ret=0\n",
			     mudname, keyval));
#endif
    return 0;
  }
}

/*
 * returns our key to 'mudname'
 */
int
get_session_key(string mudname)
{
  if( client_keys[mudname] ) {
    int key = ((class key) client_keys[mudname])->key;
    map_delete(client_keys, mudname);  // one-time-key discard
    return key;
  } else return 0;
}
