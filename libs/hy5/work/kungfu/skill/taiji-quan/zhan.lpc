// zhen.c 太极拳「粘」字诀
// snowman
#include <ansi.h>

inherit F_SSERVER;
string *taiji_msg = ({"揽雀尾","单鞭","提手上势","白鹤亮翅","搂膝勾步","白蛇吐信","高探马",
"伏虎式","揽月势","金鸡独立","玉女穿梭","进步七星","弯弓射虎","抱虎归山",});
#include "/kungfu/skill/eff_msg.h";
string *taiji_msg2 = ({"十字手","如封似闭","搬拦捶","野马分鬃","斜飞势","云手","马步靠","闪通臂"});

int perform(object me, object target)
{
        int damage;
        string msg;
        int p, force;
        float at;
       
        string *limbs;
        
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「粘」字诀只能对战斗中的对手使用。\n");

//        if(!me->query_temp("taiji"))
//                return notify_fail("太极拳精要在于将展未展，你没有运用「太极」，又如何能使用「粘」字诀？\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在真气不够，强行使用「粘」是发挥不了它的威力的！\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");     
        if( target->is_busy())
                return notify_fail("对方正自顾不暇呢，你不忙使用「粘」字诀。\n");   
                
        msg = CYN "\n$N一招一式节节贯串，如长江大河，"RED"「粘」"CYN"在$n身上，一个圆圈跟着一个圆圈，
大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出，连绵不断，滔滔不绝！\n"NOR;
        
        if(random(me->query("combat_exp")) > target->query("combat_exp")/2){
                damage = (int)me->query_skill("taiji-quan", 1)/20; 
                damage = 2+random(damage)+8+1;
                if(damage > 18) damage = 18; 
                target->start_busy(6);
                me->add("neili", -(damage*30));
                me->add("jing", -20);
                msg += HIR"这左圈右圈登时便套得$p跌跌撞撞，身不由主的立足不稳，犹如中酒昏迷！\n"NOR;       
                } 
        else{
                target->start_busy(2);
                me->start_busy(3);
                me->add("jing", -15);
                me->add("neili", -100);
                msg += HIY"$p只觉在$P太极拳笼罩之下，无可抵御，只得只得运劲于足，飘然闪开。\n"NOR;
             }
        message_vision(msg, me, target);

    if( (int)me->query_skill("taiji-quan", 1) > 200 )
    {
     limbs = target->query("limbs");
        msg = CYN "\n$N使一招太极拳「"+taiji_msg[random(sizeof(taiji_msg))]+"」，右脚实，左脚虚，运起"RED"「挤」"CYN"字诀，粘连粘随，右掌已搭住$p"+limbs[random(sizeof(limbs))]+"！\n"NOR;
        
        force = me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("unarmed")) > target->query_skill("unarmed")/2 || random(3)==0){
                me->start_busy(3);
                if(!target->is_busy()) target->start_busy(3);
                
                damage = 200+(int)me->query_skill("force");                
                if(me->query("neili") > target->query("neili")*2) damage *= 2;
                else if(me->query("neili") > target->query("neili")*3/2) damage += random(damage);
                else if(me->query("neili")*2 < target->query("neili")) damage /= 2;
                else if(me->query("neili") < target->query("neili")) damage -= random(damage);
                else damage = damage/2 + random(damage);
                if(damage> 5000) damage = 5000; 
                target->receive_damage("jing", damage/3);
                target->receive_damage("qi", damage);
                msg += HIR"跟着$P横劲发出，$p给这么一挤，身子被自己的劲力带得不由主的向前一冲，跨出数步！\n"NOR;       
                } 
        else{
                me->start_busy(2);
                msg += HIY"$p见此情景，一声惊噫，连忙收回自己的劲力，闪身避让！\n"NOR;
             }
        message_vision(msg, me, target);
}

    if( (int)me->query_skill("taiji-quan", 1) > 300 )
    {
msg = CYN "\n$N默运神功，使出太极拳「震」字诀，企图以内力震伤$n。\n"NOR;

    if (random(me->query_skill("force")) > target->query_skill("force")/3 || random(3)==0)
    {
      me->start_busy(2);
      damage = (int)me->query_skill("taiji-shengong", 1)+200;
      damage = damage/2 + random(damage)+500;

      target->receive_damage("qi", damage);
      target->receive_wound("qi", damage/2);
      me->add("neili", -damage/10);

      if( damage < 20 ) msg += HIY"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
      else if( damage < 40 ) msg += HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
      else if( damage < 80 ) msg += RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
      else msg += HIR"结果$n被$N的内力一震，眼前一黑，身子向后飞出丈许！！\n"NOR;

    } else
    {
      me->start_busy(1);
      msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
    }
    message_combatd(msg, me, target);

}
    if( (int)me->query_skill("taiji-quan", 1) > 600 )
    {
        msg = CYN "\n突然，$N一招「"+taiji_msg[random(sizeof(taiji_msg))]+"」，双手左右连画，一个圆圈已将$n套住，太极拳的"RED"「震」"CYN"字诀随即使出！\n"NOR;
        
        force = 500+me->query_skill("force") + target->query_skill("force");

        if(random(me->query_skill("force")) > target->query_skill("force")/2 || random(3)==0){
                if(me->query("neili") < target->query("neili")/2){
                       me->start_busy(2);
                       if(!target->is_busy()) target->start_busy(3); 
                       target->add("neili", -force/2);
                       msg += HIY"只听「啪」的一声，$p和$P两人内力相拼相碰，各自退了几步。\n"NOR;
                       message_vision(msg, me, target);
                       return 1;
                       }
                me->start_busy(2);
                if(!target->is_busy()) target->start_busy(2+random(3));
                
                damage = (int)me->query_skill("force")*2+600;                
                at = me->query("neili") / (target->query("neili")+1);
                if(at < 1){
                    if(at < 0.5) damage /= 2;
                    damage /= 2;
                    }
                else damage *= at;
                if(damage> 8000) damage = 8000; 
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                if(target->query("neili") >= damage/4) target->add("neili", -(damage/4));
                else target->set("neili", 0);

                if(damage > 2000)
                   msg += RED"太极之意连绵不断，有如自去行空，一个圆圈未完，第二个圆圈已生，喀喇一响，$p一处骨头被绞断！\n"NOR;
                if(damage > 3000)
                   msg += HIR"$N恨他歹毒，「震」字诀使出时连绵不断，跟着喀喀喀几声，$p全身各处骨头也被一一绞断！\n"NOR;
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "震伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";       
                } 
        else{
                me->start_busy(2);

                msg += HIY"$p一看不对，马上一阵急攻，$P登时手忙脚乱，再也来不及出招！\n"NOR;
             }
        message_vision(msg, me, target);	
   } 	
        return 1;
}