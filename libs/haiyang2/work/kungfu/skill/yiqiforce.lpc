#include <ansi.h>
inherit FORCE;
mapping *action = ({
        ([      "action":
"$N使出一招「三重天地混元」，左手聚出一团混元一气击向$n的$l",
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「五重天地混元」，右手聚出一团混元一气击向$n的$l",
                "force":                250,
                "damage_type":  "瘀伤"
        ]),
	([ 	"action":
"$N使出一招「七重天地混元」，双手聚出一团混元一气击向$n的$l",
                "force":                300,
                "damage_type":  "瘀伤"
        ]),
	([	"action":
"$N使出一招「九重天地混元」，全身腾空而起，全身化作一团混元一气击向$n的$l",
                "force":                500,
                "damage_type":  "瘀伤"
        ]),
});
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
	int force,dmg;
        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
dmg=random(damage_bonus+intp(foo));
                if( random(me->query("combat_exp")) > victim->query("combat_exp")/2)
 {
if (dmg>victim->query("qi")/5) dmg=victim->query("qi")/5;
                        victim->receive_wound("qi",dmg);
                        victim->receive_wound("neili",dmg);
                        return
HIR"$N的混元一气功摧毁了$n的真元！！！！\n"NOR;
                }
        }
        return foo;
}

int valid_enable(string usage) 
{ 
return 	usage=="iron-cloth" ||
	usage=="unarmed" ||
	usage=="force";
}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("混元一气功只能用学的。\n");
}

 
int effective_level() { return 50;}

string *absorb_msg = ({
        "$n身体虚转，双手微划，无坚不摧的混元一气功澎湃而出。\n",
        "$n施展出混元一气功，浑身肌肤坚如寒铁。\n",
        "$n身型微展，混元一气充斥了丈许空间。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「混元无我」，轻描淡写的化解了$N的攻势。\n",
});
string *parry_msg = ({
        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「混元无我」，轻描淡写的化解了$N的攻势。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
