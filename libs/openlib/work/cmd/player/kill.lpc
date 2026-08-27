/*  -*- LPC -*-  */
//
// Copyright (C) 1996 Eric Peters (epeters@netcom.com)
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
// Basic kill command.  Orig by Casper 10/14/95
//
// 09.05.96  Tim:  changed to use switch(), cleaned up a bit
//
#include <daemons.h>
#include <command.h>
 
int main(string str)
{
  object victim;
  int foo;
 
  if( !str )
    return notify_fail("Kill what?\n");

  if( !(victim = present(str, environment(this_player()))) )
    return notify_fail("There is no "+str+" here.\n");

  foo = COMBAT_D->kill_ob(this_player(), victim);
  // Returns:
  // 1 for non-living target
  // 2 for attacking self
  // 3 for unallowed combat
  // 4 for victim not present
  // 0 on success

  switch( foo )
  {
  case 0:
    return 1;  // success
  case 1:
    return notify_fail("You can't attack that which does not fight.\n");
  case 2:
    return notify_fail("You don't REALLY want to kill yourself.\n");
  case 3:
    return notify_fail("You can't bring yourself to do that.\n");
  case 4:
    return notify_fail("You can if you want, but they ain't about.\n");
  default:
    return notify_fail("error: tell a wiz that the kill command needs "
		       "looked at.\n");
  }
}
