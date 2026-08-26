/*
** File: /std/prof_room.c
** Purpose: The standard skill-adding room.
** Credits:
**  ?? May 97   Ilzarion made the very first ones.
**  11 Jul 98   Cyanide completely rewrote them, and 
**              made them inheritable (Whee!)
*/

inherit ROOM;

#define CHARACTERS ({ "a","b","c","d","e","f","g","h","i","j", \
   "k","l","m","n","o","p","q","r","s","t","u","v","w","x", \
   "y","z" })

mapping skills = ([]);
mapping min_levels = ([]);
int *v_skills, *v_minlvls;
string *k_skills, *k_minlvls;

string skills_function(string);

void create() { ::create(); }

void init (){
    add_action ("list_prof", "list");
    add_action ("learn_prof", "select");
}

int list_prof() {
    int i, val;
    string str;

    if (query("skills")) skills = query("skills");
    if (query("min_levels")) min_levels = query("min_levels");

    if (! skills || skills==([]) ) {
	write("There are no skills being taught at this time.\n");
	return 1;
    }

    k_skills = keys(skills);
    v_skills = values(skills);

    k_minlvls = keys(min_levels);
    v_minlvls = values(min_levels);

    write("         Skills available here:\n"+
      "       --------------------------\n");

    for (i=0; i<sizeof(k_skills); i++) {
	val = member_array(k_skills[i], k_minlvls);

	if (val!=-1)
	    str = "(Minimum level: "+v_minlvls[val]+")";
	else
	    str = "";


	write(capitalize(CHARACTERS[i])+
	  sprintf(": %-18s:   %d   %s\n", 
	    capitalize(k_skills[i]), v_skills[i], str) );
    }

    write("       --------------------------\n");

    write(wrap("You have "+TP->query("nwp_free")+
	" nonweapon proficiency slots remaining."));

    return 1;
}

int learn_prof( string str ) {
    int i;
    string reason, *reselectable;

    if (!str || str=="" || (strlen(str) > 1) ) {
	write("Please enter the letter of the skill.\n");
	return 1;
    }

    if (TO->query("reselectable"))
	reselectable = TO->query("reselectable");
    else
	reselectable = ({});

    if (TO->query("class")) {
	if (!TP->query_level(TO->query("class"))) {
	    write("You cannot learn any skills here.\n");
	    return 1;
	}
    }

    if (query("skills")) skills = query("skills");
    if (query("min_levels")) min_levels = query("min_levels"); 
    k_skills = keys(skills); v_skills = values(skills);
    k_minlvls = keys(min_levels); v_minlvls = values(min_levels);

    str = lower_case(str);
    i = member_array(str, CHARACTERS);

    if ( (i == -1) || (i >= sizeof(k_skills)) ) {
	write(capitalize(str)+" is not a valid choice.\n");
	return 1;
    }

    str = k_skills[i];

    if (TP->query_skill(str) && member_array(str, reselectable)==-1) {
	write("You already have that proficiency.\n");
	return 1;
    }

    if ((int)TP->query("nwp_free") < v_skills[i]) {
	write("You don't have enough slots to learn that skill.\n");
	return 1;
    }

    i = member_array(str, k_minlvls);
    if (i != -1) {
	int lvl;
	if (TO->query("class"))
	    lvl = TP->query_level(TO->query("class"));
	else
	    lvl = TP->query_level();

	if (lvl < v_minlvls[i]) {
	    write (wrap("You must be at least level "+
		v_minlvls[i]+" to purchase "+str+"."));
	    return 1;
	}
    }

    i = member_array(str, k_skills);
    i = v_skills[i] * -1;
    if (!i) {
	write("Error in proficiency room.\n"+
	  "Please notify Cyanide.\n");
	return 1;
    }

    reason = skills_function(str);

    if (reason && reason != "") {
	write(reason);
	return 1;
    }

    TP->set_skill(str, (i*-1));
    TP->add("nwp_free", i);

    write(wrap("You have selected "+str+"."));

    return 1;
}

string skills_function(string str) { return ""; }

/* EOF */
