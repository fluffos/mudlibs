// wangxiang-fufa 妄想斧法 
// marry 99.8
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([ "name":   ""MAG"盘古开天"NOR"",
           "action": "$N一式「"MAG"盘古开天"NOR"」无华地劈往$n的$l。",
           "force": 50,
           "dodge":  -10,
           "damage": 100,
           "lvl"   : 0,
           "damage_type":  "劈伤"
        ]),
        ([ "name":   ""HIM"披荆斩棘"NOR"",
           "action": "只见$N一招「"HIM"披荆斩棘"NOR"」手中$w画着十字向$n劈去。",
           "force":  250,
           "dodge":  -1,
           "damage": 250,
           "lvl"   : 150,
           "damage_type":  "劈伤"
        ]),
        ([ "name":   ""HIG"班门弄斧"NOR"",
           "action": "$N脸上神色一变，使出一招「"HIG"班门弄斧"NOR"」，手中$w如
雨点般舞向$n的$l",
           "force":  300,
           "dodge":  10,
           "damage": 300,
           "lvl"   : 250,
           "damage_type":  "劈伤"
        ]),
        ([ "name":   ""HIB"鬼斧神工"NOR"",
           "action": "$N手中$w飞速旋转，一招「"HIB"鬼斧神工"NOR"」狠狠地劈向$n。",
           "force":  350,
           "dodge":  30,
           "damage": 350,
           "lvl"   : 350,
           "damage_type":  "劈伤"
        ]),
        ([ "name":   ""WHT"乘风破浪"NOR"",
           "action": "$N忽然曲臂蓄力，$N一式「"WHT"乘风破浪"NOR"」，手中$w陡然劈向$n的$l。",
           "force":  400,
           "dodge":  50,                            
           "damage": 400,
           "lvl"   : 400,
           "damage_type":  "劈伤"
        ]),
 });


int valid_enable(string usage) { return usage=="axe" ||  usage=="parry"; }
int valid_learn(object me)
{
        object weapon;
        int lvl = (int)me->query_skill("wangxiang-fufa", 1);
        int t = 1, j;
        if (lvl<=100)
                for (j = 1; j < lvl / 10; j++)
                        t*=2;
        if ( me->query("gender") != "男性" )
                return notify_fail("你又不是男人练什么妄想斧法？\n");
        if ((me->query("family/master_id")!="xiao jin")&&
            (me->query("family/master_id")!="chu huan")&&  
            (me->query("family/master_id")!="xuanyuan liang"))
                return notify_fail("非本门亲授弟子无法学习。\n");

        if(lvl<=100)
        {
                if (lvl > 10 && (int)me->query("shen") < t * 100) 
                        return notify_fail("你的侠义正气太低了。\n");
        }
        else
        {
                if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
                        return notify_fail("你的侠义正气太低了。\n");
        }

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不足，没有办法练妄想斧法, 多练些内力再来吧。\n");

        if ((int)me->query_skill("axe", 1) < 50)
                return notify_fail("你的基本斧法火候太浅。\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "axe" )
                return notify_fail("你必须先找一柄斧头才能练斧法。\n");

        return 1;
}


string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
        object* ob, obj;
        int i,skill,damage;
        if ((me->query("family/master_id")!="xiao jin")&&
            (me->query("family/master_id")!="chu huan")&&  
            (me->query("family/master_id")!="xuanyuan liang"))
                return notify_fail("非本门亲授弟子无法练习。\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练妄想斧法！\n");
        if( skill > 100 && me->query("shen") < 1)
                return notify_fail("这种武功当得行侠义事。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
                                          
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() && me->query("family/family_name") == "痴心妄想门" )
        {
                victim->receive_wound("qi", (damage_bonus ) * 2 );
                return HIR "只听到「"HIY""BLINK"砰"NOR""HIR"」的一声巨响，$w"HIR"竟然深深陷入皮肉！\n" NOR;
        }
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("wangxiang-fufa",1)) > 399 &&me->query("neili") > 150 && me->query("family/family_name") == "痴心妄想门" )
        {
                me->add("neili", -150);
                return ([
        "action": ""HIB"忽然$N两眼寒光四射，手中$w"HIB"耍得天花乱坠。\n"
        "$n"HIB"心乱如麻，只觉得自己似乎已经无处可逃，眼看一片杀气照向自己。\n"NOR"",
        "force": 500,
        "damage": 500,
        "damage_type": "劈伤"]);
        }
        return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
        return __DIR__"wangxiang-fufa/" + action;
}
