//  -*- LPC -*-
// queue.c:  Object which implements a queue
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
// written by Tim 2/8/96
//
// See queue.h for documentation

#include "queue.h"

private mixed* queue;                    // queue[0] is first out

void
create()
{
  queue = ({});
}

int
save(string file)
{
  return save_object(file);
}

int
restore(string file)
{
  return restore_object(file);
}

void
queue(mixed item)
{
  queue += ({ item });
}

mixed
pull()
{
  mixed ret = queue[0];

  queue = queue[1..];

  return ret;
}

boolean
queued(mixed item)
{
  return member_array(queue, item) != -1;
}

void
dequeue(mixed item)
{
  queue -= ({ item });
}

boolean
is_empty()
{
  return (!sizeof(queue));
}
