// zui-gun.c -少林醉棍
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":HIB"「蓝采和，提篮劝酒醉朦胧」，$N手中$w半提，缓缓划向$n的$l"NOR,
        "force" : 180,
        "dodge" : 0,
        "parry" : 5,
        "damage": 80,
        "lvl" : 0,
        "skill_name" : "蓝采和，提篮劝酒醉朦胧",
        "damage_type":"挫伤"
]),
([      "action":HIM"「何仙姑，拦腰敬酒醉仙步」，$N左掌护胸，右臂挟棍猛地扫向$n的腰间"NOR,
        "force" : 200,
        "dodge" : 5,
        "parry" : 10,
        "damage": 100,
        "lvl" : 10,
        "skill_name" : "何仙姑，拦腰敬酒醉仙步",
        "damage_type":"挫伤"
]),
([      "action":HIR"「曹国舅，千杯不醉倒金盅」，$N倒竖$w，指天打地，向$n的$l劈去"NOR,
        "force" : 230,
        "dodge" : 5,
        "parry" : 5,
        "damage": 120,
        "lvl" : 20,
        "skill_name" : "曹国舅，千杯不醉倒金盅",
        "damage_type":"挫伤"
]),
([      "action":HIC"「韩湘子，铁棍提胸醉拔萧」，$N横提$w，棍端划了个半圈，击向$n的$l"NOR,
        "force" : 270,
        "dodge" : 5,
        "parry" : 5,
        "damage": 150,
        "lvl" : 30,
        "skill_name" : "韩湘子，铁棍提胸醉拔萧",
        "damage_type":"挫伤"
]),
([      "action":HIW"「汉钟离，跌步翻身醉盘龙」，$N手中棍花团团，疾风般向卷向$n"NOR,
        "force" : 320,
        "dodge" : 10,
        "parry" : 15,
        "damage": 180,
        "lvl" : 40,
        "skill_name" : "汉钟离，跌步翻身醉盘龙",
        "damage_type":"挫伤"
]),
([      "action":HIG"「铁拐李，踢倒金山醉玉池」，$N单腿支地，一腿一棍齐齐击向$n的$l"NOR,
        "force" : 380,
        "dodge" : 5,
        "parry" : 15,
        "damage": 200,
        "lvl" : 50,
        "skill_name" : "铁拐李，踢倒金山醉玉池",
        "damage_type":"挫伤"
]),
([      "action":HIY"「张果老，醉酒抛杯倒骑驴」，$N扭身反背，$w从胯底钻出，戳向$n的胸口"NOR,
        "force" : 450,
        "dodge" : 5,
        "parry" : 20,
        "damage": 200,
        "lvl" : 60,
        "skill_name" : "张果老，醉酒抛杯倒骑驴",
        "damage_type":"挫伤"
]),
([      "action":HIC"「吕洞宾，酒醉提壶力千钧」，$N腾空而起，如山棍影，疾疾压向$n"NOR,
        "force" : 530,
        "dodge" : 10,
        "parry" : 25,
        "damage": 250,
        "lvl" : 64,
        "skill_name" : "吕洞宾，酒醉提壶力千钧",
        "damage_type":"挫伤"
]),
});

int valid_enable(string usage) { return (usage == "club") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
                return notify_fail("你的混元一气功火候太浅。\n");
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
        int i, level;
        level   = (int) me->query_skill("zui-gun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练少林醉棍。\n");
        me->receive_damage("qi", 25);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"zui-gun/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_yinyang()
{
	return "少阳";
}