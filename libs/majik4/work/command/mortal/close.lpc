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
#include <door.h>

int
main (string str)
{
   mixed *arr;
   int x = PREV(0)->query_gridx(), y = PREV(0)->query_gridy();
   
   for (int i=y-1;i<y+2;i++)
	 {
		for (int j=x-1;j<x+2;j++)
		  {
			 if (arr = MAPENV(PREV(0))->query_door(j, i))
			   {
				  if (arr[1] == DOOR_OPEN)
					{
					   if (i == y && j == x)
						 {
							message (CMD_SEE, 0,0,0, "You have to move to either side of the door before closing it.", PREV(0));
							return TRUE;
						 }
					   else
						 {
							write_client (THOB, CMD_SOUND, SFX_CLOSE_DOOR);
							message (CMD_SEE, x, y, VISIBLE_RADIUS, "$N1 {close} a door.", MAPENV(PREV(0)), PREV(0));
							
							MAPENV(PREV(0))->update_door (j, i, arr[0], DOOR_CLOSED, arr[2]);
							return TRUE;
						 }
					}
				  else
					{
					   message (CMD_MSG, 0,0,0, "THe door is closed already.", PREV(0));
					   return TRUE;
					}
			   }
		  }
	 }
   
   message (CMD_SEE, 0,0,0, "There is no open door in your reach.", PREV(0));
   return TRUE;
}
