// yunv-sword.c 玉女剑法(华山)
// by Lonely

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N使一招" HIM "「穿针引线」" NOR "，脚踏中宫，手中$w直指$n$l",
        "$N剑随身转，一招" HIR "「天衣无缝」" NOR "，撒出一片剑影，罩向$n的$l",
        "$N舞动$w，使出一招" HIB "「夜绣鸳鸯」" NOR "剑光忽左忽右，闪烁不定，直刺$n的$l",
        "$N忽然蹂身直上，一招" MAG "「小鸟依人」" NOR "，手中$w自下往上刺向$n的$l",
});

int valid_learn(object me)
{
        object ob;
        
        if ((string)me->query("gender") != "女性" )
                return notify_fail("玉女剑法是只有女子才能练的武功。\n");
                
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够，没有办法练玉女剑法。\n") ;
                
        if ((string)me->query_skill_mapped("force") != "zixia-shengong")
                return notify_fail("玉女剑法必须配合紫霞神功才能练。\n");
                
        if (! objectp(ob = me->query_temp("weapon"))
        ||  (string)ob->query("skill_type") != "sword")
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(40),
                "attack": 60 + random(10),
                "dodge" : 60 + random(10),
                "parry" : 60 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70
        ||  (int)me->query("neili") < 70)
                return notify_fail("你的内力或气不够，没有办法练习玉女剑法。\n");
                
        me->receive_damage("qi", 60);
        me->add("neili", -60);
        
        return 1;
}

int query_effect_parry(object attacker, object me) 
{
        int lvl;
        if (! objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("yunv-sword", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}


string perform_action_file(string action)
{
        return __DIR__"yunv-sword/" + action;
}

