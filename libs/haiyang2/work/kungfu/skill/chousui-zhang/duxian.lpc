// 毒仙炎
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,extra,p;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("只能在战斗中使用。\n");
 weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "staff")
		return notify_fail("你必须空手才能使用这个绝技！\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("tianshan-zhang", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("chousui-zhang", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("huagong-dafa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通星宿派武学，使出了星宿派的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

  msg = HIM "\n$N突然间手舞足蹈，口中念念有词，诵道：“星宿神功，威震寰宇，古今无比”，\n";
  msg += HIM "跟着将手中杖向空中连连抛送，毫无章法，好似跳大罗金仙舞，让人瞠目结舌。\n\n"NOR;

  message_vision(msg, me, target );
if (random(3)==0) target->start_busy(3);
	msg = HIY "$N使出天山派绝技「天山奇峰」，身法陡然加快。万岳朝宗！" NOR;
	p  = me->query_skill("huagong-dafa",1);
        extra = me->query_skill("tianshan-zhang",1) / 10;
        extra += me->query_skill("huagong-dafa",1) /10;
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", extra*3);
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIB  "        ^^玉进天池！^^       " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "      ^^^^山风凛冽！^^^^  " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIM  "    ^^^^^^开门见山！^^^^^ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "^^^^^^^^^^^天山雪崩！^^^^^^^^^^^ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*2);    
        me->add_temp("apply/damage", -extra*3);
        message_vision(HIY"$N的招式突变，手上冒出了绿光! $n被绿光扫中，全身不由一震!\n"NOR,me,target);
        target->apply_condition("xx_poison",50);
	 msg =  HIR  "「腐尸毒」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("poison_sandu",50);
	 msg =  HIR  "「毒砂掌」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("sanpoison",50);
	 msg =  HIR  "「无形毒」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        if (random(me->query("combat_exp")) >target->query("combat_exp")/3)
        {
       	 msg =  HIR  "「三笑逍遥散」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$N突然怪异的一笑，$n尽然跟着笑了笑!\n"NOR,me,target);
            target->receive_damage("qi", p*5);  
            target->receive_wound("qi", p*3);  
        target->apply_condition("sanxiao_poison",6);
        me->add("neili", -50);
        }
message_vision(RED "\n$N用全身的内力注入地上！对着地上一指..地上出现了团"HIR"火焰\n" NOR, me);	
       message_vision(BLU"\n$N神色惨淡，伸手打开发髻，长发下垂，覆在脸上，跟着点燃红磷粉，咬破舌尖，
一口"RED"鲜血"BLU"向火焰中喷去。"HIR"火焰忽地一暗，随即大为"RED"明亮"HIR"，耀得众人眼睛也不易睁开。\n\n"NOR,me);
        msg = BLU"\n$N猛地身子急旋，如陀螺般连转了十多个圈子，接着$P大袖拂动，"HIR"整个火焰堆陡地拨起，凌空
燃烧，便如一座"RED"火墙"HIR"般，夹着排山倒海之势向$n压来！\n"NOR;
 	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {

            msg += HIY"\n$n只吓目瞪口呆，一怔之间，急忙跃起，但一朵"HIW"火花"HIY"已射到身前，嗤的一声响，
火花已烧上肚腹。$n“啊”的一声大叫，落了下来。那团"HIR"大火墙"HIY"也即回入火焰堆中。\n" NOR;
            target->receive_damage("qi", p*8);  
            target->receive_wound("qi", p*5);  
            msg += "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
            msg += "( "RED"$n受伤过重，已经有如风中残烛，随时都可能断气。"NOR")\n";
		message_combatd(msg, me, target);
}
else
{
		msg += "$p急提内力奋力一震，将$N打出的大火墙卸在了身旁!\n" NOR;
		message_combatd(msg, me, target);
}
	me->start_busy(4);
	return 1;
}
