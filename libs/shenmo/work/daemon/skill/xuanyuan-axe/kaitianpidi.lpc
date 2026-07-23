 // tie@fengyun
#include <ansi.h>
#include <combat.h>
//inherit NPC;
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,a;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");

        extra = me->query_skill("xuanyuan-axe",1);
        if ( extra < 30) return notify_fail("你的轩辕斧法还不够纯熟！\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［开天辟地］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");

    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("你使用的武器不对。\n");

    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");
    
    extra=extra/3;
if (extra> 200) extra=200;    
        me->add_temp("apply/damage", extra);
a=extra/4;
if (a> 12) a=12;
        msg = HIY  "$N"+HIY"高高地举起手中的"+ weapon->name()+ HIY"集全身之内力，向$n"+HIY"猛然砸下！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	for(i=0;i<a;i++)
	{
       msg = HIC "开天辟地第"+(i+1)+"式 $N高举"+ weapon->name()+ HIC"向$n"+HIC"猛然砸下！\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili",-40);
	}
        me->add_temp("apply/damage", -extra);
       me->start_busy(3);
        return 1;
}
