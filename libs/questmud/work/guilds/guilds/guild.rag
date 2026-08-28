/*   This is the guild object. Include it to your guild room.
 *   It contains the vital functions for all of the guilds.
 *    
 *   Follow the example of other guild rooms files, rather
 *   than making a completely new one, just copy the existing
 *   and change what you need, basically the available skills
 *   and level bonuses.
 */

#define LEVEL_COST_D 		"/guilds/guilds/level_cost_d"
#define SKILLFUN 		"/guilds/obj/skillfun"
#define SKILLPROS 		"/guilds/obj/skillpros"
#define MAX_LEVEL_COST 		1000000000  /* 1G, ettei mee yli integer rajan */
#define BACKGROUND_SKILL_LIMIT	70
#define BACKGROUND_MAX_LEVEL 	15
#define MULTIGUILD_D		"/daemons/multiguild_d"

int lesson;

guild_completed(string guild, object player) {
  if(player->query_guild_level(guild->guild_name()) == guild->guild_max_level() )
    return 1;
}


/*
 * player.c code:
 * GUILD->starter_guild_advance(level_name, starter_guild, this_object());
 * 
 */

starter_guild_advance(string guild, string *starter, object player_ob) {
  mapping skilz;
  string *indice_;
  int i, skill_value;
  if(!starter || guild != starter[0]) return;
  // guild is valid. set skills then.

  if(player_ob->query_tester()) tell_object(player_ob, "starter: "+starter[1]+" "+player_ob->query_guild_level(guild)+"\n");

  skilz = call_other(starter[1], "skill_list", player_ob->query_guild_level(guild));
  indice_ = m_indices(skilz);

  for(i=0; i < sizeof(indice_); i++) {
    skill_value = skilz[indice_[i]];
    if(skill_value > BACKGROUND_SKILL_LIMIT) skill_value = BACKGROUND_SKILL_LIMIT;

    if(player_ob->query_tester()) tell_object(player_ob, "Skill "+indice_[i]+" to "+skill_value+".\n");

    player_ob->set_skill(indice_[i], skill_value);
  }
  tell_object(player_ob, "Your skills have raised due background advancement.\n");
}

guild_long_name() {
    return guild_name();
}

get_skill_max(mixed num, int how, int lvl) {
  mapping skill;  
  int skill_max, skill_num, i, guild_level;  
  guild_level = this_player()->query_guild_level(guild_name());  
  skill = ([ ]);  
  if (lvl) {  
    guild_level = lvl;     
    if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }     
  }  
  skill = skill_list(guild_level);  /* skill_list() kiltafilessa */
  skill_num = m_indices(skill);  
  skill_max = m_values(skill);  
  if (how == 0) { return skill[num]; } /* skill_name */
  if (how == 1) { return skill_max[num]; } /* (int) */
  if (how == 2 || how == 3) { return skill_num[num]; } /* (int) */
  if (how == 4) { return skill_max; }  /* (int)allocate */
  if (how == 5) return skill; /* mapping */
  return -1;
}

load_plaque() {
  object plaque;
  if (!present("plaque")) {
    plaque = clone_object("guilds/obj/plaque.c");
    move_object(plaque, this_object());
  }
}

get_num(str) {
  return str;
}
guild_init() {
    add_action("join", "join");
    add_action("advance", "advance");
    add_action("info", "info");
    add_action("list", "list");
    add_action("train", "train");
    add_action("teach_skill", "teach");
    add_action("advance_check", "requirements");
    add_action("check_cost", "cost");
    add_action("lead", "lead");
}

check_cost() {
  int cost;
  cost = LEVEL_COST_D->query_next_cost(this_player()->query_level());
  if (this_player()->query_enough_exp(cost) == cost) {
    write("You have enough free exp to raise a level.\n");
  } else {
    write("You do not have enough free exp to advance.\n");
  }
  return 1;
}

