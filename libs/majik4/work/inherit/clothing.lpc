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

#include <living.h>

inherit ITEM;

/* Global variable definitions */
string *target;
nosave int is_worn;
int speed;
int fatique;
int offense;
int defence;

/* Function prototypes */
int is_clothing();
string *query_target();
string *set_target(string *, string *);
int set_worn(int);
int is_worn();
int set_speed_bonus(int);
int query_speed_bonus();
int set_fatique_bonus(int);
int query_fatique_bonus();
int set_offense_bonus(int);
int query_offense_bonus();
int set_defence_bonus(int);
int query_defence_bonus();

/* Functions */
int
is_clothing()
{
   return 1;
}

string *
query_target ()
{
   return target;
}

string *
set_target (string *strs, string *exclude)
{
   int i, j;
   string *locs = ({ });
   string *bts = keys(RACE_D->query_bodytypes()[BT_HUMANOID]);  
   
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		if(member_array(strs[i], bts) != -1)
		  locs += RACE_D->query_bodytypes()[BT_HUMANOID][strs[i]][0];
		else
		  locs += ({ strs[i] });
	 }
   
   if(sizeof(exclude) > 0)
	 {
		for(i=0,j=sizeof(exclude);i<j;i++)
		  {
			 if(member_array(exclude[i], locs) != -1)
			   locs -= ({ exclude[i] });
		  }
	 }
   return target = locs;
}

int 
set_worn(int i)
{
   if(i)
	 THOB->set_default("remove");
   else
	 THOB->set_default("wear");
   return is_worn = i;
}

int
is_worn()
{
   return is_worn;
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
set_fatique_bonus(int i)
{
   return fatique = i;
}

int
query_fatique_bonus()
{
   return fatique;
}

void
create_item()
{
   THOB->create_clothing();
   THOB->set_physical(FALSE);
}
