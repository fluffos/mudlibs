// 天下第一.c 太始帝经
// 三十岁之前通晓九阳神功、九阴神功、北冥神功、凌波微步、乾
// 坤大挪移、降龙十八掌和六脉神剑，合其为一创出，S+++级武学。
// 太始帝经可以激发为天下所有的武功。

#include <ansi.h>

inherit FORCE;

string *xue_name = ({
"大周天经脉", "小周天经脉", });

string *attack_name = ({"天罡地煞玄元劲" });

string *dodge_msg = ({
        HIW "$n" HIW "手足忽的一晃，$N" HIW "竟然无法进击，只能自保。\n" NOR,
        HIW "只见$n" HIW "身子轻轻晃动，$N" HIW "眼前顿时出现了无数个$n" HIW
        "的幻影，令$N" HIW "完全无法辨出虚实。\n" NOR,
        HIW "$n" HIW "往旁边歪歪斜斜的迈出一步，却恰好令$N" HIW "的攻击失之"
        "毫厘。\n" NOR,
        HIW "$N" HIW "这一招来的好快，然后$n" HIW "一闪，似乎不费半点力气，"
        "却将$N" HIW "这一招刚好避开。\n" NOR,
        HIW "但见$n" HIW "轻轻一跃，已不见了踪影，$N" HIW "心中大骇，却又见"
        "$n" HIW "擦肩奔过，步法之奇巧，当真令人思索菲仪。\n" NOR,
});

string *parry_msg = ({
        HIW "$n轻轻一带，$N" HIW "发现自己招数回击过来，吓得往后倒退几步。\n" NOR,
        HIW "$n手臂回转，在$N" HIW "手肘下轻轻一推，$N" HIW "招数落空。\n" NOR,
        HIW "$n右手伸出，在$N" HIW "手腕上轻轻一拉，$N" HIW "收势不住，直往前扑去。\n" NOR,
        HIW "$n身形不动，$N" HIW "一招击下，有如石沉大海，不觉呆住了。\n" NOR,
        HIW "$n左牵右引，$N" HIW "如身处漩流，连续转了好几个圈。\n" NOR,
        HIW "$n双手回圈，$N" HIW "只觉得前面好象有一堵墙，再也攻不进去。\n" NOR,
        HIW "$n轻轻一转，$N" HIW "一招击在地上，只打得尘土飞扬。\n" NOR,
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("wudi", 1);
        return lvl /10 * lvl /10 * 15 * 80 / 10 / 20;
}

int query_jingli_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("wudi", 1);

        if (me->query_skill_mapped("force") == "wudi")
                return lvl * 14 / 3;

        return 0;
}

mapping *actionf = ({
([      "action": HIW "$N" HIW "右手中指一竖，「天罡地煞玄元劲」向前刺出。真气鼓荡，嗤"
                  "然声响，无形气劲直指$n" HIW,
        "force" : 999999999,
        "attack": 999999999,
        "dodge" : 999999999,
        "parry" : 999999999,
        "damage": 999999999,
        "lvl": 999999999,
        "weapon": HIW "天罡地煞玄元劲" NOR,
        "damage_type":  "内伤"
]),
});

mapping *actionw = ({
([      "action": HIY "$N" HIY "攻势忽缓而不疏，$w" HIY "变化无常，捉摸不定向$n"
                  HIY "慢慢卷去",
        "force" : 999999999,
        "attack": 999999999,
        "dodge" : 999999999,
        "parry" : 999999999,
        "damage": 999999999,
        "lvl": 999999999,
        "damage_type": "内伤"
]),
});

string main_skill()
{
        return "wudi";
}

