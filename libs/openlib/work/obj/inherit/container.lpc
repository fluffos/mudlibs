//  -*- LPC -*-
// container.c:  An inheritable container object
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

#pragma save_binary
#include <mudlib.h>
#include <modules.h>

inherit OBJECT;
inherit M_CONTAINER;

void
initialize()
{
  object::initialize();
  m_container::initialize();
}

//
// override of object::long()
//
string
long()
{
  return object::long() + m_container::long();
}
