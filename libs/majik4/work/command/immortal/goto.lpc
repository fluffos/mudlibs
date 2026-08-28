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

int
main(string str)
{
   int *coords;
   int x, y;
   object target;
   
   if(!str || str == "")
	 {
		message (CMD_MSG, 0,0,0, "Usage: goto <player>", PREV(0));
		return 1;
	 }
   
   target = find_player(str);
   if(!target)
	 {
		message (CMD_MSG, 0,0,0, capitalize(str)+" is nowhere to be found.", PREV(0));
		return 1;
	 }
   
   coords = MAPENV(PREV(0))->get_near_location(target->query_gridx(), target->query_gridy(), 3);
   if(!coords)
	 {
		message (CMD_MSG, 0,0,0, "You can't get to $n1 for some reason.", PREV(0));
		return 1;
	 }
   
   x = PREV(0)->query_gridx();
   y = PREV(0)->query_gridy();
   message (CMD_SEE, x, y, VISIBLE_RADIUS, "$n1 {vanish} in a puff of smoke.", MAPENV(PREV(0)), PREV(0));
   
   x = coords[0];
   y = coords[1];
   PREV(0)->move(MAPENV(PREV(0)), x, y);
   message (CMD_SEE, x, y, VISIBLE_RADIUS, "$n1 {arrive} in a puff of smoke.", MAPENV(PREV(0)), PREV(0));
   return 1;
}
