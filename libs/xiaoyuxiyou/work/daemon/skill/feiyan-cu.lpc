//【「飞燕蹴」】feiyan-cu.c

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N碎步上前",
        "$N翻身上纵，在半空中",
        "$$N身形微颤，踏出千万残影，跟着",
        "$N身形不动，使出一招",
        "$N一个筋斗翻在半空",
        "$N身形一长",
});

string* skill_tail =({
        "，双脚交错，一前一后攻向$n。",
        "，双腿幻出千万舞影，蹴向$n。",
        "，左腿后发先至，攻向$n。",
        "，舞起千层腿影，直逼$n得连连倒退",
        "，舞起千层腿影，直逼的$n节节后退。",
        "，右腿以难以觉察的角度划了个半圈，扫向$n！",
});

mapping *action = ({
        ([      "action":               "$N碎步上前，双脚交错，一前一后戳向$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "force":                70,
                "damage_type":  "刺伤",
                "weapon":               "$N的"+random(2)?"左脚":"右脚",
                "parry_msg":            "$N一个纵劈，用腿格开",
        ]),
        ([      "action":               "$N翻身上纵，在半空中，双腿幻出千万舞影，蹴向$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "force":                80,
                "damage_type":  "砸伤",         
                "weapon":               "$N的"+random(2)?"左腿":"右腿",
                "parry_msg":            "只听见「锵」一声，被$N一脚踢开",
        ]),
        ([      "action":               "只见$N一个左侧身，右腿以难以觉察的角度划了个半圈，扫向$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "force":                60,
                "damage_type":  "筑伤",
                "weapon":               "$N的右腿",
                "parry_msg":            "只见$N一个后翻，双腿顺势格开这一击",
        ]),
        ([      "action":               "$N身形微颤，踏出千万残影，跟着左腿后发先至，攻向$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "force":                120,
                "damage_type":  "刺伤",
                "weapon":               "$N的左腿", 
                "parry_msg":            "只见$N脚步轻盈，身形游走，$n顿时只觉眼前只剩一团燕踪莺影，不知如何攻击",
        ]),
        ([      "action":               "只见$N身形不动，以左脚为轴，右腿带着呼啸的风声扫向$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "force":                60,
                "damage_type":  "撞伤",
                "weapon":               "$N的右脚",
                "parry_msg":            "$N娇叱一声，舞动双腿，幻出千层腿影，$n眼前一花，$N业然已闪至在身旁",
        ]),
        ([      "action":               "忽见$N一纵身欺近$n身旁，双手直拍$n的左右太阳，同时双脚连踢$n的$1",
                "dodge":                -5,
                "parry":                -5,
                "force":                50,
                "damage_type":  "内伤",
                "weapon":               random(2)?"$N的双手":"$N的双脚",
                "parry_msg":            "$N身似飞燕，足尖点地，飘然飞起，轻轻松松的避过了$n这招",

        ]),
});

int valid_learn(object me)
{
return 0;
}

int valid_enable(string usage)
{
return usage=="unarmed" || usage=="parry" ;
}

int practice_skill(object me)
{
return 0;
}

mapping query_action(object me, object weapon)
{
int i;
mapping* m_actions;
m_actions=me->query("skill_feiyan-cu");
if( !me->query_temp("HTH_perform")) 
        {
        if(me->query("skill_feiyan-cu")==0)
        return action[random(6)];
        if(random(2)) return action[random(6)];
        return m_actions[random(sizeof(m_actions))];
        }
else  { 
        return action[6];
        }
return action[random(sizeof(action))];
}


string perform_action_file(string func)
{
return CLASS_D("12gong") + "/feiyan/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
int i,armor,damage,time;

if ( random(3)==1 )  //已经提升且1/3几率
        {
        if ( me->query("ssbx_num")<=1 ) // 元力不足
                {
                me->add("eff_kee",200+random(300));
                if ( me->query("eff_kee")>=me->query("max_kee") )
                        me->set("eff_kee",me->query("max_kee"));
                me->add("kee",200+random(300));
                if ( me->query("kee")>=me->query("eff_kee") )
                        me->set("kee",me->query("eff_kee"));
                }
        else  {
                i = me->query("ssbx_num");
                i/=2;
                me->add("eff_kee",500*i/2);
                if ( me->query("eff_kee")>=me->query("max_kee") )
                        me->set("eff_kee",me->query("max_kee"));
                me->add("kee",500*i);
                if ( me->query("kee")>=me->query("eff_kee") )
                        me->set("kee",me->query("eff_kee"));
                me->add("eff_sen",300*i/2);
                if ( me->query("eff_sen")>=me->query("max_sen") )
                        me->set("eff_sen",me->query("max_sen"));
                me->add("sen",500*i);
                if ( me->query("sen")>=me->query("eff_sen") )
                        me->set("sen",me->query("eff_sen"));
                }
        tell_object(me,WHT"你感觉自己的体力渐渐恢复了。\n"NOR);
        return CYN"$N"CYN"忽然懒懒的打了个呵欠，对着$n"CYN"嘻嘻直笑\n"NOR;
        }
}