teach_skill(string str) {
    string skill_name, target;
    object ob;
    if (!str) { write("Syntax: teach [skill] to [name].\n"); return 1; }
    if (sscanf(str, "%s to %s", skill_name, target) != 2) {
        write("Teach what to to whom?\n");
        return 1;
    }
    ob = present(target);
    if (!ob || ob->query_npc()) {
        write(capitalize(target)+" is not here.\n");
        return 1;
    }
    if(ob == this_player()) {
	write("You cannot teach yourself.\n");
	return 1;
    }
    if (lesson) {
	write("There is already a lesson going on.\n");
	return 1;
    }
    write("You start teaching "+ob->query_name()+".\n");
    tell_object(ob, this_player()->query_name()+" starts teaching you.\n");
    call_out("real_teach", (random(3)+2), ob, skill_name);
    lesson = 1;
    return 1;
}

real_teach(object ob, string skill_name) {
    int i, skill_pros, much_over;

    string skill_num, *starter_guild;
    int teacher_skill, student_skill;
    int student_glevel, teacher_glevel;
    int teacher_max, student_max;
    int base_cost, skill_type, skill_cost, skill_max;

    lesson = 0;
    if (!present(ob->query_real_name())) {
	write(ob->query_name()+" is no longer here.\n");
	return 1;
    }

    skill_name = lower_case(skill_name);
    if (ob->query_skill_left(skill_name) &&
       !ob->query_skill_teach(skill_name)) {
        write(ob->query_name()+" is already training that skill from a"+
		" guild.\n");
        return 1;
    }

    teacher_skill = this_player()->query_skills(skill_name);
    student_skill = ob->query_skills(skill_name) +
        ob->query_skill_left(skill_name);

    teacher_glevel = this_player()->query_guild_level(guild_name());
    student_glevel = ob->query_guild_level(guild_name());

    if (!teacher_glevel) {
        write("You are not a member of this guild.\n");
        return 1;
    }
    if (!student_glevel) {
        write(ob->query_name()+" is not a member of this guild.\n");
        return 1;
    }

    teacher_max = get_skill_max(skill_name,0,teacher_glevel);
    student_max = get_skill_max(skill_name,0,student_glevel);
    if (teacher_skill <= student_max) student_max = teacher_skill;

    if (teacher_skill <= student_skill) {
        write("The teacher has to know the skill better than the student.\n");
        return 1;
    }

    if (!student_max) {
        write("No such a skill available to "+ob->query_name()+"\n");
        return 1;
    }

    if (student_max <= student_skill) {
        write(ob->query_name()+" already knows the skill as well as he"+
                " can at the current level.\n");
	tell_object(ob, "You already know the skill as well as you can at the current level.\n");
        return 1;
    }

    starter_guild = this_player()->query_starter_guild();  
            
    if(starter_guild && this_player()->query_guild_level(starter_guild[0]) < call_other(starter_guild[1], "guild_max_level")
	&& this_player()->query_guild_level(starter_guild[0]) < BACKGROUND_MAX_LEVEL) {

	// Added a 3 line code to fix the level number given in write. 17.11.2003 Celtron
	int higher_level;
	higher_level = call_other(starter_guild[1], "guild_max_level");
	if(BACKGROUND_MAX_LEVEL > higher_level) higher_level = BACKGROUND_MAX_LEVEL;
      write("You are unable to train skills before your background stage is complete. (level "+higher_level+")\n");
      return 1;
    }   

    ob->set_skill_train(skill_name, (student_max - student_skill), 0, 1);
    write("You teach '"+skill_name+"' to "+ob->query_name()+".\n");
    tell_object(ob,this_player()->query_name()+" teaches you how to train "+
        skill_name+".\n");
    tell_object(ob,"You are now training '"+skill_name+"' to "+
get_adjective((ob->query_skill(skill_name)+ob->query_skill_left(skill_name)))+".\n");
    return 1;
}


