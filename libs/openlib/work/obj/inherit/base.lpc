//  -*- LPC -*-
//
// base.c:  Base object inherited by all (most) others except daemons
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
// Created by Tim 23 Apr 96
//
// modified to have destroy(), on_destruct() - Scott 11 Jun 96
//

// The following functions are intended to increase the granularity
// beyond that of the create() function when used by clones.

// This is defined by mudlib level objects instead of create() to
// do global initialization of variables, etc.
void
initialize()
{
  /* This space intentionally left blank */
}

// This is defined by mudlib level objects to do default clone setup
void
low_setup()
{
  /* This space intentionally left blank */
}

// This is defined by end-user level objects to do final setup of clones.
// It shouldn't be used anywhere by mudlib level objects.
void 
setup()
{
  /* This space intentionally left blank */
}

nomask void
create(int no_setup)
{
  initialize();
  if( no_setup ) return;

  if( clonep() )
  {
    low_setup();
    setup();
  }
}

void
remove()
{
  /* This space intentionally left blank */
}


varargs void
on_destruct( string flags )
{
 /* This space intentionally left blank (for now) - Scott */
}


varargs int
destroy( object ob, string flags )
{
	if( !ob || !objectp(ob) ) ob = this_object();
	else return( ob->destroy() );

	ob->on_destruct( flags );
	return destruct( this_object() );
}
