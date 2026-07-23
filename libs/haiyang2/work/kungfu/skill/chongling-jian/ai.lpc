//ai.c 爱意之剑
//by sdong

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;
string msg;
        int bili,original,dodge,skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("爱意之剑只能对战斗中的对手使用。\n");


        if( me->query_skill("zixia-shengong", 1) < 60 )
                return notify_fail("你的紫霞神功火候未到，无法施展玉女素心！\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");


        if( me->query_skill("chongling-jian") < 155 )
                return notify_fail("你的冲灵剑法修为不足，还不会使用玉女素心！\n");

        if( me->query("neili") <= 400 )
                return notify_fail("你的内力不够使用爱意之剑！\n");
        if( me->query("jing") <= 100 )
                return notify_fail("你的精力不够使用爱意之剑！\n");




        if(!me)
                return notify_fail("现在没人！\n");
        if(!target)
                return notify_fail("现在没人！\n");

        skill = (int)me->query_skill("chongling-jian", 1);
        original = me->query_skill("zixia-shengong")/2;
        bili = me->query_str();
        dodge = me->query_dex();

        me->add_temp("apply/strength", 50);
        me->add_temp("apply/dexerity", 50);
        me->add_temp("apply/damage", 550);


  message_vision(HIC"只见$N的身形随着剑式一变，剑身闪出无数耀眼的光芒，震出了一片茫茫的剑幕\n"
                 HIW"\t～～"BLINK""HIR"   忘弃红尘．相思八律  "NOR""HIW"  ～～\n"NOR,me,target);

	msg = HIR "--<<红>>剑意有如风不定．伤遮流景．落红应满径--"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     msg = YEL  "--<<橙>>剑意有如抛弃久．惆怅依旧．镜里人颜瘦--" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     msg = HIY  "--<<黄>>剑意有如雨初歇．晓风残月．更与何人说--" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);



      if (!target->is_busy() && random(3)==0)
      target->start_busy(2); 
       msg = HIG  "--<<绿>>剑意有如黯天际．望极春愁．强乐还无味--" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

       msg = HIB  "--<<蓝>>剑意有如乱蝉嘶．酒徒萧索．不似去年时--" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

       msg = HIW  "--<<靛>>剑意有如照无眠．悲欢离合．何似在人间--" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

       msg = HIM  "--<<紫>>剑意有如追忆思．酒入愁肠．化作相思泪--" NOR;
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     if(random(skill) > 180)
     {
message_vision(sprintf(HIC"$n被$N的七色剑意所困，全身上下伤痕累累！\n"NOR),me,target);
          target->receive_wound("qi",skill*3);
          COMBAT_D->report_status(target,1);
     }


        me->add_temp("apply/strength", -50);
        me->add_temp("apply/dexerity", -50);
        me->add_temp("apply/damage", -550);

        me->start_busy(3);
        me->add("neili", -350);
        me->add("jing", -50);
        me->set_temp("suxin", 1);


//      me->start_busy(3);


        return 1;
}


