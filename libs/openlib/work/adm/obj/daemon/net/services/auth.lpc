//  -*- LPC -*-
// auth.c:  Intermud3 'auth' service implementation
//          performs mud authentication
//          Also sends/receives oob-req packets
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
// 3.23.96  Tim  Added the oob-req stuff
//

#include <net/daemons.h>

#define SERVICE_AUTH

void
eventReceiveOOBRequest(mixed *packet)
{
  if( file_name(previous_object()) != INTERMUD_D ) return;

  AUTH_D->generate_key(packet[2]);
  OOB_D->open_oob_port();
}

void
eventSendOOBRequest(string target_mudname)
{
  INTERMUD_D->eventWrite( ({
    "oob-req",
    5,
    mud_name(),
    0,
    target_mudname,
    0 }) );
}
  
void
eventReceiveAuthRequest(mixed *packet)
{
  int key;

  if( file_name(previous_object()) != INTERMUD_D ) return;

  key = AUTH_D->generate_key(packet[2]);
  OOB_D->open_oob_port();

  INTERMUD_D->eventWrite( ({
    "auth-mud-reply",
    5,
    mud_name(),
    0,
    packet[2], /* target mud */
    0,
    key }) );
}

void
eventReceiveAuthReply(mixed *packet)
{
  if( file_name(previous_object()) != INTERMUD_D ) return;

  AUTH_D->store_key(packet[2] /* mud */, packet[6] /* key */);
}

void
eventSendAuthRequest(string target_mudname)
{
  if( file_name(previous_object()) != OOB_D )
    return;

  INTERMUD_D->eventWrite( ({
    "auth-mud-req",
    5,
    mud_name(),
    0,
    target_mudname,
    0 }) );
}
