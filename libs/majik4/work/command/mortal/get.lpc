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
gettable (object o)
{
   if (!o)
	 {
		message (CMD_MSG, 0,0,0, "It is not there anymore.", PREV(0));
		return 0;
	 }
   
   if (o == PREV(0))
	 {
		/* no message for such a default situation */
		return 0;
	 }
   
   if (o->is_living())
	 {
		message (CMD_MSG, 0,0,0, "$n1 doesn't want to be picked up!", PREV(0), o);
		return 0;
	 }
   
   if (strlen(o->query_no_get()) > 3)
	 {
		message (CMD_MSG, 0,0,0, o->query_no_get(), PREV(0));
		return 0;
	 }
   
   if (o->query_no_get())
	 {
		message (CMD_MSG, 0,0,0, "You can't get $o1!", PREV(0), o);
		return 0;
	 }
   
   if (o->query_weight() + PREV(0)->query_carried_weight() > PREV(0)->query_max_carry())
	 {
		message (CMD_MSG, 0,0,0, "$o1 is a little bit too heavy for you to carry.", PREV(0), o);
		return 0;
	 }

   return 1;
}

int
main (string str)
{
   object ob, *obs;
   string buf = "";
   
   if (!str || str == "")
	 {
		obs = MAPENV(PREV(0))->get_obj(PREV(0)->query_gridx(), PREV(0)->query_gridy());
		foreach (object entry in obs)
		  {
			 if(!gettable(entry))
			   obs -= ({ entry });
			 else
			   buf += entry->query_name() + ";";
		  }
		
		buf += "all;";
					 		
		if (!obs || sizeof(obs) < 1)
		  message (CMD_MSG, 0,0,0, "There are no items you could pick up.", PREV(0));
		else if (sizeof(obs) == 1)
		  main (obs[0]->query_name());
		else
		  open_window (PREV(0), 0,0,0,0, LTYPE_SELECT, "Get which item?", "get", buf);
		return 1;
	 }
   else
	 {
		if(str == "all")
		  {
			 obs = MAPENV(PREV(0))->get_obj(PREV(0)->query_gridx(), PREV(0)->query_gridy());
			 if(sizeof(obs) < 1)
			   {
				  message (CMD_MSG, 0,0,0, "There is nothing to get here.", PREV(0));
				  return 1;
			   }
			 foreach(object entry in obs)
			   {
				  if(gettable(entry))
					entry->move(PREV(0), -1, -1);
			   }
			 message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {take} all the items by $s1 feet.", MAPENV(PREV(0)), PREV(0));
			 PREV(0)->update_inv();
			 return 1;
		  }
		
		ob = present (MAPENV(PREV(0)), str, PREV(0)->query_gridx(), PREV(0)->query_gridy());
		
		if (!gettable(ob))
		  return 1;

		message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {take} $p2.", MAPENV(PREV(0)), ({ PREV(0), ob }) );
		ob->move (PREV(0), -1, -1);
		PREV(0)->update_inv();
	    return 1;
	 }
}
