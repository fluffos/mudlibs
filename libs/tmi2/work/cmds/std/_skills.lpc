// _skills.c
// Command to show a player's skills.
// Created by Mobydick, 10-28-92, mostly ripped out of the existing _score.c

int cmd_skills() {

	string *skillnames, *list ;
	mapping skills ;
	int i, j ;

	this_player()->block_attack(4) ;
	write ("Your skills are:\n") ;
	skills = this_player()->query_skills() ;
	skillnames = keys(skills) ;
	list = sort_array(skillnames, "sort_skills", this_object()) ;
	for (i=0;i<sizeof(skills);i++) {
		j = this_player()->query_skill(list[i]) ;
		write (sprintf("%24-s : %d\n",capitalize(list[i]), j)) ;
	}
	return 1 ;
}

int sort_skills (string s1, string s2) {
	return strcmp (s1,s2) ;
}

int help() {
	write ("Usage: skills\n"+
"The skills command shows you your current skill levels. Your skills will\n"+
"improve as you use them, or train yourself in them. You can see other\n"+
"information about your character with the \"score\" command.\n") ;
	return 1 ;
}
