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
   THOB->set_name("first aid");
   THOB->set_type("targeted");
   THOB->set_parent("medical");
   THOB->set_cost_multiplier(1.5);
   THOB->set_max_train_diff(100);
   THOB->set_rounds(5);
   
   THOB->add_bonus_stat("wis", 1);
   THOB->add_bonus_stat("dex", 2);
}
   
int
success(string args)
{
   int x, y;
   object *obs;
   
   sscanf (args, "%d %d", x, y);
   obs = MAPENV(PREV(0))->get_livings(x, y, x, y);
   
   if (!obs || sizeof (obs) < 1)
	 {
		message (CMD_MSG, 0,0,0, "You must select a living target.", PREV(0));
		return 0;
	 }
   
   if (distance (x, y, THIS->query_gridx(), THIS->query_gridy()) > 1)
	 {
		message (CMD_MSG, 0,0,0, "You have to be able to touch $t1.", obs[0]);
		return 0;
	 }
   
   if (obs[0]->query_hp() >= obs[0]->query_max_hp())
	 {
		message (CMD_MSG, 0,0,0, "You can't see any wounds on $n1.", THIS, obs[0]);
		return 0;
	 }
   
   if (random(100) < 5)
	 obs[0]->add_hp (d("20d3"));
   else if (random(100) < 10)
	 obs[0]->add_hp (d("10d3+10"));
   else
	 obs[0]->add_hp (d("10d3"));
   
   message (CMD_SEE, THIS->query_gridx(),THIS->query_gridy(),VISIBLE_RADIUS, "$n1 {heal} some of $o2 wounds.", MAPENV(THIS), ({ THIS, obs[0] }));
   return 1;
}

int
failure(string args)
{
   int x, y;
   object *obs;
   
   sscanf (args, "%d %d", x, y);
   obs = MAPENV(PREV(0))->get_livings(x, y, x, y);
   
   if (!obs || sizeof (obs) < 1)
	 {
		message (CMD_MSG, 0,0,0, "You must select a living target.", PREV(0));
		return 0;
	 }
   
   if (distance (x, y, THIS->query_gridx(), THIS->query_gridy()) > 1)
	 {
		message (CMD_MSG, 0,0,0, "You have to be able to touch $t1.", obs[0]);
		return 0;
	 }
   
   if (obs[0]->query_hp() >= obs[0]->query_max_hp())
	 {
		message (CMD_MSG, 0,0,0, "You can't see any wounds on $n1.", THIS, obs[0]);
		return 0;
	 }
   
   message (CMD_MSG, 0,0,0, "You failed.", PREV(0));
   return 1;
}
