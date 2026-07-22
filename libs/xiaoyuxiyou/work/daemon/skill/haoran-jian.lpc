// haoran-jian.c【浩然剑气】
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      
	"name":   "罢黜百家",
    	"action" : "$N身形端正，$w舞动大开大合，一招「罢黜百家」，$w带着凌厉的浩然之气直刺$n$l！\n",
    	"dodge" : 5,
    	"damage" : 35,
    	"parry"  :5,
    	"damage_type" : "刺伤"
]),
([      "name":   "半部论语治天下",
    	"action" : "$N身形不动，右前臂外旋，剑刃上崩，一招「半部论语治天下」，手中$w舞动半旋，一剑指向$n！\n",
    	"dodge" : 10,
    	"damage" : 25,
    	"parry"  :15,
	"damage_type" : "刺伤"
]),
([      
	"name":   "存心养性",
    	"action" : "$N左脚向前，蹬地跳起，右手$w突向前刺，随转体变向，一式「存心养性」，剑光如匹练般泄向$n！\n",
    	"dodge" : 5,
    	"damage" : 30,
    	"parry"  :15,
	"damage_type" : "刺伤"
]),
([      
	"name":   "攻乎异端",
    	"action" : "$N剑锋一转，招式忽的变得凌厉，使出一式「攻乎异端」，$w往来运转如梭，连绵不绝刺向$n！\n",
    	"dodge" : -5,
    	"damage" : 40,
    	"parry"  :10,
	"damage_type" : "刺伤"
]),
([      
	"name":   "毁不危身",
    	"action" : "$N屈腕抬臂，$w挥舞平稳，奋勇向前，一式「毁不危身」公公正正直劈向$n。\n",
    	"dodge" : -10,
    	"damage" : 30,
    	"parry"  : 5,
	"damage_type" : "劈伤"
]),
([      
	"name":   "君子交绝不出恶声",
    	"action" : "$N左上步，抱剑当胸，右手$w一式「君子交绝不出恶声」，剑意圆润，刺向$n。\n",
    	"dodge" : 0,
    	"parry"  :15,
    	"damage" :20,
	"damage_type" : "刺伤"
]),
([      
	"name":   "孔孟之道",
    	"action" : "$N墨守成规，剑意规整，一记「孔孟之道」直取$n咽喉！\n",
    	"dodge" : -10,
    	"damage" : 30,
    	"parry"  :5,
    	"limb" : "颈部",
    	"damage_type" : "刺伤"
]),
([      
	"name":   "诗云子曰",
    	"action" : "$N碎步急进，提剑沿剑身方向疾速上崩，一招「诗云子曰」直取$n。\n",
    	"dodge" : -5,
    	"damage" : 30,
    	"parry"  :15,
	"damage_type" : "刺伤"
]),
([      
	"name":   "微言大指",
    	"action" : "$N剑锋舞动繁密，宛如繁星点点，细微之处却是杀机重重！这式「微言大指」却是大器已成！\n",
    	"dodge" : -15,
    	"damage" : 40,
    	"force"  : 100,
    	"parry"  :-10,
	"damage_type" : "刺伤"
]),
([      
	"name":   "邹鲁遗风",
    	"action" : "$N$w大开大合间，浩然之气澎湃而出，一招「邹鲁遗风」叫人心神皆疲。\n",
    	"dodge" : -15,
    	"damage" : 50,
    	"parry"  :-10,
    	"force"  : 120,
    	"weapon" : "浩然之气",
	"damage_type" : "刺伤"
]),
([      
	"name":   "阳儒阴释",
    	"action" : "$N神情凝重，$w剑意一转，隐含天地明理，这招「阳儒阴释」，叫人防不胜防！\n",
    	"dodge" : -10,
    	"damage" : 60,
    	"parry"  :-10,
    	"force"  : 130,
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { 
    return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
	if((int)me->query("force") < 100)
   		return notify_fail("你的内力不够。\n");
    	if ((int)me->query_skill("force", 1) < 10)
   		return notify_fail("你的内功火候太浅。\n");
   	if( me->query_skill("haoran-jian",2)>me->query_skill("haoran-zhengqi",2) )
   		return notify_fail("你的浩然正气修为不够，无法带动浩然剑意。\n");	
    	return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	i = me->query_temp("HRJ_perform");
	if( i<=0 )
        	return action[random(8)];
        else
        {
        	if( i>10 ) i =10 ;
        	if( i<8 ) i = 8;	
		return action[i];
	}	
} 
       
varargs int practice_skill(object me,int flag)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 10 )
                return notify_fail("你的内力或气不够，没有办法练习浩然剑意。\n");
   	if( me->query_skill("haoran-jian",2)>me->query_skill("haoran-zhengqi",2) )
   		return notify_fail("你的浩然正气修为不够，无法带动浩然剑意。\n");	
                
	me->add("kee", -30);
	me->add("force", -5);
	return 1;
}

string perform_action_file(string func) {
  return CLASS_D("suburb") + "/haoran-jian/" + func;
}

