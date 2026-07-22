#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
int  me_dodge,ob_dodge;
int dx;
        string msg;
        string xuewei,dodskill ;
        string* name = ({"「天突穴」","「廉泉穴」","「承浆穴」","「鱼府穴」","「孔最穴」","「天府穴」","「侠白穴」","「中府穴」","「经渠穴」","「尺泽穴」","「大渊穴」","「云门穴」","「环跳穴」", "「肩井穴」","「百汇穴」","「列缺穴」","「玉枕穴」","「偏历穴","「神门穴」","「灵道穴」","「少海穴」","「少府穴」","「通理穴」"});
        xuewei = name[random(sizeof(name))];
 

    if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
         return notify_fail("你想对谁施展？？\n");

        me_dodge = me->query_skill("dodge",1);
        ob_dodge = target->query_skill("dodge",1);
        dx= me->query_skill("fy_finger",1);

        if( (int)me->query("force") < 500 )
 
                return notify_fail("你的内力不够，没有办法「滴雨穿石」。\n");

        if((int) me->query_skill("tiangang-zhi",1) <= 150)
        return notify_fail("你的「天罡指指」还不够精纯，不能「滴雨穿石」。\n");
        if((int)me->query_skill("yuxuan-guizhen") < 100 )
                return notify_fail("你的「玉玄归真」火候不够！\n");
        if((int)me->query("force") < (int)target->query("force")/3 ) 
        return notify_fail("左手中指轻弹，一股凄厉的内劲破指而出点向对方的"+xuewei+"却如泥牛入海没有任何反应。\n");
        if(random(dx+me_dodge)<ob_dodge) {
             message_vision(
                BLU "左手食指微屈，一股凄厉的内劲破指而出,结果被$n闪开了。\n" NOR, me,target);
                target->kill_ob(me);
             return 1;
        }
        if(target->is_busy())
                return notify_fail(target->name()+"已经中了呀!一会在用吧\n");

        message_vision( GRN "$N对着$n遥遥点出一指,内劲破空而出,正是「滴雨穿石」\n"NOR,me,target);
        msg = GRN "$N中指微屈轻弹一股浑厚阴柔的内劲疾刺$n的"+xuewei ;
        msg +=  "\n$n登时只觉得头脑眩晕，全身麻木再也行动不得.\n" NOR;
        message_vision(msg, me, target);
        target->start_busy((int)me->query("force")/500);
        me->add("force",-300);
        return 1;
}