advance_check(lev) {
  int i, not_passed,num;
  string skill;
  mapping sk;
  /* joining req nakyy requirements commandilla */
  if(!lev) {
    if(!check_joining_rec())
      write("You do not meet the joining requirements of this guild.\n");
  }
  sk = check_advance_rec(lev);
  if(sk == 1) return 1;
  if(!mappingp(sk)) return 0;
  while(i<guild_max_level()) {
    i+= 1;
    while(sk[i] && sscanf(sk[i], "%s;%s",skill,sk[i]) >= 1) {
      if(sk[i] && sscanf(skill, "%s:%d",skill,num) == 2) {
        if(!lev) write("Level "+i+":\n");
        if(this_player()->query_skills(skill) < num && lev == i || !lev) {
          write("Must have trained skill '"+skill+"' atleast to '"+ get_adjective(num)+"'.\n");
          not_passed = 1;
        }
      }
    }
  }
  if(not_passed && lev) return 0;
  return 1;
}

join(string arg) {
  if(this_player()->query_guest()) return 0;
  return advance(arg, 1);
}

lead() {
 if (!this_player()->query_guild_level(guild_name())) 
 {
  write("You are not a member of this guild.\n");
  return 1;
 }
 
 (object) ("/daemons/guildrank_d");

 if(("/daemons/guildrank_d"->test_lead()) != 1)
 {
 write("You are not powerful enough to lead the guild.\n");
 }
 return 1;

}

advance(string arg, int joining) {
    int level_cost, next_level, quest_cost, free_value;
    string prefix, guild_num, *starter_guild;
    if (arg) { 
        return 0; 
    }
    guild_num = guild_name();

    if (joining && this_player()->query_guild_level(guild_name())) {
        write("You already are a member of this guild.\n");
        return 1;
    }
    if (!joining && !this_player()->query_guild_level(guild_name()) ) {
	write("You are not a member of this guild.\n");
	return 1;
    }

    if (!check_joining_rec()) {
        write("You do not meet the joining requirements of this guild.\n");
        return 1;
    }

    if (this_player()->query_level_advance()) {
	write("You are already advancing a level somewhere.\n");
	return 1;
    }
    if (!advance_check(this_player()->query_guild_level(guild_num) + 1)) {
        write("You do not meet the advancement requirements.\n");
        return 1;
    }

// special effect must be here, since appr mage guild ie. has a spec effect
    this_object()->special_advance_effect(this_player()->query_guild_level(guild_num)+1);

    if (this_player()->query_guild_level(guild_num) == this_object()->guild_max_level()) {
        write("You are at the maximum level.\n");
        return 1;
    }

    starter_guild = this_player()->query_starter_guild();

    if(starter_guild && starter_guild[0] != guild_name() &&
	this_player()->query_guild_level(starter_guild[0]) < call_other(starter_guild[1], "guild_max_level") ) {
      write("You need to complete your background guild before joining other guilds.\n");
      return 1;
    }

// multiguild requirements

    if(this_player()->query_wiz() || this_player()->query_tester()) {
	    if(!MULTIGUILD_D->join_guild(guild_name()) ) return 1;
    }

/* 
	okey, all requirements are passed, now start advancing..
*/

    level_cost = LEVEL_COST_D->query_next_cost(this_player()->query_level());

    if (this_player()->query_level() >= this_player()->query_max_level() && !this_player()->query_wiz()) {
      if(level_cost < MAX_LEVEL_COST / 5) {
        level_cost = level_cost * 5;
      } else {
        level_cost = MAX_LEVEL_COST;
      }
      write("You have exceeded your current maximum level; experience cost multiplied.\n");
    }

    if(!starter_guild || starter_guild[0] != guild_name() || this_player()->query_guild_level(starter_guild[0]) > BACKGROUND_MAX_LEVEL) {
      if (this_player()->query_enough_exp(level_cost) == level_cost) {
        this_player()->reduce_free_exp(level_cost);
        this_player()->advance_guild_level(guild_num, get_bonuses(this_player()->query_guild_level(guild_num)));
        this_player()->add_total_worth(level_cost);
        write("You advance in the " + guild_name() + " guild.\n"); 
        write_advance(guild_num);
        write("That cost you "+level_cost+" exp.\n");
        return 1;
      }

      quest_cost = this_player()->query_level() / 4 + 1;
      if (this_player()->query_quest_points() >= quest_cost) {
        this_player()->advance_guild_level(guild_num, get_bonuses(this_player()->query_guild_level(guild_num)));
        this_player()->reduce_quest_points(quest_cost);
        write("You advance the level with quest points.\n");
        write_advance(guild_num);
        write("That cost you "+quest_cost+" quest points.\n");
        return 1;
      }

      free_value = this_player()->query_enough_exp(level_cost);
    }

    // free_value == 0, if guild == starter_guild.
    if (!this_player()->set_level_advance(level_cost, free_value, guild_num,guild_long_name(),
	  get_bonuses(this_player()->query_guild_level(guild_num)))) {
      write("You already are advancing a level somewhere.\n");
      return 1;
    }

    if (free_value) this_player()->reduce_free_exp(free_value);

    next_level = this_player()->query_guild_level(guild_num) + 1;
    if (next_level == 1) { prefix = "st"; }
    else if (next_level == 2) { prefix = "nd"; }
    else if (next_level == 3) { prefix = "rd"; }
    else { prefix = "th"; }
    write("You start gathering experience for the " + guild_name() +
        "'s " + next_level + prefix + " level.\n");
    return 1;
}

