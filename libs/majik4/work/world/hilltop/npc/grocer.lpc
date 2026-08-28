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
#include <living.h>

inherit SHOP;

void
attacked_by(object obj)
{
   if (add_enemy(obj))
	 {
		force_us("shout HELP! I'm being attacked!");
		MAPENV(THOB)->get_targets(THOB->query_gridx(), THOB->query_gridy())
		  ->receive_event(E_HELP_REQUEST, ({ THOB, obj }));
		if (!enemy)
		  enemy = obj;
	 }
}


void
create_living ()
{
   set_name("grocer");
   set_long("This guy looks like a grocer. You can buy, sell or list items with him.");
   set_physical(TRUE);
   set_race ("human");
   set_gender(GENDER_MALE);
   
   THOB->add_chat_subject(({ "buy" }), (:do_buy:));
   THOB->add_chat_subject(({ "sell" }), (:do_sell:));
   THOB->add_chat_subject(({ "list" }), (:do_list:));
   THOB->add_chat_subject("you", "Hello. You are talking to the proud owner of the most best grocery. You can buy, sell and list here.");
}

void
create_shop ()
{
   set_max_value (5000);
}
