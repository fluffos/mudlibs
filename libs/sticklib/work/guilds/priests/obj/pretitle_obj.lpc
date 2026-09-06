#include "../priest.h"
#include <macros.h>
#include <living_defs.h>

#define N_TITLES 11
#define FEM_TITLES ({ \
    "Acolyte", "Daughter", "Sister", "Priestess", \
    "Arch-Priestess", "Abbottess", "Prioress", "Monsigneura", \
    "Archbishop", "Angel", "Arch-Angel" })
#define MALE_TITLES ({ \
    "Acolyte", "Son", "Brother", "Priest", \
    "Arch-Priest", "Abbott", "Prior", "Monsignoir", \
    "Archbishop", "Angel", "Arch-Angel" })


object shadowed;
string pretitle, name;


void do_shadow(object ob, int x) {
    int n;

    shadowed = ob;
    pretitle = OFFICER_D->query_title(ob);
    if(pretitle == "") {
	n = ob->query_level() / 5;
	if(n>=N_TITLES) n = N_TITLES-1;
	if(ob->query_gender() == G_MALE)
	    pretitle = MALE_TITLES[n];
	else
	    pretitle = FEM_TITLES[n];
    }
    name = pretitle +" "+ capitalize(ob->query_real_name());
    shadow(shadowed, 1);
}

string query_name() {
    if(shadowed->query_invis())
	return shadowed->query_name();
    return name;
}

string query_pretitle() {
    if(shadowed->query_invis())
	return shadowed->query_pretitle();
    return pretitle+" ";
}

void problem() { unshadow(); }

string short() {
    string race;

    if(shadowed->query_invis())
	return shadowed->short();

    if(!shadowed->query_race()) race = "human";
    else race = shadowed->query_race();

    if(shadowed->query_hp() < 0)
	return name+" is here, mortally wounded";
    return sprintf("%s the %s is here", name, race);
}

