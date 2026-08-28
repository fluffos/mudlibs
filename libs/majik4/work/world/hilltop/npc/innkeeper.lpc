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

#include <event.h>

inherit SHOP;

void
create_living ()
{
   set_name("innkeeper");
   set_long("This guy looks like an innkeeper. You can buy, sell or list items with him.");
   set_gender (1);
   set_physical(TRUE);
   set_race ("human");
   THOB->add_chat_subject(({ "buy" }), (:do_buy:));
   THOB->add_chat_subject(({ "sell" }), (:do_sell:));
   THOB->add_chat_subject(({ "list" }), (:do_list:));
   THOB->add_chat_subject("you", "I'm an innkeeper. Buy some drinks from me!");
}

void
create_shop ()
{
   set_max_value (0);
}

void 
attacked_by(object obj)
{
   if (add_enemy(obj))
	 {
		force_us("shout HELP! I'm being attacked!");
		MAPENV(THOB)->get_targets(THOB->query_gridx(), THOB->query_gridy())
		  ->receive_event(E_HELP_REQUEST, ({THOB, obj}));
		if (!enemy)
		  enemy = obj;
	 }
}

