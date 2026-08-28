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

inherit BANK;

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
   THOB->set_name("banker");
   THOB->set_physical(TRUE);
   THOB->set_race ("human");
   THOB->set_gender(GENDER_MALE);
   THOB->set_long("This guy looks like a bank.");
   THOB->add_chat_subject(({ "deposit" }), (: do_deposit :));
   THOB->add_chat_subject(({ "withdraw"  }), (: do_withdraw :));
   THOB->add_chat_subject(({ "balance" }), (: do_balance :));
   THOB->add_chat_subject(({ "transfer" }), (: do_transfer :));
   THOB->add_chat_subject(({ "loan" }), (: do_loan :));
   THOB->add_chat_subject("you", "I'm a bank officer. This is the best bank in the whole hilltop. You can deposit, withdraw, balance, transfer and loan here.");
}

void
create_bank ()
{
}
