// huagong-dafa.c 化功大法c
// by yucao
// modified by cleansword
// Modified by iszt@pkuxkx
// Modified by iszt@pkuxkx, 2007-03-20, no other force allowed
#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
        int i = (int)me->query_skill("huagong-dafa", 1);
        int t=-1,j;
        mapping skills;

        t = -i/80*i*i - 1;
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学化功大法。\n");
        if (i > 100 && (int)me->query("shen") > t && (int)me->query("shen") > -5000000) 
                return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");

        if ((int)me->query_skill("poison", 1) < 350 && (int)me->query_skill("poison", 1) < i / 2)
                 return notify_fail("你用毒的功夫还不到家，学不了化功大法。\n");  

        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
                return notify_fail("你练了秃驴牛鼻子们的心法，还学化功大法做什么！\n");


                
        skills = me->query_skills();
        for(i=0; i<sizeof(skills); i++)
        {
                //不能出师去星宿，严格限制，注意！ by Jpei
                //if(me->query("chushi/done") && me->query("chushi/last_family")!="星宿派")
                       //return 1;
                if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("force")
                  && keys(skills)[i] != "huagong-dafa"
                  && keys(skills)[i] != "xiaowuxiang-gong")
                       return notify_fail("你不先散了别派内功，怎能学化功大法？！\n");
        }
        return 1;
}

void skill_improved(object me)
{
        int skill, poison;
        skill = me->query_skill("huagong-dafa", 1);
        poison = me->query_skill("poison", 1);

        if(skill >= 50 && !me->query("xingxiu/hgdf") && poison > 50){
                tell_object(me, HIY"冥冥中你感觉到体内的化功大法和毒技相互相济，使你的内力修为有所提高！\n"NOR);
                me->add("max_neili", (150-poison>10) ? 150-poison : 10);
                me->set("xingxiu/hgdf", 1);
                }
        if(skill >= 150 && me->query("xingxiu/hgdf")==1 && poison > 100){
                tell_object(me, HIY"冥冥中你感觉到体内的化功大法和毒技相互相济，使你的精力修为有所提高！\n"NOR);
                me->add("max_jingli", 100);
                me->set("xingxiu/hgdf", 2);
                }
        if(skill >= 250 && me->query("xingxiu/hgdf")==2 && poison > 150){
                tell_object(me, HIY"冥冥中你感觉到体内的化功大法和毒技相互相济，使你的武功修为有所提高！\n"NOR);
                me->add("combat_exp", 200000);
                me->add("exp/huagong", 200000);
                me->set("xingxiu/hgdf", 3);
                }
        if(skill >= 350 && me->query("xingxiu/hgdf")==3 && poison > 200){
                tell_object(me, HIY"冥冥中你感觉到体内的化功大法和毒技相互相济，使你的属性有所提高！\n"NOR);
                me->add("con", 2);
                me->add("xiantian/con/huagong", 2);
                me->set("xingxiu/hgdf", 4);
                }
}


int practice_skill(object me)
{
        return notify_fail("化功大法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"huagong-dafa/" + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
		case "TYPE_RECOVER":          //TYPE_RECOVER
			return 80;
	  case "TYPE_REC_CD":          //TYPE_REC_CD
	  	return 8; 
    case "TYPE_SUCK_EFF":
      return 15;
	  case "TYPE_SPECIAL_NEILI_EFF": // corporeity 特技对内力最大值的影响
	    return 75;
	  default:
	  	return recv;
	}
}

//化工大法的最大内力为特别设置
//由于化工大法的最大内力相对来说没有优势，所以suck类内力的杂质含量设置为15%，相比来说也更低一点
int query_max_neili(object ob)
{
  return (400+ob->query("con") )*ob->query_skill("force")/30;
}