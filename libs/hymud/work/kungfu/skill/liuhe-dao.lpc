//Cracked by Kafei
// liuhe-dao.c  青城六合刀法
// qfy September 10, 1996

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N大喝一声，手中$w大开大阖，连连挥刀使出「呵壁问天」，斩向$n的$l",
        "force" : 120,
        "dodge" : 2,
        "parry" : 2,
        "damage": 255,
        "lvl" : 0,
        "skill_name" : "呵壁问天",
        "damage_type":  "割伤"
]),
([      "action":"$N运刀如风，一招「气盖河山」，刀势霸道之极，向着$n周身各处猛砍猛劈",
        "force" : 200,
        "dodge" : 0,
        "parry" : 5,
        "damage": 200,
        "lvl" : 10,
        "skill_name" : "气盖河山",
        "damage_type":  "割伤"
]),
([      "action":"$N一着「天地乍合」，突然抢进$n近侧，迅猛地驱刀连斩，攻式顿然合成一个圆圈",
        "force" : 230,
        "dodge" : 0,
        "parry" : 5,
        "damage": 240,
        "lvl" : 25,
        "skill_name" : "天地乍合",
        "damage_type":  "割伤"
]),
([      "action":"$N仰天悲笑，随即挥刀斩出一式「离合无常」，$w化为一丝丝寒意，裹向$n$l",
        "force" : 280,
        "dodge" : 5,
        "parry" : 10,
        "damage": 250,
        "lvl" : 35,
        "skill_name" : "离合无常",
        "damage_type":  "割伤"
]),
([      "action":"$N施展「和合六出」绕着$n飞旋，$w带着狂野刀风，凌历无比地劈出六刀",
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
	"damage": 300,
        "lvl" : 45,
        "skill_name" : "和合六出",
        "damage_type":  "割伤"
]),
([      "action":"$N脸色庄重，挥刀使出「阴阳隔阂」，$w由上而下向$n连劈，犹似一个个焦雷轰顶",
        "force" : 360,
        "dodge" : 0,
        "parry" : 5,
        "damage": 300,
        "lvl" : 60,
        "skill_name" : "阴阳隔阂",
        "damage_type":  "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
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
        int i, level, num=0;
	object ob;
//        object weapon;
        level = (int)me->query_skill("liuhe-dao",1);
	ob = me->select_opponent();
if (!ob) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
if (!me) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


	if ( me->query_temp("lianhuan") 
&& me->query_skill_mapped("blade") == "liuhe-dao"
&& objectp(weapon = me->query_temp("weapon"))
&&living(ob)
//&& me!=ob
&& !me->query_temp("dsauto"))
{
	   num = 1+random(2);
if ( (string)weapon->query("skill_type") == "blade"
&& !me->query_temp("dsauto")
&& !me->is_busy()
)
{
//if (random(2)==0) ob->start_busy(3);
ob->start_busy(2);
if (num<1) num=1;
if (num>3) num=3;
  	   for (i=1; i<num; i++) {
						if(!ob)
						{
						break;
						}
//						if(me=ob)
//						{
//						break;
//						}

						if(!me)
						{
						break;
						}

						if(!living(ob))
						{
						break;
						}
	   message_vision(YEL"\n$N闪电般地劈出凌历的"+chinese_number(num+1)+"刀。\n"NOR, me);
						if(ob && me)
						{
me->set_temp("dsauto",1);

		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
me->delete_temp("dsauto");
}
}
//}
	   }
        }
	
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_skill("liuhe-dao",1) < 199)
           return notify_fail("此项技能只能大于二百级时能学习。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
        
}

string perform_action_file(string action)
{
        return __DIR__"liuhe-dao/" + action;
}