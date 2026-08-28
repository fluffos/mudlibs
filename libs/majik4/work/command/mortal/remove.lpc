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
#include <natweap.h>

object creature;

int
disarm(string weapon)
{
   if(!creature->query_natural_weapons()[weapon])
	 return 0;
   
   message (CMD_MSG, 0,0,0, "You are no longer attacking with "+weapon+".", creature);
   creature->disarm(weapon);
   return 1;
}

int
main (string str)
{
   int i, j;
   int notequipped;
   string item;
   string buf = "";
   object o, *obs;
   string *strs;
   
   creature = PREV(0);
   
   if(!str || str == "")
	 {
		strs = ({ });
		obs = all_inventory(creature);
		for(i=0,j=sizeof(obs);i<j;i++)
		  {
			 if(obs[i]->is_worn())
			   {
				  strs += ({ obs[i]->query_name()+" ("+enumerize(creature->query_item_worn_in(obs[i]))+")" });
			   }
			 else if(obs[i]->is_wielded())
			   {
				  strs += ({ obs[i]->query_name()+" ("+enumerize(creature->query_weapon_wielded_in(obs[i]))+")" });
			   }
		  }
		strs += creature->query_armed_natural_weapons();
	    
		if(sizeof(strs) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "You are not wearing or wielding anything.", creature);
			 return 1;
		  }
		
		buf = implode(strs,";")+";";
		open_window(creature, 0,0,0,0, LTYPE_SELECT, "What do you want to remove?", "remove", buf);
		return 1;
	 }
   
   if(sscanf(str, "%s (%*s)", item) != 2)
	 item = str;

   obs = all_inventory(creature);
   foreach(object entry in obs)
	 {
		if(entry->query_name() == item || entry->query_short() == item)
		  {
			 if(!entry->is_wielded() && !entry->is_worn())
			   notequipped = 1;
			 else
			   {
				  o = entry;
				  break;
			   }
		  }
	 }
   
   if(!o)
	 {
		if(disarm(item))
		  return 1;
		
		if(notequipped)
		  message (CMD_MSG, 0,0,0, "You have not equipped "+item+".", creature);
		else
		  message (CMD_MSG, 0,0,0, "You do not have "+item+".", creature);
		return 1;
	 }
      
   message (CMD_SEE, creature->query_gridx(), creature->query_gridy(), VISIBLE_RADIUS, "$n1 {remove} $n2.", creature, ({ creature, o }));
   if(o->is_wielded())
	 creature->remove_weapon(o);
   else
	 creature->strip(o);
   return 1;
}
