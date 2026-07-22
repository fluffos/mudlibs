#include <ansi.h>

inherit F_SSERVER;
int qigong(object me, object target)
{ 
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);


    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「"+HIB"道尽魔生"NOR+"」只能对战斗中的对手使用。\n");


    if( (int)me->query_skill("daoxin-zhongmo", 1) < 1001 )
  return notify_fail("你的道心种魔大法不够熟练，不会使用「"+HIB"道尽魔生"NOR+"」。\n");

    if ( me->query("jh_dj/dj") <10)
 return notify_fail("你的等级不够，无法使用「"+HIB"道尽魔生"NOR+"」。\n");
 
    if( (int)me->query("max_neili") < 12000 )
           return notify_fail("你的内力修为还不够高。\n");

    if( (int)me->query("neili") < me->query("max_neili")/3 )
           return notify_fail("你的内力不够了。\n");    
 
    if(  me->query("shen") < 10000000)
           return notify_fail("使用道尽魔生必须要先入道,再入魔\n");
message_vision(HIC"$N突然脸色大变，手中捏一字决,使出的正是道心种魔大法之"HIB"『道尽魔生』\n", me, target);   

if(random(me->query("jh_dj/dj")) > target->query("jh_dj/dj")/2) { 
       me->start_busy(8);
   target->start_busy(random(3)); 
damage = me->query("jh_dj/dj"); 
if ( me->query("jh_dj/dj") > 60 )
damage += damage/2;
if ( target->query("str") < damage )
damage = target->query("str");
if ( target->query("con") < damage )
damage = target->query("con");
if ( target->query("dex") < damage )
damage = target->query("dex");
  switch(random(3))
{
case 0:
{
if (target->query("dex")>damage) {
target->add("daoxin/dex",damage);
target->add("dex",-damage);
message_vision(HIY"你只听到卡的一声,$n的脚骨被$N使用"HIC"道心种魔大法"HIY"打断了!\n"NOR, me, target);   
break;
}
}
 
 case 1:
{
if (target->query("str")>damage) {
target->add("daoxin/str",damage);
target->add("str",-damage);
message_vision(HIG"只听到卡的一声,$n的手被$N使用"HIC"道心种魔大法"HIG"打断了!\n"NOR, me, target);   
break;
}
}

 case 2:
{
if (target->query("con")>damage) {
target->add("daoxin/con",damage);
target->add("con",-damage);
 message_vision(HIM"只听到崩的一声,$n的奇经八脉被$N使用"HIC"道心种魔大法"HIM"打乱了!!\n"NOR, me, target);   
break;
}
}
 }
msg = HIB"$n被$N运用"HIC"道心种魔大法"HIW"之"HIR"『道尽魔生』"HIB"打成残废人了!！！！\n"NOR;
                message_vision(msg, me, target);    
  me->add("neili", -(me->query("neili")/2));
   me->set("shen",-10000000);      
    return 1;

 } else
    {
       me->start_busy(4);
           me->add("neili",-100);     
 message_vision( HIG"$n临危不乱,口中模模糊糊的念着什么咒语,$N的。\n"HIW"『道尽魔生』"HIG"根本不起作用\n"NOR, me, target);   
    } 
   me->set("shen",-10000000);  
   me->add("neili", -(me->query("neili")/2));
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
