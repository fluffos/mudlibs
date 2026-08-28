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
   int x, y;
   object *obs;
   
   if(!str || str == "")
	 {
		message (CMD_MSG, 0,0,0, "Usage: chat <subject>", PREV(0));
		return 1;
	 }
   
   x = PREV(0)->query_gridx();
   y = PREV(0)->query_gridy();
   obs = MAPENV(PREV(0))->get_livings(x-3, y-3, x+3, y+3);
   
   if(!PREV(0)->query_chat_target())
	 {
		PREV(0)->force_us("chatto");
		return 1;
	 }
   
   if(member_array(PREV(0)->query_chat_target(), obs) == -1)
	 {
		message (CMD_MSG, 0,0,0, "$N1 can't hear you now.", PREV(0), PREV(0)->query_chat_target());
		return 1;
	 }
   
   message (CMD_MSG, PREV(0)->query_gridx(),PREV(0)->query_gridy(),VISIBLE_RADIUS, "$n1 {chat} with $N2 about "+str+".", MAPENV(PREV(0)), ({ PREV(0), PREV(0)->query_chat_target() }) );
   PREV(0)->query_chat_target()->catch_message(str);
   return 1;
}
