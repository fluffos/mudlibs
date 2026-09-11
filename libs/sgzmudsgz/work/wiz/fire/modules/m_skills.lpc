// by fire on Dec 27 1997
// m_skill.c this is used for sg_system
// this fire should be inherit by living.c
#include <classes.h>
#include <ansi.h>
#include <sanguo.h>
inherit CLASS_SG_SKILL;
private mapping sg_skills = ([]);
class sg_skill set_sg_skill(string skill, int p_level,int p_exp)
{
    class sg_skill cs = sg_skills[skill];
    if ( member_array(skill, SG_SKILL_D->query_skills()) == -1 )
        error("没有此种技能\n");
    if ( !cs )
    {
        cs = sg_skills[skill] = new(class sg_skill,
                                 sk_level : p_level,
                                 sk_exp : p_exp);
    }
    else
    {
        cs->sk_level = p_level;
        cs->sk_exp = p_exp;
    }
    return cs;
}
mapping get_sg_skills()
{
    return copy(sg_skills);
}
class sg_skill get_sg_skill(string skill)
{
    return sg_skills[skill];
}
int query_sk_level(string skill)
{
    class sg_skill cs = sg_skills[skill];
    if ( !cs )
    {
	return 0;
    }
    else
    {
        return cs->sk_level ;
    }
}
int query_sk_exp(string skill)
{
    class sg_skill cs = sg_skills[skill];
    if ( !cs )
    {
	return 0;
    }
    else
    {
        return cs->sk_exp ;
    }
}
string * query_self_skills()
{
    return keys(sg_skills);
}
mixed direct_skills_liv(object liv) 
{
	return 1;
}
