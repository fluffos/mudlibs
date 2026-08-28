#include <lib.h>
#include <armour_class.h>
inherit LIB_DAEMON;
string GetArmourClass(int ac);
string BuildPrint(string var, string limb, object who, int color, string filter);
string ColorizeDamage(string str, int dmg);

mixed cmd(string args) {
  object who;
  string targstr;
  array limbs;
  string ret;
  string arms;
  string torso;
  string head;
  string legs;
  string other;
  int color = 0;
  string filter = "none";

  if (args) {
    if (member_array("-c", explode(args, " ")) != -1) {
	color=1;
	args = replace_string(args, "-c","");
     }
    if (member_array("damaged", explode(args, " ")) != -1) {
	filter = "damaged";
	args = replace_string(args, "damaged","");
     }
     args = replace_string(args, " ", ""); // remove extra spaces
   }

  if (creatorp(this_player()) && (!args)) {
    return "You must specify a target.";
   }
  if (!creatorp(this_player())) { who = this_player(); }
  else { who = find_living(args); }
  if (!who) {
    return "No such person.";
    }
  if (who == this_player()) { targstr = "You are "; }
     else { targstr = who->GetCapName() + " is "; }

  limbs = sort_array(who->GetLimbs(), 1);
  // This next line can be removed once all players have died or been given new bodies/limbs.
  // see http://bugs.havenmud.com/scp/tickets.php?id=376 for more infos. - Mel
  this_player()->eventPrint("** WARNING **\nIf you do not see any output or are missing limbs from the display, please let am IMM know.");
  foreach(string local in limbs) {
	if(who->GetLimbClass(local) == 1 && sizeof(who->GetLimbChildren(local)) > 1) {
		torso = local + ":\n"; //this is my main limb
		if(sizeof(who->GetWorn(local))) torso += BuildPrint(torso, local, who, color, filter);
		foreach(string limb in sort_array(who->GetLimbChildren(local), 1)) {
			if(regexp(limb, "^head$")) {
				head = limb + ":\n";
				if(sizeof(who->GetWorn(limb))) head += BuildPrint(head, limb, who, color, filter);
			}
			if(regexp(limb,  "arm$")) { 
				if(arms) {
					arms += limb + ":\n";
					if(sizeof(who->GetWorn(limb))) arms += BuildPrint(arms, limb, who, color, filter);
				} else {
					arms = limb + ":\n";
                    if(sizeof(who->GetWorn(limb))) arms += BuildPrint(arms, limb, who, color, filter); 
				}
				foreach(string subchild in who->GetLimbChildren(limb)) {
					arms += subchild + ":\n";
					if(sizeof(who->GetWorn(subchild))) arms += BuildPrint(arms, subchild, who, color, filter);
				}
			}
            if(regexp(limb,  "leg$")) { 
                if(legs) {
                    legs += limb + ":\n";
                    if(sizeof(who->GetWorn(limb))) legs += BuildPrint(legs, limb, who, color, filter);
                } else {
                    legs = limb + ":\n";
                    if(sizeof(who->GetWorn(limb))) legs += BuildPrint(legs, limb, who, color, filter);        
                }
            	foreach(string subchild in who->GetLimbChildren(limb)) {
               		 legs += subchild + ":\n";
               		 if(sizeof(who->GetWorn(subchild))) legs += BuildPrint(legs, subchild, who, color, filter);
            	}
            }
			// Other limbs done here -> tail/wings/etc
			if(!regexp(limb, "(leg$|arm$|^head$|^torso$)")) {
				if(!other) {
					other = limb + ":\n";
					if(sizeof(who->GetWorn(limb))) other += BuildPrint(other, limb, who, color, filter);
				} else {
					other += limb + ":\n";
					if(sizeof(who->GetWorn(limb))) other += BuildPrint(other, limb, who, color, filter);
				}
                foreach(string subchild in who->GetLimbChildren(limb)) { //this is probably unnecessary but
                     other += subchild + ":\n";                          //added for good measure
                     if(sizeof(who->GetWorn(subchild))) other += BuildPrint(legs, subchild, who, color, filter);
                }

			} 
		}
	
		ret = head + torso; 
		if(arms) ret = ret + arms; 
		if(legs) ret = ret + legs;
		if(other) ret = ret + other; 
		this_player()->eventPrint(ret);
	}

	}   
	return 1;
}

string BuildPrint(string var, string limb, object who, int color, string filter) {
	string x;
	string det_str;
	int det;
	
    foreach(object thing in (who->GetWorn(limb))) {
		det = thing->GetDeterioration();
		if (color == 1) {
			det_str = ColorizeDamage((det * 10) + "% damaged", det);
		} else {
			det_str = sprintf("%i%% damaged", (det * 10));
		}
		if(!x) {
			if (det == 0 && filter == "damaged") {
				x = "";
			} else {
				x = sprintf("   (%s) %s (%s)\n", 
					GetArmourClass(thing->GetArmourClass()), 
					thing->GetKeyName(),
					det_str 
					);
			}
		} else {
			if (det == 0 && filter == "damaged") {
				x = x;
			} else {
				x += sprintf("   (%s) %s (%s)\n",
					GetArmourClass(thing->GetArmourClass()),
					thing->GetKeyName(),
					det_str
					);
			}
		}
	}
	return x;
}

string ColorizeDamage(string str, int dmg) {
	string c;
	if (dmg == 0) c = str;
	if (dmg > 0 && dmg <= 3) c = "%^YELLOW%^"+str+"%^RESET%^";
	if (dmg > 3 && dmg <= 6) c = "%^RED%^"+str+"%^RESET%^";
	if (dmg > 6) c = "%^BOLD%^%^RED%^"+str+"%^RESET%^";
	return c;
}

string GetArmourClass(int ac) {
  string a_type;
   if (!ac)                      a_type = "Non-Armour";
   if (ac == ARMOUR_CLOTH      ) a_type = "T1 cloth";           
   if (ac == ARMOUR_LEATHER    ) a_type = "T2 leather";     
   if (ac == ARMOUR_REINFORCED ) a_type = "T3 reinforced"; 
   if (ac == ARMOUR_NATURAL    ) a_type = "T4 natural";
   if (ac == ARMOUR_CHAIN      ) a_type = "T5 chain";         
   if (ac == ARMOUR_PLATE      ) a_type = "T6 plate";         
   if (ac == ARMOUR_HEAVY_PLATE) a_type = "T7 heavy plate";   
   return a_type;
}

string GetHelp(string s) {
  return "Syntax:   armours \n"
	 "          armours -c\n"
         "          armours damaged\n"
         "          armours -c damaged\n"
         "Displays a list of all equipped armour, including current status and armour type. \n"
         "Armour types are ranked tier 1 thru 7 depending on protection value of armour.\n"
	 "The -c flag will colorize the output based upon amount of damage to each piece.\n"
         "The optional argument damaged will only display worn items that are currently more"
         " than 0% damaged";
}         
