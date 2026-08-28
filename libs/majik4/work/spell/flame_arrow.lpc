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
   set_spell(({ 80, 200, 1, "flame arrow", "arrow of flame", ({ "creation_fire_arrow"}) }));
}

void
collide(object caster, int x, int y, int level)
{
   object *obs;
   mixed *battarr;
   
   obs = MAPENV(caster)->get_obj(x, y);
   if(sizeof(obs) < 1)
	 {
		switch(MAPENV(caster)->query_tile(x, y))
		  {
		   case TILE_L_CON_TREE:
		   case TILE_L_JUN_TREE:
		   case TILE_L_DEC_TREE:
			 message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 soars through the air and hits a large tree.", MAPENV(caster), THOB);
			 break;
		   case TILE_CLOSED_DOOR:
			 message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 soars through the air and hits a closed door.", MAPENV(caster), THOB);
			 break;
		   default:
			 message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 soars through the air and hits a wall.", MAPENV(caster), THOB);
			 break;
		  }
	 }
   else
	 {
		foreach(object entry in obs)
		  {
			 if(entry->query_physical() && entry != caster && !entry->query_ethereal())
			   {
				  if(entry->is_living())
					{
					   battarr = ({ THOB, "fire", level + 50, "missile", 0, "spell direction" });
					   BATTLE_D->hit(caster, entry, battarr);
					}
				  else
					{
					   message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 soars through the air and hits $p2.", MAPENV(caster), ({ THOB, entry }));
					}
			   }
		  }
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
   
   sc = caster->use_skill("spell direction", 100, -25, 0);
   if(sc < 0)
	 {
		sc = random(abs(sc));
		sc = d("1d100") > 50 ? sc : -sc;
		err = to_float(sc) / 100.0;
	 }
   message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {call} forth $p2.", MAPENV(caster), ({ caster, THOB }) );
   dist = 20;
    
   xy = fly(caster->query_gridx(), caster->query_gridy(), x, y, dist, err, MAPENV(caster));
   if(!xy)
	 {
		message (CMD_MSG, 0,0,0, "You can't shoot yourself.", caster);
		return;
	 }
   
   if(dist > VISIBLE_RADIUS)
	 people = MAPENV(caster)->get_players(caster->query_gridx() - dist, caster->query_gridy() - dist, caster->query_gridx() + dist, caster->query_gridy() + dist);
   else
	 people = MAPENV(caster)->get_players(caster->query_gridx() - VISIBLE_RADIUS, caster->query_gridy() - VISIBLE_RADIUS, caster->query_gridx() + VISIBLE_RADIUS, caster->query_gridy() + VISIBLE_RADIUS);
   
   foreach(object entry in people)
	 write_client(entry, CMD_ANIMATE, sprintf("%d %d %d %d %d %d", '/', C_RED, caster->query_gridx(), caster->query_gridy(), xy[0], xy[1]));
   if(!MAPENV(caster)->is_clear(xy[0], xy[1]))
	 {
		collide(caster, xy[0], xy[1], level);
	 }
   else
	 {
		message (CMD_SEE, xy[0], xy[1], VISIBLE_RADIUS, "$p1 soars through the air and scorches the ground.", MAPENV(caster), THOB);
		MAPENV(caster)->update_tile(xy[0], xy[1], "b");
	 }
}

void
failure(object caster, int x, int y, int level)
{
   int *xy;
   string loc;
   object *people;
   
   switch(level)
	 {
	  case -25..0:
		message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {fail} in $s1 spell but {manage} to conjure a puff of smoke.", MAPENV(caster), caster);
		break;
	  case -50..-26:
		message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {lose} $s1 concentration on the spell and {send} it off to a random direction.", MAPENV(caster), caster);
		xy = MAPENV(caster)->get_near_location(caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS);
		xy = fly(caster->query_gridx(), caster->query_gridy(), xy[0], xy[1], d("1d10+2"), random(4), MAPENV(caster));
		people = MAPENV(caster)->get_message_targets(caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS);
		foreach(object entry in people)
		  write_client(entry, CMD_ANIMATE, sprintf("%d %d %d %d %d %d", '/', C_RED, caster->query_gridx(), caster->query_gridy(), xy[0], xy[1]));
		if(!MAPENV(caster)->is_clear(xy[0], xy[1]))
		  {
			 collide(caster, xy[0], xy[1], random(abs(level)) + 1);
		  }
		else
		  {
			 message (CMD_SEE, xy[0], xy[1], VISIBLE_RADIUS, "$p1 soars through the air and scorches the ground.", MAPENV(caster), THOB);
			 MAPENV(caster)->update_tile(xy[0], xy[1], "b");
		  }
		break;
	  default:
		loc = caster->query_target_hitloc();
		message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 miserably {fumble} $s1 spell with grave results...", MAPENV(caster), caster);
		message (CMD_SEE, caster->query_gridx(), caster->query_gridy(), VISIBLE_RADIUS, "$n1 {hit} $t1 in the "+loc+" with $s1 $n2.", MAPENV(caster), ({ caster, THOB }), caster);
		message (CMD_FEEL, 0,0,0, "You hit yourself in the "+loc+" with your $n1.", caster, THOB); 
		caster->damage_hitloc(loc, "fire", random(abs(level)) + 1);
		break;
	 }
}
