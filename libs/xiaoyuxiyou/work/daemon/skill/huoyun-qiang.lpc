// huoyun-qiang.c 【火云枪法】

inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action" : "$N大吼一声，手中$w微扬，一招"+HIR"「风起云涌」"NOR"，霎时枪影如封墙，有若旎转钢刀般挟以万钧之势封向$n。\n",
                "damage" : 55,
                "dodge" : 5,
                "parry" : -10,
                "force" : 50,		
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N反身一弹，重重枪影先将敌人身形罩住，而后一招"+HIR"「覆雨翻云」"NOR"，只见寒芒一闪，$w己闪电般射向$n。\n",
                "damage":               60,
                "dodge":                15,
                "parry":                -10,
                "force" : 55,		                
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N使出"+HIR"「火龙腾云」"NOR"，七道红芒一经泛出有若苍鹰猎兔以雷霆万钧之势，快愈飘风的刺向$n。\n",
                "damage":               65,
                "dodge":                20,
                "parry":                -10,
                "force" : 60,		                
                "damage_type":  "刺伤"
        ]),
         ([      "action": "$N$w指地，身形半曲，使出一招"+HIR"「浴火凤凰」"NOR"，往前射去，只见一道红芒掠过，人枪如流星似的划过空间，冲向$n。\n",
                "damage":               75,
                "dodge":                -10,
                "parry":                -5,
                "force" : 60,		                
                "damage_type":  "刺伤"
        ]),
         ([      "action": "$N微一反身，己使出"+HIR"「天火燎原」"NOR"，舞出万朵火花，只见红光闪闪，$n被罩入一片红光之中。\n",
                "damage":               85,
                "force" : 70,		                
                "dodge":                20,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N狂喝一声，$w己泛起一道红芒，只见狂风大作，$N枪势一带，这招"+HIR"「火云敝日」"NOR"摧枯拉朽，击向$n。\n",
                "damage":               95,
                "force" : 50,		                
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N$w一抖，枪影满天，$n顿时被罩在这招"+HIR"「晚霞满天」"NOR"的一片火光之中。\n",
                "damage":               100,
                "force" : 50,		                
                "dodge":                15,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action": "$N$w一抖，向$n脚下磋来，搅起一片尘土，这招"+HIR"「火烧连营」"NOR"逼得$n连连后退，无处落脚。\n",
                "damage":               105,
                "force" : 80,		                
                "dodge":                10,
                "parry":                -20,
                "damage_type":  "刺伤"
        ]),
	([      "action": HIR"$N"HIR"手中的$w"HIR"直挺,吐雾遮三界,喷云照四方,一天杀气凶声吼,日月星辰不见光。\n"NOR,
		"damage":              110,
                "force" : 100,				
                "dodge":              -40,
                "parry":              -40,
                "damage_type":  "刺伤"
        ]),
 });

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_maxforce() < 100 )
                return notify_fail("你的内力不够，没有办法练火云枪。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	int i;
	if( !intp(i=me->query_temp("HYQ_perform"))
	 || i<1 )
	{
		if( me->query_level()<40 )
			return action[random(4)];
		else if( me->query_level()<80 )	
			return action[random(7)];
		else	return action[random(sizeof(action))];		
	}
	if( i>sizeof(action) )
		i = sizeof(action);
	if( i<1 )
		i = 1;
	return action[i-1];
}

varargs int practice_skill(object me,int flag)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");

        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 15  )
                return notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -15);
	if ( flag )    write("你按着所学练了一遍火云枪。\n");
        return 1;
}

string perform_action_file(string func)
{
  	return CLASS_D("kusong") + "/huoyun-qiang/" + func;
}

string query_parry_msg(object me,object target)
{
	string *msg;
	if( !me || !target )
		return 0;
	if( !me->query_temp("weapon") )
		return 0;
	msg = ({
		"结果$n大吼一声，手中$W微扬，一招"+HIR"「风起云涌」"NOR"，霎时枪影如封墙全部挡住了。\n",
                "结果$n反身一弹，重重枪影先将$N身形罩住，而后一招"+HIR"「覆雨翻云」"NOR"，只见寒芒一闪将之格开。\n",
                "结果$n使出"+HIR"「火龙腾云」"NOR"，七道红芒一闪将之格开。\n",
                "结果$n一招"+HIR"「浴火凤凰」"NOR"，只见一道红芒掠过，已挡住了此招。\n",
                "结果$n微一反身，己使出"+HIR"「天火燎原」"NOR"，舞出万朵火花，将来招全部逼回。\n",
                "结果$n狂喝一声，$W己泛起一道红芒，“嘡啷”一声格开了。\n",
                "结果$n$W一抖，枪影满天，将这招挡住了。\n",
                "结果$N$W搅起一片尘土，一招"+HIR"「火烧连营」"NOR"逼得$N只得换招。\n",
                HIR"结果$n"HIR"手中的$W"HIR"直挺,一天杀气凶声吼，日月星辰不见光。$N"HIR"无奈撤招\n"NOR,
	});
	if( me->query_level()<40 )
		return msg[random(4)];
	else if( me->query_level()<80 )
		return msg[random(7)];	
	else	return msg[random(9)];
}
