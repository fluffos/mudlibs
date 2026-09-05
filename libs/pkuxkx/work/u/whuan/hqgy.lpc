//侠客拳脚之豪气干云
//by guilin/male
#include <ansi.h>

inherit F_SSERVER;
int perform(object me,object target)
{

  string msg;
 int busytime;
int targetshen;
int damage;
int coefficient;
 if( !target ) target = offensive_target(me);
if(me->query("shen")<0)
     return notify_fail("豪气干云只有正人君子方能使用!");
if(me->query("shen")<50000)
 return notify_fail("你豪气不够!");
if(me->query("age")<31)
 return notify_fail("你江湖阅历太浅,哪来的豪情?");
if( target == me ) return notify_fail("你一身豪气,不禁吟起李白的侠客行来......\n");
        if( !target || !target->is_character() ) return notify_fail("你心潮一涌,不禁吟起李白的侠客行来......\n");
      if( target->is_busy() ) return notify_fail(target->name() + "目前正自顾不暇，你豪气预备做给谁看?呵呵.\n");
if((int)me->query_skill("xiake-quanjiao",1)<100)
     return notify_fail("你侠客拳脚等级不够,无法让自己豪气逼人!");
if((int)me->query("neili")<500)
   return notify_fail("你内力不够，无法使用‘豪气干云’！");
targetshen=target->query("shen");
if(targetshen<0) targetshen=0-targetshen;
 msg=HIW"$N已闯荡江湖多年,往事种种突然浮现于胸,$N顿觉胸中豪情万丈,不由得开怀大笑起来\n";
if(( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
  &&(random(me->query("shen"))>targetshen/10))
 {
  if((int)target->query("shen")<0)
    {
      busytime=(me->query("shen")-targetshen/20)/500000;
   }
 else
{
   busytime=(me->query("shen")-target->query("shen")/4)/500000;
   }
if(busytime>40) busytime=40;
if(busytime<4) busytime=4;
if(me->query("gender")=="男性") 
{coefficient=1;}
else if (me->query("gender")=="女性") 
  {
coefficient=2;
}
else
{
coefficient=4;
}
  target->start_busy(busytime/coefficient);
if(target->query("shen")>-10000000)
target->add("shen",-1000);
if(target->query("shen")>0)
{
msg+=HIY"结果$p被$P的万丈豪气震住,一时间不知所措!\n"NOR;
}
else
{
 msg+=HIR"面对$P的万丈豪气,$p心中不平,邪念顿生。但却一时也为你正气所牵制\n" NOR;
target->kill_ob(me);
}
if((int)me->query("shen")<10000000) me->add("shen",100);
if(random(6)>4)
  
{
  damage=me->query("age")/30;
if(damage>4) damage=4;
if(damage<1) damage=1;
damage=damage*(int)me->query_skill("xiake-quanjiao",1);
damage=damage/coefficient;
if(damage>target->query("qi")*9/10)
{
 msg+=HIW"$p突然间觉得无地自容,心血一涌,竟然晕了过去!"NOR;
target->set("qi",1);
target->unconcious();
}
else
{
 msg+=HIW"$p觉得与$P比较起来自惭形秽,一副垂头丧气的样子.\n"NOR;
    target->receive_damage("qi",damage);
}
}
}
else
{
 me->start_busy(random(5));
if(target->query("shen")>0)
{
 msg+=HIR"面对$P的万丈豪气,$p淡淡一笑轻轻的摇了摇头。\n" NOR;
}
else
{
msg+=HIR"面对$P的万丈豪气,$p看到后很是不爽,不退反进,邪恶之气更甚,反以邪气逼人!\n"+HIB"$P反受其害!\n" NOR;
me->add("shen",-1000);
me->add("eff_jing",-20);
me->add("eff_qi",-20);
me->add("qi",-20);
me->add("jing",-20);
target->add("shen",-1000);
  target->kill_ob(me);
}
}
  message_vision(msg, me, target);
me->add("neili",-100);

 return 1;
}

