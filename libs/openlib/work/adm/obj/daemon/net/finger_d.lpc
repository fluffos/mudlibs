//  -*- LPC -*-
// fingerd.c:  a finger server compatible with Unix's finger program
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
// by Tim 2/21/96

#include <daemons.h>
#include <net/config.h>
#include <net/network.h>

inherit TCP_SERVER;

mapping input;

void create();
void setup();

void
create()
{
  server::create();
  call_out("setup", 1);
  input = ([]);
}

void
setup()
{
  eventListenSocket(mud_port() + 79, STREAM);
}

void
eventRead(int fd, string val)
{
  int idx;

  if(!val) return;

  if(!input[fd])
    input[fd] = val;
  else
    input[fd] += val;


  if( (idx = strsrch(input[fd], "\r\n")) != -1 ) {
    string user = input[fd][0..idx-1];

    if(!strlen(user)) user = 0;
// log_file("tfd", sprintf("%O %i\n", input[fd][0..idx-1], idx));
    eventWrite(fd, FINGER_D->GetFinger( user ), 1);
    map_delete(input, fd);
  }
}
