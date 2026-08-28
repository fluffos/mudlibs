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

inherit SKILL;

void
create_skill()
{
   THOB->set_name("skilltest");
   THOB->set_type("immediate");
   THOB->set_cost_multiplier(1.2);
   THOB->set_max_train_diff(50);
}

void
success(string str)
{
   int spot, spra;
   string buf = "";
   spot = THIS->query_skill_potential(THOB->query_name());
   spra = THIS->query_skill_practice(THOB->query_name());
   buf += "Skill potential: "+spot+";";
   buf += "Skill practice: "+spra+";";
   buf += "Skill potential experience: "+THIS->query_skill_pot_experience(THOB->query_name())+";";
   buf += "Skill practice experience: "+THIS->query_skill_pra_experience(THOB->query_name())+";";
   buf += " ;";
   buf += "Potential skill cost: "+THOB->query_pot_skill_cost(spot, spra)+";";
   buf += "Practice skill cost: "+THOB->query_pra_skill_cost(spot, spra)+";";
   buf += " ;";
   buf += "Given arguments: "+str+";";
   open_window(THIS, 0,0,0,0, LTYPE_TEXT, "Skill stuff:", "noop", buf); 
}

void
failure (string str)
{
   message (CMD_MSG, 0,0,0, "Failure.", THIS);
}
