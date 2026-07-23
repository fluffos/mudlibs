#include <ansi.h>
#include <combat.h>

#define JUEHU "「" HIR "绝户神抓" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        
        object weapon;
        int ap, dp;
        string wn, msg;
	int extra;
	int i,a;
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(JUEHU "只能在战斗中对对手使用。\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("你必须空手才能使用" JUEHU "。\n");
        if( (int)me->query_skill("taiji-shengong", 1) < 180 )
                return notify_fail("你的本门内功功力太浅了。\n");
        if (userp(me) && me->query("shen") < 10000)
                return notify_fail(HIC "\n你恶念顿生，刚想施展毒招，可突然想到当初俞莲舟"
                                   "的一番告诫，不得不中途放弃了攻击。\n" NOR);

        if ((int)me->query_skill("juehu-shou", 1) < 120)
                return notify_fail("你的虎爪绝户手不够娴熟，难以施展" JUEHU "。\n");

        if (me->query_skill_mapped("claw") != "juehu-shou")
                return notify_fail("你没有激发虎爪绝户手，难以施展" JUEHU "。\n");

        if (me->query_skill_mapped("parry") != "juehu-shou")
                return notify_fail("你没有准备使用虎爪绝户手，无法使用" JUEHU "。\n");

        if (me->query("neili") < 300)
                return notify_fail("你现在真气不够，难以施展" JUEHU "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
	extra = me->query_skill("juehu-shou",1) / 20;
	extra += me->query_skill("taiji-shengong",1) /20;
a=extra/3;
if (a> 6) a=6;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	for(i=0;i<a;i++)
	{
         msg = HIR "$N双爪化出漫天爪影，向的要害抓去第"+(i+1)+"爪！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
me->add("neili", - 50 * i);      
        message_vision(HIM "$N" HIM "大喝一声，变掌为爪，双爪化出漫天爪影，如狂风骤雨一般向$n\n"
                     "的要害抓去！"NOR,
                     me, target);

        if (random(me->query_skill("unarmed")) > target->query_skill("parry") / 2)
        {
                me->start_busy(2);

                damage = me->query_skill("juehu-shou", 1);
                damage = damage * 3 + random(damage * 6);
target->add("qi",-damage);
target->add("eff_qi",-damage);
msg =  "\n"NOR;
	msg += RED HIR "结果$p" HIR "一声惨嚎，没能招架住$P"
                                           HIR "凌厉的攻势，被抓得皮肉分离，鲜血飞溅！\n" NOR;
if (random(6)==0 && target->query("gender")=="男性" && target->query("qi") < 200
&& me->query_skill("juehu-shou",1)> 350)
{
message_vision(HIY"\n$n要害处尽然硬生生被$N撕了下来！真是皮肉分离，鲜血飞溅\n" NOR, me,target);
target->set("gender","无性");
}
                me->add("neili", -400);
if ((int)me->query("shen") > 0)
        	me->add("shen", -5000);
        } else
        {
                me->start_busy(3);
	        me->add("neili", -400);
if ((int)me->query("shen") > 0)
        	me->add("shen", -5000);
                msg += CYN "可是$p" CYN "看破了$N"
                       CYN "的企图，躲开了这招杀着。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

