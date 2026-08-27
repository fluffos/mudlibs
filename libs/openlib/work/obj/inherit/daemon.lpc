//  -*- LPC -*-
// daemon.c:  inherited by daemons (go figure) and commands
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
 
#pragma save_binary
#include "daemon.h"

void
create()
{
}

int
remove()
{
// code to be done on destruct() here
}


// Only here for Intermud3 compatability... (remove later)

void
Destruct()
{
  destruct(this_object());
}

// You can't shadow daemons

int
query_prevent_shadow()
{
  return 1;
}

void
SetNoClean(int i)
{
}
