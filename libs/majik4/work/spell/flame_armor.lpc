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
   set_spell(({ 120, 700, 0, "flame armor", "armor of flame", ({"creation_fire_shield"}) }));
}

void
success(object caster, int x, int y, int level)
{  
   object *people;
  
   message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {evoke} $p2.", MAPENV(caster), ({ caster, THOB }) );
   people = MAPENV(caster)->get_players(caster->query_gridx() - VISIBLE_RADIUS, caster->query_gridy() - VISIBLE_RADIUS, caster->query_gridx() + VISIBLE_RADIUS, caster->query_gridy() + VISIBLE_RADIUS);
   caster->add_hb_effect("flame armor", 50, "armor_on", "armor_off", "armor_develop"); 
}

void
failure(object caster, int x, int y, int level)
{
   message (CMD_SEE, x, y, VISIBLE_RADIUS, "$n1 miserably {fail} in $s1 evocation.", MAPENV(caster), caster);
}

void
armor_on()
{
   string *locs = THIS->query_existing_hitlocs();
   foreach(string entry in locs)
	 THIS->add_hitloc_protection(entry, "fire", 100);
}
 
void
armor_off()
{
   string *locs = THIS->query_existing_hitlocs();
   foreach(string entry in locs)
	 THIS->add_hitloc_protection(entry, "fire", -100);
   message (CMD_SEE, THIS->query_gridx(), THIS->query_gridy(), VISIBLE_RADIUS, "$o1 $n2 withers and dies.", MAPENV(THIS), ({ THIS, THOB }) );
}

void
armor_develop(int duration)
{
   string *locs = THIS->query_existing_hitlocs();
   if(duration <= 25)
	 {
		foreach(string entry in locs)
		  THIS->add_hitloc_protection(entry, "fire", 4);
	 }
   else
	 {
		foreach(string entry in locs)
		  THIS->add_hitloc_protection(entry, "fire", -4);
	 }
}
