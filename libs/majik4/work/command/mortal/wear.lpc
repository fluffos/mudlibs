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

int
main (string str)
{
   int i, j;
   int worn;
   object o, *obs;
   string buf = "";
   string *targ;
   string *strs;
   
   if(!str || str == "")
	 {
		strs = ({ });
		obs = all_inventory(PREV(0));
		for(i=0,j=sizeof(obs);i<j;i++)
		  {
			 if(obs[i]->is_clothing() || obs[i]->is_armor())
			   strs += ({ obs[i]->query_name() });
		  }
		
		if(sizeof(strs) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "You do not have anything you could wear.", PREV(0));
			 return 1;
		  }
		
		buf = implode(strs,";")+";";
		open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "What do you want to wear?", "wear", buf);
		return 1;
	 }
   
   obs = all_inventory(PREV(0));
   foreach(object entry in obs)
	 {
		if(entry->query_name() == str || entry->query_short() == str)
		  {
			 if(entry->is_worn())
			   worn = 1;
			 else
			   {
				  o = entry;
				  break;
			   }
		  }
	 }
   
   if(!o)
	 {
		if(worn)
		  message (CMD_MSG, 0,0,0, "You are already wearing "+str+".", PREV(0));
		else
		  message (CMD_MSG, 0,0,0, "You don't have "+str+".", PREV(0));
		return 1;
	 }
   if(!o->is_clothing())
	 {
		message (CMD_MSG, 0,0,0, "You can't wear $n1.", PREV(0), o);
		return 1;
	 }
   targ = o->query_target();
   for(i=0,j=sizeof(targ);i<j;i++)
	 {
		if(stringp(PREV(0)->query_worn_item(targ[i])))
		  {
			 message (CMD_MSG, 0,0,0, "You are already wearing $n1 in your "+targ[i]+".", PREV(0), PREV(0)->query_worn_item_from_hitloc(targ[i]));
			 return 1;
		  }
	 }
   
   if(o->is_wielded())
	 PREV(0)->remove_weapon(o);
		
   PREV(0)->wear(o);
   message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "You wear $n1.", PREV(0), o);
   return 1;
}
