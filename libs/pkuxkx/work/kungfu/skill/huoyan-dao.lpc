// huoyan-dao.c 火焰刀
// by snowman@SJ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N内息转动，运劲于双臂，全身骨节一阵暴响，起手一式「示诞生」向$n劈出，将$n全身笼罩在赤热的掌风下",
        "skill_name" : "示诞生",
        "force" : 250,
        "lvl" : 0,
        "dodge" : 15,
        "parry": 10,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N面带轻笑，一招「始心镜」，火焰刀内劲由内及外慢慢涌出，$P双掌如宝像合十于胸前，向着$n深深一鞠",
        "skill_name" : "始心镜",
        "force" : 280,
        "lvl" : 20,
        "dodge" : 10, 
        "parry": 5,
        "damage_type" : "震伤",
]),
([      "action" : "$N双掌合十而又打开，这招「现宝莲」以火焰刀无上功力聚出一朵红莲，盛开的花瓣飞舞旋转，漫布在$n四周",
        "skill_name" : "现宝莲",
        "force" : 340,
        "lvl" : 50,
        "dodge" : 5,
        "weapon" : "红莲刀气",
        "damage_type" : "割伤",
]),
([      "action" : "$N面带金刚相，双掌搓圆，使无数炙热的刀气相聚，这招「破法执」犹如一只巨大的手掌，凌空向$n飞抓而下",
        "skill_name" : "破法执",
        "force" : 320,
        "lvl" : 70,
        "dodge" : 10,
        "damage_type" : "内伤",
]),
([      "action" : "$N暴喝一声，竟然使出伏魔无上的「开显圆」，气浪如飓风般围着$P飞旋，炎流将$n一步步向着$P拉扯过来",
        "skill_name" : "开显圆",
        "force" : 400,
        "lvl" : 120,
        "dodge" : -10,
        "damage_type" : "震伤",
]),
([      "action" : "$N口念伏魔真经，双掌连连劈出，将$n笼罩在炙焰之下，这如刀切斧凿般的「显真常」气浪似乎要将$p从中劈开",
        "skill_name" : "显真常",
        "force" : 350,
        "lvl" : 140,
        "dodge" : -5, 
        "weapon" : "无形刀气",
        "damage_type" : "割伤",
]),
([      "action" : "$N现宝相，结迦兰，右手「归真法」单掌拍出，半空中刀气凝结不散，但发出炙灼的气浪却排山倒海般地涌向$n",
        "skill_name" : "归真法",
        "force" : 430,
        "lvl" : 160,
        "dodge" : -15, 
        "parry": 5,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N虚托右掌，一式「吉祥逝」，内力运转，跟着全身衣物无风自动，$P身体微倾，手掌闪电一刀，斩向$n$l",
        "skill_name" : "吉祥逝",
        "force" : 500,
        "lvl" : 180,
        "dodge" : 5, 
        "parry": 10,
        "weapon" : "无形气浪",
        "damage_type" : "割伤",
]),
});

 
int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");
        if ((int)me->query("max_neili") < 1500) 
                return notify_fail("以你的内力修为，还不足以练习火焰刀。\n");
        if ((int)me->query_con() < 30) 
                return notify_fail("你的根骨太低，不能驾御火焰刀。\n");
        if ((int)me->query_skill("longxiang-boruo", 1) < 100)
                return notify_fail("火焰刀需要有龙象般若功第一层以上的火候才能学习。\n");
        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的基本内功火候太浅，不能学火焰刀。\n");
                return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("huoyan-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");
        if ((int)me->query("qi") < 50 || (int)me->query("neili") < 20)
                return notify_fail("你的体力不够，练不了火焰刀。\n");
        me->receive_damage("qi", 40);
        me->add("neili",-10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huoyan-dao/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        string msg;
        int j, skill, neili, neili1;

        skill = me->query_skill("huoyan-dao", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

        if( random(skill) > ob->query_skill("parry", 1)/2
        && me->query("combat_exp") > ob->query("combat_exp")/2
        && me->query_skill_mapped("parry") == "huoyan-dao"
        && me->query_skill("longxiang-boruo", 1) > 150
        && neili > 1000 
        && skill > 150 
        && random(neili) > random(neili1)/2
        && living(me)
        && !me->query_temp("weapon")
        && !ob->query_temp("weapon")
        && !ob->is_visible(me)) {       
                if( me->query_temp("dazhuan_npc") ) neili += neili/2;
                    
                msg = HIR"只听得$N身前嗤嗤声响，‘火焰刀’威势大盛，"NOR;            
                if(neili >= neili1+random(neili1)+damage*2){
                        msg += "将$n招式上的内力都逼将回来！\n", 
                        j = -8000;
                }
                else if(neili >= neili1+damage){
                        msg += RED"$P手掌扬处，挡住了一些$n攻来的内力！\n"NOR, 
                        j = -(damage/2+random(damage/2));               
                }
                else{
                        msg += MAG"$P展开火焰刀法，封住了一些$n的攻击！\n"NOR, 
                        j = -damage/3; 
                }        
                if(wizardp(me)) tell_object(me, "Target damage = "+damage+" 。\n");   
                message_vision(msg, me, ob);
                return j;
       }          
}

int help(object me)
{
        write(HIR"\n大轮寺绝技「火焰刀」："NOR"\n");
        write(@HELP
        
        要求：  最大内力 1500 以上；
                后天根骨 30 以上；
                龙象般若功等级 100 以上；
                内功等级 100 以上。     
HELP
        );
        return 1;
}

