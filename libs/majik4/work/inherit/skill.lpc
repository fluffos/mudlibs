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

/* Global variable definitions */
int noadd;
nosave int rounds;

float cost_multiplier;
float max_train_diff;

string name;
string type;
string parent;

mapping bonus_stats;
mapping related_skills;

/* Function prototypes */
string set_name(string);
string query_name();
string set_type(string);
string query_type();
string set_parent(string);
string query_parent();
int set_no_add(int);
int query_no_add();
mapping set_relatives(mapping);
mapping query_relatives();
mapping query_bonus_stats();
mapping set_bonus_stats(mapping);
mapping add_bonus_stat(string,int);
float set_cost_multiplier(float);
float query_cost_multiplier();
float set_max_train_diff(float);
float query_max_train_diff();
int query_base_cost(int);
int query_cost(int);
float query_pot_train_mult(int,int);
float query_pra_train_mult(int,int);
int query_pot_skill_cost(int,int);
int query_pra_skill_cost(int,int);
int success(mixed);
int failure(mixed);
int difficulty(mixed);
int is_skill();
int set_rounds(int i);

/* Functions */
void
create()
{
   bonus_stats = ([ ]);
   THOB->create_skill();
}

int
set_rounds (int i)
{
   return rounds = i;
}

int
query_rounds ()
{
   return rounds;
}

string
set_name(string str)
{
   return name = str;
}

string
query_name()
{
   return name;
}

string
set_type(string str)
{
   return type = str;
}

string
query_type()
{
   return type;
}

string
set_parent(string str)
{
   return parent = str;
}

string
query_parent()
{
   return parent;
}

int
set_no_add(int i)
{
   return noadd = i;
}

int
query_no_add()
{
   return noadd;
}

mapping
set_related_skills(mapping map)
{
   return related_skills = map;
}

mapping
query_related_skills()
{
   return related_skills;
}

mapping
query_bonus_stats()
{
   return bonus_stats;
}

mapping
set_bonus_stats(mapping stats)
{
   return bonus_stats = stats;
}

mapping
add_bonus_stat(string stat, int divisor)
{
   return bonus_stats += ([ stat : divisor ]);
}

float
set_cost_multiplier(float f)
{
   return cost_multiplier = f;
}

float
query_cost_multiplier()
{
   return cost_multiplier;
}

float
set_max_train_diff(float f)
{
   return max_train_diff = f;
}

float
query_max_train_diff()
{
   return max_train_diff;
}

int
query_base_cost(int perc)
{
   return (perc * (perc + 1) / 2);
}

int
query_cost(int perc)
{
   float cost = query_base_cost(perc) * cost_multiplier;
   return cost;
}

float
query_pot_train_mult(int spot, int spra)
{
   if (spot >= spra)
	 return 1 + (query_cost(spot) - query_cost(spra)) / max_train_diff;
   else
	 return 1 / (1 + (query_cost(spra) - query_cost(spot)) / max_train_diff);
}

float
query_pra_train_mult(int spot, int spra)
{
   if (spra >= spot)
	 return 1 + (query_cost(spra) - query_cost(spot)) / max_train_diff;
   else
	 return 1 / (1 + (query_cost(spot) - query_cost(spra)) / max_train_diff);
}

int
query_pot_skill_cost(int spot, int spra)
{
   int i, cost = query_cost(spot);
   float mult = query_pot_train_mult(spot, spra);
   i = to_int(mult * cost);
   return 1 > i ? 1 : i;
}

int
query_pra_skill_cost(int spot, int spra)
{
   int i, cost = query_cost(spra);
   float mult = query_pra_train_mult(spot, spra);
   i = to_int(mult * cost);
   return 1 > i ? 1 : i;
}

int
is_skill()
{
   return 1;
}
