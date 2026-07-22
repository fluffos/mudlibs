//绕指柔情剑
//小龙女特殊攻击技能
//by great
//

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$N一招"+HIW"「泪如雨下」"NOR"回手一剑划破天际，长剑幻化成点点泪光如雨如露般洒下",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "划伤"
        ]),
        ([      "action":
"$N一招"+HIC"「心如刀割」"NOR"左手抚胸，右手长剑剑芒急吐，直奔$n檀中大穴而去",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N一招"+HIG"「无尽缠绵」"NOR"手中长剑寒光一闪，无尽剑气似流水般缠缠绵绵刺向$n",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一招"+HIM"「饶指柔情」"NOR"手中的长剑被内力所逼，如长蛇般吞吐不定，破空之声大作",
                "damage":               20,
                "dodge":                -10,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一招"HIR"「悲痛莫名」"NOR"面露悲痛之色，手中长剑剑尖直指自己，一个翻身划向$n",
                "damage":               20,
                "dodge":                -10,
                "parry":                10,
                "damage_type":  "划伤"
        ]),
        ([      "action":
"$N一招"HIM"「依依不舍」"NOR"身形稍退，随即急扑上来，手中长剑闪电般刺向$n的$l",
                "damage":               20,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 4000 )
                return
notify_fail("你的内力不够，没有办法学饶指柔情剑。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return
notify_fail("你必须先找一把剑才能学绕指柔情剑。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑，才能练剑法。\n");

        if( (int)me->query("kee") < 40 )
                return
notify_fail("你的体力不够练这门剑法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("pfm") + "/rouqingjian/" + func;
}

