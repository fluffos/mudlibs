// home.c: transport user to their ~/workroom
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
// -=Painfully coded by resident idiot Kyricc=-
//
// 10/18/95  Tim:  changed the find_object() to load_object() which also
//                 acts like find_object() if the obj is already loaded.
//                 Took out the line with the new() so we're not cloning a
//                 workroom (this was dumb mistake on my part).

#include <command.h>

int
main (string arg)
{
  string workroom, name;
  object me, ob;

  me = this_player();
  name = me->query_cap_name();

  workroom = RESOLVE_PATH("~/workroom");

  ob = load_object(workroom);

  if(!ob)
    return notify_fail("You do not have a workroom!\n");

  tell_room(environment(this_player()),
	    name + " hears his mother calling and runs home to mommy!\n",
	    ({this_player()}));

  me -> move(ob);
  me -> force_me("look");
  return 1;
}
