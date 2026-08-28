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

#include <skillsys.h>

/* name : ({ pot, pra, potexp, praexp }) */

/* Global variable definitions */
mapping skillmap;

/* Function prototypes */
mapping query_skills();
string *query_skill_children(string);
mapping add_skill(string,int,int);
int query_skill_potential(string);
int query_skill_practice(string);
int query_skill_chance(string);
int add_skill_pot_experience(string,int);
int add_skill_pra_experience(string,int);
int query_skill_pot_experience(string);
int query_skill_pra_experience(string);
int use_skill(string,int,int,string);
int do_skill(object,int,int,string);
int teach_skill(string,object);
void init_skills();

/* Functions */
mapping
query_skills()
{
   return skillmap;
}

string *
query_skill_children(string str)
{
   int i, j;
   object ob;
   string *skills = keys(skillmap);
   string *children = ({ });
   
   for(i=0,j=sizeof(skills);i<j;i++)
	 {
		ob = SKILL_D->find_skill(skills[i]);
		if(ob->query_parent() == str)
		  children += ({ ob->query_name() });
	 }
   return children;
}
 				
mapping
add_skill(string str, int potexp, int praexp)
{
   int i, j;
   string skillname;
   object skillob;
   string *parents;
   
   skillob = SKILL_D->find_skill(str);
   if(!skillob)
	 return 0;
   
   skillname = skillob->query_name();
   skillmap[skillname] = allocate(4);
   parents = SKILL_D->query_skill_parents(skillname);
   THOB->add_skill_pot_experience(skillname, potexp);
   THOB->add_skill_pra_experience(skillname, praexp);
   
   for(i=0,j=sizeof(parents);i<j;i++)
	 {
		if(!skillmap[parents[i]])
		  skillmap[parents[i]] = allocate(4);
		THOB->add_skill_pot_experience(parents[i], potexp / (i + 2));
		THOB->add_skill_pra_experience(parents[i], potexp / (i + 2));
	 }
   return skillmap;
}

int
query_skill_practice(string str)
{
   if(!skillmap[str])
	 return 0;
   else
	 return skillmap[str][SKILL_PRACTICE];
}

int
query_skill_potential(string str)
{
   if(!skillmap[str])
	 return 0;
   else
	 return skillmap[str][SKILL_POTENTIAL];
}

int
query_skill_chance(string str)
{
   int i, j;
   int skillbase;
   string skillname;
   object skillob;
   string *parents;
   
   skillob = SKILL_D->find_skill(str);
   if(!skillob)
	 return 0;
   
   skillname = skillob->query_name();
   if(!skillmap[skillname])
	 {
		skillbase = SKILL_D->query_stat_bonus(skillname, THOB);
	 }
   else
	 {
		parents = SKILL_D->query_skill_parents(skillname);
		if(skillob->query_type() == "lore")
		  {
			 skillbase = THOB->query_skill_potential(skillname) + SKILL_D->query_stat_bonus(skillname, THOB);
			 for(i=0,j=sizeof(parents);i<j;i++)
			   skillbase += THOB->query_skill_potential(parents[i]) + SKILL_D->query_stat_bonus(parents[i], THOB);
		  }
		else
		  {
			 skillbase = THOB->query_skill_practice(skillname) + SKILL_D->query_stat_bonus(skillname, THOB);
			 for(i=0,j=sizeof(parents);i<j;i++)
			   skillbase += THOB->query_skill_practice(parents[i]) + SKILL_D->query_stat_bonus(parents[i], THOB);
		  }
		skillbase /= j + 1;
	 }
   return skillbase;
}

int
query_skill_pot_experience(string str)
{
   if(!skillmap[str])
	 return 0;
   else
	 return skillmap[str][SKILL_POTENTIAL_EXPERIENCE];
}

int
query_skill_pra_experience(string str)
{
   if(!skillmap[str])
	 return 0;
   else
	 return skillmap[str][SKILL_PRACTICE_EXPERIENCE];
}

int
add_skill_pot_experience(string str, int addition)
{
   int i, j;
   int improved; 
   int exp, cost;
   string skillname;
   object skillob;
   string parent;
   string *strs;
   mapping relatives;
   
   skillob = SKILL_D->find_skill(str);
   if(!skillob)
	 return 0;
   
   skillname = skillob->query_name();
   if(!skillmap[skillname])
	 THOB->add_skill(skillname, 0, 0);
      
   relatives = skillob->query_relatives();
   parent = skillob->query_parent();
   exp = skillmap[skillname][SKILL_POTENTIAL_EXPERIENCE] += addition;
   cost = skillob->query_pot_skill_cost(THOB->query_skill_potential(skillname), THOB->query_skill_practice(skillname));
   
   while(exp >= cost)
	 {
		improved = 1;
		skillmap[skillname][SKILL_POTENTIAL]++;
		exp -= cost;
		cost = skillob->query_pot_skill_cost(THOB->query_skill_potential(skillname), THOB->query_skill_practice(skillname));
	 }
   
   if(improved && skillob->query_type() != "node")
	 message (CMD_MSG, 0,0,0, "You feel like you just improved your "+skillname+".", THOB);
	
   if(parent)
	 THOB->add_skill_pot_experience(parent, addition / 2);
   
   if(mapp(relatives) && relatives != ([ ]))
	 {
		strs = keys(relatives);
		for(i=0,j=sizeof(strs);i<j;i++)
		  THOB->add_skill_pot_experience(strs[i], (addition * relatives[strs[i]]) / 100);
	 }
   return skillmap[skillname][SKILL_POTENTIAL_EXPERIENCE] = exp;
}

