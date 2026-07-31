// xuedao-daofa.c 血刀
// updated by lwx 

inherit SKILL;
#include <ansi.h> 

string *action_msg = ({
        "$N跳到空中,手中$w紧握，向$n劈去，都有似开山大刀一般，好一力道雄厚的"HIC"「苍松迎客」"NOR"",

"只见$N左手辅剑，向空中舞剑，手中$w向$n的全身砍去\n"
"正是一招"HIR"「云谷鹤峰」"NOR"！",

"$N飞身上前，手中$w疾舞，一招"HIM"「青山隐隐」"NOR"幻出团团剑芒，将$n紧紧裹在其中",

"$N打到兴发，蓦地里一声清啸，手中$w急速向$n的$l刺去！这招山崩海啸般的"HIG"「白鹤振羽」"NOR"完全将$n惊呆了",

"只见$N单足离地，使出一招"HIW"「携手入云」"NOR"，手中$w急速飞进，劈出层层剑气，直向$n的$l劈去",

"$N快速前进，一式"HIB"「退隐仙乡」"NOR"，身随剑起，向$n全身环出多初剑芒，招招势若飞龙卷身，$n哪里闪避得过",

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{ int level;
        if( me->query("int")<30 )
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        if( me->query("dex")<30 )
                return notify_fail("你研究了半天，只觉招式始终无法随意施展。\n");

        if( me->query("con")<30 )
                return notify_fail("你研究了半天，只觉得根骨有些差，招式始终无法随意施展。\n");

        if( me->query("str")<30 )
                return notify_fail("你研究了半天，感觉膂力有些低，始终无法随意施展。\n");

level = me->query_skill("songhe-sword", 1);

   if ((int)me->query_skill("sword", 1) < 180)
               return notify_fail("你的基本剑法火候不够，无法学习松鹤剑法。\n");

       if ((int)me->query_skill("sword", 1) < level)
               return notify_fail("你的基本剑法水平有限，无法领会更高深的松鹤剑法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query("xiangsi");
	if( !me->query("xiangsi") ) 
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 400 + random(400), 
                "attack": 200 + random(100),
                "dodge" : 200 + random(100),
                "parry" : 200 + random(100),
                "damage_type": "刺伤", 
        ]);
}
int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("songhe-sword");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你体质欠佳，强练松鹤剑法有害无益。\n");
	if ((int)me->query("neili") < 5.)
		return notify_fail("你内力不足，强练松鹤剑法有走火入魔的危险。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5.);
	message_vision("$N默默回忆了一会儿，然后练了一遍松鹤剑法。\n", me);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"songhe-sword/" + action;
}

