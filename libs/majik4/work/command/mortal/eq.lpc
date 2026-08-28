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

string
resolve_eq_string(object ob)
{
   string retstr;
   string *strs;

   if(ob->is_worn())
	 {
		retstr = "Worn in ";
		strs = PREV(0)->query_item_worn_in(ob);
	 }
   else
	 {
		retstr = "Wielded in ";
		strs = PREV(0)->query_weapon_wielded_in(ob);
	 }
   retstr += enumerize(strs) + ": "+ob->query_short()+".";
   return wrap(retstr);
}

int
main ()
{
   int i, j;
   string buf = "";
   object *eqs = PREV(0)->query_wielded_weapons() + PREV(0)->query_worn_items();
   if(sizeof(eqs) < 1)
	 {
		message (CMD_MSG, 0,0,0, "You don't have any equipment.", PREV(0));
		return 1;
	 }
   for(i=0,j=sizeof(eqs);i<j;i++)
	 {
		buf += resolve_eq_string(eqs[i])+";";
	 }
   open_window(PREV(0), 0,0,0,0, LTYPE_TEXT, "You have the following equipment:", "eq", implode(explode(wrap(buf, 50), "\n"), ";") + ";");
   return 1;
}
