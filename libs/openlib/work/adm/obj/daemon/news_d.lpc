//  -*- LPC -*-
// news_d.c:  News Server
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
// Created by Tim 01 Jul 1996
//

#include <save.h>
#include <dirs.h>
#include "news_d.h"

#define NEWS_ARCHIVE_DIR SECURE_DIR "/news"

private mapping groups;  // maps group names to class newsgroup objects

void
create()
{
  groups = ([ ]);
  unguarded((: restore_object, SAVE_NEWSSERVER, 1 :), 1);
}

void
save_me()
{
  unguarded((: save_object, SAVE_NEWSSERVER, 1 :), 1);
}

private void
archive_post(string group, int id, class post thePost)
{
  string text =
    sprintf("[#%d]\n"
	    "Thread: %s\n"
	    "Subject: %s\n"
	    "Author: %s\n"
	    "Date: %s\n%s\n", id, thePost->thread, thePost->subject,
	    thePost->author, ctime(thePost->timestamp), thePost->content);

  unguarded((: write_file, NEWS_ARCHIVE_DIR "/" + group, text :), 1);
}

// User cmd

varargs int
create_group(string name, string domain_restriction)
{
  if( groups[name] )
    return notify_fail("Newsgroup exists!.\n");

  if( !adminp(this_player()) )
    return notify_fail("Only administrators may create newsgroups.\n");
  else
  {
    class newsgroup theGroup = new(class newsgroup);

    theGroup->posts = ([ ]);
    theGroup->first_id = 1;
    theGroup->domain = domain_restriction;

    groups[name] = theGroup;
  }
  save_me();
  return 1;
}

int
delete_group(string name)
{
  class newsgroup theGroup = groups[name];

  if( !theGroup )
    return notify_fail("No such newsgroup.\n");

  if( !adminp(this_player()) )
    return notify_fail("Only administrators may delete newsgroups.\n");
  else
  {
    foreach(int id, class post p in theGroup->posts)
      archive_post(name, id, p);

    map_delete(groups, name);
    save_me();
    return 1;
  }
}

int
group_exists(string group)
{
  return (groups[group] ? 1 : 0);
}

int
can_access_group(string group, object user)
{
  class newsgroup theGroup = groups[group];

  if( !theGroup )
    return 0;

  if( theGroup->domain && (!user || (!adminp(user) &&
		     !member_domain(user->query_name(), theGroup->domain))) )
    return 0;

  return 1;
}

int
new_post(string group, string thread,
	 string subject, string author, string content)
{
  class newsgroup theGroup = groups[group];

  if( !theGroup )
    return notify_fail("No such newsgroup.\n");

  if( theGroup->domain &&
      (!this_player() ||
       (!adminp(this_player()) &&
	!member_domain(this_player()->query_name(), theGroup->domain))) )
    return notify_fail("Insufficient access to post to newsgroup.\n");
  else
  {
    class post thePost = new(class post);

    if( sizeof(theGroup->posts) > MAX_POSTS - 1 )
    {
      int id = theGroup->first_id;

      archive_post(group, id, theGroup->posts[id]);
      map_delete(theGroup->posts, id);

      theGroup->first_id++;
    }

    theGroup->last_id++;

    thePost->timestamp = time();
    thePost->thread = thread;
    thePost->subject = subject;
    thePost->author = author;
    thePost->content = content;

    theGroup->posts[theGroup->last_id] = thePost;

    save_me();
    return 1;
  }
}

// User cmd

int
delete_post(string group, int id)
{
  class newsgroup theGroup = groups[group];

  if( !theGroup )
    return notify_fail("No such newsgroup.\n");
  else
  {
    class post thePost = theGroup->posts[id];

    if( !thePost )
      return notify_fail("No such post.\n");

    if( !adminp(this_player()) &&
        this_player()->query_name() != thePost->author )
      return notify_fail("You can only delete your own posts!\n");

    map_delete(theGroup->posts, id);
    save_me();
    return 1;
  }
}

// note this is the same packet I3 uses
// returns 0 if post non existent--you can determine if the post was deleted
// if this returns 0 and the id is between the 1st and last id's
// (assuming the last id is greater or equal to the 1st id)
mixed*
get_post(string group, int id)
{
  class newsgroup theGroup = groups[group];

  if( !theGroup )
    return (mixed *) notify_fail("No such newsgroup.\n");

  if( theGroup->domain &&
      (!this_player() ||
       (!adminp(this_player()) &&
	!member_domain(this_player()->query_name(), theGroup->domain))) )
    return (mixed *)notify_fail("Insufficient access to read newsgroup.\n");
  else
  {
    class post thePost = theGroup->posts[id];

    if( !thePost )
      return (mixed *) notify_fail("No such post.\n");
    else
      return ({ thePost->timestamp,
		thePost->thread,
		thePost->subject,
		thePost->author,
		thePost->content });
  }
}

string*
get_threads(string group)
{
  class newsgroup theGroup = groups[group];

  if( !theGroup )
    return (mixed *) notify_fail("No such newsgroup.\n");

  if( theGroup->domain &&
      (!this_player() ||
       (!adminp(this_player()) &&
	!member_domain(this_player()->query_name(), theGroup->domain))) )
    return (mixed *)notify_fail("Insufficient access to read newsgroup.\n");
  else
  {
    return distinct_array(map(values(theGroup->posts),
			      (: ((class post) $1)->thread :)));
  }
}

// User cmd

int*
get_group_info(string group)
{
  class newsgroup theGroup = groups[group];

  if( !theGroup )
    return (int *) notify_fail("No such newsgroup.\n");

  if( theGroup->domain &&
      !adminp(this_player()) &&
      !member_domain(this_player()->query_name(), theGroup->domain) )
    return (int *) notify_fail("Insufficient access to read newsgroup.\n");
  else
   return ({ theGroup->first_id, theGroup->last_id, sizeof(theGroup->posts) });
}

mixed*
get_group_list()
{
  int i;
  mixed* ret = allocate(sizeof(groups));

  foreach(string name, class newsgroup group in groups)
  {
    if( group->domain &&
        (!this_player() ||
	 (!adminp(this_player()) &&
	  !member_domain(this_player()->query_name(), group->domain))) )
      continue;
    else
      ret[i++] = ({ name, group->first_id, group->last_id });
  }
  return ret;
}
