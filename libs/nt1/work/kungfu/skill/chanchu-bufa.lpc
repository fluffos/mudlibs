// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chanchu-bufa.c 蟾蜍步法

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "只见$n一招「蟾飞九天」，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
        "但是$n一个使出「蛙鸣震天」，身形飘忽，轻轻一纵，早已避开。\n",
         "$n一招「蛙入稻田」，身行随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
        "可是$n一个「蟾蜍扑虫」，侧身一让，$N这一招扑了个空。\n",
        "却见$n「蟾翻白肚」，足不点地，往旁窜开数尺，躲了开去。\n",
        "$n身形一招「金蟾归月」，身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太差了，不能练蟾蜍步法。\n");
        
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够。\n");
                
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        
        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon) 
{
        mixed result; 
        int ap, dp, mp; 

        if ((int)me->query_skill("chanchu-bufa", 1) < 100 || 
            ! living(me)) 
                return; 

        mp = ob->query_skill("count", 1); 
        ap = ob->query_skill("force") + mp; 
        dp = me->query_skill("dodge", 1) / 2 + 
             me->query_skill("chanchu-bufa", 1) / 2; 

        if (ap / 2 + random(ap) < dp) 
        {
                result = ([ "damage" : -damage ]); 
                switch (random(3)) 
                {
                case 0:
                        result += (["msg" : WHT "$n" WHT "身体向下一伏，手脚飞快地搅动起地上的尘土，匪所思疑地往后一纵，\n" 
                                            "$N只见眼前弥漫着一阵呛人尘烟，视线一片模糊！\n" NOR]); 
                        break; 
                case 1:
                        result += (["msg" : WHT "$n" WHT "身体向后一翻，向后纵出数丈之远，"    
                                            "$N情急之下，额头的汗都出来了！\n" NOR]); ; 
                        
                        break; 
                default: 
                        result += (["msg" : WHT "$n" WHT "一个侧身闪过，" 
                                            "竟然不留一丝痕迹。\n" NOR]); 
                        break; 
                }
                return result; 
        } else 
        if (mp >= 100) 
        {
                switch (random(3)) 
                {
                case 0: 
                        result = WHT "$n" WHT "身体向下一伏，手脚飞快地搅动起地上的尘土，匪所思疑地往后一纵，\n" 
                                 "$N" WHT "猛地向前一冲，早突过尘烟，来到$n的身后。\n" NOR;  
                        break; 
                case 1: 
                        result = WHT "$n" WHT "身体向后一翻，向后纵出数丈之远，\n" 
                                 "$N一个箭步就冲到了$n面前！\n" NOR;  
                        break; 
                default: 
                        result = WHT "$n" WHT "一个侧身闪过，" 
                                 "$N就象影子一样紧紧地咬住！\n" NOR;  
                        break; 
                }
                COMBAT_D->set_bhinfo(result); 
        }
}

int query_effect_dodge(object attacker, object me) 
{
        int lvl;
        lvl = me->query_skill("chanchu-bufa", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 40;
        if (lvl < 280) return 70;
        if (lvl < 350) return 90;
        return 110;
}


