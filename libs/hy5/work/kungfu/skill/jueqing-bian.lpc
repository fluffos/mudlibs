// jueqing-bian.c  绝情鞭法

#include <ansi.h>

inherit SKILL;
#include <ansi.h>
#include <combat.h>
int sanwu
(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action":		"$N轻抖手腕，一招「青蛇吐芯」，手中$w抖得笔直，直向$n卷去",
	"force":		60,
	"dodge":		30,
	"damage":		330,
	"lvl" : 0,
	"skill_name" : "青蛇吐芯",
	"damage_type":	"鞭伤"
]),
([	"action":		"$N身形一转，一招「毒蝎反尾」，$w在空中转了个圈，以怪异的角度劈向$n",
	"force":		120,
	"dodge":		20,
	"damage":		340,
	"lvl" : 10,
	"skill_name" : "毒蝎反尾",
	"damage_type":	"鞭伤"
]),
([	"action":		"$N一抖长鞭，一招「黑蛛吐丝」，手中$w化做无数幻影，罩向$n",
	"force":		180,
	"dodge":		30,
	"damage":		350,
	"lvl" : 20,
	"skill_name" : "黑蛛吐丝",
	"damage_type":	"鞭伤"
]),
([	"action":		"$N力贯鞭梢，一招「蟾蜍出洞」，手中$w忽左忽右，直劈向$n胸口",
	"force":		240,
	"dodge":		10,
	"damage":		360,
	"lvl" : 30,
	"skill_name" : "蟾蜍出洞",
	"damage_type":	"鞭伤"
]),
([	"action":		"$N运气于腕，一招「蜈蚣翻身」，手中$w转起无数个圈圈，带着一股阴风，直向$n扑去",
	"force":		300,
	"dodge":		120,
	"damage":		380,
	"lvl" : 40,
	"skill_name" : "蜈蚣翻身",
	"damage_type":	"鞭伤"
])

});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;


	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练绝情鞭法。\n");

	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
//	三无三不手
	string *sanwu_msg = 
	({
		"$N一招"+WHT"「无孔不入」"+NOR"，$n身前身後都是$w的影子同时点$n全身各处大穴",
		"$N一招未绝，第二招"+WHT"「无所不至」"+NOR"以然打到，手中$w点向$n周身诸处偏门穴道",
		WHT"两招扫过$N又是一招「无所不为」，$w回旋飞至，专打$n周身柔弱之处"NOR,
	});

		if ( me->query_temp("sanwu") > 0 && me->query_temp("sanwu") <= 3 )
		{
			return ([
			"action": sanwu_msg[me->query_temp("sanwu")-1],
			"dodge": 120,
			"parry": 125,
			"force": 600,
			"damage": 600,
			"damage_type": "鞭伤",
			"post_action": (: sanwu :) ]);
		}

	return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jing") < 50)
		return notify_fail("你的精力不够练绝情鞭法。\n");
        me->receive_damage("jing", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jueqing-bian/" + action;
}

int sanwu(object me, object victim, object weapon, int damage)
{
//	if( damage > 0 && me->query_temp("sanwu") ) 
//		me->delete_temp("sanwu");
}
mapping *query_skilldbase() {return action;}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
       int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	       int neili, neili2;
 
	object weapon;
object target;

        level = (int) me->query_skill("wudu-shengong",1);
        level2= (int) me->query_skill("wudu-shengong",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "wudu-shengong")
{
if (!victim->is_busy()) victim->start_busy(3);	
if (me->query("qi") <= me->query("max_qi")*2) me->add("qi",damage2);
if (me->query("eff_qi") <= me->query("max_qi")*2) me->add("eff_qi",damage2);
 return HIG "$N使出五毒神功！舔了舔$n流出的鲜血，全身的伤好像好了很多！!\n";
}
        neili=me->query("neili");
        neili2=victim->query("neili");
        if(random(neili)>random(neili2)){
//                message_vision(MAG"$n猛然觉得一阵寒气袭来，身子一晃，头脑微微有些发昏。\n"NOR, me, victim);
                victim->apply_condition("chilian_poison", random(me->query_skill("chilian-shenzhang", 1)/2) + victim->query_condition("chilian_poison"));
if(me->query_skill("wudu-shengong",1)> 100)
victim->apply_condition("wuhudu_poison", random(me->query_skill("chilian-shenzhang", 1)/2) + victim->query_condition("wuhudu_poison"));
                if(victim->query("poisoner") != me) victim->set("poisoner", me);
        } else message_vision(YEL"$n忙运内力抵抗，将$N掌上的剧毒逼在体外。\n"NOR,me,victim);

}
