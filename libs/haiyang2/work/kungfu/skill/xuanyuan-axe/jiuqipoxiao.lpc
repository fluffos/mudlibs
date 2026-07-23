#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("xuanyuan-axe",1);
        if ( extra < 250) return notify_fail("你的轩辕斧法还不够纯熟！\n");
        
        

        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［九气破霄］只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("你使用的武器不对。\n");

    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");
                
                
        weapon = me->query_temp("weapon");
extra=extra/3;
if (extra> 200) extra=200;
        me->add_temp("apply/attack",extra);
		me->add_temp("apply/damage",2000);
        msg = HIY  "$N手中的"+ weapon->name()+HIY"舞动的速度愈来愈快，吼声愈来愈大\n吼声中"+weapon->name()+HIY"突然雷霆霹雳般向$n"NOR+HIY"劈出一式『九气破霄』！！！\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "电光！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "火石！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "撼三山！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIB  "震五岳！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIC  "破九霄！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIC"$N突然暴喝一声，将手中巨斧斜向上举起，然后在半空中划出一
道圆弧，随即径直斜下斩向$n！这一瞬间，$n只觉得呼吸都停止了！\n"NOR;
if (random(2)==0) target->start_busy(3);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC"$N跳起将手中巨斧斜向上举起，在半空中划出一
道圆弧，随即径直斜下斩向$n！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC"$N转身将手中巨斧斜向上举起，在半空中划出一
道圆弧，随即径直斜下斩向$n！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

me->add("neili",-390);
        me->add_temp("apply/attack",-extra);
		me->add_temp("apply/damage",-2000);

                me->start_busy(3);
        return 1;
}     
