//  -*- LPC -*-
// ucache.c:  Daemon for I3 ucache service
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
// created 11 Apr 1996 Tim@Dysfunctional Mud
//

#include <mudlib.h>
#include <dirs.h>
#include <net/daemons.h>
#include <net/save.h>

#define MAX_MUDS 60
#define MAX_USERS_PER_MUD 60

mapping ucache_info;  // mapping of mappings

void save_me() { save_object(SAVE_UCACHE_D); }

void
create()
{
  ucache_info = allocate_mapping(MAX_MUDS);
  restore_object(SAVE_UCACHE_D, 1);
}

int
remove()
{
  save_me();
  return 0;
}

mapping
dump_cache()
{
  return copy(ucache_info);
}

void
cache(string mud, string user, string visname, int gender)
{
  if( file_name(previous_object()) != SERVICES_D ) return;

  if( !ucache_info[mud] ) {
    if( sizeof(ucache_info) == MAX_MUDS )
      map_delete(ucache_info, keys(ucache_info)[0]);
    ucache_info[mud] = allocate_mapping(MAX_USERS_PER_MUD);
  }
  if( sizeof(ucache_info[mud]) == MAX_USERS_PER_MUD )
    map_delete(ucache_info[mud], keys(ucache_info[mud])[0]);
  ucache_info[mud][user] = ({ visname, gender });
  save_me();
}

string*
get_info(string mud, string user)
{
  if( ucache_info[mud] )
    return copy(ucache_info[mud][user]);
  else
    return 0;
}