int
add_skill_pra_experience(string str, int addition)
{
   int i, j;
   int sc;
   int improved;
   int exp, cost;
   string skillname;
   string *strs;
   object skillob;
   string parent;
   mapping relatives;
   
   skillob = SKILL_D->find_skill(str);
   if(!skillob)
	 return 0;
   
   if(!skillmap[skillob->query_name()])
	 THOB->add_skill(skillob->query_name(), 0, 0);
   
   skillname = skillob->query_name();
   parent = skillob->query_parent();
   relatives = skillob->query_relatives();
   if(THOB->query_active_combat_style() == skillname)
	 {
		sc = THOB->query_skill_chance(skillname);
		THOB->add_speed((skillob->query_speed_bonus() * sc / 100) * 5000);
		THOB->add_fatique_bonus(-(skillob->query_fatique_bonus() * (100 - sc)) / 100);
	 }
								   
   exp = skillmap[skillname][SKILL_PRACTICE_EXPERIENCE] += addition;
   cost = skillob->query_pra_skill_cost(THOB->query_skill_potential(skillname), THOB->query_skill_practice(skillname));
   
   while(exp >= cost)
	 {
		improved = 1;
		skillmap[skillname][SKILL_PRACTICE]++;
		exp -= cost;
		cost = skillob->query_pra_skill_cost(THOB->query_skill_potential(skillname), THOB->query_skill_practice(skillname));
	 }
   
   if(improved && skillob->query_type() != "node")
	 message (CMD_MSG, 0,0,0, "You feel like you just improved your "+skillname+".", THOB);
   
   if(parent)
	 THOB->add_skill_pra_experience(parent, addition / 2);
   
   if(mapp(relatives) && relatives != ([ ]))
	 {
		strs = keys(relatives);
		for(i=0,j=sizeof(relatives);i<j;i++)
		  THOB->add_skill_pra_experience(strs[i], (relatives[strs[i]] * addition) / 100);
	 }
   
   if(THOB->query_active_combat_style() == skillname)
	 {
		sc = THOB->query_skill_chance(skillname);
		THOB->add_speed(-(skillob->query_speed_bonus() * sc / 100) * 5000);
		THOB->add_fatique_bonus((skillob->query_fatique_bonus() * (100 - sc)) / 100);
	 }
   return skillmap[skillname][SKILL_PRACTICE_EXPERIENCE] = exp;
}

int
use_skill(string skill, int die, int bonuses, string args)
{
   int number, difficulty, ret, i;
   string skillname;
   object skillob;
   
   skillob = SKILL_D->find_skill(skill);
   if(!skillob)
	 return 0;
   skillname = skillob->query_name();
  
   number = bonuses;
   if(die)
	 number += d("1d"+die);
   
   if(skillname == "teaching")
	 number += (THOB->query_skill_chance(args) * THOB->query_skill_chance("teaching")) / 100;
	else
	 number += THOB->query_skill_chance(skillname);
   
   if(skillob->query_type() == "immediate" || skillob->query_type() == "targeted")
	 {
		if (skillob->query_can_use(args) == -1)
		  return 0;
		
		difficulty = skillob->difficulty(args);
		
		if(!difficulty)
		  difficulty = random(100);
		
		if (i = skillob->query_rounds())
		  {
			 message (CMD_SEE, THOB->query_gridx(), THOB->query_gridy(), VISIBLE_RADIUS, "$n1 {concentrate} on a skill.", MAPENV(THOB), THOB);
			 call_out ("do_skill", i, skillob, number, difficulty, args);
			 return number;
		  }
		
		if(number > difficulty)
		  ret = skillob->success(args);
		else
		  ret = skillob->failure(args);
	 }
   
   if(skillob->query_no_add() && !skillmap[skillname])
	 return number;
   
   if (ret)
	 THOB->add_skill_pra_experience(skillname, d("1d200"));
   
   return number;
}

int
do_skill (object skillob, int number, int difficulty, string args)
{
   int ret;
   
   if (number > difficulty)
	 ret = skillob->success(args);
   else
	 ret = skillob->failure(args);
   
   if(skillob->query_no_add() && !skillmap[skillob->query_name()])
	 return number;
   
   if (ret)
	 THOB->add_skill_pra_experience(skillob->query_name(), d("1d200"));
   
   return number;
}

int
teach_skill(string skill, object target)
{
   int chance;
   string skillname;
   object skillob;
   
   if(!skill || skill == "")
	 return 0;
   
   if(!target)
	 return 0;
   
   skillob = SKILL_D->find_skill(skill);
   if(!skillob)
	 return 0;
   
   skillname = skillob->query_name();
   chance = THOB->use_skill("teaching", 100, 0, skillname);
   target->add_skill_pot_experience(skillname, chance);
   return chance;
}

void
init_skills()
{
   int i, j;
   mapping map;
   string *strs;
   
   if(!skillmap)
	 skillmap = ([ ]);

   map = RACE_D->query_initial_skills()[THOB->query_race()];
   if(!map || !mapp(map))
	 return;
   
   strs = keys(map);
   for(i=0,j=sizeof(strs);i<j;i++)
	 {
		THOB->add_skill(strs[i], map[strs[i]][0], map[strs[i]][1]);
	 }
}
