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
mapping damage;
string type;

/* Function prototypes */
mapping set_damage(mapping);
mapping query_damage();
mapping add_damage(int,int);
string *query_damage_types();
int query_type_damage(string);
string set_missile_type(string);
string query_missile_type();

/* Functions */
mapping
set_damage(mapping map)
{
   return damage = map;
}

mapping
query_damage()
{
   return damage;
}

mapping
add_damage(int dt, int i)
{
   return damage += ([ dt : i ]);
}

string *
query_damage_types()
{
   return keys(damage);
}

int
query_type_damage(int dt)
{
   return damage[dt];
}

string
set_missile_type(string str)
{
   return type = str;
}

string
query_missile_type()
{
   return type;
}

int
is_missile()
{
   return 1;
}

void
create_item()
{
   THOB->create_missile();
}
