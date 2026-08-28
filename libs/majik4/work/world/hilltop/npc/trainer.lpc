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

inherit LIVING;

void
do_teach(string skill)
{
   if(!skill || skill == "" || (skill != "daggers" && skill != "dodge"))
	 {
		THOB->force_us("say So, you would like to learn, eh? I can teach you about 'daggers' and 'dodge'.");
		return;
	 }
  
  THOB->force_us("say I shall provide you with some pointers about "+skill+"...");
  THOB->teach_skill(skill, THIS);
}

void
create_living()
{
   THOB->set_name("darklash");
   THOB->set_physical(TRUE);
   THOB->set_race("human");
   THOB->set_stat(A_STR, 13);
   THOB->set_stat(A_DEX, 15);
   THOB->set_stat(A_AGI, 14);
   THOB->set_stat(A_CON, 11);
   THOB->set_gender(GENDER_MALE);
   THOB->set_long("This tall and sleek man is wearing a fine, expensive-looking black robe "+
				  "tied together with a black leather belt with a rather heavy steel buckle, "+
				  "and a pair of gleaming black leather boots. He has short black hair, a thin "+
				  "beard and a deep sickle-shaped pink scar on his right cheek. He has several "+
				  "daggers under his belt and their blades are exposed. He has deep black eyes "+
				  "and an impenetrable gaze."); 
   
   THOB->add_chat_subject(({"training","train","trainer"}), "Yes, I am a trainer... And a good one at that. Would you like me to teach you something?");
   THOB->add_chat_subject(({"teach","teaching","teacher"}), (:do_teach:));
   THOB->add_chat_subject("default", "Yeah, yeah...");
   THOB->add_chat_subject("you", "My name is Darklash, a test npc trainer. I can teach daggers and dodge.");
      
   THOB->add_skill("daggers", 500000, 500000);
   THOB->add_skill("dodge", 300000, 300000); 
   THOB->add_skill("teaching", 85000, 85000);
}
