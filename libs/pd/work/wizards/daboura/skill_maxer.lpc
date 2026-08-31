#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("skill maxer");
    set_id(({ "skills maxer", "maxer" }));
    set_short("skill maxer");
    set_long("a skill maxer");
    set_weight(1);
    set_curr_value("gold", 0);
}

void init()
{
    ::init();
    add_action("max_skills", "max");
}

void max_skills(string str)
{
    object tp = this_player();
    string *skills;
    int maxSkill;
    int x;
    
    skills = keys(this_player()->query_skills());
    x = sizeof(skills);
    
    for(int i = 0; i < x; i++) 
    {
        maxSkill = tp->query_max_skill(skills[i]);   
        write("On skill " +skills[i]);
        tp->set_skill(skills[i], (maxSkill * tp->query_level()) / 2);
    }
    tp->force_me("skills");
}

int query_auto_load() {
 
    if(this_player()->query_position() == "wizard")
        return 1; 
    
    return 0;
 
 }
