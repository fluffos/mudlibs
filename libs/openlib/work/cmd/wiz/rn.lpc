/*  -*- LPC -*-  */
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

#include <command.h>
#include <daemons.h>

#define display(X) message("system", X, this_player())
#define VERSION "0.1"

void read_loop(string newsgroup, int* info, int current_post, string input);

int
main()
{
  display("MUD ReadNews v"+VERSION+ "  Created by Tim@UltraLib.\n\n"
	  "Type ? for help.\n"
	  ": ");
  input_to("main_loop");
  return 1;
}

string*
format_post(mixed* post)
{
  return ({ "Date: " + ctime(post[0]),
	    "Subject: " + post[2],
	    "Author: " + post[3] + "\n" }) + explode(post[4], "\n");
}

void
main_loop(string input)
{
  string* args = explode(input, " ")[1..];

  switch(input[0]) {
  case 0:
    /* Blank line or input == "" */
    break;
  case '?':
    display("Help for rn:\n"
	    "g <group>          Goto 'group' and begin reading.\n"
	    "p <group>          Post a message to group.\n"
	    "l                  List known newsgroups.\n"
            "q                  Quit RnAdmin.\n");
    break;
  case 'p':
    if( sizeof(args) != 1 )
    {
      display("Failed command.\n");
      break;
    }
    else
    {
      if( !(NEWSSERVER->get_group_info(args[0])) )
      {
	display(query_notify_fail());
	break;
      }
      display("Subject: ");
      input_to("create_post", 0, args[0]);
      return;
    }
  case 'g':
    if( sizeof(args) != 1 )
    {
      display("Failed command.\n");
      break;
    }
    else
    {
      int* groupinfo = NEWSSERVER->get_group_info(args[0]);
      if( groupinfo )
      {
	mixed* post;

	while( !(post = NEWSSERVER->get_post(args[0], groupinfo[0])) )
	{
	  if( groupinfo[0] > groupinfo[2] ) break;
	  groupinfo[0]++;
	}

	if( !post )
	{
	  display("No unread messages.\n");
	  break;
	}

	display(sprintf("Entering %s (%d/%d)\n", args[0],
			groupinfo[2], groupinfo[1] - groupinfo[0]));

	this_player()->more(format_post(post),
		    (: read_loop, args[0], groupinfo, groupinfo[0], "" :));
	return;
      }
      else
	display(query_notify_fail());
    }
    break;
  case 'l':
  {
    mixed* list = NEWSSERVER->get_group_list();
    string text = "";

    foreach(mixed* groupinfo in list)
      text += sprintf("%s: %d-%d\n", groupinfo...);

    this_player()->more(explode(text, "\n"), (: main_loop, "" :));
    return;
  }
  case 'q':
    display("Exiting.\n");
    return;
  default:
    display("Unknown command.\n");
  }
  display(": ");
  input_to("main_loop");
}

void
read_loop(string newsgroup, int* info, int current_post, string input)
{
  if( input != "q")
    display(sprintf("%%^INVERSE%%^%s #%d %%^RESET%%^[npq]: ",
		    newsgroup, current_post));

  switch(input) {
  case "":
    break;
  case "q":
    return main_loop("");
  case "n":
  {
    mixed* post;

    while( !post && current_post < info[2] )
    {
      post = NEWSSERVER->get_post(newsgroup, ++current_post);
    }

    if( !post )
    {
      display("No more messages.\n");
      display(sprintf("%%^INVERSE%%^%s #%d %%^RESET%%^[npq]: ",
		      newsgroup, current_post));
      break;
    }

    this_player()->more(format_post(post),
			(: read_loop, newsgroup, info, current_post, "" :));
    return;
  }
  case "p":
  {
    mixed* post;

    while( !post && current_post > 1 )
    {
      post = NEWSSERVER->get_post(newsgroup, --current_post);
    }

    if( !post )
    {
      display("No more messages.\n");
      display(sprintf("%%^INVERSE%%^%s #%d %%^RESET%%^[npq]: ",
		      newsgroup, current_post));
      break;
    }

    this_player()->more(format_post(post),
			(: read_loop, newsgroup, info, current_post, "" :));
    return;
  }
  }
  input_to((: read_loop, newsgroup, info, current_post :));
}

void
do_post(string* buf)
{
  if( sizeof(buf) < 2 )
    display("Post corrupted. Aborting.\n");
  else
  {
    if( NEWSSERVER->new_post(buf[0], "no-thread", buf[1],
			     this_player()->query_name(),
			     implode(buf[2..], "\n") + "\n") )
      display("Article Posted.\n");
    else
      display("Post failed: "+ query_notify_fail());
  }
  return main_loop("");
}

void
create_post(string subj, string group)
{
  EDITOR_D->edit((: do_post :), ({ group, subj }));
}
