/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <symbol.h>
#include <color.h>

inherit ITEM;

/* Global variable definitions */
string *parts;
string race;

/* Function prototypes */
int is_bodypart();
string set_race(string);
string query_race();
string *set_parts(string *);
string *query_parts();

/* Functions */
int
is_bodypart()
{
   return 1;
}

string
set_race(string str)
{
   return race = str;
}

string
query_race()
{
   return race;
}

string *
set_parts(string *strs)
{
   return parts = strs;
}

string *
query_parts()
{
   return parts;
}

void
create_item()
{
   THOB->create_bodypart();
   
   THOB->set_gridchar(IS_FOOD);
   THOB->set_gridcolor(C_RED);
   THOB->set_physical(FALSE);
   THOB->set_material("flesh");
}
