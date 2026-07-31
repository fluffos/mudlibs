// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit SKILL;

string main_skill() { return "yinyang-shiertian"; }

string *dodge_msg = ({
        "只见$n施展凌波微步，神光离合，乍阴乍阳，动无常则，进止难期。\n",
        "只见$n施展凌波微步，步法轻盈，仿佛轻云之蔽月，不知怎的就到了数丈之外。\n",
        "$n的身影飘飘兮若流风之回雪，施展的正是凌波微步，$N连$n的衣角都沾不到。\n",
        "但见$n施展凌波微步，左一转，右一斜，就已经绕到了$N的身後。\n",
        "可是$n施展凌波微步，只是轻描淡写地向旁踏出一步，就巧妙地避开了$N的攻势。\n",
        "只见$n身影滴溜溜地一转，体迅飞鸟，飘忽若神，施展的正是凌波微步。\n",
        "$N只觉得眼前一花，头脑发昏，只觉得四面都是$n的身影！\n",
        "$n左脚轻轻地踏出一步，施展凌波微步，若往若返，把$N牵得团团乱转。\n",
});

mapping *action = ({ 
([      "action": "只见$n施展凌波微步，神光离合，乍阴乍阳，动无常则，进止难期",
        "force" : 350,
        "attack": 90,
        "dodge" : 90,
        "parry" : 90,
        "damage": 100,
        "damage_type":  "刺伤"
]),
}); 
mapping query_action(object me, object weapon) 
{ 
        return action[random(sizeof(action))]; 
} 

int valid_enable(string usage) 
{ 
        return usage == "dodge";
}

int valid_learn(object me)
{
        int lvl;

        lvl = me->query_skill("lingbo-weibu", 1);
        if (lvl > 300) lvl = 300;

        if (me->query("dex") < 21)
                return notify_fail("你先天身法太差，无法学习凌波微步。\n");

        if ((string)me->query("family/family_name") != "逍遥派")  
                return notify_fail("你想偷学逍遥派绝学？！\n");

        if (me->query("max_neili") < 3000 + lvl * 20)
                return notify_fail("你试着走了两步，顿觉胸"
                                   "口烦恶之极，看来是内力不济。\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("lingbo-weibu", 1) < 100 ||
            ! living(me))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("dodge") + mp;
        dp = me->query_skill("dodge", 1) / 2 +
             me->query_skill("lingbo-weibu", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIW "$n" HIW "身子轻轻晃动，$N" HIW
                                            "眼前顿时出现了无数个$n" HIW "的幻影，令$N"
                                            HIW "完全无法辨出虚实。\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIW "$n" HIW "往旁边歪歪斜斜的迈出一步，却恰"
                                            "好令$N" HIW "的攻击失之毫厘。\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$N" HIW "这一招来的好快，然后$n"
                                            HIW "一闪，似乎不费半点力气，却将$N"
                                            HIW "这一招刚好避开。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIW "$n" HIW "轻轻一跃，已不见了踪影，$N"
                                            HIW "心中大骇，却又见$n" HIW "擦肩奔过，"
                                            "当真令人思索菲仪。\n" NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(4))
                {
                case 0:
                        result = HIY "只见$n" HIY "微微一笑，身子轻轻晃动，"
                                 "顿时出现了无数个$n" HIY "的幻影，可是$N"
                                 HIY "精通易理，将其中虚实辨得清清楚楚。\n" NOR;
                        break;
                case 1:
                        result = HIY "$n" HIY "往旁边歪歪斜斜的迈出一步，然而$N"
                                 HIY "错步跟随，方位毫厘不差。\n" NOR;
                        break;
                case 2:
                        result = HIY "$n" HIY "一闪，似乎不费半点力气，却将$N"
                                 HIY "这一招刚好避开，可是$N"
                                 HIY "招中有招，进攻却是不止。\n" NOR;
                        break;
                default:
                        result = HIY "但见$n" HIY "轻轻一跃，已不见了踪影，$N"
                                 HIY "不假思索，反身出招，更是巧妙无方。\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("lingbo-weibu", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 30;
        if (lvl < 150) return 50;
        if (lvl < 200) return 80;
        if (lvl < 250) return 100;
        if (lvl < 300) return 120;
        if (lvl < 350) return 140;
        return 150;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力太差了，难以练习凌波微步。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够了，无法练习凌波微步。\n");

        me->receive_damage("qi", 90);
        me->add("neili", -90);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lingbo-weibu/" + action;
}

int difficult_level()
{
        return 500;
}

void skill_improved(object me)
{
        if (me->query_skill("lingboweibu",1) == 80 && ! me->query("lbwb") 
        &&  me->query_skill("literate", 1) > 80)
        {
                tell_object(me, HIY "$N一步步走下来，只觉的心情舒畅，不知不觉内力有所积累。\n" NOR);
                me->add("max_neili", random(30)+20);
                me->add("lbwb",1);
        }
        if (me->query_skill("lingboweibu", 1) == 120 && me->query("lbwb") == 1 
        &&  me->query_skill("literate", 1) > 100)
        {
                tell_object(me, HIM "$N六十四卦走完，刚好绕了一个大圈，回到原地，精神大振。\n" NOR);
                me->add("max_neili", random(30)+20);
                me->add("lbwb", 1);
        }
        if (me->query_skill("lingboweibu", 1) == 160 && me->query("lbwb") == 2 
        &&  me->query_skill("literate", 1) > 120)
        {
                tell_object(me, CYN "$N越走越快，内息随着步法不住运转，隐隐然自己的内力已经有了提高！\n" NOR);
                me->add("max_neili", random(30)+20);
                me->add("lbwb", 1);
        }
        if (me->query_skill("lingboweibu", 1) == 200 && me->query("lbwb") == 3 
        &&  me->query_skill("literate", 1) > 140)
        {
                message_vision(RED "$N步法娴熟，随意踏出，脚步成圆，只感神清气爽，全身精力弥漫！\n" NOR, me);
                me->add("max_neili", random(30)+20);
                me->add("lbwb", 1);
        }
}

