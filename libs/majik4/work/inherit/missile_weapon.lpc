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

inherit ITEM;

/* Global variable definitions */
mapping missiles;
string skill;
int handedness;

/* Functions prototypes */
int set_handedness(int);
int query_handedness();
mapping set_missiles(mapping);
mapping query_missiles();
mapping add_missile(string,int);
string set_skill(string);
string query_skill();
int is_missile_weapon();

/* Functions */
int
set_handedness(int i)
{
   return handedness = i;
}

int
query_handedness()
{
   return handedness;
}

mapping
set_missiles(mapping map)
{
   return missiles = map;
}

mapping
query_missiles()
{
   return missiles;
}

mapping
add_missile(string str, int i)
{
   return missiles += ([ str : i ]);
}

string
set_skill(string str)
{
   return skill = str;
}

string
query_skill()
{
   return skill;
}

int
is_missile_weapon()
{
   return 1;
}

void
create_item()
{
   THOB->create_missile_weapon();
}
