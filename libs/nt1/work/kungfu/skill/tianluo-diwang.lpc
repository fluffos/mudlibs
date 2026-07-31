// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tianluo-diwang.c 天罗地网势

#include <combat.h>
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({ 
        "$n腰肢轻摆，就如一朵菊花在风中微微一颤，斜身移步，早已避开。\n",
        "$n展开轻功提纵术，犹如疾风掠地，忽来忽往，瞬息之间进退数次，於丈许方圆之内腾挪奔跃，令$N无从进招！\n",
        "$n顺著$N攻势避过，身形一幌，竟然在$N身边一掠而过，趋退若神，步子微挫，早已让开。\n",
        "$n脚步轻盈，身手迅捷，轻功施展得圆转如意，身法之快，异乎寻常，矫夭腾挪，轻轻巧巧地避过$N这一招。\n",
        "却见$n潇洒自如，足下微尘不起，轻飘飘的似是缓步而行，不疾不徐地避了开去，的是飘逸无伦，变化万方！\n",
        "$n展开古墓派轻功，奔驰来去，斜窜急转，纵横飘忽，令$N难以确定出手的方位！\n",
        "$n衣襟当风，飘飘然如欲乘风而去，越奔越是轻捷，飞舞来去，脚下全不着力，$N不禁暗感难以捉摸！\n",
        "$n双足一登，身子腾空而起，犹似燕子穿林一般，离地尺许，平平掠过，相形之下，$N的招数似乎倒来迟一步！\n",
        "$n展开古墓派轻功，身随意走，一起脚，急奔如电，$N竟然跟随不上，心下暗暗惊佩！\n",
        "$n身子向前一挺，飞也似的滑了开去，但见$n东滑西闪，左转右折，实无瞬息之间停留，$N的诸般招式一一落空！\n",
});

string *action_msg = ({
        "$N发掌奇快，但一招一式，清清楚楚，自成段落，忽地手腕微翻，举掌往$n$l击落",
        "$N招数手法处处出以阴柔，掌法向$n绵绵无尽展了开来，变幻多端，人所莫测",
        "$N双手挥出，东边一收，西边一拍，将$n的周身去路全数挡住，双掌这边挡，那边拍，\n"
        "$n竟是难以脱出掌影笼罩三尺之外",
        "$N双臂飞舞，两只手掌宛似化成了千手千掌，任$n如何腾挪身形，始终被困在$N掌势\n围成的圈子中",
        "$N双掌一并，凭虚击去，这路「天罗地网势」的掌法使将出来，绵密无比，掌力虽不\n"
        "沉雄，但手法迅疾，东发一招、西劈一掌，飘忽灵动之极",
        "$N出手快捷无比，而手掌之来又是变幻无方，抓打撕劈、擒拿勾击，在小擒拿手中夹\n"
        "以「天罗地网势」的掌法，著著抢攻",
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" || usage=="dodge";}

int valid_combine(string combo) { return combo=="meinv-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练天罗地网势必须空手。\n");
        if ((int)me->query_skill("yunv-xinfa", 1) < 20)
                return notify_fail("你的玉女心经火候不够，无法学天罗地网势。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(60), 
                "attack": 60 + random(10), 
                "dodge" : 60 + random(10), 
                "parry" : 60 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

string query_dodge_msg(string limb) 
{
        return dodge_msg[random(sizeof(dodge_msg))]; 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了，无法练习天罗地网。\n");
        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力太低了。\n");
        me->receive_damage("qi", 60);
        me->add("neili", -60);
       
       return 1;
}

string perform_action_file(string action)
{
       return __DIR__"tianluo-diwang/" + action;
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("tianluo-diwang", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 30;
        if (lvl < 150) return 50;
        if (lvl < 200) return 80;
        if (lvl < 250) return 100;
        if (lvl < 300) return 120;
        if (lvl < 350) return 140;
        return 150;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (me->query_temp("weapon"))
                return 0;

        lvl = me->query_skill("tianluo-diwang", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
