/*  -*- LPC -*-  */
// maild.c: mudlib mail daemon.  See maild.h for details.
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

#include <mudlib.h>
#include <net/daemons.h>
#include "mail_d.h"

inherit DAEMON;

mapping open_boxes;

#ifdef DEBUG
mapping
dump_ob()
{
  return copy(open_boxes);
}
#endif

void
create()
{
  daemon::create();
  open_boxes = ([]);
}

varargs
int
check_mail(string username, int check_new)
{
  object mbox = new(MAILBOX);
  int ret;

  unguarded((: call_other, mbox, "restore_mailbox", username :), 1);
  
  if(!check_new) {
    ret = mbox->get_mesg_count();
  } else {
    ret = mbox->get_new_mesg_count();
  }

  destruct(mbox);
  return ret;
}

/*--------------------------- Read Loop ------------------------------------*/

void
cmd_mail_loop(object mbox)
{
  int start, count = mbox->get_mesg_count();
  open_boxes += ([ this_player()->query_name() : mbox ]);

  printf("MUD Mail v%s  Created by Tim@UltraLib.\n\n", VERSION);
  printf("%i unread messages of %i in mailbox.\n",
	 mbox->get_new_mesg_count(), count);
  write("Type ? for help\n\n");

  // Get to 1st unread message
  for(start = 1; start < count; start++)
    if( mbox->is_unread(start) ) break;
  reenter_mail_loop(mbox, start, count);
}

// Use this as a callback for more()
void
reenter_mail_loop(object mbox, int curr, int count)
{
  if( count )
    printf("%i of %i >> ", curr, count);
  else
    write("No messages>> ");

  input_to( (:cmd_mail_loop2:), 0, mbox, curr, count );
}  

void
cmd_mail_loop2(string input, object mbox, int curr, int count)
{
  string* args = explode(input, " ");
  string cmd;
  int i;

  if(!sizeof(args)) {
    cmd = "";
  } else {
    cmd = args[0];
    args -= ({ cmd });
  }

  if( !count && cmd != "q" && cmd != "Q" && cmd != "?" )
    return reenter_mail_loop(mbox, curr, count);
      
  // This condition could exist if count==curr==3 and we deleted 3
  if(curr > count)
    curr = count;

  switch(cmd) {
  // show help
  case "?":
    return print_help(mbox, curr, count);
    
  // save mailbox (commit changes)
  case "s":
    mbox->save_mailbox();
    printf("Changes saved: %i messages deleted.\n",
	   count - (count = mbox->get_mesg_count()));
    curr = 1;
    break;
    
  // save & quit
  case "q":
    mbox->save_mailbox();
    printf("Changes saved: %i messages deleted.\n",
	   count -  mbox->get_mesg_count());
  // quit without saving
  case "Q":
    map_delete(open_boxes, this_player()->query_name());
    destruct(mbox);
    write("Exiting.\n");
    return;

  // print headers
  case "h":
    return print_headers(mbox, curr, count);

  // next unread message
  case "":
    for(;curr < count; curr++)
      if( mbox->is_unread(curr) )
	break;
    return print_message(mbox, curr, count);

  // next message
  case "n":
    if(curr < count) {
      curr++;
      return print_message(mbox, curr, count);
    } else {
      write("No next message.\n");
    }
    break;

  // previous message
  case "p":
    if(curr > 1) {
      curr--;
      return print_message(mbox, curr, count);
    } else {
      write("No previous message.\n");
    }
    break;

  // delete messages
  case "d":
    delete_message(mbox, count, curr, args);
    break;

  // save messages to file
  case "w":
    save_message(mbox, curr, args);
    break;

  // reply to current
  case "r":
    printf("Replying to %s...\n", mbox->get_from(curr));
    cmd_send_mesg2("Re: " + mbox->get_subj(curr),
		   lower_case(mbox->get_from(curr)),
		   (: reenter_mail_loop, mbox, curr, count :));
    return;

  // show message by number
  default:
    if(sscanf(cmd, "%d", i) == 1) {
      if(i > 0 && i <= count) {
	curr = i;
	return print_message(mbox, curr, count);
      } else {
	write("Invalid message number.\n");
      }
    } else {
      write("Unknown command.\n");
    }
  }
  reenter_mail_loop(mbox, curr, count);
}

