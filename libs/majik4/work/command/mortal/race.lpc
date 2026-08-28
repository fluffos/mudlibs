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
   if (PREV(0)->query_race())
	 return 0;
   
   if (!str || str == "")
	 PREV(0)->setup (PREV(0)->query_true_name());
   else
	 {
		PREV(0)->set_race (str);
		PREV(0)->process_input (CMD_START + ":0:0.05");
		PREV(0)->setup (PREV(0)->query_true_name());
	 }
   
   return 1;
}
