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

#include <list.h>

int
main(string str)
{
   string act;
   string buf = "";
   string *actions;
   string *skills;
   
   if(!str || str == "")
	 {
		actions = ({ "tree (print skill tree)",
		             "update (update skill tree)",
			         "info (show your skills)"
		          });
		
		buf = implode(actions, ";")+";";
		open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "Skill Control", "skillctrl", buf);
	 }
   
   if(sscanf(str, "%s (%*s)", act) != 2)
	 act = str;
   
   switch(act)
	 {
	  case "tree":
		SKILL_D->print_skill_tree(PREV(0), "root", 1);
		break;
	  case "update":
		SKILL_D->destruct_skillobs();
		message (CMD_MSG, 0,0,0, "Skill tree updated.", PREV(0));
		break;
	  case "info":
		skills = keys(PREV(0)->query_skills());
		foreach(string entry in skills)
		  buf += entry + " ("+PREV(0)->query_skill_chance(entry)+", "+PREV(0)->query_skill_pra_experience(entry)+", "+PREV(0)->query_skill_pot_experience(entry) + ");";
		open_window(PREV(0), 0,0,0,0, LTYPE_TEXT, "Skill info (%, praexp, potexp):", "noop", buf);
		break;
	 }
   return 1;
}
		
