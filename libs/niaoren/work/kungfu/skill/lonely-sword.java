//lonely-sword.c 獨孤九劍
// Modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        "卻見$n踏前一步，劍式斜指你的右臂，想要使$P閃身而退。\n",
        "$n以攻為守，以進為退，凝神運氣向$P猛攻快打地揮出方位大異的泰山「快活三」三劍。\n",
        "$n劍法突變，劍勢伸縮不定，奔騰矯夭，逆使嵩山劍法的「天外玉龍」企圖迫使$P變招。\n",
        "$n突然一劍點向$P的$l，雖一劍卻暗藏無數后著，$P手足無措，攻勢不由自主停了下來！\n"
        "$n不閃不避，舉劍閃電般使出「疊翠浮青」反削$P的$l，想擋過你此招。\n",
        "$n突然使出青城派松風劍法的「鴻飛冥冥」，可是方位卻有所偏差，長劍對著$P一絞，企\n圖突破$P的攻勢！\n"
        "$n挺劍一招象是「白云出岫」回刺$P的$l，企圖將$P的攻勢化解。\n",
        "只見$n不退反進，身如飄風，詭異地一式「天柱云氣」，動向無定不可捉摸地擋住了$P的\n進攻。\n",
        "$n不退反進，使出恆山劍招「綿里藏針」，森森劍氣充溢四周！架開了$P的這招\n",
});

mapping *action = ({
        ([      "name":                 "總訣式",
                "action":               "$N使一招「總訣式」，手中$w劍光暴長，向$n的$l刺去",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "破劍式",
                "action":               "$N劍尖一指，一招「破劍式」斜斜刺向$n的$l",
                "dodge":                100,
                "damage":               400,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "破刀式",
                "action":               "$N手中$w一招「破刀式」從意想不道的方位刺向$n的$l",
                "dodge":                40,
                "damage":               350,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "破槍式",
                "action":               "$N身形一晃，手中$w龍吟一聲，使出「破槍式」往$n的$l連遞數劍",
                "dodge":                70,
                "damage":               350,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "破鞭式",
                "action":               "$N手中$w劍光暴長，一招「破鞭式」往$n$l刺去",
                "dodge":                60,
                "damage":               350,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "破索式",
                "action":               "$N手中$w疾往上挑，一招「破索式」直指$n$l",
                "dodge":                50,
                "damage":               350,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "破掌式",
                "action":               "$N突然往下一蹲，手中$w自肋下穿出  一招「破掌式」幻出一道光弧直向$n$l刺去",
                "dodge":                40,
                "damage":               350,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "破箭式",
                "action":               "$N一招「破箭式」手中$w自上而下，歪歪斜邪地刺向$n的$l",
                "dodge":                30,
                "damage":               350,
                "damage_type":  "刺傷"
        ]),
        ([      "name":                 "破氣式",
                "action":               "$N腳踏陰陽步，手中$w中宮直進，一招「破氣式」迅急無比地向$n的$l刺去",
                "dodge":                20,
                "damage":               350,
                "damage_type":  "刺傷"
        ]),
});

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "華山派"|| myfam["master_id"] != "feng qingyang")
                return notify_fail("獨孤九劍只有向風清揚老前輩學習。\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的內力不夠，沒有辦法練獨孤九劍。\n");
        if( (int)me->query_skill("zixia-shengong",1)<100)
                return notify_fail("獨孤九劍必須配合紫霞神功\才能練習。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必須先找一把劍才能練劍法。\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("這套劍法我就教到這兒，以后就要靠你自己練了。\n");

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
        return notify_fail("獨孤九劍只能通過「總訣式」來演練。\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}

