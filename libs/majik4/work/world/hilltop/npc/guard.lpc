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
#include <event.h>

inherit LIVING;

void
do_help (object *args)
{ 
   force_us("shout Hang on "+ args[0]->query_name() +", I'm on my way!");
   THOB->attacked_by(args[1]);
}

void
create_living()
{
   THOB->set_name("jugs");
   THOB->set_physical(TRUE);
   THOB->set_race("human");
   THOB->set_stat(A_STR, 15);
   THOB->set_stat(A_CON, 13);
   THOB->set_gender(GENDER_MALE);

   THOB->add_chat_subject("default", "Move along now.");
         
   THOB->add_event_handler(E_HELP_REQUEST, (:do_help:));
   THOB->add_skill("2h swords", 100000, 100000);
   THOB->add_skill("dodge", 80000, 80000);
   THOB->add_skill("berserker charging", 55000, 55000);
   THOB->set_active_combat_style("berserker charging");
   THOB->add_chat_subject("you", "Jugs, that is my name. My duty is to protect the innocent, and I WILL!");
}
