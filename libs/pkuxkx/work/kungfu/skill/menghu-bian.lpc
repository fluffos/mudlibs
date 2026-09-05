// 三十六路猛虎鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":"$N,手扬鞭起，手中$w将$n团团围住，内力一吐，鞭圈匀速缩小。",
        "force":        180,
        "dodge":        -10,
        "damage":       100,
        "skill_name" : "聚火",
        "damage_type":  "内伤"
]),
([      "action":"$N左手虚幻，右手手中$w由似一条青龙迅速击向$n。",
        "force":        200,
        "dodge":        5,
        "damage":       150,
        "skill_name" : "起光",
        "damage_type":  "刺伤"
]),
([      "action":"$N腾空而起，手中$w舞成圆环，压向$n,令$n无处可躲。",
        "force":        220,
        "dodge":        10,
        "damage":       180,
        "skill_name" : "招雨",
        "damage_type":  "内伤"
]),
([      "action":"$N力贯鞭梢，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "force":        240,
        "dodge":        -5,
        "damage":       210,
        "skill_name" : "动雷",
        "damage_type":  "淤伤"
]),
([      "action":"$N往前一纵, 但见$N身形一转，手中$w如鬼魅一般，神不知鬼不觉地袭向$n的$l！",
        "force":        270,
        "dodge":        -10,
        "damage":       220,
        "skill_name" : "移电",
        "damage_type":  "刺伤"
]),
([      "action":"$N手持$w,力贯鞭稍，手中$w犹如彩虹般击向$n,已将$n笼罩于鞭下。",
        "force":        300,
        "dodge":        -20,
        "damage":       200,
        "skill_name":  "剪虹",
        "damage_type":  "刺伤"
]),
([      "action":"$N左手虚晃，右脚突然向前迈出，右手$w如同鬼魅一般无声无息的刺向$n!",
        "force":        280,
        "dodge":        0,
        "damage":       190,
        "skill_name" : "止风",
        "damage_type":  "刺伤"
]),
([      "action":"$N向前纵出，身体飞过$n头顶，手中$w击向$n的$l",
        "force":        250,
        "dodge":        100,
        "damage":       170,
        "skill_name" : "断云",
        "damage_type":  "内伤"
]),
([      "action":"$N手中$w晃出满天鞭影，虚虚实实的鞭影，铺天盖地的击向$n",
        "force":        240,
        "dodge":        50,
        "damage":       250,
        "skill_name" : "遮月",
        "damage_type":  "淤伤"
]),
([      "action":"$N手中$w形似蛟龙又似飞蝗,密不透风的罩向$n！",
        "force":        320,
        "dodge":        40,
        "damage":       210,
        "skill_name" : "掩日",
        "damage_type":  "淤伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;
        int lvl = (int)me->query_skill("menghu-bian", 1);
        int t = 1, j;
        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不足，没有办法练三十六路猛虎鞭法, 多练些内力再来吧。\n");

        if ((int)me->query_skill("bixue-xinfa", 1) < 120)
                return notify_fail("你的碧血心法火候太浅。\n");

return 1;
/*
        if(lvl<=100)
        {
                if (lvl > 10 && (int)me->query("shen") < t * 100)
                        return notify_fail("你的侠义正气太低了。\n");
        }
        else
        {
                if ((int)me->query("shen") < (11100 + (lvl - 100) * 1000))
                        return notify_fail("你的侠义正气太低了。\n");
        }
        return 1;
*/
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
        level   = (int) me->query_skill("menghu-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练三十六路猛虎鞭法。\n");
   	if( (int)me->query("neili") < 100 )
     	return notify_fail("你的内力不够了。\n");
        me->receive_damage("qi", 50);
        me->add("neili", -20);
        return 1;
}

string perform_action_file(string action)
{
                return __DIR__"menghu-bian/" + action;
}


