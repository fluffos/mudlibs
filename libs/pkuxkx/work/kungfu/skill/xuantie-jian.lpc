// 玄铁剑法
#include <ansi.h>;
#define Menpai "古墓派"
inherit SKILL;

string  *msg = ({
"$N当胸平平刺出一剑，实在是毫无任何变化，而却有轰轰之声，$n只觉一股大力由$w直逼周身",
"$N凌空跃起，身随剑起，借助下行之势向下猛劈一剑，将$n周身笼于剑气之下",
"$N轻叹一声，运用手中的$w随手横劈一剑，缓缓指向$n，看似无丝毫变化，当真平淡中蕴涵所有变化，无招胜有招",
"$N将手中的$w迅疾挑出一剑，但见剑势如虹，快似闪电，无可当锋！此剑之快，匪夷所思，无法分辨剑路去来",
"$N仰首长啸，令风云变幻，狂风遽起，旋及一剑平指，剑气弥漫于$n周身各处，$n只觉身处
惊涛骇浪之中，惊怖中更觉$N剑力有如海潮一般，一波一浪阵阵涌来，绵延不绝，愈发愈强",
"$N祭起$w，左手捏成剑诀置于胸前，咄喝一声，正是剑法至尊的“御剑式”，空中满是剑影，宛若千道银链，只在$n身边游动",
"$N连出十余剑，一时迅疾如流星划空，一时凝重迟缓，招招无迹可寻，平淡至极又匪思至极，
顺刺，逆击，横削，倒劈，无不是剑法的入门，当真返朴归真，却已不再存任何破绽",
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}
mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(4)+3)*50,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge":5+random(10),
                "force":200+random(200),
        ]);
}

int valid_learn(object me)
{
        int skill_lvl = (int)me->query_skill("xuantie-jian",1);
        if ((string)me->query("family/master_id") != "yang guo" && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1))
                return notify_fail("玄铁剑法只能是由杨过进行点拨或亲自到大海中才能锻炼提高！\n");
        if ((int)me->query_skill("sword", 1) < 150)
                return notify_fail("你的基本剑法火候太浅。\n");
        if ((int)me->query("max_neili") < 800)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("taiji-jian", 1) > 0 || (int)me->query_skill("damo-jian", 1) > 0
        || (int)me->query_skill("fumo-jian", 1) > 0 || (int)me->query_skill("huashan-jianfa", 1) > 0
        || (int)me->query_skill("wuying-jian", 1) > 0|| (int)me->query_skill("fuliu-jianfa", 1) > 0 
        || (int)me->query_skill("mingtian-jiushi", 1) > 0
        || (int)me->query_skill("hero-sword", 1) > 0 ||(int)me->query_skill("tianyu-qijian", 1) > 0
        )
        return notify_fail("你身具其他剑法，受其拘束，无法领会玄铁剑法「无招」的妙旨。\n");
        if (skill_lvl > 1 && skill_lvl < 200)
        return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。\n");
        return 1;
}
int practice_skill(object me)
{
        object weapon;

if (!objectp(weapon = me->query_temp("weapon"))|| (string)weapon->query("skill_type") != "sword")
return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 100)
return notify_fail("你的体力不够练「玄铁剑法」。\n");

        if ((int)me->query("jing") < 100)
return notify_fail("你的体力不够练「玄铁剑法」。\n");

        if ((int)me->query("neili") < 200)
return notify_fail("你的内力不够练「玄铁剑法」。\n");

//        if (me->query("family/family_name") != "古墓派") //限制在void_learn里已经有了，by all
// return notify_fail("非古墓派弟子不能练玄铁剑法！\n");

        if ((int)me->query_skill("xuantie-jian", 1) < 300)
        return notify_fail("玄铁剑法要亲自到大海中才能锻炼提高。\n");
        me->receive_damage("qi", 40);
        me->add("neili",-20);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xuantie-jian/" + action;
}
