// by fire on Dec 27 1997
// m_skill.c this is used for sg_system
// this fire should be inherit by living.c
#include <classes.h>
#include <ansi.h>
#include <sanguo.h>
inherit CLASS_SG_SKILL;

private mapping sg_skills = ([]);
//added by suicide in 20011230 for enable base skill
private mapping skill_map = ([]);
//added end
mixed remove_sg_skill(string sk){
	map_delete(sg_skills,sk);
	return 1;
}
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
    if(CHAR_D->char_exist((this_object()->query_id())[0]))
	{
	    mapping m_sk;
	    m_sk=([]);
        foreach(string sks in keys(sg_skills))
		{
		   cs=sg_skills[sks];
		   m_sk[sks]=cs->sk_level;
		}
        CHAR_D->set_char((this_object()->query_id())[0],"skills",m_sk);
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
//:FUNCTION award_exp
//This function used to award a player some expercce of certain
//skills para award_exp(int num,string skill)
//if skill is "" or empty then award to one of the three basic
//skills randomly
//Example:  .fire->award_exp(1000,"sk_wuli");
//          CHAR_D->find_char("row")->award_exp(10);
mixed award_exp(int num,string sk)
{
   int ran,p_level,p_exp;
   int is_general;
   is_general=this_object()->query_is_jiangjun();
   if((!sk)||(sk==""))
   {  ran=random(10);
	  if(is_general)
	  {
		  switch(ran)
		  {
		  case 0..5:
			  sk="sk_wuli";break;
		  case 6..7:
				sk="sk_zhimou"; break;
		  default:
				sk="sk_meili"; break;
		  }
	  }
	  else
	  {
		  switch(ran)
		  {
		  case 0..1:
			  sk="sk_wuli";break;
		  case 2..5:
				sk="sk_zhimou"; break;
		  default:
				sk="sk_meili"; break;
		  }
	  }
   }
   if ( member_array(sk, SG_SKILL_D->query_skills()) == -1 )
      return -1; // no such skill
   p_level=query_sk_level(sk);
   p_exp=query_sk_exp(sk);
   p_exp+=num;
   if(p_exp<0) p_exp=0;
   set_sg_skill(sk, p_level, p_exp);
   return 1; // success
}

//:FUNCTION increase_level
//This function used to award a player some certain level skills
//if skill is "" or empty then award to one of the three basic
//skills randomly
//Example:  .fire->increase_level("sk_wuli");
//          CHAR_D->find_char("row")->increase_level();

mixed increase_level(string sk)
{
   int ran,p_level,p_exp;
   int is_general;
   is_general=this_object()->query_is_jiangjun();
   if((!sk)||(sk==""))
   {  ran=random(10);
	  if(is_general)
	  {
		  switch(ran)
		  {
		  case 0..5:
			  sk="sk_wuli";break;
		  case 6..7:
				sk="sk_zhimou"; break;
		  default:
				sk="sk_meili"; break;
		  }
	  }
	  else
	  {
		  switch(ran)
		  {
		  case 0..1:
			  sk="sk_wuli";break;
		  case 2..5:
				sk="sk_zhimou"; break;
		  default:
				sk="sk_meili"; break;
		  }
	  }
   }
   if ( member_array(sk, SG_SKILL_D->query_skills()) == -1 )
      return -1; // no such skill
   p_level=query_sk_level(sk);
   p_exp=query_sk_exp(sk);
   p_level++;
   set_sg_skill(sk, p_level, p_exp);
   return 1; //success
}


////all function below is added by suicide for compatiable to ES2 Mudlib
varargs int query_skill(string skill,int flag)
{
if (!flag)
   return (undefinedp(skill_map[skill])?query_sk_level(skill):query_sk_level(skill)+query_sk_level(skill_map[skill]))+
                                                                this_body()->query_temp("apply/"+skill);
else
   return query_sk_level(skill);
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_map) ) {
		map_delete(skill_map, skill);
		return;
	}

	if( !mapp(sg_skills) || undefinedp(sg_skills[mapped_to]) )
		return;
		
	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

string query_skill_mapped(string skill)
{
	if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
		return skill_map[skill];
	return 0;
}

mapping query_skill_map()
{
	return skill_map;
}