mapping sub_skills = ([
        ]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        if( me->query("int")<150 )
        {
                tell_object(me, "你演练完毕，只感思绪紊乱，看来依你的悟性，无"
                                "法将其合一。\n");
                return 0;
        }
        if( me->query("con")<150 )
        {
                tell_object(me, "你演练完毕，只觉全身真气乱窜，眼冒金星，两耳轰鸣，好"
                                "不容易才控制下来。\n");
                return 0;
        }
        if( me->query("str")<150 )
        {
                tell_object(me, "你演练完毕，只觉双臂酸疼，全身发软。\n");
                return 0;
        }
        if( me->query("dex")<150 )
        {
                tell_object(me, "你演练完毕，发现依你的身法暂时还无法将其融会贯通。\n");
                return 0;
        }

        if( me->query("age") >= 18 )
        {
                                tell_object(me, "你已错过演练的最佳时刻，今生将于此高深武学无缘。\n");
                return 0;
        }

        if (random(300) != 1 && ! wizardp(me))
        {
                tell_object(me, "你觉得有所感悟，或许再演练一次就能融会贯通，练成武道三千。\n");
                return 0;
        }

        tell_object(me, HIW "一阵凡尘往事涌上心头，你几欲放声长叹。霎那间，你放眼回首，竟有一股莫名\n"
                        "的悲哀。宗师泰斗那种高出不胜寒、登泰山而小天下之感犹然而生，你只觉得以\n往的"
                        "武学现在看来是多么的渺小可笑。\n" NOR);

        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + me->name() + "演练出"HIY"武道三千"HIM"。\n");
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}
string *usage_skills = ({ "unarmed", "strike", "claw", "hand", "cuff", "finger", "sword", "blade", "hammer", "club", "whip","staff", "dodge", "dagger", "parry", "force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_force(string force)
{
        return 1;
}

int double_attack()
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int level;
        int i;
       
        if( me->query("str")<150 )
                return notify_fail("你先天臂力不足。\n");

        if( me->query("int")<150 )
                return notify_fail("你先天悟性不足。\n");

        if( me->query("dex")<150 )
                return notify_fail("你先天身法不足。\n");
                
        if( me->query("con")<150 )
                return notify_fail("你先天根骨不足。\n");    

       if( me->query("gender") == "无性" &&
            (int)me->query_skill("wudi", 1) > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的天下第一。\n");
                
        if( me->query("max_neili")<5000 )
                return notify_fail("你的内力修为不够，难以修炼天下第一。\n");

        if ((int)me->query_skill("force", 1) < 500)
                return notify_fail("你的内功火候太浅，难以修炼天下第一。\n");

        if ((int)me->query_skill("dodge", 1) < 500)
                return notify_fail("你的轻功根基不足，难以修炼天下第一。\n");

        if ((int)me->query_skill("unarmed", 1) < 500)
                return notify_fail("你的拳脚根基不足，难以修炼天下第一。\n");

        if ((int)me->query_skill("parry", 1) < 500)
                return notify_fail("你的招架根基不足，难以修炼天下第一。\n");
    
        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("你的武学修养不足，难以修炼天下第一。\n");
                    
        if ((int)me->query_skill("buddhism", 1) < 800)
                return notify_fail("你的禅宗心法修为不足，难以修炼天下第一。\n");

        if ((int)me->query_skill("lamaism", 1) < 800)
                return notify_fail("你的密宗心法修为不足，难以修炼天下第一。\n");

        if ((int)me->query_skill("taoism", 1) < 800)
                return notify_fail("你的道学心法修为不足，难以修炼天下第一。\n");

         level = me->query_skill("wudi", 1);

        if (me->query_skill("dodge", 1) < level)
                return notify_fail("你的基本轻功水平有限，无法领会更高深的天下第一。\n"); 

        if (me->query_skill("force", 1) < level)
                return notify_fail("你的基本内功水平有限，无法领会更高深的天下第一。\n"); 
                   
        if (me->query_skill("parry", 1) < level)
                return notify_fail("你的基本招架水平有限，无法领会更高深的天下第一。\n"); 

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("你的基本拳脚水平有限，无法领会更高深的天下第一。\n"); 

        if (me->query_skill("blade", 1) < level)
                return notify_fail("你的基本刀法水平有限，无法领会更高深的天下第一。\n");

        if (me->query_skill("sword", 1) < level)
                return notify_fail("你的基本剑法水平有限，无法领会更高深的天下第一。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("天下第一博大精深，无法简单的通过练习进步。\n");
}

int difficult_level()
{
        return 30000;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name1, name2, weapon;
        name1 = xue_name[random(sizeof(xue_name))];
        name2 = attack_name[random(sizeof(attack_name))];

        victim->receive_wound("qi", damage_bonus * 40000, me);
        me->add("neili", me->query("jiali") * 30000);

        if (victim->query("neili") < 500)
                victim->set("neili", 0);
        else
                victim->add("neili", -300);

        return NOR + HIR "$n" HIR "接下$N" HIR "一招，" + name2 + "顿时由" + name1 + "狂涌而入。\n" NOR;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp, cost;

        if ((int)me->query_skill("wudi", 1) < 350
           || me->query_skill_mapped("parry") != "wudi"
           || me->query("neili")<200
           || ! living(me))
                return;

        
        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force", 1) * 4 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("wudi", 1) * 60 + me->query_skill("martial-cognize", 1);

        if( ob->query("reborn/times") < 4 )dp+=1000;
        
        if (dp + random(dp / 2) >= ap)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);


                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIW "$n" HIW "面含微笑，轻轻一格，已将天"
                                            "下所有进攻招数全部封死。\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIW "$n" HIW "眉头微微一皱，动也不动，将"
                                            "$N" HIW "震到一边。\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$n" HIW "身形微微一抖，已将$N" HIW
                                            "迫退至丈许开外。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIW "$n" HIW "一声轻哼，身形微微一动，已"
                                            "飘然远去，使$N" HIW "的进攻全无用处。\n" NOR]);
                        break;
                }
                return result;
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("wudi", 1);
        if (lvl < 200) return 200;
        if (lvl < 250) return 300;
        if (lvl < 350) return 400;
        return 200;
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("wudi", 1);
        if (lvl < 200) return 100;
        if (lvl < 250) return 150;
        if (lvl < 350) return 180;
        return 200;
}

string perform_action_file(string action)
{
        return __DIR__"wudi/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"wudi/exert/" + action;
}

void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);
        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames);
}