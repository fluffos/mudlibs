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
   int x, y;
   int middle;
   string *slices;
   string buf = "";
   object player;
   
   if(!str || str == "")
	 {
		message (CMD_MSG, 0,0,0, "Usage: view <player>.", PREV(0));
		return 1;
	 }
   
   player = find_player(str);
   if(!player)
	 {
		message (CMD_MSG, 0,0,0, capitalize(str)+" is nowhere to be found.", PREV(0));
		return 1;
	 }
   
   x = player->query_gridx();
   y = player->query_gridy();
   
   slices = MAPENV(player)->query_map(x-10,y-6,x+10,y+6);
   buf = implode(slices, ";")+";";
   middle = strlen(buf) / 2 - 1;
   buf[middle..middle] = "@";
   buf = replace_string(buf, "g", ".");
   buf = replace_string(buf, "W", "#");
   buf = replace_string(buf, "w", ".");
   buf = replace_string(buf, "s", ".");
   buf = replace_string(buf, "0", ".");
   buf = replace_string(buf, "S", "#");
   open_window(PREV(0), 0,0,0,0, LTYPE_TEXT, "Gridmap view of "+player->query_cap_name()+":", "noop", buf);
   return 1;
}
