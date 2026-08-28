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
   set_spell(({ 100, 400, 1, "fireball", "ball of fire", ({"creation_fire_sphere"}) }));
}

void
collide(object caster, int x, int y, int level)
{
   int xdist, ydist, divisor;
   object *obs;
   mixed *battarr;
   
   obs = MAPENV(caster)->get_livings(x - 3, y - 3, x + 3, y + 3);
   message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 explodes in the air.", MAPENV(caster), THOB);
   
   foreach(object entry in obs)
	 {
		x > entry->query_gridx() ? xdist = x - entry->query_gridx() : xdist = entry->query_gridx() - x;
		y > entry->query_gridy() ? ydist = y - entry->query_gridy() : ydist = entry->query_gridy() - y;
		xdist < ydist ? divisor = xdist : divisor = ydist;
		if(!divisor)
		  divisor = 1;
		battarr = ({ THOB, "fire", (level + 80) / divisor, "missile", 0, "spell direction" });
		BATTLE_D->hit(caster, entry, battarr);
	 }
}
		 
void
success(object caster, int x, int y, int level)
{
   int *xy;
   int dist;
   int sc;
   float err;
   object *people;
   
   sc = caster->use_skill("spell direction", 100, -50, 0);
   if(sc < 0)
	 {
		sc = random(abs(sc));
		sc = d("1d100") > 50 ? sc : -sc;
		err = to_float(sc) / 100.0;
	 }
   message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {evoke} $p2.", MAPENV(caster), ({ caster, THOB }) );
   dist = caster->query_skill_chance("utilization of fire");
   xy = fly(caster->query_gridx(), caster->query_gridy(), x, y, dist, err, MAPENV(caster));
   if(!xy)
	 {
		collide(caster, x, y, level);
		return;
	 }
   if(dist > VISIBLE_RADIUS)
	 people = MAPENV(caster)->get_players(caster->query_gridx() - dist, caster->query_gridy() - dist, caster->query_gridx() + dist, caster->query_gridy() + dist);
   else
	 people = MAPENV(caster)->get_players(caster->query_gridx() - VISIBLE_RADIUS, caster->query_gridy() - VISIBLE_RADIUS, caster->query_gridx() + VISIBLE_RADIUS, caster->query_gridy() + VISIBLE_RADIUS);
   
   foreach(object entry in people)
	 write_client(entry, CMD_ANIMATE, sprintf("%d %d %d %d %d %d", '*', C_RED, caster->query_gridx(), caster->query_gridy(), xy[0], xy[1]));
   
   if(!MAPENV(caster)->is_clear(xy[0], xy[1]))
	 {
		collide(caster, xy[0], xy[1], level);
	 }
   else
	 {
		message (CMD_SEE, xy[0], xy[1], VISIBLE_RADIUS, "$p1 withers and dies in the air.", MAPENV(caster), THOB);
	 }
}

void
failure(object caster, int x, int y, int level)
{
   int i, j;
   int *xy;
   object *people;
   string *locs;
   
   switch(level)
	 {
	  case -25..0:
		message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {fail} in $s1 spell but {manage} to conjure a puff of smoke.", MAPENV(caster), caster);
		break;
	  case -50..-26:
		message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {lose} $s1 concentration on the spell and {send} it off to a random direction.", MAPENV(caster), caster);
		xy = MAPENV(caster)->get_near_location(caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS);
		xy = fly(caster->query_gridx(), caster->query_gridy(), xy[0], xy[1], d("1d10+2"), random(3), MAPENV(caster));
		people = MAPENV(caster)->get_message_targets(caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS);
		foreach(object entry in people)
		  write_client(entry, CMD_ANIMATE, sprintf("%d %d %d %d %d %d", '*', C_RED, caster->query_gridx(), caster->query_gridy(), xy[0], xy[1]));
		if(!MAPENV(caster)->is_clear(xy[0], xy[1]))
		  collide(caster, xy[0], xy[1], random(abs(level)) + 1);
		else
		  message (CMD_SEE, xy[0], xy[1], VISIBLE_RADIUS, "$p1 withers and dies in the air.", MAPENV(caster), THOB);
		break;
	  default:
		locs = ({ });
		for(i=0,j=random(sizeof(caster->query_existing_hitlocs()));i<j;i++)
		  locs += ({ caster->query_random_existing_hitloc() });
		message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 miserably {fumble} $s1 spell with grave results...", MAPENV(caster), caster);
		message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {hit} $t1 with $s1 $n2.", MAPENV(caster), ({ caster, THOB }), caster);
		message (CMD_FEEL, 0,0,0, "You hit yourself with your $n1.", caster, THOB);
		for(i=0,j=sizeof(locs);i<j;i++)
		  caster->damage_hitloc(locs[i], "fire", random(abs(level)) + 1);
		break;
	 }
}
