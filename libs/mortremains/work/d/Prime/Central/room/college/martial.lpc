/*
** File: martial.c
** Purpose: The standard weapon skill-adding room.
** Credits:
**  ?? May 97   Ilzarion made the very first ones.
**  11 Jul 98   Cyanide completely rewrote them, and 
**              made them inheritable (Whee!)
**  20 Oct 98   Cyanide combined Ilzarion's wproom.c and his 
**              own profroom.c "mad scientist style".
**  31 Jul 99   Cyanide converted this to the college's Martial
**              center
*/

#include "central.h"
#include <config.h>
#include <mudlib.h>
#include <skills.h>

#define CHARACTERS ({ "a","b","c","d","e","f","g","h","i","j", \
   "k","l","m","n","o","p","q","r","s","t","u","v","w","x", \
   "y","z" })

mapping get_skills(object);

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set("author", "cyanide");
    set( "light", 1 );
    set ("short", CITY_NAME+" Community College Martial Center");
    set( "long", wrap(
	"You stand within the massive Martial Center. There are hundreds "+
	"of trophies here displayed within huge glass cases. The sounds "+
	"of battle and the yells of the teachers fill the halls here\n"+
	"Available commands are: list, select <letter>"
      ) );
    set( "exits", ([
      "east" : COLLEGE("campus"),
    ]) );
}

/*********************************************************/

void init (){
    add_action ("list_prof", "list");
    add_action ("learn_prof", "select");
}

/*********************************************************/

mapping get_skills(object ob) {
    string str;
    mapping skills;

    str = ob->query_class();
    switch(str) {
    case "dragon" :
	skills = SK_WP_DRAGON;
	break;
    case "warrior" : 
	skills = SK_WP_FIGHTER;
	if (ob->query_level("barbarian")) skills = SK_WP_BARBARIAN;
	if (ob->query_level("knight")) skills = SK_WP_KNIGHT;
	break;
    case "wizard" : skills = SK_WP_MAGE; break;
    case "rogue" : 
	skills = SK_WP_THIEF; 
	if (ob->query_level("assassin")) 
	    skills = SK_WP_ASSASSIN;
	break;
    case "priest" : skills = SK_WP_CLERIC; 
	if ((string)ob->query("deity")=="oghma")
	    skills["Unarmed"] = 4;		
	break;
    case "psionicist" : skills = SK_WP_PSIONIC; break;
    default : skills = ([]);
    }

    return skills;
}

/*********************************************************/

string skill_level(int i, int f) {
    string str;

    switch (i) {
    case 0 : str = "Unskilled"; break;
    case 1 : str = "Proficient"; break;
    case 2 : 
	if (f) str = "Specialized";
	else str = "Expert";
	break;
    case 3 : str = "Master"; break;
    case 4 : str = "High Master"; break;
    case 5 : str = "Grand Master"; break;
    }

    return str;
}

/*********************************************************/

/*
** Function:  int list_prof()
** Purpose:   Outputs a list of all weapon skills a player may
**            select, as well as his current skill levels.
** Variable:
**   string  *skill_names   Array of the skill names.
**   int     *skill_maxes   Array of max level of each skill
**                          for the player.
**   mapping  skills        The main skills list.
*/

int list_prof() {
    int *skill_maxes, i, current;
    string *skill_names;
    string strB;
    mapping skills;

    if (!TP->query_level()) {
	write("You have been blocked from registration until you join "+
	  "a class.\n");
	return 1;
    }

    skills = get_skills(TP);

    if (!skills || skills==([]) ) {
	write("There are no weapons you may learn here.\n");
	return 1;
    }

    skill_names = keys(skills);
    skill_maxes = values(skills);

    write("         Skills available here:\n"+
      "       --------------------------\n");

    for (i=0; i<sizeof(skill_names); i++) {
	current = TP->query_skill(skill_names[i]);

	strB = "("+skill_level(current,
	  TP->query_level("warrior"));
	if (current>=skill_maxes[i]) strB += "*";
	strB += ")";

	write(capitalize(CHARACTERS[i])+
	  sprintf(": %-24s   %s\n", skill_names[i], strB));
    }

    write("       --------------------------\n");

    write(wrap("You have "+TP->query("wp_free")+
	" weapon proficiency slots remaining."));

    write(wrap("* = Maximum level has been reached."));

    return 1;
}

/*********************************************************/

int learn_prof( string str ) {
    int val, i, *v_skills;
    string *k_skills;

    if (!str || str=="" || (strlen(str) > 1) ) {
	write("Please enter the letter of the skill.\n");
	return 1;
    }

    k_skills = keys(get_skills(TP));
    v_skills = values(get_skills(TP));

    str = lower_case(str);
    i = member_array(str, CHARACTERS);

    if ( (i == -1) || (i >= sizeof(k_skills)) ) {
	write(capitalize(str)+" is not a valid choice.\n");
	return 1;
    }

    if (TP->query("weapon1") || TP->query("weapon2")) {
	write("Please unwield your weapons first.\n");
	return 1;
    }

    str = k_skills[i];
    if (TP->query_skill(str)>=v_skills[i]) {
	write(wrap("You are as skilled as a "+TP->query_class()+
	    " may become in the "+lower_case(str)+" style."));
	return 1;
    }

    i = TP->query_level();

    // This check is here just so the function won't puke if
    // TP somehow has no level.
    if (!i) {
	write("Mere peasants cannot learn the skills of battle!\n");
	return 1;
    }

    switch(TP->query_skill(str)+1) {
    case 3 :
	if (i<6) {
	    write ("You must be 6th level for mastery.\n");
	    i = 0;
	}
	break;
    case 4 :
	if (i<12) {
	    write ("You must be 12th level for high mastery.\n");
	    i = 0;
	}
	break;
    case 5 :
	if (i<18) {
	    write ("You must be 18th level for grand mastery.\n");
	    i = 0;
	}
	break;
    }

    // We use the flag to keep the spaghetti code to a minimum.
    // -Cyanide
    if (!i) return 1;

    if ((int)TP->query("wp_free") < 1) {
	write("You don't have enough slots to learn that skill.\n");
	return 1;
    }

    // Oghma priest-only stuffs.
    i = TP->query_level();
    switch(TP->query_skill(str)) {
    case 0 :
	TP->set("damage", ({ 2, 4 }));break;
    case 1 :
	TP->set("damage", ({ 3, 6 }));
	TP->set("unarmed_natt", 2);break;
    case 2 :
	TP->set("damage", ({ 4, 8 }));
	TP->set("unarmed_natt", 3);break;
    case 3 :
	TP->set("damage", ({ 7, 12 }));break;
    case 4 :
	TP->set("damage", ({ 9, 15 }));
	TP->set("unarmed_natt", 4);break;
    }

    TP->set_skill(str, (TP->query_skill(str)+1));
    TP->add("wp_free", -1);

    write(wrap("You have selected "+str+"."));

    return 1;
}

/* EOF */
