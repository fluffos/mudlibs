// taiji-jian.c 太极剑
// cleansword 2/15/96
// Marz 5/21/96
// Raozhi auto perform by jpei 05092008

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 25,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l",
        "force" : 140,
        "dodge" : 15,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
        "force" : 170,
        "dodge" : 15,
        "damage" : 40,
        "lvl" : 9,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$n的$l",
        "force" : 190,
        "dodge" : 10,
        "damage" : 50,
        "lvl" : 19,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
        "force" : 240,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 29,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，逼向$n的$l",
        "force" : 280,
        "dodge" : 5,
        "damage" : 70,
        "lvl" : 39,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「却步抽剑」，左脚跃步落地，$w回抽，反手勾向$n的$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 80,
        "lvl" : 59,
        "damage_type" : "刺伤"
]),
([      "action" : "$N右腿半屈般蹲，一招「如封似闭」，剑尖虚指，转身撩向$n的$l",
        "force" : 330,
        "dodge" : -5,
        "damage" : 90,
        "lvl" : 79,
        "damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
        "force" : 380,
        "dodge" : -5,
        "damage" : 115,
        "lvl" : 99,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_combine(string combo) { return combo=="xuanxu-dao"; }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 20)
                return notify_fail("你的太极神功火候太浅。\n");
        if ((int)me->query_skill("taiji-jian", 1) >= (int)me->query_skill("taiji-quan", 1))
        //if ((int)me->query_skill("taiji-quan", 1) < 20)
                return notify_fail("你的太极拳火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int level, pflv;
		mapping ac=([]);

        level = (int) me->query_skill("taiji-jian",1);
		ac += action[random(sizeof(action))];
		pflv = (int)me->query("purefamily/level");

		if (pflv>=5 && random(5)==0 && me->query("purefamily/family_name") == "武当派")
		{
			ac["action"] += "！\n" HIC "$N" HIC "以太极剑“神在剑先、绵绵不绝”之意运剑，心中全无半点拘囿，这一招便使得浑然天成，威力无俦";
			ac["damage"] += level;
			return ac;
		}

        if ( random(10) == 0 
          && me->query("taiji")
          && me->query("neili") > 100 
          && (string)me->query_skill_mapped("force") == "taiji-shengong" ){
                me->add("neili", -50-random(50));
                return ([
                "action": HIB"$N"HIB"默运太极，手中之剑竟成了一条软带，轻柔曲折，飘忽不定，正是武当绝学「绕指柔剑」！"NOR,
                "dodge": 40,
                "damage": level,
                "damage_type": "刺伤"]);
        }
		
		return ac;
}

int practice_skill(object me)
{
        object weapon;
        if ((int)me->query_skill("taiji-jian", 1) >= (int)me->query_skill("taiji-quan", 1))
                return notify_fail("你的太极拳火候太浅。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练太极剑法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"taiji-jian/" + action;
}

string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n使出太极剑法「卸」字诀，$v轻轻一点，$N的$w好象打在棉絮中，对$n毫无伤害。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
        "$p左手剑诀斜引，$w横过，画了个半圈，平搭在$P$w之上，劲力传出，$w登时一沉。\n",
        "$p手中$w斜指，太极圆圈在$w上一搭，结果$P的力道被卸在一旁！",
        "$p将$w交左手，在身前划了两个圆圈，$P见$p剑劲连绵，护住全身，竟无半分空隙。\n",
        "只见$p使出四两拨千斤之巧劲，$w斜引，将$P的$w引在一旁！\n",
        "$p剑招未曾使老，已然圈转。突然之间，$P眼前出现了几个白色光圈，大圈小圈，正圈斜圈，闪烁不已。$P眼睛一花，只好回招。\n",
        "$p当下凝神专志，将一套太极剑法使得圆转如意，严密异常的守住门户，使$P招数落空。\n",
        "$p以太极剑中「云麾三舞」三式解开。$P见$p化解时举重若轻，深得内家剑术三昧，不待$p回手，跳开一步。\n"        
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


