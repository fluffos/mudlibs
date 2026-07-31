// yitian.c 倚天剑决

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

#define ZHAO "「" HIY "佛光普照" NOR "」"

#define YUN "「" HIW "云海明灯" NOR "」"
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, ob;
        int extra,i,time,ap,dp,damage;
        string msg;
                int lvl,skill;
        lvl=me->query_skill("yitian-jian");
        i = me->query_skill("yitian-jian", 1) + me->query_skill("sword", 1) + me->query_skill("linji-zhuang", 1);
        time = 5;
         if( !target ) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「倚天剑决」只能在战斗中使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("「倚天剑决」必须用剑才能使用！\n");
        if (me->query_skill_mapped("sword") != "yitian-jian")
                return notify_fail("你没有激发倚天剑法，怎么使用「倚天剑决」啊？\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你的内功修为不够！\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("yitian-jian",1) < 120 )
                return notify_fail("你的倚天剑法还不到家，无法使用「倚天剑决」！\n");

        msg =HIY "$N" HIY "长啸一声：\n" HIR "武林至尊、宝刀屠龙。号令天下，莫敢不从。倚天不出，谁与争锋? \n"
             HIR "顿时风云变色，" HIR "$N" HIR "手中舞出漫天剑光........ \n" NOR;

        message_vision(msg, me);
        if (random(3)==0) target->start_busy(3);
if (i>200) i=200;
        me->add_temp("apply/attack", i);
//        me->add_temp("apply/damage", i/2);
        me->add_temp("apply/damage", 1200);
//        for(i=1;i<=(int)time;i++)
        //{
        msg =  HIC "-----拔云见日!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  BLU "-----星河在天!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  HIM "-----剑气浩荡!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg =  HIM "-----神剑天威!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);      

        msg =  HIY "-----倚天不出!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  HIR "-----谁与争锋!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  HIM "-----号令天下!----- \n"NOR;
        //message_vision(msg,me,target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

  
        

        //}
        me->add_temp("apply/attack", -i);
//        me->add_temp("apply/damage", -i/2);
        me->add_temp("apply/damage", -1200);
        me->add("neili",-200);
        msg =HIY "$N暗念倚天剑决，身法陡然加快！\n" NOR;
        message_vision(msg, me);
if (lvl>300)
{
	
	msg = 
YEL "\n$N使出天罡指穴法绝技「凌空指穴」，回过身来，背后竟似生了眼睛一般，左
手食中二指向$n接连戳去，一连七指，全是对向$n的头脸与前胸重穴。\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 || random(3)==0)
	{
		msg +=  NOR "结果$p被$P指力点中几处穴道! \n" ;
		target->start_busy( 7);

	}
	else
	{
		msg += NOR "$p情急智生，狠力一跃，退出老远。\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);	
}	

if (lvl>600)
{
msg = HIY "\n$N" HIY "运起全身功力，顿时真气迸发，全身骨骼噼啪作"
              "响，猛然一掌向$n" HIY "\n全力拍出，力求一击毙敌，正是一"
              "招「佛光普照」。\n" NOR;
         
        ap = me->query_skill("hand") +
             me->query_skill("force") +
             me->query("str") * 10;

        dp = target->query_skill("dodge") +
             target->query_skill("force") +
             me->query("con") * 10;

        damage = me->query_skill("hand")+lvl;

        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {

                me->start_busy(5);
                msg += HIW "只听轰然一声巨响，$n" HIW "已被一招正中，可$N"
                       HIW "只觉全身内力犹如江河入\n海，又如水乳交融，登"
                       "时消失得无影无踪。\n" NOR; 
        } else
        if (ap / 2 + random(ap) > dp || random(3)==0)
        {

                me->start_busy(2);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "只听轰然一声巨响，$n" HIR "被$N"
                                           HIR "一招正中，身子便如稻草般平平飞出"
                                           "，重\n重摔在地下，呕出一大口鲜血，动"
                                           "也不动。\n" NOR;

        } else 
        { 

                me->start_busy(3);
                msg += CYN "可是$p" CYN "内力深厚，及时摆脱了" 
                       CYN "$P" CYN "内力的牵扯，躲开了这一击！\n" NOR; 
        }
        message_combatd(msg, me, target);	
	
}	

        me->start_busy(2);
        return 1;
}

