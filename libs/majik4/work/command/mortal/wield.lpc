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
#include <weapon.h>
#include <hitloc.h>
#include <natweap.h>

object wielder;

int
arm(string str)
{
   if(!wielder->query_natural_weapons()[str])
	 return 0;
  
   if(wielder->query_natural_weapon_cond(str) != NATWEAP_OK)
	 {
		message (CMD_MSG, 0,0,0, "Try as you might, you cannot arm "+str+".", wielder);
		return 0;
	 }
   wielder->arm(str);
   message (CMD_MSG, 0,0,0, "You are now attacking with "+str+".", wielder);
   return 1;
}

int
main (string str)
{
   int i, j;
   int wielded;
   object o, *obs;
   string weaponstr, weapon, locstr, *locs;
   string buf = "";
   string *strs;
   
   wielder = PREV(0);
   
   if(!str || str == "")
	 {
		strs = ({ });
		obs = all_inventory(wielder);
		for(i=0,j=sizeof(obs);i<j;i++)
		  {
			 if(!obs[i]->is_worn())
			   strs += ({ obs[i]->query_name() });
			 if(obs[i]->is_wielded())
			   strs[member_array(obs[i]->query_name(), strs)] += " ("+enumerize(wielder->query_weapon_wielded_in(obs[i]))+")";
		  }
		strs += wielder->query_usable_natural_weapons();
				  
		if(sizeof(strs) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "You do not have anything you could wield.", wielder);
			 return 1;
		  }
		
		buf = implode(strs, ";")+";";
		open_window(wielder, 0,0,0,0, LTYPE_SELECT, "What do you want to wield?", "wield", buf);
		return 1;
	 }
   
   if(sscanf(str, "%s in %s", weaponstr, locstr) == 2)
	 {
		if(sscanf(weaponstr, "%s (%*s)", weapon) != 2)
		  weapon = weaponstr;
		
		obs = all_inventory(wielder);
		foreach(object entry in obs)
		  {
			 if(entry->query_name() == weapon || entry->query_short() == weapon)
			   {
				  if(entry->is_wielded())
					wielded = 1;
				  else
					{
					   o = entry;
					   break;
					}
			   }
		  }
		
		if(!o)
		  {
			 if(arm(weapon))
			   return 1;
			 
			 if(wielded)
			   message (CMD_MSG, 0,0,0, "You are already wielding "+weapon+".", wielder);
			 else
			   message (CMD_MSG, 0,0,0, "You don't have "+weapon+".", wielder);
			 return 1;
		  }
			 
		locs = allocate(2);
		if(sscanf(locstr, "%s and %s", locs[0], locs[1]) != 2)
		  locs = ({ locstr });
			
		for(i=0,j=sizeof(locs);i<j;i++)
		  {
			 if(!wielder->query_hitlocs()[locs[i]])
			   {
				  message (CMD_MSG, 0,0,0, "You don't have a "+locs[i]+".",wielder);
				  return 1;
			   }
			 if(wielder->query_wielded_weapon_from_hitloc(locs[i]))
			   {
				  wielder->remove_weapon(wielder->query_wielded_weapon_from_hitloc(locs[i]));
			   }
			 if(wielder->query_hitloc_cond(locs[i]) != HITLOC_OK)
			   {
				  message (CMD_MSG, 0,0,0, "Alas, your "+locs[i]+" is in no condition to wield weapons.", wielder);
				  return 1;
			   }
		  }
		
		message (CMD_SEE, wielder->query_gridx(), wielder->query_gridy(), VISIBLE_RADIUS, "$n1 {wield} $p2 in $s1 "+locstr+".", MAPENV(wielder), ({ wielder, o }));
		wielder->wield(o, locs);
		return 1;
	 }
   else
	 {
		if(sscanf(str, "%s (%*s)", weapon) != 2)
		  weapon = str;
		
		if(!weapon)
		  return 1;
		
		obs = all_inventory(wielder);
		foreach(object entry in obs)
		  {
			 if(entry->query_name() == weapon || entry->query_short() == weapon)
			   {
				  if(entry->is_wielded())
					wielded = 1;
				  else
					{
					   o = entry;
					   break;
					}
			   }
		  }
		
		if(!o)
		  {
			 if(arm(weapon))
			   return 1;
			 			  
 			 if(wielded)
			   message (CMD_MSG, 0,0,0, "You are already wielding "+weapon+".", wielder);
			 else
			   message (CMD_MSG, 0,0,0, "You don't have "+weapon+".", wielder);
			 return 1;
		  }
		strs = wielder->query_possible_wield_hitlocs(o);
		if(sizeof(strs) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "You are not able to wield $n1.", wielder, o);
			 return 1;
		  }
		buf = implode(strs,";")+";";
		open_window(wielder, 0,0,0,0, LTYPE_SELECT, "Where do you want to wield it?", "wield "+o->query_name()+" in", buf);
		return 1;
	 }
}
