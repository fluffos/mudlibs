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

#include <natweap.h>

/* Global variable definitions */
mapping natural_weapons;

/* Function prototypes */
mapping query_natural_weapons();
mapping remove_natural_weapon(string);
mixed *add_natural_weapon(string,mixed *);
void init_natural_weapons();
string query_natural_weapon_damtype(string);
string query_natural_weapon_reqloc(string);
int query_natural_weapon_cond(string);
int query_natural_weapon_damage(string);
string query_natural_weapon_skill(string);
string query_natural_weapon_in_hitloc(string);
string *query_usable_natural_weapons();
string *query_all_natural_weapon_reqlocs();

/* Functions */
mapping
query_natural_weapons()
{
   return natural_weapons;
}

mapping
remove_natural_weapon(string weapon)
{
   map_delete(natural_weapons, weapon);
   return natural_weapons;
}

mixed *
add_natural_weapon(string weapon, mixed *data)
{
   natural_weapons += ([ weapon : data ]);
   return natural_weapons[weapon];
}

void
init_natural_weapons()
{
   int i, j;
   mapping wmap;
   string *strs;
   
   wmap = RACE_D->query_natural_weapons()[RACE_D->query_natweapon_index(THOB->query_race())];
   strs = keys(wmap);
   natural_weapons = ([ ]);
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		THOB->add_natural_weapon(strs[i], wmap[strs[i]]);
		THOB->arm(strs[i]);
	 }
}

string
query_natural_weapon_damtype(string weapon)
{
   if(!natural_weapons[weapon])
	 return 0;
   else
	 return natural_weapons[weapon][NAT_DAMTYPE];
}

string 
query_natural_weapon_reqloc(string weapon)
{
   if(!natural_weapons[weapon])
	 return 0;
   else
	 return natural_weapons[weapon][NAT_REQLOC];
}

int
query_natural_weapon_cond(string weapon)
{
   if(!natural_weapons[weapon])
	 return 0;
   else
	 return THOB->query_hitloc_cond(natural_weapons[weapon][NAT_REQLOC]);
}

int
query_natural_weapon_damage(string weapon)
{
   if(!natural_weapons[weapon])
	 return 0;
   else
	 return natural_weapons[weapon][NAT_DAMAGE];
}

string
query_natural_weapon_skill(string weapon)
{
   if(!natural_weapons[weapon])
	 return 0;
   else
	 return natural_weapons[weapon][NAT_SKILL];
}

string
query_natural_weapon_range(string weapon)
{
   if(!natural_weapons[weapon])
	 return 0;
   else
	 return natural_weapons[weapon][NAT_RANGE];
}

int
query_natural_weapon_blocking_type(string weapon)
{
   if(!natural_weapons[weapon])
	 return 0;
   else
	 return natural_weapons[weapon][NAT_BLOCKTYPE];
}

string
query_natural_weapon_in_hitloc(string loc)
{
   int i, j;
   string *strs = keys(THOB->query_natural_weapons());
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(THOB->query_natural_weapon_reqloc(strs[i]) == loc)
		  return strs[i];
	 }
   return 0;
}

string *
query_usable_natural_weapons()
{
   int i, j;
   string *strs = keys(natural_weapons), *retstrs = ({ });
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(THOB->query_natural_weapon_cond(strs[i]) == NATWEAP_OK)
		  retstrs += ({ strs[i] });
	 }
   return retstrs;
}

string *
query_blocking_natural_weapons()
{
   int i, j;
   string *retstrs = ({ });
   string *strs = THOB->query_usable_natural_weapons();
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(THOB->query_natural_weapon_blocking_type(strs[i]) == NAT_BLOCK)
		  retstrs += ({ strs[i] });
	 }
   return retstrs;
}

string *
query_all_natural_weapon_reqlocs()
{
   int i, j;
   string *retstrs = ({ }), *natweapons = keys(THOB->query_natural_weapons());
   for(i=0,j=sizeof(natweapons);i<j;i++)
	 {
		retstrs += ({ THOB->query_natural_weapon_reqloc(natweapons[i]) });
	 }
   return retstrs;
}

mixed *
query_natweapon_battle_array(string weapon, object cstyleob)
{
   if(!natural_weapons[weapon])
	 return 0;
   else
	 return ({ weapon, THOB->query_natural_weapon_damtype(weapon), THOB->query_natural_weapon_damage(weapon), THOB->query_natural_weapon_range(weapon), cstyleob, THOB->query_natural_weapon_skill(weapon) });
}
