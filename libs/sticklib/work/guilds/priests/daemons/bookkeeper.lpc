#include "../priest.h"

#include "../skills.h"

inherit PSKILLS;

#define FILE_NAME PRIEST_SAVE_DIR "top_list"
#define LIST_SIZE 20

#define TP this_player()

int *a_scores, *p_scores;
string *a_names, *p_names;


void
reset(int arg)
{
    int i;
    if(arg) return;

    if(!restore_object(FILE_NAME)) {
	TP->tell_me("Bookkeeper save file doesn't exist, creating new.");
	a_scores = allocate(LIST_SIZE);
	a_names = allocate(LIST_SIZE);
	p_scores = allocate(LIST_SIZE);
	p_names = allocate(LIST_SIZE);
	for(i=0;i<LIST_SIZE;i++) {
	    a_scores[i] = p_scores[i] = 0;
	    a_names[i] = p_names[i] = "--";
	}
	save_object(FILE_NAME);
    }
}

void
remove_me(string name)
{
    int n;
    if((n = member(a_names,name))>-1) {
	a_scores[n] = -1;
	a_scores -= ({-1});
	a_names -= ({name});
	a_scores += ({0});
	a_names += ({"--"});
    }
    if((n = member(p_names,name))>-1) {
	p_scores[n] = -1;
	p_scores -= ({-1});
	p_names -= ({name});
	p_scores += ({0});
	p_names += ({"--"});
    }
}

void
update_me(object who)
{
    int a_coeff, p_coeff;
    int i, *pexes;
    object sym;
    string name;

    sym = who->query_guild_object();
    pexes = sym->query_pexes();
    a_coeff = p_coeff = 0;
    for(i=0;i<7;i++)
	p_coeff += pexes[i];
    for(i=7;i<N_SKILLS;i++)
	a_coeff += pexes[i];

    name = who->query_real_name();
    remove_me(name);
    i = LIST_SIZE-1;
    if(a_coeff>a_scores[i--]) {
	while(i>=0 && a_coeff>a_scores[i]) {
	    a_scores[i+1] = a_scores[i];
	    a_names[i+1] = a_names[i];
	    i--;
	}
	a_scores[i+1] = a_coeff;
	a_names[i+1] = name;
    }

    i = LIST_SIZE-1;
    if(p_coeff>p_scores[i--]) {
	while(i>=0 && p_coeff>p_scores[i]) {
	    p_scores[i+1] = p_scores[i];
	    p_names[i+1] = p_names[i];
	    i--;
	}
	p_scores[i+1] = p_coeff;
	p_names[i+1] = name;
    }

    save_object(FILE_NAME);
}

string
top_alc_list()
{
    string str;
    int i;

    str = "";
    for(i=0;i<LIST_SIZE;i++) {
	str += sprintf("%:2d %-:26s %d\n",
	  i+1, capitalize(a_names[i]), a_scores[i]);
    }
    return
    "\nThe top " + LIST_SIZE + " alchemists of the Priest guild:\n\n" +
    sprintf("%-*#s\n", 78, str);
}

string
top_spell_list()
{
    string str;
    int i;

    str = "";
    for(i=0;i<LIST_SIZE;i++) {
	str += sprintf("%:2d %-:26s %d\n",
	  i+1, capitalize(p_names[i]), p_scores[i]);
    }
    return
    "\nThe top " + LIST_SIZE + " priests:\n\n" +
    sprintf("%-*#s\n", 78, str);
}

