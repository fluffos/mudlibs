#include <ansi.h>
#include <combat.h>

#define CHUAN "「" HIM "柔月穿空" NOR "」"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string wn, msg;
	int extra;
	int i,a;
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(CHUAN "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" CHUAN "。\n");

        if (me->query_skill("force") < 150)
                return notify_fail("你的内功的修为不够，难以施展" CHUAN "。\n");
        if( (int)me->query_skill("taiji-shengong", 1) < 180 )
                return notify_fail("你的本门内功功力太浅了。\n");
        if (me->query_skill("raozhi-roujian", 1) < 100)
                return notify_fail("你的绕指柔剑修为不够，难以施展" CHUAN "。\n");

        if (me->query_skill_mapped("sword") != "raozhi-roujian")
                return notify_fail("你没有激发绕指柔剑，难以施展" CHUAN "。\n");

        if (me->query("neili") < 250)
                return notify_fail("你现在真气不够，难以施展" CHUAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

	extra = me->query_skill("raozhi-roujian",1) / 20;
	extra += me->query_skill("taiji-shengong",1) /20;
a=extra/3;
if (a> 6) a=6;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	for(i=0;i<a;i++)
	{
         msg = HIR "$N逆转剑锋，弯剌出第"+(i+1)+"剑！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", - 30 * i);         



        message_vision(HIM "\n只见$N" HIM "暮地里一声清啸，剑法忽变，那\n"
                     "柄" + wn + HIM "竟似成了一条软带，轻柔曲折，飘忽\n"
                     "不定，疾刺$n" HIM "胸膛，剑到中途，剑尖微颤，竟\n"
                     "然弯了过去斜刺$n" HIM "右肩，招式精奇之极。\n" NOR,
                     me, target);

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
target->add("qi",-damage);
target->add("eff_qi",-damage);
msg =  "\n"NOR;
	msg += RED "结果$p一个不慎，登被$P剑招刺中，"
                                          "一声惨嚎，鲜血飞溅而出。\n" NOR;

                me->start_busy(2);
                me->add("neili", -150);
        } else
        {
                msg = CYN "可是$p并不慌乱，收敛心神，轻轻格"
                      "挡开了$P的剑招。\n" NOR;
                me->start_busy(3);
                me->add("neili", -60);
        }
        message_vision(msg, me, target);

        return 1;
}
