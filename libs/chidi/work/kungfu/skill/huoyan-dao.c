// huoyan-dao.c 火焰刀

inherit SKILL;
mapping *action = ({
([      "action" : "$N使出一招「"+RED+"钻木取火"+NOR+"」，飞身急转，双掌向前平平拍向$n",
        "skill_name" : RED "钻木取火" NOR,
        "force" : 100,
        "lvl" : 0,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+RED+"祝融怀焰"+NOR+"」，手掌如刀，斜斜劈向$n的$l",
        "skill_name" : RED "祝融怀焰" NOR,
        "force" : 150,
        "lvl" : 10,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+RED+"风火无边"+NOR+"」，双掌一拍，一道内力自掌中攻向$n的$l",
        "skill_name" : RED "风火无边" NOR,
        "force" : 200,
        "lvl" : 20,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+RED+"六道轮回"+NOR+"」，双手合十，当头劈向$n",
        "skill_name" : RED "六道轮回" NOR,
        "force" : 250,
        "lvl" : 30,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+RED+"双龙吐焰"+NOR+"」，双掌一错，两道内力交叉攻向$n的$l",
        "skill_name" : RED "双龙吐焰" NOR,
        "force" : 300,
        "lvl" : 40,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+RED+"刀山火海"+NOR+"」，双掌向下斜拍，顿时万千道内力从四面八方攻向$n",
        "skill_name" : RED "刀山火海" NOR,
        "force" : 350,
        "lvl" : 60,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+RED+"白佛光度"+NOR+"」，左臂回收，右掌引内力直刺$n的$l",
        "skill_name" : RED "白佛光度" NOR,
        "force" : 400,
        "lvl" : 80,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「"+RED+"火内莲花"+NOR+"」，双掌微并，两臂前伸，一道内劲如排山倒海般攻向$n",
        "skill_name" : RED "火内莲花" NOR,
        "force" : 500,
        "lvl" : 100,
        "damage_type" : "瘀伤",
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }
int practice_level(){   return 100;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练火焰刀必须空手。\n");
    else if ((int)me->query("max_neili") < 1000) //  火焰刀要有很高的内力才能学
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("huoyan-dao", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("longxiang", 1) >= 60 ||
        (int)me->query_skill("xiaowuxiang", 1) >= 60)
        return 1;
    else if ((int)me->query_skill("longxiang", 1) < 60)
        return notify_fail("你的龙象般若功火候太浅。\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 60)
        return notify_fail("你的小无相功火候太浅。\n");
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
    mapping a_action;
    level   = (int) me->query_skill("huoyan-dao",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练火焰刀必须空手。\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("你的体力不够，练不了火焰刀。\n");
    me->receive_damage("qi", 20);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob=victim->query_temp("armor/cloth");
    int skill=me->query_skill("huoyan-dao",1);
    if ( skill< 200 )
        return damage_bonus;
    if (!ob){
            victim->apply_condition("fire_poison",skill/4);
        return damage_bonus;
    }
    if ( ob->query("material")==("cloth") || ob->query("material")==("leather")){
            message_vision( HIR+"$N身穿的"+ob->query("name")+HIR+"突然着火燃烧起来，$N手忙脚乱地把它脱了下来，丢在地上！\n"+NOR, victim);
            ob->unequip();
            ob->move(environment(victim));
            ob->set("long", "这是一件烧得无法再穿的"+ob->query("name")+"。\n");
            ob->set("name","烧破的"+ob->query("name"));
            ob->set("value",0);
            ob->set("armor_prop",0);
        }
    return 0;
}

string perform_action_file(string action)
{
    return __DIR__"huoyan-dao/" + action;
}

