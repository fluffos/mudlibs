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
   object target;
   string player, msg;
   
   if(!str || str == "")
	 {
		message (CMD_MSG, 0,0,0, "Usage: tell <player> <string>", PREV(0));
		return 1;
	 }
   
   if(sscanf(str, "%s %s", player, msg) != 2)
	 {
		message (CMD_MSG, 0,0,0, "Usage: tell <player> <string>", PREV(0));
		return 1;
	 }
   
   target = find_player(player);
   if(!target)
	 {
		message (CMD_MSG, 0,0,0, capitalize(player)+" is nowhere to be found.", PREV(0));
		return 1;
	 }
   
   if(!interactive(target))
	 {
		message (CMD_MSG, 0,0,0, "$N1 is link dead.", PREV(0), target);
		return 1;
	 }
   
   if(target->query_name() == PREV(0)->query_name())
	 {
		message (CMD_MSG, 0,0,0, "No point telling yourself.", PREV(0));
		return 1;
	 }
   
   message (CMD_MSG, 0,0,0, "$n1 {tell} $n2 '^cW"+msg+"^c0'.", ({ PREV(0), target }), ({ PREV(0), target }));
   return 1;
}
