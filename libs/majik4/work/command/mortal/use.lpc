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

int
main(string str)
{
   string args;
   string skillname;
   object skillob;
      
   if(!str || str == "")
	 {
		message (CMD_MSG, 0,0,0, "Usage: use <skill> at <target>", PREV(0));
		return 1;
	 }
   
   if(sscanf(str, "%s at %s", skillname, args) != 2)
	 skillname = str;
   sscanf(skillname, "%s (%*s)", skillname);
	    
   if(!PREV(0)->query_skills()[skillname])
	 {
		message (CMD_MSG, 0,0,0, "You have no such skill.", PREV(0));
		return 1;
	 }
   
   skillob = SKILL_D->find_skill(skillname);
   if(!skillob)
	 return 1;
   
   switch(skillob->query_type())
	 {
	  case "immediate":
	  case "lore":
		PREV(0)->use_skill(skillob->query_name(), 100, 0, args);
		break;
	  case "targeted":
		if(!args || args == "")
		  select_target(PREV(0), "use "+skillob->query_name()+" at");
		else
		  PREV(0)->use_skill(skillob->query_name(), 100, 0, args);
		break;
	  case "combat style":
		PREV(0)->set_active_combat_style(skillob->query_name());
		message (CMD_MSG, 0,0,0, "Your active combat style is now $n1.", PREV(0), skillob);
		break;
	  case "automatic":
	    message (CMD_MSG, 0,0,0, "This skill is automatically in use.", PREV(0));
	    break;
	  default:
		break;
	 }
   return 1;
}
