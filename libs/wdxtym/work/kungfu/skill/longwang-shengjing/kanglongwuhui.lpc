#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define HUI "「" HIR "亢龙有悔" NOR "」"
#define HUIP "「" HIR "亢龙有悔" HIW "」"
string query_name() { return "亢龙无悔"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
	 int skill;
	 int damage;
	 
       int  ap, dp;
	 
        extra = me->query_skill("longwang-shengjing",1);
        skill = me->query_skill("longwang-shengjing",1);
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」只能对战斗中的对手使用。\n");

               if( objectp(me->query_temp("weapon")) )
              return notify_fail("你必须空手使用「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」！\n");
     
        if( (int)me->query_skill("longwang-shengjing", 1) < 800 )
                return notify_fail("你的龙王圣经不够娴熟，无法施展出「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」。\n");
if ( me->query_skill_mapped("force") != "yinyangjiuzhuanshierchongtian" )
return notify_fail("你没有太始帝经！\n");
if ( me->query_skill_mapped("unarmed") != "longwang-shengjing" )
return notify_fail("你没有使用这门掌法！\n");

        if (me->query_skill("yinyangjiuzhuanshierchongtian", 1)<520)
                return notify_fail("你的本门内功火候未到，！\n");
       
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够，无法施展出「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」。\n");
        if ( (int)me->query("neili") < 1500)
                return notify_fail("你的真气不够，无法施展出「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+"」。\n");
                 
                 me->add_temp("apply/attack", 100);
	         me->add_temp("apply/damage", 1000);
	me->add("neili", -200);
		 msg = YEL "$N双掌平平提到胸前，神色沉重的缓缓施出龙王圣经的最后一招「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+YEL"」一招八式推向$n！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "第一式！$N右掌一式「龙现于野」，勇猛无比地劈向$n！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "第二式！$N双掌施出一式「鸿龙在陆」，隐隐约约带着掌风拍向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "第三式！$N左掌御胸，右掌一式「潜龙出海」缓缓推向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第四式！$N使出「龙跃在天」，向$n的连拍数掌！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG "第五式！$N双掌一式「双龙戏水」一前一后按向$n的胸前！" NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "第六式！$N身形转动，使出「晴天六龙」向$n连打六下！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "第七式！$N脚下一转，突然欺到$n身前，一式「龙战于野」直拍向$n面门" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "第八式！$N突然飞起，双掌居高临下最后一式「龙啸九天」全力拍向$n！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);
if ((!userp(me) || skill>200) && me && target)
{
 msg = HIB "
$N默运混天气功，施展出「雷霆一击」，全身急速转动起来，越来越快，就犹如一股旋风，骤然间，$N已卷向正看得发呆的$n。"NOR;  

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(3)==0) { 
      me->start_busy(3);
   damage = (int)me->query_skill("longwang-shengjing", 1)*3+(int)me->query_skill("yinyangjiuzhuanshierchongtian",1);
   damage = damage + random(damage)+200;
    if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
   target->receive_damage("qi", damage,me);
   target->receive_wound("qi", damage,me);

   msg +=  COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 120,
   "$n只见一阵旋风影中陡然现出$N的双掌，根本来不及躲避，被重重击中，五脏六腑翻腾不休，口中鲜血如箭般喷出！！！\n"NOR);
message_combatd(msg, me, target);
COMBAT_D->report_status(target);

    } else
    {
      me->start_busy(3);

       msg += "可是$n看破了$N的企图，忽然向$N攻击。\n"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->report_status(me);
    }	
}	

if ((!userp(me) || skill>300) && me && target)
{
if (objectp(weapon = target->query_temp("weapon")))
{
    msg = HIW "$N" HIW "暴喝一声，全身内劲迸发，气贯右臂奋力外扯，企图将$n"
              HIW "的" + weapon->name() + HIW "吸入掌中。\n" NOR;

        ap = me->query_skill("longwang-shengjing") + me->query("str") * 10;
        dp = target->query_skill("parry") + target->query("dex") * 10;

        if (ap / 3 + random(ap) > dp || random(3)==0)
        {
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
                msg += HIR "$n" HIR "只觉周围气流涌动，手中" + weapon->name()
                       + HIR "竟然拿捏不住，向$N" HIR "掌心脱手飞去。\n" NOR;

                weapon->move(environment(me), 1);
}
                target->receive_damage("qi", ap*2,me);
                target->receive_wound("qi", ap*2,me);
        } else
        {
                msg += CYN "$n" CYN "只觉周围气流涌动，慌忙中连将手中"
                       + weapon->name() + CYN "挥舞得密不透风，使得$N"
                       CYN "无从下手。\n" NOR;

        }
        message_combatd(msg, me, target);
}	
	
}	
if ((!userp(me) || skill>400) && me && target)
{
  msg = WHT "$N" WHT "施出龙王圣经之「" HIW "震惊百里" NOR +
              WHT "」，全身真气鼓动，双掌如排山倒海般压向$n" WHT "。\n"NOR;  

        ap = me->query_skill("longwang-shengjing",1) + me->query("str") * 10;
        dp = target->query_skill("dodge",1) + target->query("dex") * 10;

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        { 
                damage = ap + random(ap / 2)+400;
    if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
   target->receive_damage("qi", damage*2,me);
   target->receive_wound("qi", damage*2,me);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 150,
						HIR "$n" HIR "只觉一股罡风涌至，根本不"
                                           "及躲避，$N" HIR "双掌正中前胸，鲜血如"
                                           "箭般喷出。\n" NOR);

                me->start_busy(2);
        } else
        {
                msg += CYN "$n" CYN "眼见$N" CYN "来势汹涌，丝毫不"
                       "敢小觑，急忙闪在了一旁。\n" NOR;

                me->start_busy(2);
        }
        message_combatd(msg, me, target);
}	

if ((!userp(me) || skill>500) && me && target)
{
        ap = me->query_skill("longwang-shengjing",1) + me->query("str") * 10;
        dp = target->query_skill("dodge",1) + target->query("dex") * 5;

        message_vision(HIW "\n忽然$N" HIW "身形激进，左手一划，右手呼的一掌"
                     "拍向$n" HIW "，正是龙王圣经" HUIP "。\n力自掌生之际"
                     "说到便到，以排山倒海之势向$n" HIW "狂涌而去，当真石"
                     "破天惊，威力无比。\n" NOR, me, target);

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = ap + random(ap)+800;
    if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
   target->receive_damage("qi", damage*2,me);
   target->receive_wound("qi", damage*2,me);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 170,
					HIR "$P身形一闪，竟已晃至$p跟前，$p躲"
                                          "闪不及，顿被击个正中。\n" NOR);
        } else
        {
                msg = HIC "却见$p气贯双臂，凝神应对，$P掌"
                      "力如泥牛入海，尽数卸去。\n" NOR;
        }
        message_vision(msg, me, target);

}	

        if( random(me->query("combat_exp")) > target->query("combat_exp")/4
		&& me->query("xlz/hang"))
	 {

 msg = HIR"你咬紧牙关，双掌护身，心中默念龙王圣经的口诀!"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔!!"NOR+" ";
                msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
         damage=(int)me->query_skill("longwang-shengjing",1)+200;
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage*3,me);
                target->receive_wound("qi",damage*3,me);
		target->receive_wound("jing", 10 + random(200),me);
                if (!target->is_busy()) target->start_busy(2);
//             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	}



        me->start_busy(5);
        return 1;
}
