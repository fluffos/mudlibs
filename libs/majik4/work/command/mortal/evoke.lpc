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

int 
main(string str)
{
   int x, y;
   string spell;
   string buf = "";
   string *strs;
   object spellob;
   
   if(!str || str == "")
	 {
		strs = PREV(0)->query_spells()["elemental"];
		if(!strs || sizeof(strs) < 1)
		  {
			 message (CMD_MSG, 0,0,0, "You don't know any elemental spells.", PREV(0));
			 return 1;
		  }
		buf = implode(strs, ";")+";";
		open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "Evoke which elemental spell?", "evoke", buf);
		return 1;
	 }
   
   if(sscanf(str, "%s to %d %d", spell, x, y) != 3)
	 spell = str;
   
   if(!PREV(0)->query_has_spell("elemental",spell))
	 {
		message (CMD_MSG, 0,0,0, "You don't know how to evoke "+spell+".", PREV(0));
		return 1;
	 }
   
   spellob = SPELL_D->find_spell("elemental",spell);
   if(!spellob)
	 {
		message (CMD_MSG, 0,0,0, "ERROR! No such spell ("+spell+").", PREV(0));
		return 1;
	 }
   
   if(spellob->query_targeted("elemental"))
	 {
		if(!x && !y)
		  select_target(PREV(0), "evoke "+spell+" to");
		else
		  PREV(0)->start_elemental_spell(spellob, x, y);
	 }
   else 
	 PREV(0)->start_elemental_spell(spellob, PREV(0)->query_gridx(), PREV(0)->query_gridy());
   return 1;
}
