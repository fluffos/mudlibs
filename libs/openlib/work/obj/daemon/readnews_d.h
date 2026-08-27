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
#ifndef _READNEWS_D_H
#define _READNEWS_D_H

class reader 
{
  function cb;
  
  mapping newsrc;
  mapping touched;
  
  string  group;
  string  prev_group;
  
  int*    info;
  string* threads;
  string  thread;
  int     post;
  mixed*  prev_post;  
}

// Public functions
varargs int read_news(mapping newsrc, function call_back);
varargs int read_one_group(string newsgroup, mapping newsrc, function call_bk);

// Private prototypes
void prompt_group(class reader r);
void read_group(class reader r);
void prompt_thread(class reader r);
void prompt_message(class reader r);

#endif
