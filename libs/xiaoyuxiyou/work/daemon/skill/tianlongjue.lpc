#include <ansi.h>

inherit SKILL;

string  *msg = ({
"$N身子左侧，一式"BLINK+HIC"「月下踏径」"NOR"，右手$w从身体下方突然甩出，直射向$n的$l",
"$w破空飞出，一式"BLINK+HIW"「长虹经天」"NOR"，缓缓一个弧线，由左自右，绕向$n的$l，",
"$N双手连扬，一式"BLINK+HIY"「破云见日」"NOR"，两把$w向$n撒出，笼罩$n的全身上下",
"$N向空中一撒，却是$n一招"BLINK+YEL"「秋日落叶」"NOR"，十多枚$w由空中缓缓落下",
"$N身形急速向前滑动，一式"BLINK+HIW"「雪地追踪」"NOR"，三枚$w向$n的胁下射去",
"$N一式"BLINK+HIB"「回首沧桑」"NOR"，身体一转，反手掷出数枚$w，飞向$n的背部",
"$N凌空一纵，一招"BLINK+HIM"「雨打浮萍」"NOR"，居高临下，手中$w疾射，直向$n的$l",
"$N一招"BLINK+HIW"「流星电闪」"NOR"，手指弹出五枚$w，一点黑光射向$n的头部",
});

int valid_enable(string usage)
{
        return usage == "throwing";
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":45+(me->query_skill("tianlongjue",1))/50,
                "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
                "damage_type":"刺伤",
                "dodge": -20-random(20),
        ]);
}
int practice_skill(object me)
{
       if ((int)me->query("kee") < 50)
               return notify_fail("你的体力不够练天龙诀。\n");
       me->receive_damage("kee", 30);
       return 1;
}

int valid_learn(object me)
{
       object weapon;
       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "throwing")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query("max_force") < 100)
               return notify_fail("你的内力不够。\n");
       return 1;
}
      string perform_action_file( string action)
      {
           return CLASS_D("emei") + "/tianlongjue/" + action;
      }

