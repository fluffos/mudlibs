/*  -*- LPC -*-  */
// Basic weapon Inheritable.
//
// Copyright (C) 1996 Eric Peters (epeters@netcom.com)
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
// Orig by Casper 9/95
//
// 10/14/95   Tim: removed set_long/short to work with changes to OBJECT,
//                 and removed var's long and short
// 04/20/96   Tim: updated w.r.t. object.c
// 04/23/96   Modularized by Tim
 
#include <mudlib.h>
#include <modules.h>

inherit OBJECT;
inherit M_WEAPON;

//
// Private Functions
//
void unwield();

void
initialize()
{
  object::initialize();
  m_weapon::initialize();
}

varargs string short(int fflag)
{
  if( fflag )
    return short_desc;
  return short_desc + (query_wielded() ? "(wielded)" : "");
}

int move(mixed dest)
{
  unwield();
  return object::move(dest);
}

int remove()
{
  unwield();
  return object::remove();
}

private void
unwield()
{
  if( query_wielded() )
    environment()->do_unwield(this_object(), 1);
}
