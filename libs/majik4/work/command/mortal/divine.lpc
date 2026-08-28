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
   string chant, spell;
   object spellob;
   
   if(!str || str == "")
	 {
		message (CMD_MSG, 0,0,0, "Usage: divine <name>-<name>-<name>.", PREV(0));
		return 1;
	 }
   
   if(sscanf(str, "%s to %d %d", chant, x, y) != 3)
	 chant = str;
   
   spell = PREV(0)->handle_true_names(chant);
   if(spell == "incomplete")
	 {
		message (CMD_SEE, PREV(0)->query_gridx(), PREV(0)->query_gridy(), VISIBLE_RADIUS, "Nothing happens.", MAPENV(PREV(0)));
		return 1;
	 }
   
   spellob = SPELL_D->find_spell("truename", spell);
   if(!spellob)
	 {
		message (CMD_MSG, 0,0,0, "ERROR! No such spell ("+spell+").", PREV(0));
		return 1;
	 }
   
   if(spellob->query_targeted("truename"))
	 {
		if(!x && !y)
		  select_target(PREV(0), "divine "+chant+" to");
		else
		  PREV(0)->recite_true_name(spellob, chant, x, y);
	 }
   else 
	 PREV(0)->recite_true_name(spellob, chant, PREV(0)->query_gridx(), PREV(0)->query_gridy());
   return 1;
}
