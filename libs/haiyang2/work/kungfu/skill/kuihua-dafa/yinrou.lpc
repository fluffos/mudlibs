// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
        string *order = ({"关元穴", "檀中穴", "肩井穴", "太阳穴", "气海穴", "百汇穴","腹结穴","涌泉穴","大椎穴"});
int perform(object me, object target)
{
	string msg;
	int extra,ap,dp,damage;
	int i;
	object weapon,ob;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("只能对战斗中的对手使用。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("你手中没有装备剑类武器！\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("pixie-jian", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("kuihua-dafa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("kuihua-xinfa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "kuihua-xinfa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


   if ( !wizardp(me) && (string)me->query("gender")=="男性" )
        return notify_fail("你必须先自宫!!\n");

        msg = HBWHT "$N贯通日月神教武学，使出了日月神教的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

	extra = me->query_skill("kuihua-dafa",1) / 20;
	extra += me->query_skill("kuihua-xinfa",1) /20;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", (extra*3));
	msg = HIR  "$N忽然化身为二，幻出左右两个身影高速滑向$n，手中$w幻化不定，招招紧逼$n的$l!" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC "$N的人影变成了几个，．．．．\n" NOR;
        message_vision(msg, me, target);
	if (random(2)==0) target->start_busy(3);
	for(i=0;i<extra/4;i++)
	{
	msg = HIW "$n身旁出现人影，向$n刺了过去！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -(extra*3));

	me->start_busy(4);
        msg=YEL"\n\n只见$N双目一滞，面上闪过一阵异彩，身法突然加快，如影随形，蹂身而上！\n"NOR;

        msg+=YEL"随着一声凄厉的长啸，$N手中宝剑绽开朵朵剑花，猛地罩向$n全身各处命门大穴！\n\n"NOR;


        ap=me->query_skill("kuihua-dafa")+me->query_skill("strike");
        dp=target->query_skill("parry")+target->query_skill("dodge");
        if(random(ap)+30>random(dp))   
           {
              damage=(me->query_str()-target->query_str()+10);
            damage=damage*random(me->query_cor());
/* */ damage=me->query("str")+me->query_skill("unarmed",1)/10+600;
/* */ damage=damage*(20+random(20));

      if(damage<0)    damage=600;
      if(damage>9600) damage=9600;
      msg+=RED"$n惊叫一声，"+HIY+(order[random(7)])+NOR+RED+"部位血花飞溅,\n"NOR;
      switch(random(2))
      {
         case 1:
           {
               msg+=RED"$n“哇”地一口鲜血从口中喷出！\n"NOR;
               target->reset_action();
 break;
           }
         default:
      msg+=RED"$n身形一震, 一股鲜血从口中喷出,直喷向$N,但见$N头一歪,轻松的躲了过去！！\n"NOR;
               target->reset_action();
      }
         switch(random(2))
     {
         case 1:
         { 
             target->receive_wound("qi",damage/2);
             target->receive_damage("qi",damage);
     if(wizardp(me)) tell_object(me,sprintf("damage: %d\n",damage));
     break;
         }
      default:   
         { 
           target->receive_wound("qi",damage*2/3);
           target->receive_damage("qi",damage*5/4);
 if(wizardp(me)) tell_object(me,sprintf("damage: %d\n",damage*5/4));
                      }

                  }            
           }
        else 
           {
                msg+=CYN"$p冷笑一声，身形虚晃几下闪了开去！\n"NOR;
           }

        message_vision(msg, me, target);


  message_vision(RED"\n$N猛地纵起，向$n扑去，手指一弹，细针飞了出去，插向$n右目。\n\n"NOR, me, target);
      
if((me->query("combat_exp")) > (int)target->query("combat_exp")/3) {
        message_vision(HIR"\n$n猝不及防，大叫一声，右眼中针！\n"NOR, me, target);
        tell_object(target, HIY "你感觉细针正插在自己的瞳仁之中，如果这针直贯入脑，便有性命之忧！\n" NOR);
                me->add("neili", -300);
                damage = extra*10;
                damage = damage*6;
               
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
               }
         else 
              {
                message_vision(HIY"\n可是$n看破了$N的企图，飞身闪了开去。\n"NOR, me, target);

              }


	return 1;
}
