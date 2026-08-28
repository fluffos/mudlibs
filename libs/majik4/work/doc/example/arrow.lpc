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

inherit MISSILE;

void
create_missile()
{
   THOB->set_name("unholy arrow");
   THOB->set_material("juniper");
   THOB->set_damage(([DT_STAB:80]));
   THOB->set_missile_type("arrow");
   THOB->set_dimension(1,1,50,0);
   THOB->set_gridcolor(C_BLUE);
   THOB->set_gridchar(IS_MISSILE);
}
