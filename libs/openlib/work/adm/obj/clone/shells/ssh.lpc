//  -*- LPC -*-
// ssh.c: a simple shell for a non-wiz user
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
// written by Tim 02.28.96
//

#include <shells.h>

object user;

/*
 * Required
 */
string shell_id();                                 // returns shell id string
string* query_path();

/*
 * Masked Functions
 */
void write_prompt();                               // prints normal prompt
string process_input(string input);                // process player input
object shell_init(object user);                    // called by logind
int cmd_set(string arg);                           // set env variables

/*
 * Implementation
 */

string 
shell_id()
{
  return "Simple Shell";
}

void
write_prompt()
{
  message("prompt", "ssh> ", user);
}

string
process_input(string input)
{
  return input;
}

object
shell_init(object owner)
{
  if(user) return;
  
  user = owner;
  return shadow(owner);
}

private int
cmd_set(string arg)
{
  string var, val;

  if(!arg) {
    foreach(string key, mixed v in this_player()->get_environment())
      printf("%-10s   %-O\n", key, v);
  } else {
    if( sscanf(arg, "%s %s", var, val) != 2 )
      return notify_fail("usage: set <var> <val>\n");
    else
      this_player()->set_env(var, val);
  }
  return 1;
}

int
cmd_hook(string args)
{
  if(previous_object() != user) return 0;

  switch(query_verb()) {
  case "set":
    return cmd_set(args);
  default:
    return user->cmd_hook(args);
  }
}

string* query_path() { return DEFAULT_PATHS; }
