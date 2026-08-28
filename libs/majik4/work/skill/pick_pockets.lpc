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

inherit SKILL;

void
create_skill()
{
   THOB->set_name("pick pockets");
   THOB->set_type("targeted");
   THOB->set_parent("manipulation");
   THOB->set_cost_multiplier(1.5);
   THOB->set_max_train_diff(100);
   
   THOB->add_bonus_stat("dex", 1);
   THOB->add_bonus_stat("wis", 2);
   THOB->add_bonus_stat("int", 3);
   THOB->add_bonus_stat("cha", 3);
}

int
difficulty(string args)
{
   int x, y;
   object *obs;
    
   sscanf(args, "%d %d", x, y);
   obs = MAPENV(PREV(0))->get_livings(x, y, x, y);
   if(!obs || sizeof(obs) < 1)
	 {
		message (CMD_MSG, 0,0,0, "You must select a living target.", PREV(0));
		return 0;
	 }
   return obs[0]->query_stat(A_AGI) * 3 + obs[0]->query_stat(A_INT) * 3 + obs[0]->query_stat(A_WIS) * 2;
}

int
success(string args)
{
   message (CMD_MSG, 0,0,0, "Success!", PREV(0));
}

int
failure(string args)
{
   message (CMD_MSG, 0,0,0, "Failure...", PREV(0));
}
