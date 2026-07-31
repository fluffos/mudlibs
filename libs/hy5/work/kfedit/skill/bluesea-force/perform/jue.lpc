// jue.c 绝仙决
 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER; 
int perform(object me, object target)
{
	string msg;
	int ap, dp;
        int damage;
        int lvl,i,j;
        //mixed dp;        
        
lvl=me->query_skill("bluesea-force", 1);
        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("绝仙决只能对战斗中的对手使用。\n");
 
	if (me->query_skill("bluesea-force", 1) < 200)
		return notify_fail("你的南海玄功还不够娴熟，不能使用绝仙决！\n");

        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("你使用的内功不对。\n");


        if (me->query("neili") < 800)
                return notify_fail("你的内力不够，不能使用绝仙决！\n");
 
       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "哈哈大笑，绝仙决 一掌挥出，变化出满天掌影，封住了$n"
              HIC "所有的退路！\n" NOR;
 


        ap = me->query_skill("strike") + me->query("con") * 20;
        dp = target->query_skill("force")+ target->query("dex") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "然而$n" HIG "看破了$N" HIG
                       "的掌势，不慌不忙的躲过了这一击！\n" NOR;
        } else
	{
		me->add("neili",-75);
                        damage = me->query_skill("force")+100;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);

                msg += HIR "$n" HIR "$n" HIR "竭力腾挪躲闪，却听“啪”的"
                                           "一声被$P" HIR "结结实实的打在了胸前，登"
		                           "时吐血不止！\n" NOR;
	}

	message_combatd(msg, me, target);

if (lvl>=300  || !userp(me))
{
msg = HIC "$N" HIC "嘿然冷笑，戮仙决 决 拍出一掌，吞吞吐吐，变化莫测，攻向$n"
              HIC "！\n" NOR;
 
        ap = me->query_skill("force") + me->query("con") * 20;
        dp = target->query_skill("parry")+ target->query("con") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "然而$n" HIG "看破了$N" HIG
                       "的掌势，不慌不忙的躲过了这一击！\n" NOR;
        } else
	{
		me->add("neili",-75);
                        damage = me->query_skill("force")+300;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);

                msg += HIR "$n" HIR "不明所以，运功抵挡，只觉得$P的掌力怪"
                                           "异之极，直渗入至奇经八脉，登时受了内伤！\n" NOR;
		                           
	}

	message_combatd(msg, me, target);	
	
}	


if (lvl>=600  || !userp(me))
{
msg = HIC "$N" HIC "面容肃穆，斩仙决 倏的一掌拍出，虚虚实"
              "实的攻向$n" HIC "，变化令人难以捉摸。\n" NOR;
 
        ap = me->query_skill("force") + me->query("con") * 20;
        dp = target->query_skill("parry")+ target->query("str") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "然而$n" HIG "看破了$N" HIG
                       "的掌势，不慌不忙的躲过了这一击！\n" NOR;
        } else
	{
		me->add("neili",-75);
damage = me->query_skill("force")*2+600;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);

                msg += HIR "$n" HIR "稍一犹豫，被这一掌击了"
                                           "个正中！接连退了几步，吐了一地的血。\n" NOR;
	}

	message_combatd(msg, me, target);
	
}	


if (lvl>=900  || !userp(me))
{
msg = HIC "$N" HIC "随手拍出一掌，诛仙决 疾若奔马，如箭一般飞向$n"
              HIC "速度快的不可思议！\n" NOR;
 
        ap = me->query_skill("force") + me->query("con") * 20;
        dp = target->query_skill("parry")+ target->query("int") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "然而$n" HIG "看破了$N" HIG
                       "的掌势，不慌不忙的躲过了这一击！\n" NOR;
        } else
	{
		me->add("neili",-75);
               damage = me->query_skill("force")*3+1000;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                target->start_busy(3);
                msg += HIR "$n" HIR "正在思虑这一掌的后势，掌力已至"
                                           "胸前，只听“噗”的一声，$n吐血三尺！\n" NOR;

	}

	message_combatd(msg, me, target);

msg = HIC "$N" HIC "轻轻划了个圈子，身形忽然变快，合数招为一击攻向$n"
              HIC "！\n" NOR;
        i = 6;

                msg += HIY "内力激荡之下，$n" HIY "登时觉得呼吸"
                       "不畅，浑身有如重压，万分难受，只见$N"
                       HIY "一掌接一掌的攻到，有如海浪。\n" NOR;
	message_combatd(msg, me, target);
                me->add_temp("apply/attack", 100);
                me->add_temp("apply/damage", 1000);
        j=1;
        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 4 && ! target->is_busy())
                        target->start_busy(1);
	msg = HIR "$N击出诛仙 第"+ chinese_number(j) +" 式！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        j=j+1;
        }

                me->add_temp("apply/attack", -100);
                me->add_temp("apply/damage", -1000);
	
}

if (lvl>=1000 || !userp(me))
{
msg = HIC "$N" HIC "暴喝一声，变掌为爪，五阴焚灭 迅捷无比的袭向$n！\n";

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
        
        if (ap * 2 / 3 + random(ap) > dp)
        {
                ap = me->query_skill("bluesea-force");
                dp =  target->query_skill("parry",1);
	        me->add("neili", -60);
	        me->start_busy(1 + random(2));

	        
                // if (dp >= 10000)
                if (me->query("max_neili") < target->query("max_neili") * 2) 
                {
                        damage = me->query_skill("strike")+100;

                target->add("qi",-damage);
		target->add("eff_qi",-damage);

                msg += HIR "$n" HIR "只觉此招，阴柔无比，诡异莫测，"
                                        "心中一惊，却猛然间觉得一股阴风透骨而过。\n" NOR;


                        me->add("neili", -140);

                        message_combatd(msg, me, target);
                        // target->start_busy(1 + random(2));
                        return 1;
                } else
                {
                damage = (int)target->query("qi")/3;
                if (damage>80000) damage=80000;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                	
                        msg += HIR "这一招完全超出了$n" HIR "的想象，被$N"
                                HIR "结结实实的抓中了气海穴，浑身真气登时涣散！\n" NOR;
                        message_combatd(msg, me, target);


                        return 1;
                }
        } else
        {
                msg += HIM "$n" HIM "大吃一惊，连忙胡乱抵挡，居"
                                "然没有一点伤害，侥幸得脱！\n" NOR;
                
                me->start_busy(3);
        }
me->start_busy(2);
        message_combatd(msg, me, target);

}
me->start_busy(2);
	return 1;
}
