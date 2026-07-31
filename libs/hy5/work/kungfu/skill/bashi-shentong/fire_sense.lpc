// fire_sense.c 火识神通
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;
int conjure(object me, object target)
{
    string msg;
    string msg1;
    string msg2;
    string msg3;
    string msg4;
    int damage, ap, dp,i;
    i=random(3);
    if( !target ) target = offensive_target(me);
    if( !target
     || !target->is_character()
     || target->is_corpse()
     || target==me)
    return notify_fail(HIR"你要对谁施展「火识」？\n"NOR);
    if (i==0){
        msg1="$N双手各捻个法诀，再并拢向外一推，大喝道："+HIC"“般若波罗密，风火雷电……打！！”"NOR+"\n;
        刹那间，风起云涌，浓云密布，一道闪电自天空中疾闪而下向$n劈去！！！\n";
        msg2=HIR"“轰”的一声打了个正着，"+target->query("name")+"被电得象烟熏猪头一样黑！\n"NOR;
        msg3=RED"你只觉得全身发麻，眼前金星乱冒。。。。\n"NOR;
        msg4="jing";
    }
    if(i==1){
        msg1="$N身形一转散作七处同时口中念道：\n"+HIY"
        “天地无相，万剑归宗，浩天正气，神剑伏魔！！”"NOR+"\n
        只见空中出现万点金光向$n射去。。。\n";

        msg2="只听“嗤嗤”声响不绝，金光射入"+target->query("name")+"身体。"+
        target->query("name")+"变成了千窗百孔的大筛子！！！\n";
        msg3=RED"你只觉的遍体生风，浑身剧痛。\n"NOR;
        msg4="jing";
    }
    if (i==2){
        msg1="$N双手环抱胸前，口中喃喃念道：\n"+HIR"“天地无极，乾坤借法！！”"NOR+"\n  
        突然大喝一声：“中！！”\n双掌并力将一巨大的金色光球推向$n！\n";
        msg2="“砰”！"+target->query("name")+"身子向后一仰，连退了几步………\n";
        msg3="“砰”！你胸口如遭锤击，两眼一黑，险些昏了过去！\n";
        msg4="qi";
    }

    if((int)me->query("jingli") < 150 )
        return notify_fail("你的精力不够！\n");

    if((int)me->query("jing") < 35 )
        return notify_fail("现在你的精神无法有效集中！\n");

    me->add("jingli", -30);

    if( random(me->query("max_jingli")) < 150 ) {
       write("你失败了。\n");
       return 1;
    }
    msg="\n";
    message_vision(msg1, me, target);
    ap = me->query_skill("bashi-shentong");
    ap = ( ap * ap * ap / 4 ) * (int)me->query("jing") / 100;
    dp = target->query("combat_exp");
    if( random(ap + dp) > dp) {
       damage = (int)me->query("max_jingli") / 10 + random((int)me->query("eff_jing") / 5);
       damage -= (int)target->query("max_jingli") / 20 + random((int)me->query("eff_jing") / 10);
       if(target->is_ghost()) damage=damage*10;
       if( damage > 0 ) {
        target->receive_damage(msg4, damage, me);
        target->receive_wound(msg4, damage/2, me);
        tell_room(environment(me),msg2,target);
        tell_object(target,msg3);
        me->improve_skill("bashi-shentong", 1, 1);
     } else
     {
        msg = "$N的「火识」好象没有造成任何伤害！\n";
        me->receive_damage("jing", 10);
     }
   } else
   msg = "但是$n巧妙地躲开了。\n";
   message_vision(msg, me, target);

   if( damage > 0 ) COMBAT_D->report_status(target);
   if( !target->is_fighting(me) ) {
     if( living(target) ) {
      if( userp(target) ) target->fight_ob(me);
        else target->kill_ob(me);
     }
     me->kill_ob(target);
   }

   me->start_busy(2);
   return 1;
}

