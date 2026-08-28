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
main ()
{
   string stair;
   int x = PREV(0)->query_gridx(), y = PREV(0)->query_gridy();
   debug(x+"#"+y);
   stair = MAPENV(PREV(0))->find_stair (x, y);
   
   if (stair != "" && MAPENV(PREV(0))->query_tile(x, y) == '>')
	 {
		message (CMD_MSG, 0,0,0, "You climb down the stairs.", PREV(0));
		PREV(0)->move (stair, x, y);
	 }
   else
	 message (CMD_MSG, 0,0,0, "There are no stairs down here.", PREV(0));
   
   return TRUE;
}
