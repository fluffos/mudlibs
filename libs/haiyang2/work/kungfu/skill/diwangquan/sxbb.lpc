// perform dodge.shenxingbaibian

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
     string msg;
        int extra,i,j,lmt;
        object weapon;
extra = me->query_skill("diwangquan",1);
  weapon = me->query_temp("weapon");
if ( extra < 100) return notify_fail("你的神龙帝王拳还不够纯熟！\n");

 if( !target ) target = offensive_target(me);
  if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［神形百变］只能对战斗中的对手使用。\n");
                        if(me->is_busy()) return notify_fail("您现在没空！！\n");

        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够！\n");
        if( me->query("jing") <= 500 )
                return notify_fail("你的精力不够！\n");
                
i = random(10);
if(me->query_skill_mapped("force") == "shenlong-xinfa")
{
switch(i)

{case 0:
case 1:

{
message_vision(HIW"$N身法忽急忽缓，不断绕着$n游走，突然使出韦小宝的绝技「" + HIC "神行百变" + HIW "」！\n"NOR,me,target);
        if(random((int)target->query("combat_exp")) < 10*(int)me->query("combat_exp"))

        {
        message_vision(HIW"结果$N被弄的头昏眼花,不知所措！\n"NOR,target);
        target->start_busy(3);

        }
        else{
        message_vision(HIY"$N潜运内力,集中精神,并没有受到迷惑！\n"NOR,target);
        target->start_busy(2);
        me->start_busy(1);
        }

        break;}
case 2:
case 3:
case 4:
case 5:
case 6:


{

        msg = RED "$N拼尽全力，使出神形百变中威力最大的一式「" + HIC "一脚定乾坤" NOR + RED"」，\n" ;
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
{msg += HIR "只听$n一声惨叫,整个人像一摊烂泥一样的瘫了下去！\n" NOR;
target->receive_damage("qi",(int) me->query("max_qi"));
              target->start_busy(1+random(1));}
else {msg += CYN "$n连忙就地打滚,虽然躲过了这致命一击,却也狼狈不堪,冷汗直冒！\n" NOR;
target->start_busy(1+random(1));}
me->start_busy(1);
message_vision(msg, me, target);
break;}
case 7:
case 8:
case 9:
{msg = HIM  "$N突然横腿疾扫，卷起地下大片沙石，身子一分为二，前后夹击、连攻数招！" NOR;
message_vision(msg,me,target);
target->set_temp("is_unconcious",1);

lmt = random(6)+3;
for(j=1;j<=lmt;j++)
        {
        msg =  HIM "第"+chinese_number(j)+"腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }

 target->delete_temp("is_unconcious");
me->start_busy(1);
target->start_busy(1+random(1));
break;}}}

else
{
switch(i)

{case 0:
case 1:

{
message_vision(HIW"$N身法忽急忽缓，不断绕着$n游走，突然使出韦小宝的绝技「" + HIC "神行百变" + HIW "」！\n"NOR,me,target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))

        {
        message_vision(HIW"结果$N被弄的头昏眼花,不知所措！\n"NOR,target);
        target->start_busy(3);
        }
        else{
        message_vision(HIY"$N潜运内力,集中精神,并没有受到迷惑！\n"NOR,target);}
        me->start_busy(1);
        break;}
case 2:
case 3:
case 4:
case 5:
case 6:


{

        msg = RED "$N拼尽全力，使出神形百变中威力最大的一式「" + HIC "一脚定乾坤" NOR + RED"」，\n" ;
if( random(me->query("combat_exp")) > (int)target->query("combat_exp") )
{msg += HIR "只听$n一声惨叫,整个人像一摊烂泥一样的瘫了下去！\n" NOR;
target->receive_damage("qi",(int) me->query("max_qi"));
}
else {msg += CYN "$n连忙就地打滚,虽然躲过了这致命一击,却也狼狈不堪,冷汗直冒！\n" NOR;
}
me->start_busy(1);
message_vision(msg, me, target);
break;}
case 7:
case 8:
case 9:
{msg = HIM  "$N突然横腿疾扫，卷起地下大片沙石，身子一分为二，前后夹击、连攻数招！" NOR;
message_vision(msg,me,target);
lmt = random(2)+1;
for(j=1;j<=lmt;j++)
        {
        msg =  HIM "第"+chinese_number(j)+"腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }

me->start_busy(1);
break;}}
}
  me->start_busy(3);
  me->add("neili",-180);

return 1;
}

