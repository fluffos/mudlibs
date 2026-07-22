// ming.c 「冥思决」
// By Dream 19:32 01-12-19
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
    string msg;
    int skill, jing_cost;
    skill = me->query_skill("jiuzhuan-12tian",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() - 50;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("「冥思决」不能在战斗中演练。\n");
    if( !skill || (skill > 15000))
       return notify_fail("你的阴阳九转十二重天已经练到极限了」！\n");
    if( !skill || (skill < 300))
       return notify_fail("你的阴阳九转十二重天等级不够, 不能演练「冥思决」！\n");
    if( me->query("neili") < 50000 )
        return notify_fail("你的内力不够，没有内力演练「冥思决」！\n");

if (me->query("special_skill/gongfusoul") == 1 )
 {
       if(time()-me->query_temp("gongfu_end")<1) return notify_fail("你刚练过功，会走火入魔的！\n");
        }
        else
       {
      if(time()-me->query_temp("gongfu_end")<2) return notify_fail("你刚练过功，会走火入魔的！\n");
        }  

    
    if (me->query_skill("jiuzhuan-jiuyang",1)<= skill)
        return notify_fail("你的九阳残篇不够，无法通过演练「冥思决」提高阴阳九转十二重天的技巧！\n");
    if (me->query_skill("jiuzhuan-jiuyin",1)<= skill)
        return notify_fail("你的九阴残篇不够，无法通过演练「冥思决」提高阴阳九转十二重天的技巧！\n");
    if (me->query_skill("jiuzhuan-liuyin",1)<= skill)
        return notify_fail("你的六阴残篇不够，无法通过演练「冥思决」提高阴阳九转十二重天的技巧！\n");
  
    
    if( me->query("jing") < -jing_cost )
        return notify_fail("你现在太累了，无法集中精神演练「冥思决」！\n");
    if(!me->query("jiuzhuan-12tian/mingsi"))
    {
    tell_object(me, MAG "你盘腿坐下，将自己所学的「阴阳九转十二重天」冥想了一遍。\n" + NOR);    
    me->add("neili", -5000);
    me->add("jing", jing_cost);
    me->improve_skill("jiuzhuan-12tian",random((int)me->query_int())*4);
me->set_temp("gongfu_end",time());
write(MAG "你的「阴阳九转十二重天」进步了！\n" + NOR);

       
        // me->start_busy(1);   
        return 1;
    }
    else
{
    tell_object(me, MAG "你盘腿坐下，用☆速成大法☆把「阴阳九转十二重天」冥想了一遍。\n" + NOR);   
    me->add("neili", -50);
    me->add("jing", jing_cost);
    me->improve_skill("jiuzhuan-12tian",random((int)me->query_int())*3);
write(MAG "你的「阴阳九转十二重天」进步了！\n" + NOR);
me->set_temp("gongfu_end",time());
      
        me->start_busy(1);   
        return 1;
}
}

