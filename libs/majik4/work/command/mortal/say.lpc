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

#include <living.h>

int
main (string str)
{
   string verb;
   
   if(!str || str == "") 
	 {
		message (CMD_MSG, 0,0,0, "Say what?", PREV(0));
		return TRUE;
	 }
   
   if(PREV(0)->query_uncons())
	 return TRUE;
      
   switch(str[<1])
	 {
	  case '?':
		verb = "ask";
		break;
	  case '!':
		verb = "exclaim";
		break;
	  case '.':
		verb = "say";
		break;
	  default:
		verb = "say";
		str += ".";
		break;
	 }
   
   message (CMD_HEAR, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "$n1 {"+verb+"}, '^cW" + str + "^c0'", MAPENV(PREV(0)), PREV(0));
   if(PREV(0)->query_verbal_meaning(lower_case(str[0..<2])))
	 {
		if(!PREV(0)->query_magic_style() || PREV(0)->query_magic_style() == "")
		  PREV(0)->set_magic_style(SPELL_D->query_symbol_style(lower_case(str[0..<2])));
		PREV(0)->add_spell_component(PREV(0)->query_verbal_meaning(lower_case(str[0..<2])), PREV(0)->query_stat(A_POW));
	 }
   return TRUE;
}
