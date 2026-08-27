//  -*- LPC -*-
// mail.c:  I3 'mail' service implementation
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
// Created by Tim@Dysfunctional Mud 3.31.96
//

#include <daemons.h>
#include <net/daemons.h>

#define SERVICE_MAIL

private mapping mail_ids;

private int
new_mail_id()
{
  int* ids = keys((mail_ids ? mail_ids : mail_ids = ([])));

  if( sizeof(ids) )
    return ids[<1]++;
  else
    return 0;
}

void
eventReceiveMail(string mudname, mixed* packet)
{
  if( file_name(previous_object()) != OOB_D ) return;
  MAIL_D->send_mail(packet[3], packet[4], packet[5], packet[2] +"@"+mudname,
		    packet[6], packet[7], packet[8]);
  OOB_D->OOBSendPacket(mudname, ({ "mail-ack",
				   ([ packet[1] : ({}) ]) }));
}

void
eventReceiveMailAck(mixed* packet)
{
  if( file_name(previous_object()) != OOB_D ) return;
  foreach(int id in keys((mapping) packet[1]))
    log_file("maild", sprintf("Got ACK from %s\n", mail_ids[id]));
}

void
eventSendMail(string target_mudname, string from, mapping to_list,
	      mapping cc_list, string* bcc_list, int time, string subject,
	      string contents)
{
  int id = new_mail_id();
  mail_ids[id] = target_mudname;
  OOB_D->OOBQueuePacket(target_mudname, ({ "mail",
					   id,
					   from,
					   to_list,
					   cc_list,
					   bcc_list,
					   time,
					   subject,
					   contents 
					   }) );
}
