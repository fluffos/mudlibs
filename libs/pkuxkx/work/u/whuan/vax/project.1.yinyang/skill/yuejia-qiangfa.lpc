inherit SKILL;

#include <ansi.h>
mapping *action = ({
        ([      "action":
HIW"$N使出一招「气吞山河」，手中的$w"+HIW"画了数圈，又一个急转，向$n的$l刺来",NOR
                "dodge":                20,
                "force":                100,
                "damage":               150,
                "lvl":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N手中的$w"+HIW"突然从手中越起使出一招「还我河山」，扫向$n的$l",NOR
                "dodge":                2,
                "force":                150,
                "damage":               200,
                "lvl":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N把枪一竖，一招「运筹帷幄」，身形借枪之力腾空跃起，手中$w"+HIW"从天而降，指向$n的$l",NOR
                "dodge":                200,
                "force":                110,
                "damage":               160,
                "lvl":               80,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N将手中$w"+HIW"一横,身体一转,$w又从跨下刺出,一招「万川归一」对准$n的面部袭来!\n",NOR
                "dodge":                0,
                "force":                250,
                "damage":               300,
                "lvl":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N将手中$w"+HIW"连晃几个虚招，口中吟道:「生亦何欢,死亦何苦」? 向$n刺去!\n",NOR
                "dodge":                40,
                "force":                300,
                "damage":               350,
                "lvl":               160,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N左手一反,右手单臂握$w"+HIW",使出一招「怒发冲冠」直指向$n的$l",NOR
                "dodge":                300,
                "force":                350,
                "damage":               400,
                "lvl":               200,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N手中$w"+HIW"轻轻一晃，$w"+HIW"化为一道电光，却不禁神色黯然的使出「潇潇雨歇」刺向$n的$l",NOR
                "dodge":                30,
                "force":                450,
                "damage":               500,
                "lvl":               230,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
HIW"$N突然想起岳王爷不由得悲从心头起,使出「岳家枪法」最厉害的一招「夺魄连环」,手中$w"+HIW"闪电般的直奔$n的胸口而去!",NOR
                "dodge":                60,
                "force":                600,
                "damage":               800,
                "lvl":               250,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 150 )
                return notify_fail("你的内力不够，没有办法练岳家枪法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一杆枪才能练此枪法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="spear"|| usage == "parry" ;
}
int valid_combine(string combo) { return combo=="yuejia-qiangfa"; }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 50 )
                return  notify_fail("你的内力或气不够，没有办法练习岳家枪法。\n"
);
        if(me->query_skill("yuejia-qiangfa",1)>50)
                return notify_fail("你现在只能通过watch才能继续提高岳家枪法!。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -40);
        write("你按著所学练了一遍岳家枪法。\n");
        return 1;
}


string *parry_msg = ({
        HIR"$n以攻代守，$v直向$N刺去。$N吓的连退数步，撤回了攻势。\n",NOR
        HIR"$n连滚带爬勉强躲了开去。\n",NOR
});

string *unarmed_parry_msg = ({
        HIR"$n将手中的$v连续刺出，挡住$N的全部攻势。\n",NOR
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"yuejia-qiangfa/" + action;
}

string query_yinyang()
{
	return "太阳";
}
