// snowsword. 【风回雪舞剑法】
//lestat modi for dtxy 2001
// 寒芳留照魂应驻，碗凝深翠拂平沙
// 攒花染出几霜痕，霜印传神梦也空
// 篱筛破落锁玲珑，暗香浮动影黄昏
// 风波不信菱枝弱
// 夜间使用，伤害1.5倍
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N身形稍退，使出一招",
        "$N不闪不避，一式",
        "$N使出",
        "$N妍然一笑，一式",
        "$N一个急转，使出",
});
string* skill_tail =({
        "，手中$w化为一道疾光刺向$n的$l。",
        "，手中$w化为一道金光罩向$n。",
        "，手中$w不偏一歪，直刺$n的$l。",
        "，手中$w如飞，发出点点寒光。",
        "，顿时一阵幽香飘向$n",
});


mapping *action = ({
        ([      "action":"$N使一招"+HIB"「寒芳留照魂应驻」"NOR+"，手中$w化为一道疾光刺向$n的$l",
                "dodge":-10,
                "parry":-10,
                "damage":30,
                "damage_type":"刺伤",
        ]),
        ([      "action":"只见$N几个急转，使出"+HIG"「晚凝深翠拂平沙」"NOR+"，一声娇喝中剑光冲天而起，扫向$n的$l",
                "dodge":-40,
                "parry":-5,
                "damage":40,
                "damage_type":"割伤",
        ]),
        ([      "action":"$N淡淡一笑，一式"+HIY"「攒花染出几霜痕」"NOR+"舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
                "dodge":-15,
                "parry":-15,
                "damage":35,
                "damage_type":"刺伤",
        ]),
        ([      "action":"$N手中$w轻轻一抖，一式"+HIW"「霜印传神梦也空」"NOR+"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
                "dodge":-35,
                "parry":-5,
                "damage":35,
                "damage_type":"刺伤",
        ]),
        ([      "action":"$N手中$w再一抖，只见寒光点点，飘浮不定。这一招"+HIR"「篱筛破月锁玲珑」"NOR+"只看得$n眼花缭乱，哪里还能招架",
                "dodge":-25,
                "parry":-20,
                "damage":45,
                "damage_type":"刺伤",
        ]),
        ([      "action":"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸，正是一式"+MAG"「暗香浮动月黄昏」"NOR+"",  
                "dodge":-40,
                "parry":-5,
                "damage":40, 
                "damage_type":"刺伤",
        ]),
        ([      "action":"$N不闪不避，一式"+HIC"「风波不信菱枝弱」"NOR+"，神色娴雅，蓄势待发，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
                "dodge":-20,
                "parry":-10,
                "damage":50,
                "damage_type":"刺伤",
        ]),
        ([      "action":"$N手中$w轻轻一抖，一式"HIW"「霜印传神梦也空」"NOR"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
                "dodge":-35,
                "parry":-5,
                "damage":45,
                "damage_type":"刺伤",
        ]),
        ([      "action":"$N手中$w再一抖，只见寒光点点，飘浮不定，罩向$n的$l",
                "dodge":-20,
                "parry":-15,
                "damage":65,
                "damage_type":"刺伤",
        ]),
        ([      "action":"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，$w虚空而立，直指$n的后胸",
                "dodge":-35,
                "parry":-5,
                "damage":55,
                "damage_type":"刺伤",
        ]),
        ([      "action":"$N一式「风波不信菱枝弱」，神色娴雅，蓄势待发，一道剑光澄如秋水、寒似玄冰",  
                "dodge":-40,
                "parry":-5,
                "damage":100, 
                "damage_type":"刺伤",
        ]),
});

