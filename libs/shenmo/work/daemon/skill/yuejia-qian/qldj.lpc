// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER; 
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp,i,basic;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("yuejia-qian",1);
        if ( extra < 50) 
                return notify_fail("你的岳家中平枪法还不够纯熟！\n");
                

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［其力断金］只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 1500  ) 
		return notify_fail("你的内力不够。\n");

        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        if(random(hisexp) < myexp * 10 && weapon)        
        {
        message_vision(
HIW "\n\n$N使出一式其力断金，枪身似灵蝎般缠住$n手中的兵刃，"+ 
weapon->name()+  "脱手而飞！\n\n" NOR, me,target);
        if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 1000);
        msg = HIR+ "\n\n$N使出一式其力断金枪，手中的"+(me->query_temp("weapon"))->name()+"如灵蝎般直刺$n的$l！\n\n"+ NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);
        me->start_busy(2);
        }
        basic = extra/50;
        if (basic>9)
                basic=9;        
                for(i=0;i<basic;i++)
                {
                        msg = HIY"长笑声中，$N翻身一下回身枪，第"+chinese_number(i+1)+"枪！\n"NOR;
                        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        me->add("neili",-10);
                }
        return 1;
}