void
print_message(object mbox, int curr, int count)
{
  mbox->mark_read(curr);                      // mark message as read

  this_player()->more(explode(mbox->get_mesg(curr), "\n"),
		      (: reenter_mail_loop, mbox, curr, count :) );
}

void
print_help(object mbox, int curr, int count)
{
  string text =
@ENDTEXT
Help for Mail System:

?                Show this help message.
d [message #]    Delete current message if no argument.
h                Print message headers.
n                Show next message.
p                Show previous message.
<enter>          Show next _unread_ message.
<msg number>     Show message number given.
s                Save mailbox. (Commit changes)
q                Quit and save state of mailbox.
Q                Quit without saving changes to mailbox.
r                Reply to current message.
w [filename]     Append current message to file. (default: ~/mbox)
                 Appends to ~/mbox if no filename given.
ENDTEXT;

  this_player()->more(explode(text, "\n"),
		      (: reenter_mail_loop, mbox, curr, count :));
}

void
print_headers(object mbox, int curr, int count)
{
  string* text = allocate(count + 1);

  text[0] = "Headers:";
  
  for(int i = 1; i <= count; i++) {
    string from = mbox->get_from(i);
    int idx;

    // Remove @mud name if from this mud
    idx = strsrch(from, "@"+ mud_name());
    if( idx != -1 ) from = from[0..idx - 1];
      
    text[i] = sprintf("%c%c %-3i  %:-20s %:-48s",
		      (i == curr ? '>' : ' '),
		      (mbox->is_del(i) ? 'D' :
		                         (mbox->is_unread(i) ? 'N' : 'R')),
		      i, from, mbox->get_subj(i));
  }

  this_player()->more(text, (: reenter_mail_loop, mbox, curr, count :));
}

void
delete_message(object mbox, int count, int curr, string* args)
{
  int i;

  if(!sizeof(args)) {
    // case no args given--delete current message
    mbox->mark_del(curr);
    write("Message marked for deletion.\n");
  } else {
    // case there's an argument
    if(!sscanf(args[0], "%d", i)) {
      write("Must supply a numerical argument.\n");
      return;
    }

    if(i > 0 && i <= count) {
      mbox->mark_del(i);
      printf("Marked message %d for deletion.\n", i);
    } else {
      write("Invalid message number.\n");
    }
  }
}

void
save_message(object mbox, int curr, string* args)
{
  string savefile;

  if(!wizardp(this_player())) {
    write("Not a player command.\n");
    return;
  }
  
  if(!sizeof(args)) {
    savefile = HOME_DIR(this_player()) + "/mbox";
  } else {
    savefile = RESOLVE_PATH(args[0]);
  }

  write_file(savefile, (string) mbox->get_mesg(curr));

  printf("Appended message to %s.\n", savefile);
}

/*-------------------------- Send Dialog -----------------------------------*/

void
cmd_send_mesg(string tolist, function call_func)
{
  write("Subject: ");
  input_to((: cmd_send_mesg2 :), 0, tolist, call_func);
}

void
cmd_send_mesg2(string input, string tolist, function cf)
{
  EDITOR_D->edit((: cmd_send_mesg3, input, tolist, cf :));
}

void
cmd_send_mesg3(string subject, string tolist, function cf, string* lines)
{
  if( !lines ) {
    write("Mail aborted.\n");
    if( cf ) evaluate(cf);
  } else {
    write("CC:");
    input_to((: cmd_send_mesg4 :), 0, tolist, subject,
	   implode(lines, "\n") + "\n", cf);
  }
}

void
cmd_send_mesg4(string cclist, string tolist, string subject,
	       string contents, function cf)
{
  mapping to_list, cc_list;
  string* tmp_tolist;
  string* tmp_cclist;
  string* userlist;
  string from = this_interactive()->query_cap_name();

  to_list = filter_remote_users(explode(tolist, ","));
  cc_list = filter_remote_users(explode(cclist, ","));

  //  from = sprintf("%s@%s", from, mud_name());

  foreach(string mud in distinct_array(keys(cc_list) + keys(to_list))) {
    string* bcclist = ({});
    
    if( mud == mud_name() )
      send_mail(to_list, cc_list, bcclist, from, time(), subject, contents);
    else
    {
      SERVICES_D->eventSendMail(mud,
				from,
				to_list,
				cc_list,
				bcclist,
				time(), subject, contents);
      if( this_player() ) printf("Mail queued to %s\n", mud);
    }
  }
  if( cf ) evaluate(cf);
}

/* This puts a list of users in the form of ([ mud_name : ({ user list }) ]) */

private mapping
filter_remote_users(string* arr)
{
  mapping ret = ([]);

  foreach(string addr in arr)
  {
    string user, host;
    
    if( sscanf(addr, "%s@%s", user, host) == 2)
    {
      user = replace_string(user, " ", "");
      if( (host = INTERMUD_D->GetMudName(host)) ) {
	if( !ret[host] )
	  ret[host]  = ({ user });
	else
	  ret[host] += ({ user });
      }
      else if( this_player() )
	printf("%s: no such host.\n", host);
    }
    else
    {
      if( !ret[mud_name()] )
	ret[mud_name()] = ({ addr });
      else
	ret[mud_name()] += ({ addr });
    }
  }
  
  return ret;
}

void
send_mail(mapping to_list, mapping cc_list, string* bcc_list, string from,
	  int time, string subject, string content)
{
  string localmesg;
  object tmpmbox = new(MAILBOX);
  string* userlist;

  function collapse = function(mapping x)
                      {
			string ret = "";
			foreach(string mud, string* list in x)
			  ret += implode(list, sprintf("@%s, ", mud)) +
			         "@" + mud;
			return ret;
		      };

  if( !content || !to_list || !cc_list || !bcc_list || !from || !subject )
    return;
  
  if( content[<1] != '\n' )
    content += "\n";
  
  localmesg = sprintf("To: %s\n"
		      "From: %s\n"
		      "Date: %s\n"
		      "Subject: %s\n"
		      "CC: %s\n"
		      "-------\n"
		      "%s",
		      evaluate(collapse, to_list),
		      from, ctime(time), subject,
		      evaluate(collapse, cc_list),
		      content);

  userlist = bcc_list + (cc_list[mud_name()] ? cc_list[mud_name()] : ({}))
    + (to_list[mud_name()] ? to_list[mud_name()] : ({}));
  
  foreach(string user in userlist) {
    object ob = find_player(user);
    user = lower_case(user);
    /*
     * if user is in mail right now
     */
    if( open_boxes[user] ) {
      ((object) open_boxes[user])->add_mesg(subject, from, localmesg);
      if( this_player() ) printf("Mail sent to %s.\n", user);
      if( ob )
	message("system", "%^BELL%^You have %^GREEN%^NEW%^RESET%^ mail.\n",ob);
      continue;
    }
    if( !unguarded((: call_other, tmpmbox, "restore_mailbox", user:), 1) ) {
      log_file("maild", sprintf("error loading mbox for %s\n", user));
      /*
       * Couldn't load an existing mailbox for this user.
       * We need to do this if the box doesn't load so the messages in
       * the previous box aren't still hanging around.
       */
      unguarded((: call_other, tmpmbox, "reinit_mailbox", user :), 1);
    }
    tmpmbox->add_mesg(subject, from, localmesg);
    if( !unguarded((: call_other, tmpmbox, "save_mailbox":), 1) ) {
      log_file("maild", sprintf("error saving mbox for %s\n", user));
      if(this_player())
	printf("%%^RED%%^Failed%%^RESET%%^ to send mail to %s.\n", user);
    } else {
      if( this_player() ) printf("Mail sent to %s.\n", user);
      if( ob )
	message("system", "%^BELL%^You have %^GREEN%^NEW%^RESET%^ mail.\n",ob);
    }
  }
  destruct(tmpmbox);
}
