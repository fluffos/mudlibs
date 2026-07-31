// fonxanforce.c
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{
    mapping skl;
    string *sname;
    int i;
        int lvl = (int)me->query_skill("jingyi-shengong", 1);
//	if (!wizardp(me))
//		return notify_fail("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");			
        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的净衣神功。\n");
//        if( (string)me->query("gender") != "女性" )
//                return notify_fail("碧波神功是只有女子才能练的武功。\n");			
    if (me->query("family/family_name")!="白云城" && me->query("family/family_name")!="白云城")
   return notify_fail("你不加入本门，无法传授本门技能的精髓。\n");			
    if (me->query_skill("force",1)<100)
        return notify_fail("你的基本内功基础不够，怎能学净衣神功。\n");
   
    skl = this_player()->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
      
    }
    return 1;
}



int practice_skill(object me)
{
        return notify_fail("净衣神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
return __DIR__"jingyi-shengong/"+func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage2,ap,dp;
	damage2 = (int)me->query_skill("jingyi-shengong",1);
	ap = me->query_skill("jingyi-shengong",1);
	dp = victim->query_skill("force",1);
    if( damage_bonus < 100 ) return 0;
	if ( me->query_skill("jingyi-shengong",1) < 100)	 return 0;
	if ( me->query("jiali") < 1 || me->query("neili") < 100 || me->query_skill_mapped("force") != "jingyi-shengong") return 0;	
	if (damage2<10) damage2=10;
	if ( random(ap) > dp/20 && random(8)==0 && me->query("jiali") > 0) 
	{
		victim->receive_wound("qi", 100+damage2+damage_bonus,me);
		me->add("neili", -100 );
		return HIB "$N发挥出"+HIR+"净衣神功"NOR HIB"的真髓,浪涛滚滚摧毁了$n的真元！！！！\n" NOR;
	}
}

mapping exercise_msg(object me)
{
  return ([
        "status_msg" : "脸上青光隐现，静坐如海涛之礁石。\n" ,
        "start_my_msg" : "盘膝坐下，双掌并拢，平放在小腿上，胸口起伏不定，嘴一张一合，并有白色烟圈吐出。\n",
        "start_other_msg" :  me->name() + "盘膝坐下，胸口起伏不定，嘴一张一合，并有白色烟圈吐出。\n",
        "heal_my_msg" : "吐出来的白色烟圈一波接一波，如浪涛一般缓缓飘向远方，似有海浪声传来。\n",
        "heal_other_msg" :  me->name() + "吐出来的吐出来的白色烟圈一波接一波，如浪涛一般缓缓飘向远方，"+ me->name() + "似乎听到有海浪拍岸声传来。\n",
        "halt_msg" :  "长长的吸了一口气，白色雾圈倒吸回来，站了起来。\n",
        "end_my_msg" : "长长的吸了一口气，待白色雾圈吸入胸腹，你睁开双眼，缓缓站起。\n",
        "end_other_msg" : me->name()+"口中不断吸入白色雾圈，待得白雾吸尽，"+me->name()+"睁开双眼，缓缓站起。\n",		
        "hover_my_msg" : "海涛拍岸声一波接一波。过了良久，浪涛声越来越远，跟着那团白色烟圈也渐渐消失了。\n",
        "hover_other_msg" : me->name()+"一呼一吸之间，只听得海浪拍岸，一浪高过一浪。过了良久，浪涛声越来越远，跟着那团白色烟圈也渐渐消失了。\n",	
    ]);
}
