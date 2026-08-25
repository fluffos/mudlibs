//    /daemon/project.c
//    Nightmare Mudlib
//    Nightmare Project Tracking System
//    by Kalinash@Nightmare on June 30, 1994.
 
#include <save.h>
#include <security.h>
 
int add_group(string name, string leader);
int add_member(string group, string name);
int remove_group(string group);
int remove_member(string group, string name);
int add_project(string group, string name, string project, string file);
int remove_project(string group, string name, string project);
string *query_members(string group);
mapping query_all_members();
string *query_groups();
 
private mapping __Projects;
 
void create() {
    __Projects = ([]);
    restore_object(SAVE_PROJECTS);
}
 
int add_group(string name, string leader) {
    if(!name || !leader) return 0;
    if(!__Projects[name]) __Projects[name] = ([]);
    if(__Projects[name]) return 0;
    __Projects[name]["leader"] = leader;
    save_object(SAVE_PROJECTS);
    return 1;
}
 
int add_member(string group, string name) {
    if(!group || !name) return 0;
    if(!__Projects[group]) return 0;
    if(!__Projects[group]["members"]) 
        __Projects[group]["members"] = ({});
    if(member_array(name, __Projects[group]["members"]) != -1)
        return 0;
    __Projects[group]["members"] += ({ name });
    save_object(SAVE_PROJECTS);
    return 1;
}
 
int remove_group(string group) {
    if(!group) return 0;
    if(!__Projects[group]) return 0;
    map_delete(__Projects, group);
    save_object(SAVE_PROJECTS);
    return 1;
}

int remove_member(string group, string name) {
    if(!group || !name) return 0;
    if(!__Projects[group]) return 0;
    if(!__Projects[group]["members"]) return 0;
    if(member_array(name, __Projects[group]["members"]) == -1) return 0;
    __Projects[group]["members"] -= ({ name });
    save_object(SAVE_PROJECTS);
    return 1;
}

string *query_groups() {
    return keys(__Projects);
}
