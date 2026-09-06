/*--------------------------------------------------------------------------
 * /std/player/bin/dict.c  --  To access the dict daemon
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * [Mica] 30Jun97 fixed a small bug which lead to dict_server beeing invalid
 */

#include <properties.h>
#include <daemons.h>


public int main( string arg ) 
{
  object dict_server;

  if(!arg)
  {
    tell_object(this_player(), "Usage: dict <word to look up>\n");
    return 1;
  }

  if(!stringp(arg))
    return 0;

  if(!dict_server = find_object(DICT_D))
    dict_server = load_object(DICT_D);

  write("One moment please...\n");
  dict_server->dict(arg);
  return 1;
}
