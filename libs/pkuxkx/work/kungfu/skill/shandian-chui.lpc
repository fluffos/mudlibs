// shandian-chui
// 2006-9-17

inherit SKILL;
#include <ansi.h>
string *parry_msg = ({
HIC"$n不闪不避，举起手中兵器"+HIC"，架向$N的$w"NOR,
HIC"却见$n踏前一步，抡起兵器"+HIC"，砸向$N的$w"NOR,
HIC"$n舞起兵器"+HIC"，如山锤影把身体护得风雨不透"NOR,
});

string  *msg = ({
HIG"$N一式"+HIR"「五丁开山」"+HIG"，抡起$w"+HIG"向$n砸下，当真是势劲力疾，挟风带啸，非同凡响"NOR,
HIM"$N腕力猛吐，一招未收，一招又发，"+HIG"「鹰击长空」"+HIM"，$w"+HIM"呼的一声向$n的$l打去",
HIG"但见$N一个转身，手中$w"+HIG"由下而上一荡，$n只听一阵风声擦耳而过！\n"+HIY"$n正在暗叫侥幸之时，$N的$w"+HIY"就势一转，又砸了回来，好一招"+HIR"「浪子回头」"NOR,
HIW"$N大喝一声，一招"+HIY"「五雷轰顶」"+HIW"，$w"+HIW"向$l当头砸下"NOR,
CYN"$N手中$w"+CYN"一转，使出"+HIR"「如雷贯耳」"+NOR+CYN"击向$n耳门"NOR,
HIG"$N二指拈住锤柄，偌大一颗$w"+HIG"轻飘飘直似无物，在$n眼前划出数道白光，一式"+HIR"「头碎如星雨」"+HIG"，\n$w"+HIG"向$n颅顶直砸，端的是迅捷无伦。"NOR,
HIM"$N背负大锤，锤未到人先至，$n正喜对方破绽大露，却见$N一个猛虎翻身,\n$w"+HIM"从腋下倏然而出迎面撞来,耀眼红光森森摧到,正是一招"+HIR"「血洒似流苏」"+HIM"，大有电劈昆仑之意"NOR,
HIG"突然天地间一个炸雷,$N手中$w"+HIG"仰天高举厉声大喝，电光石火中$N腾空直上人锤合一,\n一式"+HIW"「泰山从中裂」"+HIG"由闪电中锵然劈落,仿佛古之恶来复生"NOR,
HIY"$N突地将大锤掷起,双手摩擦噼啪作响,待锤落到面门双手拍击其上,只听滋卡之声不绝于耳,\n$w"+HIY"竟然变成一个巨大"+HIB"蓝色耀眼光球"+HIY"向$n扑来,竟然是“电字诀”中最凌厉的一招"+HIW"「人鬼两殊途」!"NOR,
});

int valid_enable(string usage)
{
        return usage == "hammer" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                  "damage":random(5)*40+150,
                "damage_type":"砸伤",
                "dodge":20+random(50),
                "force":200,
        ]);
}

string query_parry_msg(object weapon)
{
        if (!weapon) return "但是被$n格开了。\n";
        if (weapon->query("skill_type") == "hammer")

                return parry_msg[random(sizeof(parry_msg))] + "。\n";
        if (weapon->query("skill_type") != "hammer")
               return "但是被$n格开了。\n";
}


string perform_action_file(string action)
{
        return __DIR__"shandian-chui/" + action;
}



int practice_skill(object me)
{
        object weapon;
        if ((string)me->query("family/family_name") != "日月神教")
                return notify_fail("你不是日月神教弟子，不能练日月闪电锤。\n");


        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                 return notify_fail("你的体力不够练日月闪电锤。\n");
        if ((int)me->query("neili") < 30)
                 return notify_fail("你的内力不够练日月闪电锤。\n");
        me->receive_damage("qi", 30);
        me->add("neili",-5);
        if ((int)me->query_skill("shandian-chui",1)>1000&&me->query("riyuepfm/chui"))
        {
            me->add("neili",-40);
        }
        return 1;
}

