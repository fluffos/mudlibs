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

#include <cstyle.h>

inherit COMBAT_STYLE;

void
create_combat_style()
{
   THOB->set_name("berserker charging");
   THOB->set_parent("combat styles");
   THOB->set_cost_multiplier(1.5);
   THOB->set_max_train_diff(80);
   THOB->add_bonus_stat("str", 1);
   THOB->add_bonus_stat("stu", 1);
   THOB->add_bonus_stat("agi", 2);
      
   THOB->add_weapon_skill("unarmed combat");
   THOB->add_weapon_skill("weapons");
   THOB->set_speed_bonus(10);
   THOB->set_defence_bonus(-30);
   THOB->set_offense_bonus(50);
   THOB->set_damage_bonus(25);
   THOB->set_fatique_bonus(15);
}

int
damage(object attacker, object defender, string loc, int percent, int damage, mixed atweapon, mixed defweapon)
{
   message (CMD_SEE, attacker->query_gridx(), attacker->query_gridy(), VISIBLE_RADIUS, "$n1 {plunge} forward for the attack.", MAPENV(attacker), attacker);
   return 0;
}
