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
main(string str)
{
   int i, j;
   int x, y;
   string buf = "";
   string *names;
   object *obs;
   
   x = PREV(0)->query_gridx();
   y = PREV(0)->query_gridy();
   obs = MAPENV(PREV(0))->get_targets(x, y, 3);
      
   if(!str || str == "")
	 {
		if(!obs || sizeof(obs) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "There's no-one to chat with.", PREV(0));
			 return 1;
		  }
		
		names = ({ });
		for(i=0,j=sizeof(obs);i<j;i++)
		  {
			 if(obs[i] != PREV(0))
			   names += ({ obs[i]->query_cap_name(PREV(0)) });
		  }
		
		if(sizeof(names) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "There's no-one to chat with.", PREV(0));
			 return 1;
		  }
		
		buf = implode(names,";")+";";
		open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "Select a chat target.", "chatto", buf);
		return 1;
	 }
   
   for(i=0,j=sizeof(obs);i<j;i++)
	 {
		if(obs[i]->query_name(PREV(0)) == str || obs[i]->query_cap_name(PREV(0)) == str || obs[i]->query_short(PREV(0)) == str)
		  break;
	 }
   
   PREV(0)->set_chat_target(obs[i]);
   message (CMD_MSG, 0,0,0, "Your chat target is now $N1.", PREV(0), obs[i]);
   return 1;
}
