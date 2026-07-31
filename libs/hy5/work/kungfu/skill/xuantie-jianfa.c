// 玄铁剑法
#include <ansi.h>;

inherit SKILL;

string  *msg = ({
"$N当胸平平刺出一剑，实在是毫无任何变化，而却有轰轰之声，$n只觉一股大力由$w直逼周身",
"$N凌空跃起，身随剑起，借助下行之势向下猛劈一剑，将$n周身笼于剑气之下",
"$N轻叹一声，随手横劈一剑，缓缓指向$n，看似无丝毫变化，却尽得剑法精髓，当真平淡中
蕴涵所有变化，无招胜有招",
"$N迅疾挑出一剑，但见剑势如虹，快似闪电，无可当锋！此剑之快，匪夷所思，无法分辨剑路去来",
"$N仰首长啸，令风云变幻，狂风遽起，旋及一剑平指，剑气弥漫于$n周身各处，$n只觉身处
惊涛骇浪之中，惊怖中更觉$N剑力有如海潮一般，一波一浪阵阵涌来，绵延不绝，愈发愈强",
"$N祭起$w，左手捏成剑诀置于胸前，咄喝一声，正是剑法至尊的“御剑式”，空中满是剑影，
宛若千道银链，只在$n身边游动",
"$N连出十余剑，一时迅疾如流星划空，一时凝重迟缓，招招无迹可寻，平淡至极又匪思至极，
顺刺，逆击，横削，倒劈，无不是剑法的入门，当真返朴归真，却已不再存任何破绽",
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(2)+2)*220,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge":(random(2)+2)*50,
                "force":(random(2)+2)*220
        ]);
}

int valid_learn(object me)
{
        return notify_fail("你只能通过领悟来提高玄铁剑法。\n");
}
string perform_action_file(string action)
{
        return __DIR__"xuantie-jianfa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("xuantie-jianfa", 1);

        if (damage_bonus < 50
           || lvl < 160
           || random(2)
              || ! objectp(weapon)
           || me->query("neili") < 500
           || me->query_skill_mapped("sword") != "xuantie-jianfa"
      		 || me->query_skill_mapped("force") != "yunv-xinfa")
      		return damage_bonus / 4;

        if (lvl / 2 + random(lvl) > victim->query_skill("parry", 1) || random(10)==0)
        {
                me->add("neili", -100);
                victim->receive_damage("qi", damage_bonus * 4 / 5+10, me);
                victim->receive_wound("qi", damage_bonus * 4 / 5+10, me);
      
                return HIW "$N" HIW "手中" + weapon->name() + HIW "犹如神助，从天而下，威不"
                       "可挡地劈向$n" HIW "，气势恢弘之极。\n" NOR;
         }
}