write_advance(guild_num) {
 write("You are now level " + this_player()->query_guild_level(guild_num) + " in " + guild_name() + ".\n");
 write("New stats are: Str " + 
   this_player()->query_str() + " Dex " + 
   this_player()->query_dex() + " Con " +
   this_player()->query_con() + " Wis " + 
   this_player()->query_wis() + " Int " + 
   this_player()->query_int() + ".\n");
}

info() {
  string str, tmp, dis, tmp2;
  int i;
  str = get_bonuses();
  if(!str) return;
  str = "a "+str+" a";
  write("The "+guild_name()+" guild ("+guild_max_level()+
	" levels) trains the following stats:\n");
  if(sscanf(str, "%s str %d %s", tmp, i, tmp2) == 3) { }
  dis = "Str: "+get_adjek(i);
  i = 0;
  if(sscanf(str, "%s dex %d %s", tmp, i, tmp2) == 3) { }
  dis += "\tDex: "+get_adjek(i);
  i = 0;
  if(sscanf(str, "%s con %d %s", tmp, i, tmp2) == 3) { }
  dis += "\tCon: "+get_adjek(i)+"\n";
  i = 0;
  if(sscanf(str, "%s int %d %s", tmp, i, tmp2) == 3) { }
  dis += "Int: "+get_adjek(i);
  i = 0;
  if(sscanf(str, "%s wis %d %s", tmp, i, tmp2) == 3) { }
  dis += "\tWis: "+get_adjek(i)+"\n";
  write(dis);
  return 1;
}

get_adjek(int i) {
  i += 1;
  if(i == 0) return "none";
  if(i == 1) return "a little";
  if(i == 2) return "some";
  if(i == 3) return "much";
  if(i == 4) return "very much";
  if(i > 4) return "a lot";
}

get_adjective(pros) {
  string skill_adj;
  if (!pros) { return "none"; }
  skill_adj = call_other(SKILLPROS,"pros_names",pros);
  while(skill_adj && extract(skill_adj,0,0) == " ") {
    skill_adj = extract(skill_adj, 1, strlen(skill_adj));
  }
  return skill_adj;
}


