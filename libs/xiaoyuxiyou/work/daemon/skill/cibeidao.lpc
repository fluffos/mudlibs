#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w斜指，一招「五体投地」，反身一顿，一刀向$n的$l撩去。\n",
    	"parry_msg" : "结果被$n“镗”的一声，用$W格开了。\n",
	"force"  : 45,
        "dodge"  : -5,
        "parry"  :  -5,
	"damage_type" : "砍伤"
]),
([	"action" : "$N一招「拜佛朝圣」，左右腿虚点，$w一提一收，平刃挥向$n的颈部。\n",
	"parry_msg" : "结果被$n一招「拜佛朝圣」挡开了。\n",
        "dodge"  : -10,
        "parry"  : -10,
	"force"  : 45,
	"limb"	 : "颈部",
	"damage_type" : "砍伤"
]),
([	"action" : "$N展身虚步，提腰跃落，一招「舍身饲鹰」，刀锋一卷，拦腰斩向$n。\n",
	"parry_msg" : "结果被$n一招「舍身饲鹰」挡开了。\n",
        "dodge"  : -5,
        "parry"  :   -10,
	"force"  : 55,
	"limb"   : "腰间",
	"damage_type" : "砍伤"
]),
([	"action" : "$N一招「开门见佛」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n$l。\n",
	"parry_msg" : "结果$n一招「开门见佛」，$W大开大阖，尽数封住来势。\n",
        "dodge"  : 5,
        "parry"  :  -10,
	"force"  : 100,
	"damage_type" : "砍伤"
]),
([	"action" : "$N手中$w一沉，一招「临溪卧佛」，双手持刃拦腰反切，砍向$n的胸口。\n",
	"parry_msg" : "结果被$n一招「临溪卧佛」挡开了。\n",
        "dodge"  : 10,
        "parry"  : -10,
        "limb"	 : "胸口",
	"force"  : 30,
	"damage_type" : "砍伤"
]),
([	"action" : "$N挥舞$w，使出一招「佛心所向」，上劈下撩，左挡右开，齐齐罩向$n。\n",
	"parry_msg" : "结果被$n一招「佛心所向」架住了。\n",
        "dodge"  : 15,
        "parry"  : -10,
	"force"  : 75,
	"damage_type" : "砍伤"
]),
([	"action" : "$N一招「如沐佛音」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l。\n",
	"parry_msg" : "结果被$n一招「佛心所向」架住了。\n",
        "dodge"  : 5,
        "parry"  : -10,
	"force"  : 120,
	"damage_type" : "砍伤"
]),
([	"action" : "$N盘身驻地，一招「普渡慈航」，挥出一片流光般的刀影，向$n的全身涌去。\n",
	"parry_msg" : "结果$n一招「普渡慈航」，$W挥出一片流光般的刀影，逼回了这招。\n",
        "dodge"  : 20,
        "parry"  : -10,
	"force"  : 160,
	"damage_type" : "砍伤"
]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_maxforce() < 100 )
                return notify_fail("你的内力不够，没有办法学慈悲刀法，等内力提高了再来吧。\n");
        if( !(ob = me->query_temp("weapon"))
          || (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能学慈悲刀法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
	int i = (me->query_skill("cibeidao",1)-80)/64+1;
	if( i>8 ) i = 8;
        return action[random(i)];
}

string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}

varargs int practice_skill(object me,int flag)
{
        if( (int)me->query("kee") < 20
        ||  (int)me->query("force") < 30 )
                return notify_fail("你的内力或气不够，没有办法练习慈悲刀法。\n");
        me->receive_damage("kee", 20);
        me->add("force", -5);
	if ( flag )     write("你按着所学练了一遍慈悲刀法。\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("putuo") + "/cibeidao/" + func;
}
