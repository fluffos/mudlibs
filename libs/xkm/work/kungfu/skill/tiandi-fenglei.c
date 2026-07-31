#include <ansi.h>
#include <combat.h>
inherit SKILL;
mapping *action = ({
([      "action" : HIC"$N缩颈藏头，一招「飞天式」，手中$w轻轻颤动，虚虚实实点向$n"NOR,
        "force" : 100,
        "dodge" : 5,
        "damage" : 10,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : HIW"$N不慌不忙将手中的$w挽了一个剑花向$n刺了过去,好一招[遁地式]啊"NOR, 
        "force" : 150,
        "dodge" : 15,
        "damage" : 5,
        "lvl" : 20,
        "damage_type" : "刺伤",
]),
([      "action" : HIB"$N忽然右手做平身势,左手居然紧握$w的柄部直点$n周身大穴,已然将一招[扑风式]巧妙使出"NOR, 
        "force" : 180,
        "dodge" : 5,
        "damage" : 35,
        "lvl" : 20,
        "damage_type" : "瘀伤"
]),
([      "action" : HIM"$N双足点地一跃而起,手中$w在双手间左右把势,正是一招[惊雷式]推向$n"NOR,
        "force" : 200,
        "dodge" : 10,
        "damage" : 40,
        "lvl" : 30,
        "damage_type" : "割伤",
]),
([      "action" : HIY"$N右脚独立，右手$w向后撤，再向前平平托起，一招「惊天式」刺向$n"NOR, 
        "force" : 210,
        "dodge" : 5,
        "damage" : 55,
        "lvl" : 40,
        "damage_type" : "割伤",
]),
([      "action" : MAG"$N右手将$w背于身后,突交左手使出一招[裂地式]攻向$n"NOR, 
        "force" : 220,
        "dodge" : 15,
        "damage" : 65,
        "lvl" : 60,
        "damage_type" : "刺伤",
]),
([      "action" : RED"$N突然身形一转,手中$w在胸前平刺,正是一招[狂风式]推向$n"NOR, 
        "force" : 250,
        "dodge" : 15,
        "damage" : 75,
        "lvl" : 80,
        "damage_type" : "内伤" 
]),
([      "action" : HIG"$N暴喝一声,手中$w变幻了几个姿势,使出一招[迅雷式]推向$n"NOR,
        "force" : 300,
        "dodge" : 15,
        "damage" : 85,
        "lvl" : 100,
        "damage_type" : "内伤" 
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("tiandi-fenglei",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力不够练天地风雷剑。\n");
        me->receive_damage("jingli", 20);
        return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({ HIW"$n使出天地风雷剑的[飞天式]，身法似乎也加快了。\n"NOR, }); 

string *unarmed_parry_msg = ({ HIW"$n使出天地风雷剑中的[飞天式]，身法似乎也加快了。\n"NOR, }); 

string query_parry_msg(object weapon) 
{ 
if( weapon ) return parry_msg[random(sizeof(parry_msg))]; 
else return 
unarmed_parry_msg[random(sizeof(unarmed_parry_msg))]; 
} 
string perform_action_file(string action)
{
        return __DIR__"tiandi-fenglei/" + action;
}
