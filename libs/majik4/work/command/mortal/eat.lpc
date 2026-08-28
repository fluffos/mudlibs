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
main (string str)
{
   object o;
   
   if (!str)
	 {
		message (CMD_MSG, 0,0,0, "Eat what?", PREV(0));
		return 1;
	 }
   
   o = present (PREV(0), str);
   
   if (o)
	 {
		message (CMD_SEE, PREV(0)->query_gridx(),PREV(0)->query_gridy(),VISIBLE_RADIUS, "$n1 {eat} $p2.", MAPENV(PREV(0)), ({ PREV(0), o }));
		destruct (o);
	 }
   else
	 message (CMD_MSG, 0,0,0, "You don't have "+str+".", PREV(0));
   
   return 1;
}
