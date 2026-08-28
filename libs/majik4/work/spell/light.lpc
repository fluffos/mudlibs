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

inherit SPELL;

#include <spell.h>
#include <tile.h>
#include <color.h>

void
create_spell()
{
   set_spell(({ 50, 150, 0, "flaming light", "flaming light", ({"creation_fire_essence"}) }));
}

void
success(object caster, int x, int y, int level)
{  
   message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {evoke} $p2.", MAPENV(caster), ({ caster, THOB }) );
   caster->add_hb_effect("elemental light", 200, "light_on", "light_off", "light_develop");
}

void
failure(object caster, int x, int y, int level)
{
   message (CMD_SEE, x, y, VISIBLE_RADIUS, "$n1 miserably {fail} in $s1 evocation.", MAPENV(caster), caster);
}

void
light_on()
{
   THIS->set_gridlight(THIS->query_gridlight() + 5);
   THIS->update_inv();
}
 
void
light_off()
{
   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS, "$o1 $n2 withers and dies.", MAPENV(THIS), ({ THIS, THOB }) );
   THIS->set_gridlight(0);
   THIS->update_inv();
}

void
light_develop(int duration)
{
   if(!(duration % 50))
	 {
		THIS->set_gridlight(THIS->query_gridlight() - 1);
		THIS->update_inv();
		message (CMD_FEEL, 0,0,0, "Your $n1 weakens a bit.", THIS, THOB);
	 }
}
