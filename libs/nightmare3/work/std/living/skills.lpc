//	/std/living/skills.c
//	from the Nightmare mudlib
//	code for the Nightmare skill system
//	created by Descartes of Borg 1september 1992
//	recoded 14 february 1993

#include <daemons.h>

string str_class;
mapping skills;
nosave mapping skill_bonus;

void init_skills(string cl);
void add_skill_points(string skill, int amount);
void reduce_skill_points(string skill, int amount);
void set_skill(string str, int x);
int skill_exists(string str);
int query_max_skill(string str);
int query_skill(string str);
void set_class(string str);
string query_class();

void init_skills(string cl) {
    skills = (mapping)SKILLS_D->init_skills(cl);
}

void add_skill_points(string skill, int amount) {
    int x, max, borg, lvl;

    if(!skills[skill]) return;
    if(amount<1) return;
    x = skills[skill]["points"];
    lvl = skills[skill]["level"];
    x += amount;
    max = ((skills[skill]["max"])*((int)this_object()->query_level()))/20;
    while( x > (borg = (int)SKILLS_D->training_formula(str_class, lvl, skill)) ) {
	x -= borg;
	if(max > lvl) lvl ++;
	else break;
    }
    skills[skill]["points"] = x;
    if(lvl != skills[skill]["level"]) {
      log_file("skills", (string)this_object()->query_name()+" advanced "+
        skill+" from "+skills[skill]["level"]+" to "+lvl+" ("+
        ctime(time())+")\n"
      );
    }
    skills[skill]["level"] = lvl;
}

void reduce_skill_points(string skill, int amount) {
    int x, lev;

    if(skills[skill]) x = skills[skill]["points"];
    else return;
    if(amount < 1) return;
    x -= amount;
    lev = skills[skill]["level"];
    while(x<0) {
	x += (int)SKILLS_D->training_formula(str_class,skills[skill]["level"]-1, skill);
	skills[skill]["level"] --;
    }
    skills[skill]["points"] = x;
    if(skills[skill]["level"] != lev)
      log_file("skills", (string)this_object()->query_name()+" reduced "+
        skill+" from "+skills[skill]["level"]+" to "+lev+" ("+
        ctime(time())+")\n"
      );
}

int query_max_skill(string skill) {
    if(!skills[skill]) return 0;
    else return skills[skill]["max"];
}

int skill_exists(string str) {
    string *vars;

    vars = keys(skills);
    if(str == "picking") return 0;
    if(member_array(str, vars) == -1) return 0;
    else return 1;
}

int query_skill(string skill) {
    int x;

    if(skill_bonus) x= skill_bonus[skill];
    else x = 0;
    if(skills[skill]) x+= skills[skill]["level"];
    else x+= 0;
    return x;
}

int query_base_skill(string skill) {
    if(!skills || !skills[skill]) return 0;
    else return skills[skill]["level"];
}

void set_skill(string str, int x) {
    if(!skills[str]) skills[str] = ([ "level":0 ]);
    skills[str]["level"] = x;
    if(!this_object()->is_player() || creatorp(this_object())) return;
    log_file("illegal", (string)this_object()->query_name()+
      " was advanced in "+str+" artificially by "+
      (this_player() ? this_player()->query_name() : previous_object()->query_name())+"\n");
    log_file("illegal", "file: "+file_name(previous_object())+" ("+
      query_privs(previous_object())+") "+ctime(time())+"\n");
}

void set_class(string str) { str_class = str; }

string query_class() { return str_class; }

protected  void reduce_skills() {
    string *ind;
    int x;
    int i;

    ind = keys(skills);
    for(i=0; i<sizeof(ind); i++) {
        if(!skills[ind[i]]) continue;
	if(query_skill(ind[i]) < 5) continue;
        if(random(101) > 50) {
            log_file("skills", this_object()->query_name()+" lost "+
              ind[i]+" through reduce_skills() "+ctime(time())+"\n");
            skills[ind[i]]["level"] -= random(5)+1;
            skills[ind[i]]["points"] = 0;
        }
    }
}

int add_skill(string type, int level, int max)
{
     if(skill_exists(type)) return 0;
     skills[type] = (["level" : level, "points": 0, "max": max]);
     return 1;
}

int delete_skill(string type)
{
     if(!skill_exists(type)) return 0;
     map_delete(skills, type);
     return 1;
}

string *query_all_skills() { return keys(skills); }

void add_skill_bonus(string skill, int amount) {
    if(!skill_bonus) skill_bonus = ([]);
    if(!skill_bonus[skill]) skill_bonus[skill] = amount;
    else skill_bonus[skill] += amount;
    if(!skill_bonus[skill]) map_delete(skill_bonus, skill);
}

int query_skill_bonus(string skill) {
    if(!skill_bonus) return 0;
    if(!skill_bonus[skill]) return 0;
    return skill_bonus[skill];
}
