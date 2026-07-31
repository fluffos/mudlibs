// gonggui.c 全真剑法 同归剑法

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int skill;
	int extra;
        string msg;
	extra = me->query_skill("quanzhen-jian",1);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("同归于尽只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("quanzhen-jian", 1) < 135 )
                return notify_fail("你的全真剑法不够娴熟，不会使用「同归剑法」。\n");

        if( (int)me->query_skill("xiantian-qigong",1) < 100)
                return notify_fail("你的先天神功火候不够，不能使用「同归剑法」。\n");
    if(me->query_skill_mapped("force") != "xiantian-qigong" )
        return notify_fail("你要把先天神功做为内功才能用。\n");

        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("你已经在运太玄功了。\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("你已经在运葵花无敌功了。\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 
        
//                if(!( me->query("eff_qi")<1||(int)(me->query("max_qi")/me->query("eff_qi"))>=2.5))
//                return notify_fail("你还没受重伤，不要使用此剑法。\n");

        if( (int)me->query("neili") < 800  ) 
                return notify_fail("你的内力不够。\n");
 
//        if( (int)me->query_temp("powerupxtg") ) 
//                return notify_fail("你已经在运先天大法了。\n");


        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运功中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 

        if( me->query_temp("qzjtong") ) 
                return notify_fail("你已经在运功中了。\n");

        msg = HIB+me->name()+HIB"左手捏一个剑决，右手握起" + weapon->name() + "，拼着最后的力气，一式「同归剑法」，\n";
	msg += "驭剑猛烈绝伦地冲向"+target->name()+HIB",意图与"+target->name()+HIB"同归一尽！\n"NOR;
        message_vision(msg, me, target);
        if (me->query_skill("qixing-array",1)>80)
{
        msg = HIC "$N脚走七星， 倒转天权！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>150)
{
        msg = HIG "$N脚走七星， 风动玉衡！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>200)
{
        msg = HIW "$N脚走七星， 瑶光音迟！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}

        me->set_temp("qzjtong", 1);
        me->set_temp("qzj_tong", 1);
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);
	me->add_temp("apply/dexerity",extra/2);
        me->add_temp("apply/strength",extra/2);
//        me->add_temp("apply/dodge", -(int)me->query_skill("dodge",1)/2);
        me->add_temp("apply/damage",(int)me->query_skill("quanzhen-jian",1)/2);
        me->set_temp("qzj_tong", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, (int)me->query_skill("dodge",1)/2, (int)me->query_skill("quanzhen-jian",1)/2:), 30);
	me->add("neili", -500);
	me->start_busy(3);

        return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	int extra;
	extra = me->query_skill("quanzhen-jian",1);
	me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
	me->add_temp("apply/dexerity",-extra/2);
        me->add_temp("apply/strength",-extra/2);
        me->add_temp("apply/damage",-(int)me->query_skill("quanzhen-jian",1)/2);
        me->delete_temp("qzj_tong");
        me->delete_temp("qzjtong");
	me->start_busy(1);
       tell_object(me, "你运功完毕。\n"); 
}

