/* 
   jingang-zhang.c 大金刚神掌
   和寂灭爪(jimie-zhua)互备
   取自《天龙八部》等。
   2/3/98 by snowman
*/
#include <ansi.h>
inherit SKILL;
 
mapping *action = ({
([      "action" :"$N蔼然微笑，一式「礼敬如来」，双手合十向前微微一拜，一股暗劲蓄势而发，击向$n的$l",
         "force" : 200,
         "dodge" : 35,
         "damage": 260,
         "lvl" : 0,
         "skill_name" : "礼敬如来",
         "damage_type" : "瘀伤"
]),
([      "action" :"$N面色恭敬，一式「遇佛传法」，闪到$n的身后，左手单拳在胸前一立，右手成掌直击$n的后脑",
         "force" : 140,
         "dodge" : 25,
         "damage": 260,
         "lvl" : 10,
         "skill_name" : "遇佛传法",
         "damage_type" : "瘀伤"
]),
([      "action" :"$N一声冷笑，一式「幽冥搜魂」双拳快速交替击出十数掌，掌带风声呼呼作响，令$n不住倒退，疲于招架",
         "force" : 200,
         "dodge" : 20,
         "damage": 260,
         "lvl" : 20,
         "skill_name" : "幽冥搜魂",
         "damage_type" : "瘀伤"
]),
([      "action" :"$N暴雷般大喝声中，一式「引火炼妖」，双掌相搓，一前一后，挟着一股热浪推向$n",
         "force" : 240,
         "dodge" : 20,
         "damage": 360,
         "lvl" : 30,
         "skill_name" : "引火炼妖",
         "damage_type" : "瘀伤"
]),
([      "action" :"$N一式「魂散心魔」，低眉垂目之间，突然双掌直上直下，不成章法，犹如疯魔一般攻向$n的身前身后",
         "force" : 260,
         "dodge" : 15,
         "damage": 360,
         "lvl" : 40,
         "skill_name" : "魂散心魔",
         "damage_type" : "瘀伤"
]),
([      "action" :"$N一式「无相法相」，右掌虚晃，身形一变，已化出数十个幻影，齐齐印向$n的全身各处要穴",
         "force" : 280,
         "dodge" : 10,
         "damage": 360,
         "lvl" : 60,
         "skill_name" : "无相法相",
         "damage_type" : "瘀伤"
]),
([      "action" :"$N腾身跃起，半空中出现巨大身影，突然一式「攀天祥云」，头下脚上，旋转着俯冲下来，双掌兜住$n",
         "force" : 300,
         "dodge" : 5,
         "damage": 360,
         "lvl" : 80,
         "skill_name" : "攀天祥云",
         "damage_type" : "瘀伤"
]),
([      "action" :"$N庄严伫立，深深吸了一口气，全身衣服微微涨起，低喝一声，一式「超度极乐」，内力澎湃而出，击向$n的前胸",
         "force" : 350,
         "dodge" : 0,
         "lvl" : 100,
         "damage": 360,
         "skill_name" : "超度极乐",
         "damage_type" : "瘀伤"
])
});
 
int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }
 
int valid_combine(string combo){
        if(this_player()->query_skill("jingang-zhang", 1) > 100
	   && this_player()->query_int() > 20)
   	         return combo=="jimie-zhua";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练大金刚拳必须空手。\n");
        if ((int)me->query_skill("yijinjing", 1) < 140)
                return notify_fail("你的易筋经内功火候不够，无法学大金刚拳。\n");
        if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太弱，无法练大金刚掌。\n");
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
         level   = (int) me->query_skill("jingang-zhang",1);
         for(i = sizeof(action); i > 0; i--)
                 if(level > action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}
 
int practice_skill(object me)
{
         if ((int)me->query("jing") < 50)
                 return notify_fail("你的体力太低了。\n");
         if ((int)me->query("neili") < 20)
                 return notify_fail("你的内力不够练大金刚拳。\n");
         me->receive_damage("jing", 45);
         me->add("neili", -15);
         return 1;
}
 
string perform_action_file(string action)
{
         return __DIR__"jingang-zhang/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
	victim->receive_wound("qi", damage);
}
	return HIR"只见$n$l闷哼一声，吐出一口鲜血，已被易筋经的护体真气给击伤!\n"NOR;
}
}