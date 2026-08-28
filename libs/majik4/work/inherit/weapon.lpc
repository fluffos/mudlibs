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

#include <weapon.h>

inherit ITEM;

/* Global variable definitions */
mapping damage;
int range;
int offense;
int defence;
int fatique;
int speed;
int handedness;
string skill;

/* Function prototypes */
int is_weapon();
int *query_damage_types();
int query_type_damage(int);
mapping set_damage(mapping);
int set_range(int);
int query_range();
int set_offense_bonus(int);
int query_offense_bonus();
int set_defence_bonus(int);
int query_defence_bonus();
int set_fatique_bonus(int);
int query_fatique_bonus();
int set_handedness(int);
int query_handedness();
string set_skill(string);
string query_skill();
int damage(object,object,string,int,int,mixed,mixed);
int attacked(object,object,string,int,int,mixed,mixed);
int miss(object,object,mixed,mixed);
int block(object,object,mixed,mixed);

/* Functions */
int
is_weapon()
{
   return 1;
}

int *
query_damage_types ()
{
   return keys(damage);
}

int
query_type_damage (string str)
{
   return damage[str];
}

mapping
set_damage (mapping map)
{
   return damage = map;
}

int 
set_range (int s)
{
   return range = s;
}

int
query_range()
{
   return range;
}

int
set_handedness (int i)
{
   return handedness = i;
}

int
query_handedness ()
{
   return handedness;
}

string
set_skill (string str)
{
   return skill = str;
}

string
query_skill ()
{
   return skill;
}

int
set_fatique_bonus(int i)
{
   return fatique = i;
}

int
query_fatique_bonus()
{
   return fatique;
}

int
set_defence_bonus(int i)
{
   return defence = i;
}

int
query_defence_bonus()
{
   return defence;
}

int
set_offense_bonus(int i)
{
   return offense = i;
}

int
query_offense_bonus()
{
   return offense;
}

int
set_speed_bonus(int i)
{
   return speed = i;
}

int
query_speed_bonus()
{
   return speed;
}

void
create_item()
{
   THOB->create_weapon();
   THOB->set_physical(FALSE);
}
