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

#include <list.h>

string *help = ({
"!     - say something (exit with <tab>)",
">     - go down",
"<     - go up",
"o     - open door",
"c     - close door",
"q     - quit",
"l     - look objects in sight",
"?     - help",
"+     - message buffer: scroll down",
"-     - message buffer: scroll up",
"*     - message buffer: toggle",
"d     - drop",
"D     - dump some debugging info",
",     - get",
"i     - inventory",
"g     - give",
"w	   - wield",
"W	   - wear",
"r     - remove eq",
"C     - enter chatprompt (exit with <tab>)",
"S     - show skills",
"t     - throw",
"s     - shoot",   
"z     - exit, a popup window for example",
"<tab> - toggle between prompt modes" });

int
main (string str)
{
   open_window (PREV(0), 0,0,0,0, LTYPE_TEXT, "Keybindings:", "noop", implode(help, ";")+";");
   return TRUE;
}
