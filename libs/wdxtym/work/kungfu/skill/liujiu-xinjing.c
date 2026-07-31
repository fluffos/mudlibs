#include <ansi.h>
inherit FORCE;

string *dodge_msg = ({
        HIW "$n" HIW "身前一道剑光闪过，竟与剑光合为一体，$N" HIW "目瞪口呆，一时难以找出其间破绽。\n" NOR,
        HIW "只见$n" HIW "以气御剑，剑中生剑，顿时，无数剑影令$N" HIW "眼花缭乱，无从攻击。\n" NOR,
        HIW "$n" HIW "运气内功，呵气成剑，以神御剑，剑花乍现将将$N" HIW "团团围住，哪里还有机会攻击。\n" NOR,
});

string *parry_msg = ({
        HIG "$N" HIG "一招攻出，$n" HIG "不退不避，无数剑芒飞射而出，将此招竟数化解与无形。\n" NOR,
        HIG "$n" HIG "面露微笑，身体猛然间幻化为一把气剑，任$N" HIG "怎样攻击都无法伤之毫厘。\n" NOR,
        HIG "$n" HIG "不慌不忙，手中剑光在面前画出一道优美的弧线，竟将$N" HIG "攻势全部化解。\n" NOR,
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("liujiu-xinjing", 1);
        return lvl * lvl / 100 * 15 * 38  / 200;
}

int query_jingli_improve(object me)
{
        int lvl;
        
        lvl = (int)me->query_skill("liujiu-xinjing", 1);
        
        if (me->query_skill_mapped("force") == "liujiu-xinjing")
                return lvl * 14 / 10;

        return 0;
}

mapping *action = ({
([      "action": HIW "$N" HIW "使出「六字诀」，此剑世间少有，描绘无限星河，仿若不经意间，刺向$n" NOR,
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 550,
        "skill_name" : "六字诀",
        "damage_type": "刺伤"
]),
([      "action": HIM "$N手中$w" HIM "犹如天上星河，发出一声微鸣，一式「六心绝」使出，顿时将$n" HIM "重创" NOR,
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 550,        
        "skill_name" : "六心绝",
        "damage_type": "割伤"
]),
([      "action": HIG "$N" HIG"一剑自上而下，「九字诀」使出，剑气无处不在，飞向$n" HIG "，令人无法招架。" NOR,
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 450,    
        "skill_name" : "九字诀",
        "damage_type": "割伤"
]),
([      "action": HIR "$N" HIR "剑法清辉，一式「九心绝」，一股剑气自$w" HIR "内心而出，不可力敌，无法匹敌，无边剑气攻向$n" NOR,
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 550,
        "lvl"   : 300,        
        "skill_name" : "九心绝",
        "damage_type": "割伤"
]),

});

int valid_force(string force)
{
        return 1;
}

int double_attack()
{
        return 1;
}

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry" || usage == "dodge" || usage == "unarmed" || usage == "force";
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}



int get_ready(object me)
{
        return 1;
}



int valid_learn(object me)
{
        int level;
        level = me->query_skill("liujiu-xinjing", 1);
		
		if( me->query("zhuanshi")<5 && me->query("chongxiu")<1 )
                return notify_fail("你先天臂力不足。\n");

        if( me->query("str")<150 )
                return notify_fail("你先天臂力不足。\n");

        if( me->query("int")<150 )
                return notify_fail("你先天悟性不足。\n");

        if( me->query("dex")<150 )
                return notify_fail("你先天身法不足。\n");
                
        if( me->query("con")<150 )
                return notify_fail("你先天根骨不足。\n");                        
                
        if( me->query("max_neili")<100000 )
                return notify_fail("你的内力修为不够，难以修炼六十九心经。\n");
                                            
        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的六十九心经。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的六十九心经。\n");
                
if (me->query_skill("martial-cognize", 1) < level &&
            me->query_skill("martial-cognize", 1) < 600)
                                return notify_fail("你武学修养不够，无法继续修炼。\n");              

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("你的基本轻功水平有限，无法领会更高深的六十九心经。\n"); 

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("你的基本内功水平有限，无法领会更高深的六十九心经。\n"); 
                                                
        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("你的基本招架水平有限，无法领会更高深的六十九心经。\n"); 
                                                                
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return notify_fail("六十九心经博大精深，无法简单的通过练习进步。\n");
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("liujiu-xinjing", 1);
        if (lvl < 200) return 70;
        if (lvl < 250) return 80;
        if (lvl < 350) return 120;
        return 150;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("liujiu-xinjing", 1);
        if (lvl < 200) return 200;
        if (lvl < 250) return 300;
        if (lvl < 350) return 400;
        return 500;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{

        string *desc;
        object weapon;
        
        weapon=me->query_temp("weapon");
        
        if (! objectp(weapon))return damage_bonus;
        
        desc = ({
                HIY "$N" HIY "微微举起手中" + weapon->name() + HIY "只是刹那剑刺向$n" HIY "。\n" NOR,
                HIG "$N" HIG "运起六九真气，气纳都天，化作六十九道剑气将$n" HIG "笼罩。\n" NOR,
                HIR "$N" HIR "祭起手中" + weapon->name() + HIR "，瞬间天地异象，风云变幻，$n" HIR "没有丝毫反抗之力。\n" NOR,
        });
        
        if (me->is_busy() 
           || ! living(victim) 
           || damage_bonus < 120 
           || me->query("neili")<500
           || me->query_skill("liujiu-xinjing", 1) < 300) 
                return 0; 

        // 追加特效
        victim->receive_wound("qi", damage_bonus , me);
        // 500级后再追加50%伤害
        if (me->query_skill("liujiu-xinjing", 1) >= 500)
                victim->receive_wound("qi", damage_bonus / 2, me);
        
        if (random(3) == 1)victim->start_busy(3 + random(3));
        
        if( random(10) == 1)victim->add("neili", -1*me->query_skill("liujiu-xinjing",1)*2);
        
        return desc[random(sizeof(desc))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp, cost;

        if ((int)me->query_skill("liujiu-xinjing", 1) < 350
           || me->query_skill_mapped("parry") != "liujiu-xinjing"
           || me->query("neili")<200
           || ! living(me))
                return;

        
        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force", 1) * 4 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("liujiu-xinjing", 1) * 6 + me->query_skill("martial-cognize", 1);

        if( ob->query("reborn/times") < 4 )dp+=1000;
        
        if (dp + random(dp / 2) >= ap)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIG "$n" HIW "身形一顿，竟化做剑光，转瞬即逝。\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIM "$n" HIW "逆着剑光，不退反进，竟将$N" HIW "攻击尽数接下。\n" NOR]);
                        break;
                default:
                        result += (["msg" : MAG "$n" HIW "轻舞数剑，周身遍布剑气，没有一招可以突破其防御。\n" NOR]);
                        break;
                }
                return result;
        }
}
string perform_action_file(string action)
{
        return __DIR__"liujiu-xinjing/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"liujiu-xinjing/exert/" + action;
}

int difficult_level()
{
        return 25000;
}