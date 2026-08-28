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

void
create_skill()
{
   THOB->set_name("picking");
   THOB->set_type("automatic");
   THOB->set_parent("mining");
   THOB->set_cost_multiplier(1.3);
   THOB->set_max_train_diff(90);
   
   THOB->add_bonus_stat("str", 1);
   THOB->add_bonus_stat("dex", 2);
   THOB->set_relatives((["axes":30]));
}
