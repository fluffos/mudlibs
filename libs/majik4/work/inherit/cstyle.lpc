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

inherit SKILL;

/* Global variable definitions */
int speed;
int defence;
int offense;
int fatique;
int damage;
string *weapon_skills;

/* Function prototypes */
int set_defence_bonus(int);
int query_defence_bonus();
int set_offense_bonus(int);
int query_offense_bonus();
int set_fatique_bonus(int);
int query_fatique_bonus();
int set_speed_bonus(int);
int query_speed_bonus();
int set_damage_bonus(int);
int query_damage_bonus();
string *set_weapon_skills(string *);
string *query_weapon_skills();
string *add_weapon_skill(string);
int damage(object,object,string,int,int,mixed,mixed);
int attacked(object,object,string,int,int,mixed,mixed);
int miss(object,object,mixed,mixed);
int block(object,object,mixed,mixed);

/* Functions */
void
create_skill()
{
   weapon_skills = ({ });
   THOB->set_type("combat style");
   THOB->create_combat_style();
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
set_damage_bonus(int i)
{
   return damage = i;
}

int
query_damage_bonus()
{
   return damage;
}

string *
set_weapon_skills(string *skills)
{
   return weapon_skills = skills;
}

string *
add_weapon_skill(string skill)
{
   return weapon_skills += ({ skill });
}

string *
query_weapon_skills()
{
   return weapon_skills;
}
