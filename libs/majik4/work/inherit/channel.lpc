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

string *channels;

void 
enable_channel (string chan)
{
   if (!channels)
	 channels = ({ chan });
   if (member_array(chan, channels) == -1)
	 channels += ({ chan });
}

void
disable_channel (string chan)
{
   if (!channels)
	 channels = ({ });
   channels -= ({ chan });
}

int
channel_enabled (string chan)
{
   if (!channels)
	 channels = ({ });
   if (member_array(chan, channels) != -1)
	 return 1;
   return 0;
}
