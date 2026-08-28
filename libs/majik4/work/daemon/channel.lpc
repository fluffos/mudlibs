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

#include <security.h>

nosave mapping channels = ([
"ooc" 	: SEC_MORTAL,
"deity" : SEC_DEITY,
"god" 	: SEC_GOD
]);

int
channel (string verb, string args)
{
   int i;
   object *o;
   string chanstr, logstr;
   
   i = member_array(verb, keys(channels));
   if (i == -1)
	 return 0;
   
   if (!args || args == "")
	 {
	   	message(CMD_MSG, 0, 0, 0, "Usage: " + verb + " [message | who | last [lines]]", THIS);
		return 1;
	 }
   
   if (args == "on")
	 {
		PREV(0)->enable_channel(verb);
		message(CMD_MSG, 0, 0, 0, "Channel '" + verb + "' is now enabled.", PREV(0));
		return 1;
	 }
   if (args == "off")
	 {
		PREV(0)->disable_channel(verb);
		message(CMD_MSG, 0, 0, 0, "Channel '" + verb + "' is now disabled.", PREV(0));
		return 1;
	 }
   
   chanstr = capitalize(PREV(0)->query_name());
   logstr = chanstr;
   if (PREV(0)->query_security())
	 {
		chanstr += " ^cp<^cW" + verb + "^cp>^c0: ";
		logstr += " <" + verb + ">: ";
	 } 
   else
	 {
		chanstr += " ^cc[^cW" + verb + "^cc]^c0: ";
		logstr += " [" + verb + "]: ";
	 }
   chanstr += args;
   logstr += args;
   
   o = users();
   
   if (!PREV(0)->channel_enabled(verb))
	 {
		PREV(0)->enable_channel(verb);
		message(CMD_MSG, 0, 0, 0, "Channel '" + verb + "' is now enabled.", THIS);
	 }
   
   for (i = 0; i < sizeof(o); i++)
	 if (o[i]->channel_enabled(verb))
	   message(CMD_MSG, 0, 0, 0, chanstr, o[i]);
   log_file("channel." + verb, "[" + ctime(time())[4..15] + "] " + logstr); 
   return 1;
}

   
							   


