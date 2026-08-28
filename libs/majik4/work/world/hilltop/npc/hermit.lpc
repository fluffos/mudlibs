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

inherit LIVING;

void
create_living ()
{
   set_name ("hermit");
   set_physical(TRUE);
   set_race("human");
   set_long ("The hermit looks like he has been here for ages. He has a " +
			 "long beard which reaches down to his waist. He's trying to " +
			 "fill somekind of application with an old feather. It seems " +
			 "he has ran out of ink a long long time ago. Next to him there " +
			 "is a stack of papers.");
   
   set_talk (({
	  "Someday I will be a wizard!", 
	  "Just after I have filled this application!", 
	  "I know it!!",
	  "Maybe I'll soon be greater than Namhas itself!",
	  "I wish I already were a wizard.", 
	  "If I would just get this application filled.",
	  "This application shouldn't have any errors on it!",
	  "I hope I get this right before I run out of applications.",
   }));
   
   add_chat_subject(({"hi","hello","greetings"}),
					"Hiya!");
   add_chat_subject(({"you","work","job","occupation","hermit","name"}), 
					"Oh, you want to know about me, eh? "+
					"Well I be known as the Hermit! I've been filling up "+
					"these blasted applications for decades now and I'm sure "+
					"I will be accepted among the gods once I'm finished!");
   add_chat_subject(({"gods","god"}),
					"Aye, the Gods! This 'ere place was important back in the "+
					"days of creation you know! One of them flying rooms crashed "+
					"right where we're standing now. Shattered the mountain that stood "+
					"here to pieces it did! A good example on the power of the Gods. "+
					"One day I will be one of the Gods as well! The wise Namhas, "+
					"the malicous Sinister, the shining Aluna, the dreadful Yorkaturr, "+
					"Harum the warmonger, Dazzt the healer... mmm... When I become a God, "+
					"I will replace Namhas as the head of the Pantheon, I will! My portfolio "+
					"is same as Namhas' and there can be only ONE.");
   add_chat_subject("portfolio",
					"Portfolio? Where? ... Oh that portfolio! All the Gods have their "+
					"own portfolio you know, they call them \"Spheres of Control\". Sounds nice, "+
					"eh? Anyway, the portfolios define what the Gods can do. The higher the "+
					"God in the Pantheon, the larger is its Sphere of Control.");
   add_chat_subject(({"Pantheon","pantheon"}), 
					"The Pantheon is sort of like a divine council that decides upon things "+
					"concerning the universe. All the Gods have their places in the Pantheon. "+
					"Namhas, the Greatest of all Gods, can be thought as the chairman of the "+
					"council, he has a final say in everything, and Sinister and Aluna, the "+
					"Greater Gods, as his closest advisors. After them comes the Gods: Dazzt, "+
					"Yorkaturr and Harum, and then the lesser gods like Darshan.");
}
