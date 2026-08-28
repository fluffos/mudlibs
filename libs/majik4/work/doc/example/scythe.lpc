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
#include <symbol.h>
#include <color.h>

inherit WEAPON;

void
create_weapon()
{
   THOB->set_name("unholy scythe");
   THOB->set_gridchar(IS_WEAPON);
   THOB->set_gridcolor(C_BLUE);
   THOB->set_material("juniper");
   THOB->set_damage(([DT_CUT:350]));
   THOB->set_range(RANG_CLOSE);
   THOB->set_handedness(WEAPON_2H);
   THOB->set_skill("polearms");
   THOB->set_dimension(3,3,120,0);
}

int
damage(object attacker, object defender, string loc, int percent, int damage, mixed atweapon, mixed defweapon)
{
   message (CMD_SEE, attacker->query_gridx(), attacker->query_gridy(), VISIBLE_RADIUS, "The ^cbUnholy Scythe^c0 wails in pleasure as it draws blood!", MAPENV(attacker));
   return 0;
}

int
attacked(object attacker, object defender, string loc, int percent, int damage, mixed atweapon, mixed defweapon)
{
   message (CMD_MSG, 0,0,0, "The ^cbUnholy Scythe^c0 surges a stream of power down your spine.", attacker);
   attacker->add_hp(damage / 2);
   return 0;
}

int
block(object attacker, object defender, mixed atweapon, mixed defweapon)
{
   if(!atweapon)
	 return 0;
   
   if(stringp(atweapon))
	 {
		message (CMD_SEE, defender->query_gridx(), defender->query_gridy(), VISIBLE_RADIUS, "The ^cbUnholy Scythe^c0 wails in displeasure and plunges through $o1 "+attacker->query_natural_weapon_reqloc(atweapon)+".", MAPENV(attacker), attacker);
     	attacker->remove_hitloc(attacker->query_natural_weapon_reqloc(atweapon));
	 }
   else
	 {
		message (CMD_SEE, defender->query_gridx(), defender->query_gridy(), VISIBLE_RADIUS, "The ^cbUnholy Scythe^c0 wails in displeasure as it disintegrates $o1 $n2.", MAPENV(attacker), ({ attacker, atweapon }) );
		attacker->remove_weapon(atweapon);
		atweapon->remove();
	 }
   return 1;
}

int
miss(object attacker, object defender, mixed atweapon, mixed defweapon)
{
   message (CMD_SEE, attacker->query_gridx(), attacker->query_gridy(), VISIBLE_RADIUS, "The ^cbUnholy Scythe^c0 lets out a hollow wail as it misses the target.", MAPENV(attacker));
   return 1;
}
