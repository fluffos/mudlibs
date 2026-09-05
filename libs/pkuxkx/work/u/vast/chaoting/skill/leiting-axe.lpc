#include <ansi.h>
#include <combat.h>
inherit SKILL;
mapping *action = ({
([      "action":"$N立定当地，时快时缓的将手中的$w在面前移动，突然一招「"+BLU+"樵夫问道"+NOR+"」向$n劈去",
        "force" : 80,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N渊停岳峙般的身形猛的升起五丈，一招「"+RED+"飞虹惊落"+NOR+"」寒光乍现般向$n劈去",
        "force" : 90,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N突然暴喝一声，手里的$w一挫，一招「"+HIW+"风雪故人来"+NOR+"」劈向$n",
        "force" : 80,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N斜移两步，手中$w发出阵阵寒光，一招「"+MAG+"似幻似真"+NOR+"」劈向$n",
        "force" : 80,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N双手一顿，一招「"+YEL+"流星雨"+NOR+"」,手中的$w以极快的速度劈向$n",
        "force" : 90,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N将$w舞得尤如万条金龙，使人不敢靠近，猛的一招「"+RED+"大屠魂"+NOR+"」向$n劈去",
        "force" : 140,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N手中的$w“铛”的一声，斧锋侧翻，光铧骤闪，一招「"+HIW+"绝一闪"+NOR+"」劈向$n",
        "force" : 80,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N斧尖指天，斧锋骤颤，一招「"+RED+"天泣血"+NOR+"」数十道冷光劈向$n",
        "force" : 140,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N突然一招「"+HIC+"刃无还"+NOR+"」,手中的$w像是一道穹苍中的一道闪电，劈向$n",
        "force" : 60,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N一越拔空，长啸仿如龙吟，一招「"+YEL+"天外归星"+NOR+"」$w犹如一个光球，劈向$n",
        "force" : 200,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
([      "action":"$N忽然步法一变，以不可言喻的快速围绕着$n，猛的一招「"+RED+"千魂入窍"+NOR+"」劈向$n",
        "force" : 340,
        "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
        "damage_type":  "劈伤"
]),
});

int valid_enable(string usage)
{
    return (usage == "axe" || usage == "parry");
}
int practice_level(){   return 200;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "axe")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query_skill("bixue-xinfa", 1) < 180)
            return notify_fail("你的「碧血心法」火候不够，无法学习「雷霆斧」。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    mapping ran_action;
    int level = me->query_skill("leiting-axe",1);
    if (level > 100) level = 100;
        if (me->query_temp("sum_power"))
        return ([  "action": "$N将斧缓缓提到胸前，神色沉重地施出「"+RED+"雷霆震天"+NOR+"」劈向$n的$l",
                    "damage": level*6,
                    "attack": level*2,
                    "dodge": 0 - 5 * level,
                    "damage_type": "劈伤",
                ]);
    else{
        ran_action=action[random(sizeof(action))];
        ran_action["dodge"]= 0 - level;
        ran_action["damage"]= level;
        ran_action["attack"]= level/2;
        }
    return ran_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "axe")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练雷霆斧法。\n");
    me->receive_damage("qi", 25);
    return 1;
}
string *parry_msg = ({
        "$n后退一步，一招［荡气回肠］手中的$v猛的砸向$N的$w。\n",
	"$n身形微顿，手中的$v一招［围韩救赵］反捣$N的必救之处。\n",
	"$n手中的$v从下往上急挥，一招［恶鬼还阳］磕开了$N手中的$w\n",
});

string *unarmed_parry_msg = ({
	"$n一招［钟鼓齐鸣］，手中的$v从偏锋击向$N的太阳大穴。\n",
	"$n手中的$v从左划右，一招［横扫千军］封住了$N的攻势。\n",
	"$n凌空三连翻，一招［披沙拣金］手中的$v反击$N的后脑，逼得$N中途撤招。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
    return __DIR__"leiting-axe/" + action;
}
