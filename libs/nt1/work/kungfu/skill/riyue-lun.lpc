// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// riyue-lun.c 日月轮法

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N一招「大赞叹光明势」，右手立掌念经，左手单臂抡起$w，夹杂着阵阵风声向$n的$l砸去",
        "$N将手中$w抛上半空，跃起一掌砸在$w上，这式「大皈依光明势」有如流星坠地，直轰$n",
        "凭空闪出一道雪白的光幕，光电闪烁中$w挟「大功德光明势」的无上劲力，从$N手中飞出砍向$n的$l",
        "$N双眼磕闭，全身衣物却在内劲冲击下涨如气球，那$w在这「大福德光明势」的推动下，向$n缓缓压来",
        "$N双手画圈，越转越急，光幕宛如一轮明月，将$P笼罩，这「大吉祥光明势」的劲力带着$w以排山倒海之势飞旋而出",
        "$N口中高唱「降魔咒」，一招「大三昧光明势」挥出，$w幻化的漫天的轮影犹如行云流水般涌向$n",
        "$N一招「大般若光明势」，面带宝光，以无上降魔大法催动手$w，那舞动的光云慢慢移向$n，彷佛要笼罩一切妖魔",
        "$N提一口真气，使出「大智慧光明势」，手中$w上下翻飞，轮番砸向$n，叫$p再也分不清哪个是真，哪个是假",
        "$N面带微笑，眼露慈光，全身所散发出的「大慈悲光明势」气劲宛如惊涛骇浪，$w一层接一层地涌向$n",
        "$N双手高举$w，大喝一声使出「大圆满光明势」自上而下斩向$n，其快绝无比，气势汹涌，已达圆满之境",
});

string *parry_msg = ({
        "$n不躲不避，手中$w摆开，在$P跟前形成了一道光幕，$N此招根本无法再进。\n",
        "却见$n踏前一步，手中$w翻飞，其势甚巨，$N前进不能，只好闪身而退。\n",
        "$n轮法突变，$w带着风声飞舞出去，后发先至，在$N还没攻出时就破了$p的招数。\n",
        "但见$n举$w硬挡，乒的一声架开了来势汹汹的$N。\n",
});

string  *msg = ({
        CYN"空中那五只$w"CYN"对击，声若龙吟，悠悠不绝，就在$n"CYN"一呆之际，$w"CYN"飞砸了出去！"NOR,
        MAG"呜呜声响中，$w"MAG"旋转飞舞着撞向$n"MAG"，在$p"MAG"便要挡隔时，却绕过$n"MAG"飞到了身後"NOR,
        MAG"$w"MAG"连续掷出，连续飞回，绕著$n"MAG"兜个圈子，忽高忽低，或正或斜，所发声音也是有轻有响，旁观众人均给扰得眼花撩乱，心神不定"NOR,
        YEL"一声「小心了！」，蓦然间$w"YEL"五体归一，并排向$n"YEL"撞去，势若五牛冲阵，威不可挡"NOR,
        HIB"只见$w"HIB"绕著$n"HIB"，上下翻飞，$w"HIB"跳跃灵动，呜呜响声不绝，掀的阵阵狂风有如刀割，似要把$n"HIB"从中劈开"NOR,
        HIR"突然，狂风乱起，激荡中那$w"HIR"相碰相撞，五轮归一，合并了向$n砸去"NOR,
        HIG"法轮在$n"HIG"身前环饶，猛地向$p"HIG"迎头击下，接着又飞来一轮，一抄一送，呜呜声响，兜向$n"HIG"$l"NOR,
        HIW"呼呼飞啸声中，那五只$w"HIW"或直飞、或斜飞、或回旋、或下坠、或上升，霎时间$n"HIW"的全部退路已被封死"NOR,
        HIC"猛地里$w"HIC"向$n"HIC"$l飞砸下，在$p"HIC"沉肩卸避之时，$w"HIC"又突然上飞击出，砸向$p"HIC"的$l"NOR,
        HIM"那$w"HIM"飞旋砸到，$n"HIM"却并不回头，听风辨器，一一挡开，但$w"HIM"便如长上了眼睛一般，竟然又旋飞到了$n"HIM"$l"NOR,
        HIG"随着森森慑人的厉吼，$w"HIG"锤蓦而急颤晃动，轮身嗡嗡震响，在不及眨眼的瞬息间，耀目的电光金蛇四射迸闪，飞掠周遭，迅捷无匹的击$n！"NOR,
        MAG"法轮再次合围，紫电精芒围著$n"MAG"的四周旋舞闪射，千百轮影幻映出一幅美丽而眩目的图案，这图案美极了，似是一片多角形的紫色雪晶体"NOR,
});

