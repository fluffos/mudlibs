/*  -*- LPC -*-  */
// readnews_d.c:  Provides a user interface to NEWS_D
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

#include <daemons.h>
#include "readnews_d.h"


int
max(int i1, int i2)
{
  if( i1 > i2 )
    return i1;
  else
    return i2;
}

// list is made up of int's and ranges
// This function will reduce a list to a new list containing the fewest
// number of int's possible (tries to group them into ranges).
// It's ugly, but it works :)
string
condense_list(string list)
{
  string* ranges = explode(replace_string(list, " ", ""), ",");
  int* numbers;

  numbers = map(filter(ranges, (: strsrch($1, '-') == -1 :)), (: to_int :));
  numbers = sort_array(numbers, 1);
  ranges = filter(ranges, (: strsrch($1, '-') != -1 :));

  // Extend out existing ranges as far as possible...
  for(int i = 0; i < sizeof(ranges); i++)
  {
    int start, end;

    sscanf(ranges[i], "%d-%d", start, end);

    while( member_array(start - 1, numbers) != -1 )
    {
      start--;
      numbers -= ({ start });
    }

    while( member_array(end + 1, numbers) != -1 )
    {
      end++;
      numbers -= ({ end });
    }

    foreach(int num in numbers)
      if( num >= start && num <= end )
	numbers -= ({ num });

    ranges[i] = sprintf("%i-%i", start, end);
  }

  // Create new ranges where possible...
  for(int i = 0; i < sizeof(numbers); i++)
  {
    int start, end;

    start = end = numbers[i];

    while( member_array(start - 1, numbers) != -1 )
    {
      start--;
      numbers -= ({ start });
    }
    
    while( member_array(end + 1, numbers) != -1 )
    {
      end++;
      numbers -= ({ end });
    }

    if( start != end )
    {
      ranges += ({ sprintf("%i-%i", start, end) });
      numbers -= ({ numbers[i] });
      i--;
    }
  }

  // Combine ranges where possible...
  // First put them in order...
  ranges = sort_array(ranges, function(string s1, string s2)
		              { 
				if( to_int(s1) > to_int(s2) )
				  return 1;
				if( to_int(s1) == to_int(s2) )
				  return 0;
				else
				  return -1;
			      });

  for(int i = 0; i < sizeof(ranges) - 1; i++)
  {
    int start, end, startnext, endnext;

    sscanf(ranges[i], "%d-%d", start, end);
    sscanf(ranges[i+1], "%d-%d", startnext, endnext);

    if( end + 1 >= startnext )
    {
      ranges[i] = sprintf("%i-%i", start, max(end, endnext));
      ranges -= ({ ranges[i+1] });
      i--;
    }
  }
  return implode(ranges + map(numbers, (: sprintf("%i", $1) :)), ",");
}

int*
expand_list(string list)
{
  string* items = explode(list, ",");
  string* ranges = filter(items, (: strsrch($1, '-') != -1 :));
  int* numbers = map(items - ranges, (: to_int :));
  
  foreach(string range in ranges)
  {
    int start, end;
    sscanf(range, "%d-%d", start, end);
    for(int i = start; i <= end; i++)
      numbers += ({ i });
  }

  return sort_array(numbers, 1);
}

int
member_list(int number, string list)
{
  string* ranges = explode(replace_string(list, " ", ""), ",");
  int* numbers = map(filter(ranges, (: strsrch($1, '-') == -1 :)),
		     (: to_int :));
  ranges = filter(ranges, (: strsrch($1, '-') != -1 :));

  if( member_array(number, numbers) != -1 )
    return 1;

  foreach(string range in ranges)
  {
    int start, end;

    sscanf(range, "%d-%d", start, end);
    if( number >= start && number <= end )
      return 1;
  }

  return 0;
}

int
max_in_list(string list)
{
  int* numbers = map(explode(replace_string(replace_string(list, " ", ""),
					    "-", ","), ","), (: to_int :));
  int max;

  foreach(int num in numbers)
    if( num > max )
      max = num;

  return max;
}


// user command
varargs int
read_news(mapping newsrc, function call_back)
{
  class reader r = new(class reader);
  
  if( !newsrc )
  {
    mixed* groups = NEWSSERVER->get_group_list();

    message("system", "Setting up your newsrc...\n", this_player());

    newsrc = ([ ]);
    
    foreach(mixed* ginfo in groups)
    {
      newsrc[ginfo[0]] = "";
    }
  }

  r->cb = call_back;
  r->newsrc = newsrc;
  r->touched = ([ ]);
  r->group = "";  // this is important to select_thread()
  
  prompt_group(r);
  return 1;
}


varargs int
read_one_group(string newsgroup, mapping newsrc, function call_back)
{
  class reader r = new(class reader);

  r->cb = call_back;
  r->newsrc = newsrc;
  r->group = newsgroup;
  read_group(r);

  return 1;
}


// prompt the user to see if they want to read the next group

void
prompt_group(class reader r)
{
  string* list = keys(r->newsrc);

  r->prev_group = r->group;
  
  while( sizeof(list) && r->touched[r->group = list[0]] )
  {
    list = list[1..];
  }
  
  if( !sizeof(list) )
  {
    message("system", "End of newsgroups.\n", this_player());
    return evaluate(r->cb, r->newsrc);
  }

  r->touched[r->group] = 1;
  
  message("system", sprintf("Enter group %s? [ynpusgq]: ", r->group),
	  this_player());
  get_char("select_group", 0, r);
}


