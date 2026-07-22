//
// riyue-lun.c 日月轮法
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N使一招「"+GRN+"破竹势"+NOR+"」，抡起手中的$w向$n的$l砸去  ",
        "skill_name" : GRN "破竹势" NOR,
        "force" : 120,
        "lvl" : 0,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「"+YEL+"隐山谷势"+NOR+"」，双肩一沉，舞动手中$w向$n的$l横扫  ",
        "skill_name" : YEL "隐山谷势" NOR,
        "force" : 160,
        "lvl" : 22,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「"+MAG+"隐微势"+NOR+"」，就地一滚，手中$w自下而上撩向$n的$l  ",
        "skill_name" : MAG "隐微势" NOR,
        "force" : 200,
        "lvl" : 45,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「"+BLK+"擒纵势"+NOR+"」，身形起伏之际$w扫向$n的$l  ",
        "skill_name" : BLK "擒纵势" NOR,
        "force" : 240,
        "lvl" : 68,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「"+HIM+"圆满势"+NOR+"」，$w如离弦之箭般直捣$n的$l  ",
        "skill_name" : HIM "圆满势" NOR,
        "force" : 290,
        "lvl" : 92,
        "damage_type" : "挫伤",
]),
([      "action" : "$N跃入半空，使一招「"+HIC+"月重辉势"+NOR+"」，高举$w敲向$n的$l  ",
        "skill_name" : "月重辉势",
        "force" : 320,
        "lvl" : 114,
        "damage_type" : "挫伤",
]),
([      "action" : "$N使一招「"+HIW+"捉月势"+NOR+"」，斜举手中$w击向$n的$l  ",
        "skill_name" : HIW "捉月势" NOR,
        "force" : 360,
        "lvl" : 136,
        "damage_type" : "挫伤",
]),
([      "action" : "$N提一口真气，使出「"+RED+"显吉祥"+NOR+"」，$w扫向$n的头部  ",
        "skill_name" : RED "显吉祥" NOR,
        "force" : 400,
        "lvl" : 160,
        "damage_type" : "挫伤",
]),
});

int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }
int practice_level(){   return 160;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("longxiang", 1) < 100)
        return notify_fail("你的龙象般若功火候太浅。\n");
    if (me->query_skill("hammer", 1) <=me->query_skill("riyue-lun", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("riyue-lun",1);
    if (level>100 && me->query("neili")>50){
       me->add_temp("riyue_no", 1);
       if (me->query_temp("riyue_no")>20){
            me->set_temp("riyue_no", 0);
            message_vision( BOLD"\n$N深深地吸了口气，显然是有点累了！\n"NOR, me);
            me->set_temp("str",0);
       }else if( (int)me->query_temp("riyue_no") % 2 ){
            message_vision( HIY"\n$N深吸了一口气，挥舞"+me->query_temp("weapon")->name()+HIY+"，呼呼有声！\n"NOR, me);
            me->add_temp("str",level/10);
            me->add("neili",-50);
       }
    }
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level*2;
    a_action["damage"] = level*2;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "hammer")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "hammer")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够,练不了日月轮法。\n");
    me->receive_damage("qi", 40);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"riyue-lun/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object victim_w;
	victim_w = victim->query_temp("weapon");

	if (victim->query_temp("weapon") ||
	    victim->query_temp("secondary_weapon"))
	{
                if( (int)me->query_skill("riyue-lun", 1) < 150 )
		return HIW "一阵兵刃相撞的声音过后，对方兵器居然完好无损。\n" NOR;
		if( random(victim->query_temp("apply/damage")) < 
			random(me->query_skill("riyue-lun", 1)/3 ) )
		{
			victim_w->unequip();
			victim_w->reset_action();
			victim_w->move(environment(victim));
			victim_w->set("name", victim_w->query("name") + "的碎片");
			victim_w->set("value", 0);
			victim_w->set("weapon_prop", 0);
			victim_w->set("long", "一堆破碎物事，好象是兵器碎片。\n");
			return HIB "你听到「叮当」一声兵刃破碎的声音，兵器碎片溅了一地！\n" NOR;
		}
	}
}
