//  -*- LPC -*-
// mail.c: mail command
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
// Written 12.10.95 by Tim (astasia@iastate.edu)
//

#include <command.h>
#include <daemons.h>

int
main(string str)
{
  object mbox;

  if( !str ) /* read mail */
  {
    string name = this_player()->query_name();
    
    mbox = new(MAILBOX);
    unguarded((: call_other, mbox, "restore_mailbox", name :), 1);

    if( !mbox->get_mesg_count() )
    {
      printf("No mail for %s.\n", capitalize(name));
      destruct(mbox);
    }
    else
      MAIL_D->cmd_mail_loop(mbox);
  }
  else /* send mail */
    MAIL_D->cmd_send_mesg(str);
  
  return 1;
}