// process input from prompt_group()

void
select_group(string input, class reader r)
{
  message("system", "\n", this_player());
  
  switch(input[0])
  {
  case 'y':
    return read_group(r);
  case 'n':
    return prompt_group(r);
  case 'p':
    r->group = r->prev_group;
    return read_group(r);
  case 'u':
    map_delete(r->newsrc, r->group);
    message("system", "Unsubscribed.\n", this_player());
    return prompt_group(r);
  case 's':
    message("system", "Group to subscribe to: ", this_player());
    input_to("subscribe", 0, r);
    return;
  case 'g':
    message("system", "Go to group: ", this_player());
    input_to("goto", 0, r);
    return;
  case 'q':
    return evaluate(r->cb, r->newsrc);
  default:
    message("system", sprintf("Enter group %s? [ynpq]: ", r->group),
	    this_player());
    get_char("select_group", 0, r);
  }
}


void
subscribe(string group, class reader r)
{
  if( NEWSSERVER->get_group_info(group) )
  {
    r->newsrc[group] = "";
    r->group = group;
    message("system", "Subscribed.\n", this_player());
    return read_group(r);
  }
  else
  {
    string msg = query_notify_fail();

    if( !msg )
      msg = "No such group.\n";
    
    message("system", msg, this_player());
    message("system", sprintf("Enter group %s? [ynpusgq]: ", r->group),
	    this_player());
    get_char("select_group", 0, r);
  }
}


void
goto(string group, class reader r)
{
  if( !r->newsrc[group] )
  {
    message("system", "You are not subscribed!\n", this_player());
    message("system", sprintf("Enter group %s? [ynpusgq]: ", r->group),
	    this_player());
    get_char("select_group", 0, r);
  }
  else
  {
    r->group = group;
    return read_group(r);
  }
}

    
// figures out how to read the specified group

void
read_group(class reader r)
{
  r->info = NEWSSERVER->get_group_info(r->group);

  if( !r->info ||  !NEWSSERVER->can_access_group(r->group, this_player()) )
  {
    message("system", "You cannot access that group.\n", this_player());
    return evaluate(r->cb, r->newsrc);
  }
  
  if( undefinedp(r->newsrc[r->group]) )
    r->newsrc[r->group] = "";

  r->threads = NEWSSERVER->get_threads(r->group);

  // Get newsrc entry up-to-date
  if( r->info[0] != 1 )
    r->newsrc[r->group] = condense_list("1-"+ r->info[0] +
					"," + r->newsrc[r->group]);
  prompt_thread(r);
}


// Prompt the user to see if they want to read the next thread

void
prompt_thread(class reader r)
{
  if( !sizeof(r->threads) )
  {
    message("system", "No more threads.\n", this_player());
    prompt_group(r);
  }
  else
  {
    r->thread = r->threads[0];
    r->threads = r->threads[1..];
    message("system", sprintf("Read thread \"%s\"? [ynq]: ", r->thread),
	    this_player());
    input_to("select_thread", 0, r);
  }
}


// process the input of prompt_thread()

void
select_thread(string input, class reader r)
{
  switch(input[0])
  {
  case 'y':
    r->post = 0;
    return prompt_message(r);
  case 'n':
    return prompt_thread(r);
  case 'q':
    if( r->prev_group )
      return prompt_group(r); // this is how we tell if we're only readin 1 gp
    else
      return evaluate(r->cb, r->newsrc);
  default:
    message("system", sprintf("Read thread \"%s\"? [ynq]: ", r->thread),
	    this_player());
    input_to("select_thread", 0, r);
  }
}


// prompt the user to see if they want to read the next message in the 
// current thread

void
prompt_message(class reader r)
{
  mixed* post;
  int*   list = expand_list(r->newsrc[r->group]);

  // Skip non-existent and already-read posts
  while( !(post = NEWSSERVER->get_post(r->group, ++r->post)) ||
         member_array(r->post, list) != -1 )
  {
    if( r->post > r->info[1] /* last id */ )
    {
      message("system", "End of thread.\n", this_player());
      return prompt_thread(r);
    }
  }

  message("system", sprintf("Read article \"%s\"? [ynprq]: ", post[2]),
	  this_player());
  input_to("select_message", 0, r, post);
}


// process input from prompt_message()

void
select_message(string input, class reader r, mixed* post)
{
  switch(input[0])
  {
  case 'y':
    r->newsrc[r->group] = condense_list(r->newsrc[r->group] + "," + r->post);
					   
    r->prev_post = post;
    this_player()->more(({ "Date: " + ctime(post[0]), "From: " + post[3],
			   "Subject: " + post[2] }) + explode(post[4], "\n"),
			(: prompt_message, r :));
    break;
  case 'n':
    return prompt_message(r);
  case 'p':
    post = r->prev_post;
    this_player()->more(({ "Date: " + post[0], "From: " + post[3],
			   "Subject: " + post[2] }) + explode(post[4], "\n"),
			(: prompt_message, r :));
    break;
  case 'r':
    message("system", "Reply not implemented.\n", this_player());
    /* create message with same thread */
    break;
  case 'q':
    return prompt_thread(r);
  default:
    message("system", sprintf("Read article \"%s\"? [ynprq]: ", post[2]),
	    this_player());
    input_to("select_message", 0, r, post);
  }
}
