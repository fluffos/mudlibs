//  -*- LPC -*-
// object.c:  a representation of a normal object
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
// Originally by Tim 23 Apr 96
//

#pragma save_binary
#pragma no_warnings

#include <mudlib.h>
#include <modules.h>
#include <object_types.h>

inherit BASE;

inherit M_CLEAN_UP;
inherit M_OBJECT_CLASS;
inherit M_FLAGS;
inherit M_VISIBLE;
inherit M_MOVE;
inherit M_VALUE;
inherit M_DIMENSIONS;

void
initialize()
{
  m_flags::initialize();
  m_visible::initialize();
  m_value::initialize();

  set_object_class(OBJECT_OBJECT | query_object_class());
}
