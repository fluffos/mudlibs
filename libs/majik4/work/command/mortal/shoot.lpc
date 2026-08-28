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

#include <list.h>
#include <living.h>
#include <battle.h>
#include <weapon.h>
#include <tile.h>

int
collide(object shooter, object ob, object weapon, int x, int y)
{
   int i, j;
   int phys;
   object *coll;
   mixed *battarr;
   
   coll = MAPENV(shooter)->get_obj(x, y);
   phys = -1;
   if(sizeof(coll) > 0)
	 {
	  	for(i=0,j=sizeof(coll);i<j;i++)
		  {
			 if(coll[i]->query_physical() && !coll[i]->query_ethereal())
			   {
				  phys = i;
				  break;
			   }
		  }
	 }
   
   if(phys == -1)
	 {
		switch(MAPENV(shooter)->query_tile(x, y))
		  {
		   case TILE_L_CON_TREE:
		   case TILE_L_DEC_TREE:
		   case TILE_L_JUN_TREE:
			 message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 soars through the air and hits a large tree.", MAPENV(shooter), ob);
			 break;
		   case TILE_CLOSED_DOOR:
			 message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 soars through the air and hits a closed door.", MAPENV(shooter), ob);
			 break;
		   default:
			 message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 soars through the air and hits a wall.", MAPENV(shooter), ob);
			 break;
		  }
	 }
   else
	 {
		if(coll[0]->is_living())
		  {
			 battarr = allocate(WD_MAX);
			 battarr[WD_WEAPON] = ob;
			 battarr[WD_DAMTYPE] = ob->query_damage_types()[random(sizeof(ob->query_damage_types()))];
			 battarr[WD_DAMAGE] = (ob->query_type_damage(battarr[WD_DAMTYPE]) + weapon->query_missiles()[ob->query_missile_type()]) / 2;
			 battarr[WD_RANGE] = RANG_MISSILE;
			 battarr[WD_SKILL] = weapon->query_skill();
			 if(BATTLE_D->hit(shooter, coll[0], battarr) == HIT_MISS)
			   return 0;
		  }
		else
		  {
			 message (CMD_SEE, x, y, VISIBLE_RADIUS, "$p1 soars through the air and hits $n2.", MAPENV(shooter), ({ ob, coll[0] }) );
		  }
	 }
   return 1;
}
 
int
main(string str)
{
   int x, y, tx, ty;
   int sc;
   int *xy;
   float err;
   object weapon, missile;
   object *obs;
   string secstr, misstr, weapstr;
   string *missiles;
   string buf = "";
   
   if(!str || str == "")
	 {
		obs = PREV(0)->query_missile_weapons();
		if(sizeof(obs) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "You haven't armed anything you could shoot things with.", PREV(0));
			 return 1;
		  }
	
		if(sizeof(obs) > 1)
		  {
			 foreach(object entry in obs)
			   buf += entry->query_short()+";";
			 open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "What do you want to shoot with?", "shoot", buf);
			 return 1;
		  }
		else
		  {
			 weapon = obs[0];
			 PREV(0)->force_us("shoot "+weapon->query_short());
			 return 1;
		  }
	 }
   
   if(sscanf(str, "%s with %s", weapstr, secstr) != 2)
	 {
		weapon = present(PREV(0), str, -1, -1);
		if(!weapon)
		  {
			 message (CMD_MSG, 0,0,0, "You don't have "+str+".", PREV(0));
			 return 1;
		  }
		if(!weapon->is_missile_weapon())
		  {
			 message (CMD_MSG, 0,0,0, "$n1 is not a missile weapon.", PREV(0), weapon);
			 return 1;
		  }
		
		missiles = ({ });
		obs = all_inventory(PREV(0));
		foreach(object entry in obs)
		  {
			 if(weapon->query_missiles()[entry->query_missile_type()])
			   {
				  if(member_array(entry->query_short(), missiles) == -1)
					missiles += ({ entry->query_short() });
			   }
		  }
		if(sizeof(missiles) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "You don't have any missiles for $n1.", PREV(0), weapon);
			 return 1;
		  }
		if(sizeof(missiles) > 1)
		  {
			 buf = implode(missiles, ";")+";";
			 open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "What do you want to shoot?", "shoot "+weapon->query_short()+" with", buf);
			 return 1;
		  }
		PREV(0)->force_us("shoot "+weapon->query_short()+" with "+missiles[0]);
		return 1;
	 }
   
   weapon = present(PREV(0), weapstr, -1, -1);
   if(!weapon)
	 {
		message (CMD_MSG, 0,0,0, "You don't have "+weapstr, PREV(0));
		return 1;
	 }
   if(!weapon->is_missile_weapon())
	 {
		message (CMD_MSG, 0,0,0, "$n1 is not a missile weapon.", PREV(0), weapon);
		return 1;
	 }
   
   if(sscanf(secstr, "%s to %d %d", misstr, x, y) != 3)
	 {
		missile = present(PREV(0), secstr, -1, -1);
		if(!missile)
		  {
			 message (CMD_MSG, 0,0,0, "You don't have "+secstr, PREV(0));
			 return 1;
		  }
		if(!weapon->query_missiles()[missile->query_missile_type()])
		  {
			 message (CMD_MSG, 0,0,0, "You can't shoot $n1 with $n2.", PREV(0), ({ missile, weapon }) );
			 return 1;
		  }
	 	select_target(PREV(0), "shoot "+weapon->query_short()+" with "+missile->query_short()+" to");
		return 1;
	 }
        
   tx = PREV(0)->query_gridx();
   ty = PREV(0)->query_gridy();
     
   sc = PREV(0)->use_skill(weapon->query_skill(), 100, -50, 0);
   if(sc < 0)
	 {
		sc = random(abs(sc));
		sc = d("1d100") > 50 ? sc : -sc;
		err = to_float(sc) / 100.0;
	 }
   
   xy = fly(tx, ty, x, y, 50, err, MAPENV(PREV(0)));
   if(!xy)
	 {
		message (CMD_MSG, 0,0,0, "You can't shoot yourself.", PREV(0));
		return 1;
	 }
   
   missile = present(PREV(0), misstr, -1, -1);
   if(missile->is_wielded())
	 PREV(0)->remove_weapon(missile);
   
   obs = MAPENV(PREV(0))->get_message_targets(tx, ty, 50);
   message (CMD_SEE, tx, ty, VISIBLE_RADIUS, "$n1 {shoot} $p2 with $p3.", MAPENV(PREV(0)), ({ PREV(0), missile, weapon }) );
   foreach(object entry in obs)
	 write_client(entry, CMD_ANIMATE, sprintf("%d %d %d %d %d %d", to_int(missile->query_gridchar()), to_int(missile->query_gridcolor()), tx, ty, xy[0], xy[1]));
   if(!MAPENV(PREV(0))->is_clear(xy[0], xy[1]))
	 {
		collide(PREV(0), missile, weapon, xy[0], xy[1]);
		if(tx > xy[0])
		  xy[0]++;
		else if(tx < xy[0])
		  xy[0]--;
		if(ty > xy[1])
		  xy[1]++;
		else if(ty < xy[1])
		  xy[1]--;
		missile->move(MAPENV(PREV(0)), xy[0], xy[1]);
		PREV(0)->update_inv();
		return 1;
	 }
   
   missile->move(MAPENV(PREV(0)), xy[0], xy[1]);
   message (CMD_SEE, xy[0], xy[1], VISIBLE_RADIUS, "$p1 hits the ground.", MAPENV(PREV(0)), missile);
   PREV(0)->update_inv();
   return 1;
}
