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

string *commands = ({ "come", "go", "attack", "kill", "guard", "calm", "return" });

object
find_horseman(string str)
{
   object *obs = objects();
   foreach(object entry in obs)
	 if(entry->is_horseman() && entry->query_name() == lower_case(str) && base_name(entry) != file_name(entry))
	   return entry;
   
   return clone_object("/share/"+lower_case(str));
}
	   
int 
main(string str)
{
   string horseman, secstr, cmd, args;
   string buf = "";
   object *obs;
   object horseob;
   
   if(!str || str == "")
	 {
		if(PREV(0)->query_name() != "yorkaturr" && PREV(0)->query_name() != "sinister")
		  {
			 message (CMD_MSG, 0,0,0, "You do not have the right to command the horsemen of evil!", PREV(0));
			 return 1;
		  }
		buf += "Malice;Mayhem;Wrath;Strife;Bane;Carnage;Vengeance;Decay;Shroud;";
		open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "Order whom?", "order", buf);
		return 1;
	 }
   if(PREV(0)->query_name() != "yorkaturr" && PREV(0)->query_name() != "sinister")
	 {
		message (CMD_MSG, 0,0,0, "You do not have the right to command the horsemen of evil!", PREV(0));
		return 1;
	 }
   if(sscanf(str, "%s %s", horseman, secstr) != 2)
	 horseman = str;
   
   horseob = find_horseman(horseman);
   if(!horseob)
	 {
		message (CMD_MSG, 0,0,0, capitalize(horseman)+" is nowhere to be found.", PREV(0));
		return 1;
	 }
   
   if(!secstr)
	 {
		buf = implode(commands, ";")+";";
		open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "Order "+horseob->query_cap_name()+" what?",  "order "+horseob->query_name(), buf);
		return 1;
	 }
   
   if(!ENV(horseob))
	 horseob->do_come(PREV(0));
   else if(member_array(horseob, MAPENV(PREV(0))->get_livings(PREV(0)->query_gridx()-5,PREV(0)->query_gridy()-5,PREV(0)->query_gridx()+5,PREV(0)->query_gridy()+5)) == -1)
	 horseob->do_come(PREV(0));
   
   if(sscanf(secstr, "%s %s", cmd, args) != 2)
	 cmd = secstr;
   switch(cmd)
	 {
	  case "come":
		if(member_array(horseob, MAPENV(PREV(0))->get_livings(PREV(0)->query_gridx()-5,PREV(0)->query_gridy()-5,PREV(0)->query_gridx()+5,PREV(0)->query_gridy()+5)) == -1)
		  horseob->do_come(PREV(0));
	  	break;
	  case "go":
		if(!args)
		  {
			 PREV(0)->force_us("say Go.");
			 obs = users() - ({ PREV(0) });
			 if(sizeof(obs) < 1)
			   {
				  horseob->force_us("say There is no-one to go to, milord.");
				  return 1;
			   }
			 buf = "";
			 foreach(object entry in obs)
			   buf += entry->query_cap_name()+";";
			 horseob->force_us("say To whom dost thou wish me to go, milord?");
			 open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "Order "+horseob->query_cap_name()+" to go to whom?", "order "+horseob->query_name()+" go", buf);
			 return 1;
		  }
		PREV(0)->force_us("say Go to "+capitalize(args)+".");
		horseob->do_go(args, PREV(0));
		break;
	  case "kill":
		if(!args)
		  {
			 PREV(0)->force_us("say Kill for me.");
			 obs = users() - ({ PREV(0) });
			 if(sizeof(obs) < 1)
			   {
				  horseob->force_us("say There is no-one left to kill, milord.");
				  return 1;
			   }
			 buf = "";
			 foreach(object entry in obs)
			   buf += entry->query_cap_name()+";";
			 horseob->force_us("say Who dost thou wish me to slay, my liege?");
			 open_window(PREV(0), 0,0,0,0, LTYPE_SELECT, "Order "+horseob->query_cap_name()+" to kill whom?", "order "+horseob->query_name()+" kill", buf);
			 return 1;
		  }
		PREV(0)->force_us("say Kill "+capitalize(args)+".");
		horseob->do_kill(args, PREV(0));
		break;
	  case "attack":
		PREV(0)->force_us("say Kill everyone.");
		horseob->do_attack();
		break;
	  case "guard":
		PREV(0)->force_us("say Stand guard.");
		horseob->do_guard();
		break;
	  case "calm":
		PREV(0)->force_us("say Calm down.");
		horseob->do_calm();
		break;
	  case "return":
		PREV(0)->force_us("say Return to the abyss.");
		horseob->do_return();
		break;
	 }
   return 1;
}
