/*******************************************************************
**                     Skill setup and querying                   **
*******************************************************************/
add_skill(str){
	if(!skills) skills = ({ str });
	else skills += ({ str });
}
query_skill(){ return skills; }
remove_skill(str){ skills -= str; }
set_skill(str){ skills = str; }

add_creation(int i){ creation += i; }
add_control(int i){ control += i; }
add_combat(int i){ combat += i; }
query_creation(){ return creation; }
query_control(){ return control; }
query_combat(){ return combat; }

spend_pts(str){
	if(!skill_pts){ write("You have no skill points to spend.\n"); return 1; }
	if(!str){ write("raise which skill: combat, control, or creation?\n"); return 1; }
	if(str == "creation"){
		if(creation < 6){
			tell_object(USER, query_color()+"You raise Creation. For a list of new abilities type: skills"+NORM+"\n");
			skill_pts -= 1;
			creation += 1;
		}
		else{ tell_object(USER, query_color()+"You cannot raise Creation further."+NORM+"\n"); return 1; }
		return 1;
	}
	else if(str == "control"){
		if(control < 6){
			tell_object(USER, query_color()+"You raise Control. For a list of new abilities type: skills"+NORM+"\n");
			skill_pts -= 1;
			control += 1;
		}
		else{ tell_object(USER, query_color()+"You cannot raise Control further."+NORM+"\n"); return 1; }
		return 1;
	}
	else if(str == "combat"){
		if(combat < 6){
			tell_object(USER, query_color()+"You raise Combat. For a list of new abilities type: skills"+NORM+"\n");
			skill_pts -= 1;
			combat += 1;
		}
		else{ tell_object(USER, query_color()+"You cannot raise Combat further."+NORM+"\n"); return 1; }
		return 1;
	}
	else{ tell_object(USER, "raise_skill <creation, combat, control>\n"); return 1; }
	return 1;
}




/****************************************************************
**   Advancement system for New Symbs      1.5 Million to max  **
****************************************************************/
convert_xp(int i){
	int expcost,minexp,woo;
	
	if(glvl > 15){ write("You are maxed.\n"); return 1; }
	if(!i){ write("convert how many experience points?\n"); return 1; }
	sscanf(i, "%d", woo);
	if(USER->query_level() > 19) return 1;
	
	if(woo < 1){
		write("You must convert a positive number of experience points.\n");
	return 1; }
	
	expcost = woo;
	
	if(USER->query_extra_level() < 1 && USER->query_level() < 21)
	minexp = this_player()->query_exp() - call_other("room/adv_guild", "get_next_exp",
	(this_player()->query_level()) - 1);
	
	if(USER->query_extra_level() > 0 && USER->query_level() < 21)
	minexp = USER->query_exp() - call_other("room/exlv_guild", "get_next_exp",
	USER->query_extra_level() - 1);
	
	if(expcost > minexp) {
		write("You do not have enough available experience to convert.\n");
		return 1;
	}
	
	USER->add_exp(-woo);
	write("You convert "+i+" experience towards your Symbiotic Control.\n");
	
	check_advance(woo);
	return 1;
}

check_advance(exp){
	
	if(glvl > 15) return;
	
	gxp += exp;
	
	if(250000 <= gxp){
		gxp = gxp - 250000;
		glvl += 1;
		skill_pts += 1;
		
		tell_object(USER,
			"\n"+query_color()+"                  !!! You Gain a Level !!! "+NORM+"\n"+
		"               You are now Symbiote Level "+glvl+".\n");
		if(250000 <= gxp) check_advance(0);
		save_venom(1);
		return 1;
	}
	return 1;
}