int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

void skill_improved(object me)
{
        int skill = me->query_skill("riyue-lun", 1);
        if (skill == 200)
        {
                tell_object(me, HIW"\n忽然，你感道体内内息越转越快，瞬时间功力已经上升到了一个新的境界！\n你的精力增加了！\n你的臂力增加了！\n"NOR);
                me->add("max_jingli", skill+random(skill));
                // me->add("str", 1);
         }
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("hammer", 1) < (int)me->query_skill("riyue-lun",1))
                return notify_fail("你的基本锤法水平有限，无法领会更高深的日月轮法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        string str, message;
        level   = (int) me->query_skill("riyue-lun",1);

        if (! userp(me) && weapon)
        {
                if (weapon->query("id") == "jin lun") 
                        str = "金轮";
                else if (weapon->query("id") == "yin lun") 
                        str = "银轮";
                else if (weapon->query("id") == "fa lun") 
                        str = "法轮";
                else str = weapon->name();
                message = msg[random(sizeof(msg))];
                message = replace_string(message, "$w", str);
                switch(str)
                {
                case "金轮" : 
                        message = HIY+message+NOR; break;
                case "银轮" : 
                        message = HIW+message+NOR; break;
                case "法轮" : 
                        message = HIC+message+NOR; break;
                default : break;
                }
                return ([
                        "action" : message,
                        "damage" : 200,
                        "damage_type" : random(2)?"砸伤":"瘀伤",
                        "dodge" : 100,
                        "parry" : 100,
                        "attack": 200,
                ]);
        }
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage": 120 + random(50),
                "attack": 70 + random(10),
                "damage_type" : random(2)?"砸伤":"瘀伤",
        ]);
}

string query_parry_msg(object weapon)
{
        object weapon1;
        
        if (objectp(weapon1 = this_player()->query_temp("weapon")) 
        &&  weapon1->query("skill_type") == "hammer")
                return parry_msg[random(sizeof(parry_msg))];
}

int practice_skill(object me)
{
        object weapon;

       if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的现在的内力不足,无法继续练日月五行轮。\n");
        me->receive_damage("qi", 70);
        me->add("neili", -70); 
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"riyue-lun/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon, weapon1;  object master;   
        weapon = me->query_temp("weapon");
        weapon1= victim->query_temp("weapon");

        if (weapon1 && me->query_skill("riyue-lun", 1) > 150 && me->query("jiali")
        &&  me->query("neili") > 1000 
        &&  random(10) >= 5 && (string)weapon->query("skill_type") == "hammer"
        &&  me->query_skill_mapped("parry") == "riyue-lun")
        {
                message_combatd(HIW"$N手臂暴长，施展「锁」字诀，"+weapon->name()+
                                HIW"探出，嚓的一声锁住了$n"+weapon1->name()+HIW"。\n"NOR, 
                                me, victim);

                if (random(me->query_str()) > victim->query_str())
                {           
                        me->add("neili", -100);
                        message_combatd(HIG+me->query("name")+"运劲回拉，$n臂骨喀的一声，险些就被拉断，剧痛之下手一松，"+
                                        weapon1->name()+HIG"被夺了过去！\n"NOR, me, victim);
                        weapon1->unequip();
                        weapon1->move(me);
                } else 
                if (random(me->query_str()) > victim->query_str() / 2)
                {           
                        me->add("neili", -50);
                        message_combatd(HIG+me->query("name")+"运劲回拉，$N被带得踉跄几步，但觉虎口剧痛，"+
                                        weapon1->name()+HIG"脱手飞出！\n"NOR, victim);
                        weapon1->unequip();
                        weapon1->move(environment(victim));
                } else
                if (victim->query_temp("shield"))
                {           
                        me->add("neili", -50);
                        message_combatd(HIY"$N借势前冲，"+weapon1->name()+HIY"直刺过去，但被"+
                                        victim->query("name")+"护体真气荡得滑了开去。\n"NOR, victim);
                }

                else    message_combatd(HIY"$N借势前冲，"+weapon->name()+HIY"直刺"+victim->query("name")+"，"+
                                        victim->query("name")+"变招奇快，"+weapon->name()+HIY"一抖松脱，纵身退了开去。\n"NOR, 
                                        victim);
        }
}

