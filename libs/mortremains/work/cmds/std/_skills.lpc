// _skills.c
// Command to show a player's skills.
// Created by Mobydick, 10-28-92, mostly ripped out of the existing _score.c
// (04-12-98) Chronos squashes a bug.  (Used to error on !skills)  OOps.

#include <skills.h>

int cmd_skills() {

    string *skillnames, *wplist, *list, *wpskillnames, *wskillsn, *tempskillnames ;
    mapping skills, wpskills ;
    int i, j, k, num, nwp, wp ;


    skills = this_player()->query_skills() ;
    nwp = TP->query("nwp_free") ;
    wp = TP->query("wp_free") ;
    // Chronos's fix.
    if (!skills) {
	write("You have no noteworthy skills yet.\n") ;     
	write("You have "+wp+" weapon proficiency slots open.\n");
	write("You have "+nwp+" non-weapon proficiency slots open.\n") ;
	return 1;
    }
    write("Your skills are:\n");
    write("Nonweapon                          Weapon\n") ;
    skillnames = keys(skills) ;
    wskillsn = keys(SK_WP_FIGHTER);
    tempskillnames = skillnames;
    wpskillnames = ({});
    for (i=0;i<sizeof(skills);i++) {
	if (member_array(tempskillnames[i], wskillsn ) != -1){
	    wpskillnames += ({ tempskillnames[i] });
	    skillnames -= ({ tempskillnames[i] });
	}
    }




    wplist = sort_array(wpskillnames, "sort_skills", this_object()) ;
    list = sort_array(skillnames, "sort_skills", this_object()) ;

    num = sizeof(skillnames)-sizeof(wpskillnames);
    //write("num = "+num+"\n");
    if (num == 0){
	for (i=0;i<sizeof(skillnames);i++) {
	    j = this_player()->query_skill(list[i]) ;
	    k = this_player()->query_skill(wplist[i]) ;
	    write(sprintf("%-15s : %-15d  %-30s : %-10d\n",list[i], j, wplist[i], k)) ;
	}
    }

    if (num>0){
	for (i=0;i<sizeof(wpskillnames);i++) {
	    j = this_player()->query_skill(list[i]) ;
	    k = this_player()->query_skill(wplist[i]) ;
	    write(sprintf("%-15s : %-15d  %-30s : %-10d\n",list[i], j, wplist[i], k)) ;
	}
	for (i=(sizeof(wpskillnames));i<(sizeof(skillnames));i++) {
	    j = this_player()->query_skill(list[i]) ;
	    write(sprintf("%-15s : %-15d \n",list[i], j)) ;
	}

    }
    if (num<0){
	for (i=0;i<sizeof(skillnames);i++) {
	    j = this_player()->query_skill(list[i]) ;
	    k = this_player()->query_skill(wplist[i]) ;
	    write(sprintf("%-15s : %-15d  %-30s : %-10d\n",list[i], j, wplist[i], k)) ;
	}
	for (i=(sizeof(skillnames));i<(sizeof(wpskillnames));i++) {
	    k = this_player()->query_skill(wplist[i]) ;
	    write(sprintf("                                   %-30s : %-10d\n",wplist[i], k)) ;
	}
    }



    write("Free - NWP: "+nwp+"  WP: "+wp+" \n");
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
