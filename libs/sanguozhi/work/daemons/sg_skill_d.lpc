// sg_skill_d.c write by fire on 26 Dec. 1997
#include <security.h>
#include <classes.h>
#include <sanguo.h>
#define SAVE_FILE "/data/daemons/sg_skill"

inherit M_ACCESS;
inherit CLASS_SG_SKILL;
private mapping sg_skills = ([]);


int restore_me() {
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	return 1;
}
int save_me() {
       unguarded(1, (: save_object, SAVE_FILE :));
	return 1;
}

void create(){
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    return;
}

mixed add_skill(string sk) {
	class sg_skill_reg p_sk;
	if((!sk)||(sk=="")) return "must give name\n";
	if(sg_skills[sk]) return "already has this skill\n";

    p_sk=new(class sg_skill_reg, 
                    sk_name : "",
                    sk_type : 0,
                    sk_get : "",
                    sk_use : "" ,
                    sk_succ : "",
                    sk_fail : "" );
	sg_skills[sk]=p_sk;
	save_me();
	return sg_skills[sk];
}
mixed set_skill(string sk,string par,mixed val) {
	class sg_skill_reg p_skill;
	if(!sg_skills[sk]) return "no such skill.\n";
	p_skill=sg_skills[sk];
	switch(par) {
	case "name":
		p_skill->sk_name=val; break;
	case "type":
		p_skill->sk_type=val; break;
	case "get":
		p_skill->sk_get=val; break;
	case "use":
		p_skill->sk_use=val; break;
	case "succ":
		p_skill->sk_succ=val; break;
	case "fail":
		p_skill->sk_fail=val; break;
	default : return "no such field.\n";
	}
	sg_skills[sk]=p_skill;
	save_me();
	return sg_skills[sk];
}
mixed get_skill(string sk) {
	return sg_skills[sk];
}
void register_skill(string skill, class sg_skill_reg p_skill)
{
//    if ( !check_privilege(PRIV_REQUIRED) )
//        error("security: illegal attempt to add a skill\n");
    if ( sg_skills[skill] )
    {
	printf("The skill of %s has been registed before.\n",skill);
        return;
    }
    sg_skills[skill] = p_skill;
    save_me();
    printf("The skill of %s is successfully registed.\n",skill);
}
void remove_skill(string skill)
{
//    if ( !check_privilege(PRIV_REQUIRED) )
//        error("security: illegal attempt to remove a skill\n");
    if ( !sg_skills[skill] )
    {   printf("The skill of %s is not currently registed.\n",skill);
        return;
    }
    map_delete(sg_skills, skill);
    save_me();
    printf("The skill of %s is successfully removed.\n",skill);
}
string * query_skills()
{
    return keys(sg_skills);
}
string query_name(string skill)
{
	class sg_skill_reg p_skill;
	p_skill=sg_skills[skill];
	if(!p_skill)
		return "";
	else
		return p_skill->sk_name;
}
int query_type(string skill)
{
	class sg_skill_reg p_skill;
	p_skill=sg_skills[skill];
	if(!p_skill)
		return 0;
	else
		return p_skill->sk_type;
}
string query_get(string skill)
{
	class sg_skill_reg p_skill;
	p_skill=sg_skills[skill];
	if(!p_skill)
		return "";
	else
		return p_skill->sk_get;
}
string query_use(string skill)
{
	class sg_skill_reg p_skill;
	p_skill=sg_skills[skill];
	if(!p_skill)
		return "";
	else
		return p_skill->sk_use;
}
string query_succ(string skill)
{
	class sg_skill_reg p_skill;
	p_skill=sg_skills[skill];
	if(!p_skill)
		return "";
	else
		return p_skill->sk_succ;
}
string query_fail(string skill)
{
	class sg_skill_reg p_skill;
	p_skill=sg_skills[skill];
	if(!p_skill)
		return "";
	else
		return p_skill->sk_fail;
}
