// po.c 「总诀式」
#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
    string msg;
    object weapon;
    int skill, jing_cost;
//    mapping my_fam  = me->query("family");
    skill = me->query_skill("dugu-jiujian",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() - 50;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("「总诀式」不能在战斗中演练。\n");
 
if (me->query("special_skill/gongfusoul") == 1 )
 {
       if(time()-me->query_temp("gongfu_end")<1) return notify_fail("你刚练过功，会走火入魔的！\n");
        }
        else
       {
      if(time()-me->query_temp("gongfu_end")<2) return notify_fail("你刚练过功，会走火入魔的！\n");
        }  

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先去找一把剑。\n");
    if( !skill || (skill < 60))
        return notify_fail("你的独孤九剑等级不够, 不能演练「总诀式」！\n");
    if( me->query("neili") < 50 )
        return notify_fail("你的内力不够，没有力气演练「总诀式」！\n");
    if (me->query_skill("sword",1)<= skill)
        return notify_fail("你的基本剑法不够，无法通过演练「总诀式」提高独孤九剑的技巧！\n");
    if( me->query("jing") < -jing_cost )
        return notify_fail("你现在太累了，无法集中精神演练「总诀式」！\n");
 write(HIC "你使出独孤九剑之「总诀式」，将手中" + weapon->name() + HIC "随意挥舞击刺。\n" + NOR);
    me->add("neili", -50);
    me->add("jing", jing_cost);
  me->improve_skill("dugu-jiujian",random((int)me->query_int())*4);
 me->set_temp("gongfu_end",time());
        if (me->query("special_skill/gongfusoul") == 1 )
 {
       me->start_busy(random(1));
        }
        else
       {
        me->start_busy(random(2));
        }  
    return 1;
}
