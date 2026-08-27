//  -*- LPC -*-
//
// Copyright (C) 1996 Jason Borgmann (kyricc@inetnebr.com)
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
// -=Coded by the local idiot Kyricc=-
//

#include <mudlib.h>

inherit MONSTER "/human";

void
create()
{
  object weap;

  ::create();
  set_undead();
  set_name("zombie");
  set_short("Zombie");
  set_long("A badly decayed corpse that has, somehow, come back to life\n");
  set_move_around(15);
  weap = new("/obj/examples/weapon");
  weap->move(this_object());
  do_wield(weap, 1, 1);
}