train(skill) {
    int skill_cost, total_cost, silver_cost, cost_fail; 
    int much, much_train, num, i, last_cost, over_max, skill_pros, much_over;
    int skill_type, base_cost, over_cost;
    int max_level;
    string skill_num, *starter_guild;
    if(this_player()->query_guest()) return 0;
    if (!this_player()->query_guild_level(guild_name())) {
        write("You are not a member of this guild.\n");
        return 1;
    }
    if (!skill) {
        write("Train what? Try 'list' command.\n");
        return 1;
    }
    skill_num = lower_case(skill);
    skill_pros = this_player()->query_skills(skill_num) + this_player()->query_skill_left(skill_num);
    base_cost = call_other(SKILLFUN, "skill_costs",skill_num,0,"base_cost");

    starter_guild = this_player()->query_starter_guild();

//Added by Rag (15.1.2004) because all players don't have a starter_guild

    if(!starter_guild) {
	write("Please contact a wizard for reincarnation.\n");
	return 1;
    }

//Added by Rag (13.1.2004) to fix training with base guilds with more than 15 levels

    if( BACKGROUND_MAX_LEVEL < call_other(starter_guild[1], "guild_max_level")) {
        max_level = BACKGROUND_MAX_LEVEL;
    } else {
        max_level = call_other(starter_guild[1], "guild_max_level");
    }
                                                                                                                                            
    if( starter_guild && this_player()->query_guild_level(starter_guild[0]) < max_level ) {
      write("You are unable to train skills before your background stage is complete. (level "+max_level+")\n");
      return 1;
    }

/*    
    if(starter_guild && this_player()->query_guild_level(starter_guild[0]) < call_other(starter_guild[1], "guild_max_level") ) {
      write("You are unable to train skills before your background stage is complete. (level "+BACKGROUND_MAX_LEVEL+")\n");
      return 1;
    }
*/
    if (sscanf(skill, "%s to %s", skill, num) != 2) {
	much = 1;	
    } else {
        skill_num = skill;
        skill_pros = this_player()->query_skills(skill_num) + this_player()->query_skill_left(skill_num);
    	base_cost = call_other(SKILLFUN, "skill_costs",skill_num,0,"base_cost");

        if (!get_skill_max(skill_num)) {
           write("No such a skill '" + skill + "' available.\n");
           return 1;
   	}
        if (num == "max") {
            much = get_skill_max(skill_num) - skill_pros;
        }
        if (call_other(SKILLPROS, "adjectives", num)) {
            num = call_other(SKILLPROS, "adjectives", num);
            much = num - skill_pros;
        } else if (num != "max") {
	    write("Usage: 'train [skill] to [<adjective> | max]'.\n");
	    return 1;
 	}
        if (much < 1 && intp(num)) {
            write("You already have or are training '" + skill + "' to more than '"+get_adjective(num)+"'.\n");
            return 1;
        }
    }  
    if (!get_skill_max(skill_num)) {
        write("No such skill '" + skill + "' available.\n");
        return 1;
    }

    skill_type = call_other(SKILLFUN, "skill_costs", skill_num,0,0,1);
    if (much + skill_pros > get_skill_max(skill_num) || skill_pros >= get_skill_max(skill_num)) {     
        write("The maximum of current level for '" + skill + "' is '" +
		get_adjective(get_skill_max(skill_num)) + "'.\n");
        return 1;
    }
    if (skill_type == 1 || skill_type == 2) {
        if (skill_pros + much > this_player()->query_skill_max(base_cost)) {
            if (this_player()->query_skills(skill_num) >= this_player()->query_skill_max(base_cost)) {
		if (num == "max") {
		    write("You already have the skill at your racial max.\n"+
"Use 'train [skill]' or 'train [skill] to [adjective]' to advance further.\n");
		    return 1;
		}
                if (skill_pros + much > 100) {
                    much = 100 - skill_pros;
                }
                write("The knowledge of this skill is getting really difficult for you.\n");
                over_max = 1;
            }
            else {
                much = this_player()->query_skill_max(base_cost) - skill_pros;
            }
        }
        if (skill_pros + much > this_player()->query_skill_max(base_cost) && !over_max || much == 0) {
            write("You already have or are training '" + skill + "' at your racial maximum.\n");
            return 1;
        }
    }
    if (skill_type == 3 || skill_type == 4) {
        if (skill_pros + much > this_player()->query_spell_max(base_cost)) {
            if (this_player()->query_skills(skill_num) >= this_player()->query_spell_max(base_cost)) {
		if (num == "max") {
		    write("You already have the skill at your racial max.\n"+
"Use 'train [skill]' or 'train [skill] to [adjective]' to advance further.\n");
		    return 1;
		}
                if (skill_pros + much > 100) {    
                    much = 100 - skill_pros;
                }
                write("The knowledge of this skill is getting really difficult for you.\n");
                over_max = 1;
            }
            else {
                much = this_player()->query_spell_max(base_cost) - skill_pros;
            }       
        }  
        if (skill_pros + much > this_player()->query_spell_max(base_cost) && !over_max || much == 0) {
            write("You already have or are training '" + skill + "' at your racial maximum.\n");
            return 1;
        }
    }
    if (skill_pros + much > get_skill_max(skill_num)) {
        write("You already have or are training '" + skill + "' at maximum of current level.\n");
        return 1;
    }
    /* define skillcost */
    if(much==1) {
      skill_cost=allocate(102);
      skill_cost[skill_pros] = call_other(SKILLFUN, "skill_costs",skill_num,(skill_pros));
    } else {
      skill_cost = call_other(SKILLFUN, "skill_costs", skill_num,0,1);
    }
    /* end of define */
    if(!skill_cost[skill_pros] && skill_cost[skill_pros] < 0) {
      write("Error: too big expcost.\n");
      return 1;
    }
  if (this_player()->query_enough_exp(skill_cost[skill_pros]) == skill_cost[skill_pros]) {
    while (i < much) {
      int scost;
      if (over_max) {
	if (skill_type == 1 || skill_type == 2) {
	  much_over = (skill_pros-this_player()->query_skill_max(base_cost))/3+2;
	} else if (skill_type == 3 || skill_type == 4) {
	  much_over = (skill_pros-this_player()->query_spell_max(base_cost))/3+2;
	}
	scost = skill_cost[skill_pros] * much_over;
      } else {
        scost = skill_cost[skill_pros];
      }
      if (scost == this_player()->query_enough_exp(scost)) {
        this_player()->reduce_free_exp(scost);
        this_player()->add_total_worth(scost);
        total_cost += scost;
        if (total_cost > 500000000) {
          write("That cost you 500.000.000 experience points (ouch).\n");
          total_cost -= 500000000;
        }
        this_player()->advance_skill(skill_num, 1);
        skill_pros = this_player()->query_skills(skill_num) + this_player()->query_skill_left(skill_num);
        much_train += 1;                
      } else {
        i = much;
      }
      i += 1;
    } /* end of while */

    if (much_train) {
      much -= much_train;
      if (much_train == 1) {
        write("You trained '"+skill+"' a bit.\n");
        if(call_other(SKILLPROS,"pros_names", this_player()->query_skills(skill_num)) !=
		call_other(SKILLPROS,"pros_names",(this_player()->query_skills(skill_num)-1))) {
	  write("Your skill level advanced to '"+get_adjective(this_player()->query_skills(skill_num))+"'.\n");
	}
      } else {
        write("You trained '"+skill+"' to '"+get_adjective(this_player()->query_skills(skill_num))+"'.\n");
      }
      write("That cost you " + total_cost + " experience points.\n");
      if (!much) { return 1; }
    }
  }

  /* define money costs and state results*/
  i = 0;
  while (i < much) {
        last_cost = silver_cost;
	if (this_player()->query_level() > 7) {
	   silver_cost += skill_cost[skill_pros+i] / 20000;
           if (!silver_cost) {
	      silver_cost = 1;
	   }
	}
        if (this_player()->query_money(3) < silver_cost) {
            much = i;
            cost_fail = silver_cost;
            silver_cost = last_cost;
        }
        i += 1; 
    }
    if (much) {
	if (silver_cost) {
	  this_player()->reduce_money(silver_cost,3);
	}
        this_player()->set_skill_train(skill_num, much,
		this_player()->query_enough_exp(skill_cost[skill_pros]));
        this_player()->reduce_free_exp(
		this_player()->query_enough_exp(skill_cost[skill_pros]));
    }
    if (much == 1) {
	write("You start training '"+skill+"' a bit more.\n");
	if(call_other(SKILLPROS,"pros_names", (this_player()->query_skill(skill_num)+
this_player()->query_skill_left(skill_num))) != call_other(SKILLPROS,"pros_names",
(this_player()->query_skill(skill_num)+ this_player()->query_skill_left(skill_num)+1))) {
	   write("You are now training '"+skill+"' to "+
get_adjective((this_player()->query_skill(skill_num)+this_player()->query_skill_left(skill_num)))+".\n");
	}
    } else {
	write("You start training '" + skill + "' from '" +
get_adjective((this_player()->query_skill(skill_num)+this_player()->query_skill_left(skill_num)-much))+"' to '"+
get_adjective((this_player()->query_skill(skill_num)+this_player()->query_skill_left(skill_num)))+"'.\n");
    }
    if (silver_cost) {
    	write("That cost you " + silver_cost + " bronze coins.\n");
    }
    if (cost_fail) {
        much += 1;
        write("Training to '"+
get_adjective((this_player()->query_skill(skill_num)+this_player()->query_skill_left(skill_num)+much))+
"' would have cost you " +(cost_fail-silver_cost) + " bronze coins more, which you didn't have.\n");
    }
    return 1;
}    

