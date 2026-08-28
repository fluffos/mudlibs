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

#include <living.h>
#include <list.h>

int
main(string str)
{
   string buf = "stand;sit;lie;";
   
   if(!str || str == "")
	 {
		open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "You are currently "+PREV(0)->query_position_string()+".", "pos", buf);
		return 1;
	 }
   
   switch(str)
	 {
	  case "stand":
	    message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {stand} up.", MAPENV(PREV(0)), PREV(0));
		PREV(0)->set_position(POS_STANDING);
		break;
		
	  case "sit":
		message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {sit} down.", MAPENV(PREV(0)), PREV(0));
		PREV(0)->set_position(POS_SITTING);
		break;
		
	  case "lie":
		message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {lie} down.", MAPENV(PREV(0)), PREV(0));
		PREV(0)->set_position(POS_LYING);
		break;
		
	  default:
		break;
	 }
   return 1;
}		
