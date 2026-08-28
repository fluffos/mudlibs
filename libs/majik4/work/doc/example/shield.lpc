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

#include <color.h>
#include <symbol.h>
#include <weapon.h>

inherit SHIELD;

void
create_shield()
{
   THOB->set_name("unholy shield");
   THOB->set_gridchar(IS_ARMOR);
   THOB->set_gridcolor(C_BLUE);
   THOB->set_material("bronze");
   THOB->set_dimension(70,50,1,50);
   THOB->set_shielding(100);
   THOB->set_skill("clubs");
   THOB->set_damage(([DT_IMPACT:50]));
   THOB->set_handedness(WEAPON_1H);
   
   THOB->set_speed_bonus(10);
   THOB->set_defence_bonus(30);
   THOB->set_offense_bonus(0);
   THOB->set_fatique_bonus(5);
}
