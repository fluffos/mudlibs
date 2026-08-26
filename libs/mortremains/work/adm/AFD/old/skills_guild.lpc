// guild.c
// People come to the guild and buy skill training for gold.
// Ideally, you'd like to have people train in skills, taking up time. But
// it's super-boring having people type "kill dummy" over and over and
// seeing "You hit the target dummy" eternally. So instead, you can trade
// gold for skills, straight up. That way you have them spend the time
// getting more gold instead :)
// Written by Mobydick@TMI-2, 11-15-92
// Please leave the credits part of this header in place.
// You can delete the rest of it.

#include <mudlib.h>

inherit ROOM ;

// The variable trainable_skills stores the skills which this guild can
// train you in.

mixed trainable_skills ;

// This function sets the skills you can train in at this guild.
// If you pass the string argument ALL, then you can train in all
// skills. Otherwise, you should pass an array of strings and the skills
// names in that array are trainable, others are not.

void set_trainable_skills (mixed skills) {
	trainable_skills = skills ;
}

// This function returns 1 if the guild trains in the skill and 0 if not.
// It does NOT error check to make sure the string is actually a skill.

int can_train (string skill) {
// If trainable_skills is not set, or is set to "ALL", then we can train it.
	if (!trainable_skills) return 1 ;
	if (trainable_skills=="ALL") return 1 ;
// If it is not a member of trainable_skills, we cannot train it.
	if (member_array(skill,trainable_skills)==-1) return 0 ;
// It is a member of trainable skills, so we can train in it.
	return 1 ;
}

// Init adds the cost and train commands. You must call this if you
// add your own init functions.

void init() {
	add_action ("buy_skill", "train") ;
	add_action ("list_costs", "list") ;
}

// This function returns the cost of improving a named skill.
// Right now it is set up so that the cost is 1 gp per 2 skill uses needed
// to improve the skill the hard way. To do this, we copied the
// skill improvement formula into this object. You don't need to have
// the cost related to the use points, but we thought we'd set it up that
// way. If you want to keep it that way, and you change the improvement
// function, change this one too.

int cost_of_skill (string str) {

	int i, cost, uses ;
	string *names ;
	mapping skills, stats ;

	skills = this_player()->query_skills() ;
	names = keys(skills) ;
	if (member_array(str,names)==-1) return -1 ;
	stats = this_player()->query_skill_stats() ;
	uses = (50-stats[str])*(2*skills[str]+1) ;
	cost = (uses-1)/2+1 ;
	return cost ;
}

// This function lets players buy skill improvements for gold. The cost
// function is hardwired in here: you can change it if you want to.

int buy_skill (string skill) {

	int cost, wealth, res ;

	if (!skill) {
		notify_fail ("What skill would you like to train in?\n") ;
		return 0 ;
	}
// In the default mudlib, all skill names are capitalized. If you use
// lowercase skill names, then replace this with a call to lower_case.
// You probably should not use both capital and lowercase skill names,
// but if you do, dike this out completely.
	skill = capitalize(skill) ;
	cost = cost_of_skill(skill) ;
	if (cost==-1) {
		notify_fail ("That is not a valid skill. Type \"skills\" to see a list of your options, or\n"+
		"\"list\" to see the costs of all skills you could buy.\n") ;
		return 0 ;
	}
	if (!can_train(skill)) {
		notify_fail ("This guild cannot train you in that function.\n") ;
		return 0 ;
	}
	 wealth = this_player()->query("wealth/gold") ;
	if (wealth<cost) {
		notify_fail ("The training would cost you "+cost+" gold coins, which you don't have.\n") ;
		return 0 ;
	}
	this_player()->set("wealth/gold",wealth-cost) ;
// Increase the player's carrying capacity.
	res = this_player()->query("capacity") ;
	this_player()->set("capacity", res+cost) ;
	write ("You train laboriously and your skill improves.\n") ;
	res = this_player()->query_skill(skill) ;
	this_player()->change_skill_level(skill,res+1) ;
// We do not change his skill use points. That way, if he was one use short
// of improving before training, he will be one use short of making the next
// improvement plus the number of extra uses required the make the higher
// level. This way, the player always gets credit for the total number of
// uses to make the level, rather than the number he needs to make it just
// up to the new level. This seems fairer since the cost is the same whether
// he needs 1 use or 1000, but it also means a player might buy skill level
// N and very quickly improve again to skill level N+1. You could, if you
// wanted, set his skill use points back to zero after training, and if
// you REALLY wanted to you could have the price of training reflect this.
// We chose not to, though; this way is less code, and easier code to read
// (although the explanatory comment may eat the gain :)
	return 1 ;
}

int list_costs() {

	int i, s ;
	mapping skills ;
	string *names, *s_names ;

	skills = this_player()->query_skills() ;
        names = skills ? keys(skills) : ({ });
	s_names = sort_array(names,"sort_skills",this_object()) ;
	write("Skill                     Cost\n") ;
	write("------------------------------\n") ;
	s = sizeof(names) ;
	for (i=0;i<s;i++) {
		if (!can_train(s_names[i])) continue ;
		 write(sprintf("%25-s %d gold\n",s_names[i],cost_of_skill(s_names[i]))) ;
	}
	return 1 ;
}

int sort_skills (string s1, string s2) {
	return strcmp (s1,s2) ;
}
