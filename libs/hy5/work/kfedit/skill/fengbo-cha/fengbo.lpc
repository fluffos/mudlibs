#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;


string* skill_head1 =({
        HIW"$N身形稍退，使出一招 苍龙出海",
        HIW"$N仰天长笑，看也不看，一招 龙腾四海",
        HIW"$N一个虎跳，使出 龙跃九洲",
        HIW"$N一声巨喝，好一个 双龙戏珠",
        HIW"$N使出 龙震四野",
        HIW"$N连翻几个筋斗，一招 龙吟长啸",

});

string* skill_tail1 =({
        HIW"，手中$w迎风一抖，朝着$n劈头盖脸地砸将下来。",
        HIW"，随手一棒向$n当头砸下。",
        HIW"，越过$n头顶，手中$w抡个大圆，呼！地一声砸向$n$l。",
        HIW"，就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l。",
        HIW"，脚步跄踉，左一棒，右一棒，\n打得$n手忙脚乱，招架不迭。",
        HIW"，手中$w转得如风车一般，\n一连三棒从半空中击向$n顶门。",
});

int perform(object me, object target)
{
        int mypot,tapot,time, ap, dp,damage;
object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「无尽风波」只有在战斗中才能使用。\n");

        if( (int)me->query_skill("fengbo-cha", 1) < 50 ) 
                return notify_fail("你的修为不够深，还使不出这一招！\n");
    
  if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展？\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);
  
     
        
    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才行。\n");

      if( (int)me->query_skill("jinghai-force", 1) < 60 )
                return notify_fail("你的靖海神功还差些火候。\n");            
        if ((int)me->query("max_neili")<800)
                return notify_fail(RED"你的内力修为不足。\n"NOR);
  
        if ((int)me->query("neili")<400)        
                return notify_fail(HIC"你现在内力不够！\n"NOR);   
        if( target->is_busy() )
                return notify_fail(target->name()+"已经够忙了，你使的再漂亮也不会注意到。\n");

        message_vision(HIC"$N挥展开来，左一叉，右一叉，幻出无数大小光环向$n绕去。
虽看起来柔弱无力，却宛若秋波般连绵不绝，实是暗藏杀机！\n\n"NOR,me, target);

        me->add("jing", -60);

        mypot=(int)me->query_skill("club");
        mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        time=(int)me->query_skill("fengbo-cha", 1)/10 - (int)target->query_skill("parry")/20;
    
        if ( time > 10 ) time = 10;
        if ( time < 6  ) time = 6;

//        if ( (mypot+tapot)/4+random( mypot + tapot ) > tapot ) {
//        if ( (mypot+tapot)/2+random( mypot + tapot ) > tapot ) {
        if ( (mypot+tapot)/2+random( (mypot+tapot)*3/4 ) > tapot ) 
        {
                message_vision(HIR"$N果然被这光环套住，当时目瞪口呆，不知所措！\n"NOR,target);
                target->start_busy(time);
                me->set_temp("no_pfm",time() + 2);
        }
        else 
        {
                message_vision(HIR"不料却被$N看破，攻其不备，$n反被打了个措手不及！\n"NOR,target,me);
//                me->start_busy(3);
                me->start_busy(1+random(2));
        }

        
 if ((int)me->query_skill("fengbo-cha",1) > 300 )
{
         me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 2000); 

        if(!target->is_busy())
                target->start_busy(1);
        

	msg = skill_head1[0]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[1]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[2]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[3]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[4]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = skill_head1[5]+skill_tail1[random(sizeof(skill_tail1))]+"\n"NOR;   
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-100);
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -2000);
}
 if ((int)me->query_skill("fengbo-cha",1) > 600  || !userp(me))
{
     msg = HIR
"\n$N默运靖海神功，身形忽向斜后飞出，$n正要追击，却不料$N手中放出一道绚丽的光环，顿时天空中出现一个大力魔神，只见魔神手举天庭神棒，\n"
"如闪电，如雷火一般直贯$n胸前，仓惶间$n早已六神无主，不知如何是好\n" NOR;

        ap = me->query_skill("fengbo-cha", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");
        if( random((ap + dp)/400) <  dp/1000 ) 
        {
                msg += "$n"+HIG"身体立即直冲云霄，似有一种"+HIW"我于天斗，老天奈何于我"+HIG"的气势，躲过了这致命一击！\n\n"NOR;
                message_vision(msg, me, target);
        } 
        else 
        {
                damage = 300+((int)me->query_skill("club",1)*2)  +
        (int)me->query("jing") / 300 + random((int)me->query("jing") / 200 ) +
        (int)me->query("qi") / 300 + random((int)me->query("qi") / 200 );
                msg += HIY "天魔一击顿时从$n的胸口直贯而过，$n的胸口顿时血流如注，大呼"+HIW"天既如此，我耐如何"+HIR"，$n现在已是风中残烛，命在旦夕！\n" NOR;
                damage +=random(50);
                if (damage > 28000) damage=28000;
                target->receive_damage("jing", damage/5,me);
                target->receive_wound("qi", damage,me);
                
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }	
	
}	
               
        me->start_busy(1+random(2));

        return 1;
}
    


