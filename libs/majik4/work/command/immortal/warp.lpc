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

// TODO: Fix messages :)

int 
main(string args)
{
   int *dxy,x,y;
   
   if (!args || args == "" || sscanf(args, "%d %d", x, y) != 2)
	 {
		message(CMD_MSG, 0, 0, 0, "Usage: warp <x> <y>", THIS);
		return 1;
	 }
/*   message(CMD_MSG, THIS->query_gridx(), THIS->query_gridy(), 6,
		   "$N1 {transform} into a cloud of greenish smoke and {disappear}!",
		   all_inventory(ENV(THIS)), THIS, THIS);*/
   dxy = MAPENV(THIS)->get_near_location(x,y,5);

   THIS->move(ENV(ENV(THIS)), dxy[0], dxy[1]);
/*   message(CMD_MSG, THIS->query_gridx(), THIS->query_gridy(), 6,
		   "A greenish cloud of smoke starts whirling and transforms into $N1!",
		   all_inventory(ENV(THIS)), THIS, THIS);*/
   return 1;
}

