// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// huoyan-dao 火焰刀

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N双掌相对虚搓了几下，突然大喝一声，双掌一式「钻木取火」，激起一片热浪攻向$n$l",
        "紧接着$N使出「祝融怀焰」，双手如抱圆球，内力运处，一股炙热无形刀气斩向$n的$l",
        "$N使一式「风火无边」，左掌立刃大开大阖，右掌飘忽灵动，将$n拢罩在灼炙的刀风之下",
        "$N口念轮回经，长吸了一口气，右掌如刀切斧凿，一式「六道轮回」，携着气浪照$n周身连劈六刀", 
        "只见$N面色凝重，施展「双龙吐焰」，双掌缓缓推出，两股炙灼的内力猛然直袭$n的$l",
        "$N面带笑容使出「刀山火海」，身形微侧，手掌从袖底穿出，挟两股极热的劲力劈向$n",
        "$N左手捧人颅式，身形一展「白佛光度」，右掌一刀劈空向$n的$l砍去",
        "$N跃起一式「火内莲花」，左掌连劈，沸腾的劲力罩住$n的身子，右掌紧扬，一刀斩向$n顶门",
        "$N内息转动，运劲于双臂，全身骨节一阵暴响，起手一式「示诞生」向$n劈出，将$n全身笼罩在赤热的掌风下",
        "$N面带轻笑，一招「始心镜」，火焰刀内劲由内及外慢慢涌出，$P双掌如宝像合十于胸前，向着$n深深一鞠",
        "$N双掌合十而又打开，这招「现宝莲」以火焰刀无上功力聚出一朵红莲，盛开的花瓣飞舞旋转，漫布在$n四周",
        "$N面带金刚相，双掌搓圆，使无数炙热的刀气相聚，这招「破法执」犹如一只巨大的手掌，凌空向$n飞抓而下",
        "$N暴喝一声，竟然使出伏魔无上的「开显圆」，气浪如飓风般围着$P飞旋，炎流将$n一步步向着$P拉扯过来",
        "$N口念伏魔真经，双掌连连劈出，将$n笼罩在炙焰之下，这如刀切斧凿般的「显真常」气浪似乎要将$p从中劈开",
        "$N现宝相，结迦兰，右手「归真法」单掌拍出，半空中刀气凝结不散，但发出炙灼的气浪却排山倒海般地涌向$n",
        "$N虚托右掌，一式「吉祥逝」，内力运转，跟着全身衣物无风自动，$P身体微倾，手掌闪电一刀，斩向$n$l",

});

int valid_enable(string usage) { return usage == "strike" ||  usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功火候太浅。\n");

        if (me->query_skill("strike", 1) < me->query_skill("huoyan-dao", 1))
                return notify_fail("你的基本掌法火候有限，无法领会更高深的火焰刀法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(120), 
                "attack": 70 + random(10), 
                "dodge" : 70 + random(10), 
                "parry" : 70 + random(10), 
                "damage_type" : random(2)?"震伤":"割伤", 
        ]); 
}

void skill_improved(object me)
{
        int skill = me->query_skill("huoyan-dao", 1);
        if (skill == 200 && ! me->query("sl/huoyandao"))
        {
                tell_object(me, HIW"\n忽然，你感道体内内息越转越快，瞬时间功力已经上升到了一个新的境界！\n"
                                "你的内力增加了！\n你的根骨增加了！\n" NOR);
                me->add("max_neili", skill+random(skill));
                me->add("con", 1);
                me->set("sl/huoyandao", 1);
         }
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练火焰刀。\n");
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huoyan-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        string msg;
        
        if (damage_bonus < 100) return 0;

        if (random(damage_bonus / 2) > victim->query_str() 
        &&  (int)me->query("neili") > (int)victim->query("neili") * 2 / 3) 
        {
                result = ([ "damage" : damage_bonus]);
                
                switch(random(3)) 
                {
                case 0: 
                        msg = HIR"$n的经脉被一丝丝狂燥的火劲给侵入，全身痛苦无比！\n"NOR;
                case 1: 
                        msg = HIR"只听见“碰”的一声，$n身上的火劲爆发了！\n"NOR;
                case 2: 
                        msg = HIR"$n只闻到一阵阵烧焦的味道，完全不知道自己已经被烧地体无完肤了！\n"NOR;
                }
                result += ([ "msg" : msg ]);
                return result;
        }
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("huoyan-dao", 1) < 100 ||
            ! living(me) || me->query_temp("weapon"))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("huoyan-dao", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage" : -damage / 2 ]);
                result += ([ "msg" : HIR "$n展开火焰刀法，封住了一些$N的攻击！\n" NOR ]);          
                return result;
       }          
}

