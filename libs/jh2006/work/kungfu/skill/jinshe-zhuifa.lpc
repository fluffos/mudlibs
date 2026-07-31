#include <ansi.h>
inherit SKILL;
string  *msg = ({
"突然$N一声暴喝，寒芒闪动，$w流星般飞出，带着刺耳呼啸之声，直打$n的$l",
"$N双手连挥，$N眼中但见寒光流动，耳畔风声呼呼，数枚$w绵绵而至，如疾风，如骤雨，摄人心魄",
"$N手中$w突然化做数道寒光急飞而出，$n只觉眼前一花，数枚$w却无声无息从后袭来",
"$N弹出数枚$w，竟作弧形飞来，凌空互击，四散而出，令$n无从躲避",
"蓦地里$N双臂一振，一蓬光雨带着尖锐风声激射而出，有如雷霆电闪般向$n飞来",
});

int valid_enable(string usage)
{
        return usage == "throwing";
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(3)+1)*60,
                "damage_type":random(2)?"刺伤":"割伤",
                "dodge":random(10)+10,
                "force":random(200)+100,
                "post_action":
                  (: call_other, WEAPON_D, "throw_weapon" :)
                ]);
}
int practice_skill(object me)
{
       object weapon;
       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("id") != "jinshe zhui")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query_skill("jinshe-zhuifa", 1) < 100)
           return notify_fail("你现在只能通过研习《金蛇秘籍》来提高。\n");
       
       
       if ((int)me->query("jingli") < 50)
               return notify_fail("你的体力不够练金蛇锥法。\n");
       me->receive_damage("jingli", 30);
       return 1;
}

int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够。\n");
       if ((int)me->query_skill("throwing", 1) < 100)
                return notify_fail("你的基本功太浅。\n");
       return 1;

}
string perform_action_file(string action)
{
       return __DIR__"jinshe-zhuifa/" + action;
}

