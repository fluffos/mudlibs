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

#include <sound.h>

int
main (string str)
{
   if (!str || str == "")
	 {
		message (CMD_MSG, 0,0,0, "WARNING: Your character can be killed while you are not connected, thus it is not safe to quit just anywhere, safe places are for example the inns where you can rent a room. Always think twice before quiting.", PREV(0));
		prompt_client (PREV(0), 0, "quit", "Are you sure (y/N) ? ");
		return 1;
	 }
   else if (str != "y")
	 return 1;
   
   write_client (PREV(0), CMD_SOUND, SFX_LOGOFF);
   PREV(0)->quit("Normal exit.");
   return TRUE;
}
