// po.c 「总诀式」

#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
        string msg;
        object weapon;
        int skill, jing_cost, exp;
//        mapping my_fam  = me->query("family");

        skill = me->query_skill("lonely-sword",1);
        jing_cost = (int)me->query("int") - 45;

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");

     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("独孤九剑必须配合紫霞神功。\n");
       if (((int)me->query_skill("huashan-sword", 1)+150) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的剑宗华山剑法太低了。\n");
       if (((int)me->query_skill("kuangfeng-jian", 1)+150) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的气宗狂风快剑太低了。\n");
       if (((int)me->query_skill("poyu-quan", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的破玉拳太低了。\n");
       if (((int)me->query_skill("hunyuan-zhang", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的混元掌太低了。\n");
       if (((int)me->query_skill("feiyan-huixiang", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的飞燕回翔太低了。\n");
       if (((int)me->query_skill("huashan-neigong", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的剑宗内功太低了。\n");
       if (((int)me->query_skill("zixia-shengong", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("你的气宗内功太低了。\n");


        if( me->is_fighting() )
           return notify_fail("「总诀式」不能在战斗中演练。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
           return notify_fail("你必须先去找一把剑。\n");

        if (environment(me)->query("sleep_room"))
                return notify_fail("卧室不能练功，会影响别人休息。\n");


       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

        if( !skill || (skill < 20))
           return notify_fail("你的独孤九剑等级不够, 不能演练「总诀式」！\n");

        if( me->query("neili") < 170 )
           return notify_fail("你的内力不够，没有力气演练「总诀式」！\n");
        if( me->query("qi") < 170 )
           return notify_fail("你的体力不够，没有力气演练「总诀式」！\n");
        if( me->query("jing") < 170 )
           return notify_fail("你的精力不够，没有力气演练「总诀式」！\n");

        if( me->query("jing") < -jing_cost )
           return notify_fail("你现在太累了，无法集中精神演练「总诀式」！\n");

if (
	me->query_skill("xuantie-sword",1)
	|| me->query_skill("xuantie-jianfa",1)
	|| me->query_skill("yunv-jian",1)
	|| me->query_skill("quanzhen-jian",1)
	|| me->query_skill("taijia-jian",1)
	|| me->query_skill("jinshe-jian",1)
	|| me->query_skill("liangyi-jian",1)
	|| me->query_skill("huifeng-jian",1)
	|| me->query_skill("yunlong-jian",1)
 	|| me->query_skill("pixie-sword",1)
	|| me->query_skill("pixie-jian",1)
	|| me->query_skill("liancheng-jian",1)
	|| me->query_skill("duanjia-sword",1)
	|| me->query_skill("duanjia-jian",1)
	|| me->query_skill("wuying-jian",1)
	|| me->query_skill("damo-jian",1)   ||
me->query_skill("tianyu-qijian",1)    ||
me->query_skill("murong-jianfa",1)   ||
me->query_skill("yuxiao-jian",1)   
)
       return notify_fail("你不放弃别的剑法怎能领悟独孤九剑无剑胜有剑的绝招？！\n");

        exp= (int)me->query("combat_exp");
        if( skill*skill*skill/10>exp )
           return notify_fail("你的实战经验不够，无法体会「总诀式」！\n");

        msg=HIG"$N使出独孤九剑之「总诀式」，将手中"+weapon->name()+HIG"随意挥舞击刺。\n"NOR;
        message_combatd(msg, me);
if (jing_cost < 40) jing_cost=40;
        me->add("qi", -70);
        me->add("neili", -70);
        me->add("jing", jing_cost);

        if ( skill < 60)
           me->improve_skill("lonely-sword",10);
        else if (skill < 90)
           me->improve_skill("lonely-sword",10+random((int)me->query("int")- 9));
        else if (skill < 140)
           me->improve_skill("lonely-sword",10+random((int)me->query("int")*2-9));
        else if (skill < 200)
           me->improve_skill("lonely-sword",10+random((int)me->query("int")*4-9));
        else
           me->improve_skill("lonely-sword",10+random((int)me->query("int")*8-9));

        msg = MAG"$P的「独孤九剑」进步了！\n"NOR;
        me->start_busy(1);
        message_combatd(msg, me);
        return 1;
}