list(str) {
    int i, cost, next_pros, list_level;
    int skill_left, skill_max;
    string skill_num, next_pros_str, skill_left_str, cost_str;
    string str1, str2, str3, str4, str5, str6;
    if (str) {
        sscanf(str, "level %d", list_level);
        if (str == "all") { 
           list_level = guild_max_level(); 
        } else if (sscanf(str, "level %d", list_level) != 1) {
           write("Usage: 'list', 'list all' or 'list level <level>'.\n");
           return 1;
        }
        if (list_level > guild_max_level() || list_level < 1) {
           write("No such a guild level.\n");
           return 1;
        }       
    }
    else if (!this_player()->query_guild_level(guild_name())) {
        write("You are not a member of this guild.\n");
        return 1;
    }   

write(
"\n+-----------------------+-----------+-----------+-----------+-----------+\n");
write(
"|Skill:                 |  Current  |Training to|  Maximum  |Skill level|\n");
write(
"+-----------------------+-----------+-----------+-----------+-----------+\n");
    while(i < sizeof(get_skill_max(0, 4, list_level))) {
        str1 = "|";
        str5 = "|";
        skill_num = get_skill_max(i,2, list_level);
        next_pros = this_player()->query_skills(skill_num);
	next_pros_str = call_other(SKILLPROS, "pros_names",
		next_pros);
	if (!next_pros_str) { next_pros_str = "       none"; }

 	skill_left = this_player()->query_skill_left(skill_num);
	if (skill_left) {
	    skill_left_str = call_other(SKILLPROS,
			"pros_names",(skill_left+next_pros));
	} else { skill_left_str = 0; }

	if (!skill_left_str) { skill_left_str = "       none"; }

        skill_max = get_skill_max(i, 1, list_level);
	skill_max = call_other(SKILLPROS, "pros_names",
		skill_max);

	str6 = get_skill_max(i,2,list_level);
        cost_str = call_other(SKILLFUN,
	  "get_skill_cost_adjective", lower_case(str6));
	if(str6) str6 = "|"+capitalize(str6);
	else str6 = "| Error, no skillmax";
	if (strlen(str6) < 8) { str6 = str6+"\t"; }
	if (strlen(str6) < 16) { str6 = str6+"\t"; }
	if (strlen(str6) < 24) { str6 = str6+"\t"; }
	str6 = str6+"";
/* Write the whole thing now: */
        write(str6 + str1 + next_pros_str + str1 + skill_left_str + str1 + 
		skill_max);
        if (next_pros + skill_left < 100) {
            write(str5 + cost_str + "|\n");
        }
        else {
            write("|     At max|\n");
        }
        i += 1;
    }
write(
"+-----------------------+-----------+-----------+-----------+-----------+\n");
write("To get info about skills listed, see 'help skill <skillname>'.\n");
    return 1;
}    

