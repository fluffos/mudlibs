// da.c 打蛇打七寸

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
	string msg;
	int lvl,b1,b2;
 
	weapon = me->query_temp("weapon");

        if( !target )
		return notify_fail("你要打哪条蛇？\n");

        if ( target->query("race")!="野兽")
                return notify_fail("看清楚些，那不是蛇，你瞎搞什么？\n");

	if( strsrch(target->query("name"), "蛇")<0)
                return notify_fail("看清楚些，那不是蛇，你瞎搞什么？\n");		
	if( target->query("owner"))
                return notify_fail("看清楚些，那不是蛇，你瞎搞什么？\n");		
                
         if( (int)me->query_skill("wudu-shengong",1) < 10 )
                return notify_fail("你的五毒神功修为还不够！\n");

        if( !living(target) )
                return notify_fail("那条蛇暂时不会动弹了，你不必再打了。\n");

	if( (int)me->query_skill("shedu-qiqiao", 1) < 20 )
		return notify_fail("你的蛇毒奇巧还不够娴熟, 不能打蛇 !\n");

	if( (int)me->query_skill("force") < 30 )
		return notify_fail("你的内功的修为不够, 不能打蛇 !\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你现在的内力不够！\n");

        if( weapon )
                msg = HIG "\n$N舞动手中的" + weapon->name() + "，朝着" +
                      target->name() + "的七寸打了过去。\n" NOR;
        else
                msg = HIG "\n$N伸出双指，迅跻无比的朝着" +
                      target->name() + "的七寸点了过去。\n" NOR;

        lvl = (int) me->query_skill("shedu-qiqiao", 1) +
              (int) me->query_skill("dodge");
        lvl = lvl * lvl / 10 * lvl;
        if( lvl / 2 + random(lvl) > (int) target->query("combat_exp") )
        {
                msg += HIM "“啪”的正打在" + target->name() + "的七寸上。\n";
                lvl = (int) me->query_skill("force");
                lvl = lvl * 13 / 10;
                lvl = lvl * lvl / 10 * lvl;
                if ( lvl / 2 + random(lvl) > (int) target->query("combat_exp") )
                {
                        msg += HIM + target->name() + "身子轻轻晃动几下，就不再动弹。\n" + NOR;
                        message_vision(msg, me);
   if (target->query("qi") > 30000)
{
target->add("qi",-25000);
target->add("eff_qi",-25000);
}else target->unconcious();
                } else
                {
                        msg += HIW + "哪里想到" + target->name() + "挨了这一击，"
                               "竟然若无其事！！！\n\n" + NOR;
                        message_vision(msg, me);
                        target->kill_ob(me);
                }
        } else
        {
                msg += HIW "然而" + target->name() + "身子一闪，躲了过去。\n\n" NOR;
                message_vision(msg, me);
                target->kill_ob(me);
        }


	me->add("neili", -50);
	me->start_busy(2);

	return 1;
}
