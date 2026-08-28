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

#include <weapon.h>
#include <missile_weapon.h>
#include <color.h>
#include <symbol.h>

inherit MISSILE_WEAPON;

void
create_missile_weapon()
{
   THOB->set_name("unholy bow");
   THOB->set_handedness(WEAPON_2H);
   THOB->set_missiles((["arrow":120]));
   THOB->set_skill("bows");
   THOB->set_material("juniper");
   THOB->set_dimension(1,1,250,0);
   THOB->set_gridcolor(C_BLUE);
   THOB->set_gridchar(IS_MISSILE_WEAPON);
}