mapping *action2 = ({
        ([      "action":"$N使一招"+HIB"「寒芳留照魂应驻」"NOR+"，手中$w化为一道疾光刺向$n的$l",
                "dodge":-15,
                "parry":-12,
                "damage":32,
                "damage_type":"刺伤",
                "weapon" : "疾光",
        ]),
        ([      "action":"只见$N几个急转，使出"+HIG"「晚凝深翠拂平沙」"NOR+"，一声娇喝中剑光冲天而起，扫向$n的$l",
                "dodge":-45,
                "parry":-7,
                "damage":42,
                "damage_type":"割伤",
                "weapon" : "剑光",
        ]),
        ([      "action":"$N淡淡一笑，一式"+HIY"「攒花染出几霜痕」"NOR+"舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
                "dodge":-20,
                "parry":-17,
                "damage":37,
                "damage_type":"刺伤",
        ]),
        ([      "action":"$N手中$w轻轻一抖，一式"+HIW"「霜印传神梦也空」"NOR+"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
                "dodge":-40,
                "parry":-7,
                "damage":37,
                "damage_type":"刺伤",
                "weapon" : "寒光",
        ]),
        ([      "action":"$N手中$w再一抖，只见寒光点点，飘浮不定。这一招"+HIR"「篱筛破月锁玲珑」"NOR+"只看得$n眼花缭乱，哪里还能招架",
                "dodge":-30,
                "parry":-22,
                "damage":47,
                "damage_type":"刺伤",
                "weapon" : "寒光",
        ]),
        ([      "action":"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，$w上霞光一闪，直指$n的后胸，正是一式"+MAG"「暗香浮动月黄昏」"NOR+"",  
                "dodge":-45,
                "parry":-7,
                "damage":42, 
                "damage_type":"刺伤",
                "weapon" : "霞光",
        ]),
        ([      "action":"$N不闪不避，一式"+HIC"「风波不信菱枝弱」"NOR+"，神色娴雅，蓄势待发，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
                "dodge":-25,
                "parry":-17,
                "damage":52,
                "damage_type":"刺伤",
                "weapon" : "剑光",
        ]),
        ([      "action":"$N手中$w轻轻一抖，一式"HIW"「霜印传神梦也空」"NOR"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
                "dodge":-40,
                "parry":-7,
                "damage":47,
                "damage_type":"刺伤",
                "weapon" : "寒光",
        ]),
        ([      "action":"$N手中$w再一抖，只见寒光点点，飘浮不定，罩向$n"+HIW"的$l"NOR,
                "dodge":-20,
                "parry":-17,
                "damage":67,
                "damage_type":"刺伤",
                "weapon" : "寒光",
        ]),
        ([      "action":"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，$w凌空而立，直指$n的后胸"NOR,
                "dodge":-40,
                "parry":-7,
                "damage":57,
                "limb" : "后心",
                "damage_type":"刺伤",
                "weapon" : "飞剑",
        ]),
        ([      "action":"$N一式"HIW"「风波不信菱枝弱」"NOR"，神色娴雅，蓄势待发，一道剑光澄如秋水、寒似玄冰",  
                "dodge":-45,
                "parry":-7,
                "damage":102, 
                "damage_type":"刺伤",
                "weapon" : "剑光",
        ]),
});

