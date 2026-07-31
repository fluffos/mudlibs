// xuedao-daofa.c 血刀
// updated by lwx 

inherit SKILL;
#include <ansi.h> 

string *action_msg = ({
        "$N双脚一顿，笔直跃起，手中$w不停地颤抖着，\n"
"笼罩住$n全身。这势"HIC"「御剑生风」"NOR"果然是无孔不入",
"$n稍退半步,手中的$W快速挥动,挡开了$N的攻势。\n",


        "$N手中$w带起点点寒光，指向$n前胸穴道。$n正专心致志地对付着剑招，\n"
"不料$N左手运力拍向$n的$l。这势"HIR"「御剑如虹」"NOR"亦真亦幻，实是难防",
"$n招法突变,手中的$W直刺$N,逼的$N只好收回招式。\n",


"$N在$n四周游走，一招"HIY"[御剑成龙]"NOR",手中$w去势飘忽不定，只看得$n眼花缭乱。\n"
"趁此良机，$N于朦朦胧胧中一抖$w，向$n的$l疾挑",
"$n不紧不慢,手中$W身前空处连刺数剑。挡开了$N的攻势。\n",

"$N仗起手中$w，带出点点寒光，罩住$n的胸腹，只等$n的破绽。\n"
"这招"HIM"「御剑行空」"NOR"直如细雨般紧密，$n实在不知$w将要指向自己身上何处",

"$N手中$w中宫直进，疾速刺向$n的前心。\n"
"这招"HIG"「御剑无影」"NOR"令人耳目一新。$n只觉浑身一紧，$w已刺到了$l",

"$N手中$w向$n的右手疾刺，但正当$n要招架时，\n"
"$w却突然转向了$n的左足！这招"HIB"「御剑飞腾」"NOR"确实神鬼莫测",
"$n不顾自身，将手中的$W连连刺向$N。这背水一战之计果然奏效，将$N逼了回去。\。\n",

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{ int level;
        if( me->query("int")<35 )
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        if( me->query("dex")<35 )
                return notify_fail("你研究了半天，只觉招式始终无法随意施展。\n");

        if( me->query("con")<35 )
                return notify_fail("你研究了半天，只觉得根骨有些差，招式始终无法随意施展。\n");

        if( me->query("str")<35 )
                return notify_fail("你研究了半天，感觉膂力有些低，始终无法随意施展。\n");

level = me->query_skill("yujianshu", 1);

   if ((int)me->query_skill("sword", 1) < 180)
               return notify_fail("你的基本剑法火候不够，无法学习御剑术。\n");

   if ((int)me->query_skill("sword", 1) < level)
               return notify_fail("你的基本剑法水平有限，无法领会更高深的御剑术。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
	
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 600 + random(100), 
                "attack": 100 + random(100),
                "dodge" : 100 + random(100),
                "parry" : 100 + random(100),
                 "damage_type" : random(2) ? "刺伤" : "震伤",
        ]);
}

int practice_skill(object me)
{
         
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("yujianshu");
            if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
       if ((int)me->query("qi") < 3000)
		return notify_fail("你体质欠佳，强练御剑术有害无益。\n");
	if ((int)me->query("neili") < 500)
		return notify_fail("你内力不足，强练御剑术有走火入魔的危险。\n");
	me->receive_damage("qi", 3000);
	me->add("neili", -500);
	message_vision("$N默默回忆了一会儿，然后练了一遍御剑术。\n", me);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yujianshu/" + action;
}

