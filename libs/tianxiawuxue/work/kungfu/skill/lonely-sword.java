//lonely-sword.c 独孤九剑
// Modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        "却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。\n",
        "$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「快活三」三剑。\n",
        "$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」企图迫使$P变招。\n",
        "$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！\n"
        "$n不闪不避，举剑闪电般使出「叠翠浮青」反削$P的$l，想挡过你此招。\n",
        "$n突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，长剑对着$P一绞，企\n图突破$P的攻势！\n"
        "$n挺剑一招象是「白云出岫」回刺$P的$l，企图将$P的攻势化解。\n",
        "只见$n不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地挡住了$P的\n进攻。\n",
        "$n不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周！架开了$P的这招\n",
});

mapping *action = ({
        ([      "name":                 "总诀式",
                "action":               "$N使一招「总诀式」，手中$w剑光暴长，向$n的$l刺去",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "破剑式",
                "action":               "$N剑尖一指，一招「破剑式」斜斜刺向$n的$l",
                "dodge":                100,
                "damage":               400,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "破刀式",
                "action":               "$N手中$w一招「破刀式」从意想不道的方位刺向$n的$l",
                "dodge":                40,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "破枪式",
                "action":               "$N身形一晃，手中$w龙吟一声，使出「破枪式」往$n的$l连递数剑",
                "dodge":                70,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "破鞭式",
                "action":               "$N手中$w剑光暴长，一招「破鞭式」往$n$l刺去",
                "dodge":                60,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "破索式",
                "action":               "$N手中$w疾往上挑，一招「破索式」直指$n$l",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "破掌式",
                "action":               "$N突然往下一蹲，手中$w自肋下穿出一招「破掌式」幻出一道光弧直向$n$l刺去",
                "dodge":                40,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "破箭式",
                "action":               "$N一招「破箭式」手中$w自上而下，歪歪斜邪地刺向$n的$l",
                "dodge":                30,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "破气式",
                "action":               "$N脚踏阴阳步，手中$w中宫直进，一招「破气式」迅急无比地向$n的$l刺去",
                "dodge":                20,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "华山派"|| myfam["master_id"] != "feng qingyang")
                return notify_fail("独孤九剑只有向风清扬老前辈学习。\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力不够，没有办法练独孤九剑。\n");
        if( (int)me->query_skill("zixia-shengong",1)<100)
                return notify_fail("独孤九剑必须配合紫霞神功才能练习。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int practice_skill(object me)
{
        return notify_fail("独孤九剑只能通过「总诀式」来演练。\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}