mapping *action3 = ({
        ([      "action":"$N使一招"+HIB"「寒芳留照魂应驻」"NOR+"，手中$w化为一道疾光刺向$n的$l",
                "dodge":-20,
                "parry":-15,
                "damage":35,
                "damage_type":"刺伤",
                "weapon" : HIC"疾光"NOR,
        ]),
        ([      "action":"只见$N几个急转，使出"+HIG"「晚凝深翠拂平沙」"NOR+"，一声娇喝中剑光冲天而起，扫向$n的$l",
                "dodge":-50,
                "parry":-10,
                "damage":45,
                "damage_type":"割伤",
                "weapon" : HIC"剑光"NOR,
        ]),
        ([      "action":"$N淡淡一笑，一式"+HIY"「攒花染出几霜痕」"NOR+"舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
                "dodge":-30,
                "parry":-20,
                "damage":40,
                "damage_type":"刺伤",
                "weapon" : HIC"剑影"NOR,
        ]),
        ([      "action":"$N手中$w轻轻一抖，一式"+HIW"「霜印传神梦也空」"NOR+"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
                "dodge":-45,
                "parry":-10,
                "damage":40,
                "damage_type":"刺伤",
                "weapon" : HIC"寒光"NOR,
        ]),
        ([      "action":"$N手中$w再一抖，只见寒光点点，飘浮不定。这一招"+HIR"「篱筛破月锁玲珑」"NOR+"只看得$n眼花缭乱，哪里还能招架",
                "dodge":-35,
                "parry":-25,
                "damage":50,
                "damage_type":"刺伤",
                "weapon" : HIC"寒光"NOR,
        ]),
        ([      "action":"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸，正是一式"+MAG"「暗香浮动月黄昏」"NOR+"",  
                "dodge":-55,
                "parry":-10,
                "damage":45, 
                "damage_type":"刺伤",
                "weapon" : HIC"剑气"NOR,
        ]),
        ([      "action":"$N不闪不避，一式"+HIC"「风波不信菱枝弱」"NOR+"，神色娴雅，蓄势待发，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
                "dodge":-25,
                "parry":-20,
                "damage":55,
                "damage_type":"刺伤",
                "weapon" : HIC"剑光"NOR,
        ]),
        ([      "action":"$N手中$w轻轻一抖，一式"HIW"「霜印传神梦也空」"NOR"幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
                "dodge":-50,
                "parry":-10,
                "damage":50,
                "damage_type":"刺伤",
                "weapon" : HIC"寒光"NOR,
        ]),
        ([      "action":"$N手中$w再一抖，只见寒光点点从天而降，飘浮不定，罩向$n的$l",
                "dodge":-40,
                "parry":-20,
                "damage":70,
                "damage_type":"刺伤",
                "weapon" : HIW"寒光"NOR,
        ]),
        ([      "action":"$n只觉得一缕冷香掠过，$N已悄然间出现在$n身后，$w剑气逼人，直指$n的后胸",
                "dodge":-50,
                "parry":-10,
                "damage":60,
                "limb" : "后心",
                "damage_type":"刺伤",
                "weapon" : HIC"剑气"NOR,
        ]),
        ([      "action":"$N一式"HIW"「风波不信菱枝弱」"NOR"，神色娴雅，蓄势待发，一道剑光澄如秋水、寒似玄冰",  
                "dodge":-55,
                "parry":-10,
                "damage":105, 
                "damage_type":"刺伤",
                "weapon" : HIC"剑光"NOR,
        ]),
});

int valid_learn(object me)
{
        object ob;
	if( (string)me->query("gender") !="女性")
        	return notify_fail("风回雪舞剑只有女子才能学习!!\n");
    	if( (int)me->query_maxforce() < 50 )
		return notify_fail("你的内力不够，没有办法练风回雪舞剑法。\n");
        if( (string)me->query_skill_mapped("force")!= "moonforce")
		return notify_fail("风回雪舞剑法必须配合昆仑山玉女峰的圆月心法才能练。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
	mapping* m_actions;
        i = me->query_temp("WX_perform");
        if( me->query_level()<40 )
        	m_actions = action;
        else if( me->query_level()<80 )
        	m_actions = action2;
        else	m_actions = action3;	
        if( i>0 && i<12 )
        	return m_actions[i-1];
        return m_actions[random(sizeof(m_actions))];
}

varargs int practice_skill(object me,int flag)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的内力或气不够，没有办法练习风回雪舞剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        if ( flag )  write("你按著所学练了一遍风回雪舞剑法。\n");
        return 1;
}

string perform_action_file(string func)
{
	return CLASS_D("moon") + "/snowsword/" + func;
}

varargs mixed hit_ob(object me, object victim, int damage_bonus,int factor)
{
	int dayphase;
	if( !me || !living(me) || !victim || !me->is_fighting(victim)
	 || damage_bonus<2 )
		return 0;
	if( me->query("family/family_name")!="月宫" 
	 && me->query("chushi/chushi_moon")!="yes" )
		return 0;	
	if( !me->is_killing(victim->query("id")) )
		return 0;
					
	dayphase =NATURE_D->query_current_day_phase();
	if( dayphase>=6 )
		return damage_bonus/2;
	return 0;
}