// duo.c 空手入白刃
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp, damage,ap;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query_temp("duo") )
		return notify_fail("你已经在夺敌人的兵刃了。\n");
	skill = me->query_skill("zhemei-shou",1);

	if( !(me->is_fighting() ))
		return notify_fail("空手入白刃只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手。\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
	   return notify_fail("对方没有兵刃，你不用担心。\n");

	if( skill < 50)
		return notify_fail("你的天山折梅手等级不够, 不能空手入白刃！\n");

        if (((int)me->query_skill("bahuang-gong", 1) < 50) &&
            ((int)me->query_skill("beiming-shengong", 1) < 50 ))
        return notify_fail(RED"你本门内功火候不够，使不出「空手夺白刃」。\n"NOR);

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，无法空手入白刃！\n");
 
	msg = CYN "$N凝神闭息，打算施展空手入白刃的绝技. \n";
	message_combatd(msg, me);
     if( weapon2->query("ownmake"))
                return notify_fail("这个武器好像夺不下来！\n");
     if( weapon2->query("no_get") && weapon2->query("no_drop") )
                return notify_fail("这个武器好像夺不下来！\n");

	dp = target->query_skill("dodge",1);
	if( dp < 1 )
		dp = 1;
	if( random(skill) > random(dp) )
	{
		if(userp(me))
			me->add("neili",-50);
if (!weapon2->query("systemmake") && !weapon2->query("ownmake"))
{
		msg = "$N使出空手入白刃的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
		target->start_busy(2);
		weapon2->move(environment(me));

		if (weapon2->query("ownmake")==1)
		{
			weapon2->move(target);
			msg += "那可是$n的随身家伙！$n手一伸将它捡回来。\n" NOR;
		}
		
		me->start_busy(2);
}		
	}
	else
	{
		msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);


if( (int)me->query_skill("liuyang-zhang", 1) > 200 )
{
 msg = HIB "$N" HIB "挥手疾舞，施出逍遥折梅手「海渊式」，手法"
              "缥缈，虚虚实实罩向$n" HIB "要害。\n" NOR;

        me->add("neili", -50);
        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        if (ap / 2 + random(ap) > dp  || random(3)==0)
        {
                damage = me->query_skill("hand",1)+200;
                me->add("neili", -100);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "霎时漫天掌影化为一抓，$p" HIR "闪"
                                           "避不及，被$N" HIR "五指插入胸膛，鲜血"
                                           "四处飞溅！\n" NOR;


                me->start_busy(2);
        } else 
        {
                me->add("neili", -50);
                msg += HIC "可是$p" HIC "身手敏捷，身形急转，巧妙的躲过了$P"
                       HIC "的攻击。\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
}	

if( (int)me->query_skill("liuyang-zhang", 1) > 300 )
{
msg = HIC "$N" HIC "双手虚虚实实的抓向$n"
              HIC "的要害，身法缥缈，手式奇特，令人难以捉摸。\n" NOR;

        ap = me->query_skill("hand") + me->query("str") * 20;
        dp = target->query_skill("dodge") + target->query("dex") * 20;
             
        if (ap / 2 + random(ap) > dp || random(3)==0)
	{
		damage = me->query_skill("hand",1)+100;

  target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "一个闪避不及，结果被$P"
                                           HIR "抓了个正中，浑身内息不由得一滞，气血翻涌。\n" NOR;

		me->start_busy(2);
	} else 
	{
		msg += HIC "可是$p" HIC "身手敏捷，巧妙的躲过了$P"
                       HIC "的攻击！\n"NOR;

		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}
	return 1;
}
