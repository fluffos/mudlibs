//Cracked by Kafei
//yunwu.c 百变千幻衡山云雾十三式 by maco

#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「百变千幻衡山云雾十三式」只能对战斗中的对手使用。\n");

        if( me->query_temp("yunwu") )
                return notify_fail("你已经使出「百变千幻衡山云雾十三式」了！\n");

        if (!me->query_temp("weapon"))
                return notify_fail("你手中无剑，如何能施展「百变千幻衡山云雾十三式」？\n");
        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何能施展「百变千幻衡山云雾十三式」？\n");

        if( me->query_skill("dodge") < 100 )
                return notify_fail("你的轻功修为未到，难以施展「百变千幻衡山云雾十三式」的变幻之处！\n");

        if( me->query_skill("sword") < 100 )
                return notify_fail("你在剑法上的造诣不足以使出「百变千幻衡山云雾十三式」！\n");

        if( me->query("neili") <= 200 )
                return notify_fail("你的内力不够施展「百变千幻衡山云雾十三式」！\n");

        skill = me->query_skill("sword");


        msg = HIC
"\n$N神色潇潇,手中剑芒幻出五彩光芒，将剑身向$n极速圈去，好一招“晓风三月”\n" NOR;
        me->add_temp("apply/attack",200	);
        me->add_temp("apply/damage",3800);
                message_combatd(msg + "\n", me, target, "");
                msg = HIM "$n只觉三股剑气罩住自己,登时全身一麻,动弹不得!!\n" NOR;
                
                message_combatd(msg, me, target, "");
       target->start_busy(2);
                msg=HIM"第一股五彩剑气一出，早春三月的寒露为之融化，让$n惊叹！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIC"第二股五彩剑气一出，万物生灵争妖艳，让$n感慨！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"第三股五彩剑气一出，似口含蜜露的雀儿，飞舞、疾驰，让$n无奈！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                msg=HIW"第四股五彩剑气一出，醉看风落帽，舞爱月流人。让$n心痛！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                 
                msg=HIW"第五股五彩剑气一出，红颜弃轩冕，白首卧松云。让$n心慌！"NOR;
                 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);                 

        me->add_temp("apply/attack",-200	);
        me->add_temp("apply/damage",-3800);
        message_vision(HIC "\n但见寒光陡闪，$N手中"+weapon->query("name")+HIC"越使越快，如梦如幻，正是衡山派绝技"+HIW"「百变千幻衡山云雾十三式」"NOR+HIC"！\n" NOR, me, target);
        me->start_busy(1);
        me->set_temp("yunwu", 1);
        call_out("checking", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/4);

	
	
	
        me->add("neili", -100);
        //me->add("jing", -100);
        return 1;
}


void checking(object me, object target)
{

	object weapon;
if (!me)
return;
if (!me->query_temp("weapon"))
          {
                tell_object(me, "\n你手中没有持剑，「百变千幻衡山云雾十三式」的攻势便即瓦解！\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
	weapon = me->query_temp("weapon");

        if ( me->query_temp("yunwu")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n你手中没有持剑，「百变千幻衡山云雾十三式」的攻势便即瓦解！\n" NOR);
		me->delete_temp("yunwu");
                return;
           }


           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n你的"+weapon->name()+"已毁，无法持续「百变千幻衡山云雾十三式」的攻势！\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if ( (int)me->query("neili") < 400  ) {
                tell_object(me, "\n你的内力后继不足，难以持续「百变千幻衡山云雾十三式」的威力，好收缓剑招。\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "jiutian-sword" ) {
                tell_object(me, "\n你转而施展其他剑法，无法再以「百变千幻衡山云雾十三式」攻敌！\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n你现在没有和人过招，当下收回了「百变千幻衡山云雾十三式」的攻势。\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;

}  

void remove_effect(object me, int amount)
{

        if ( me->query_temp("yunwu") ) {
                message_vision(HIW"\n$N剑招渐缓，已将一套「百变千幻衡山云雾十三式」使完！\n" NOR, me);
        me->delete_temp("yunwu");
        }
}
