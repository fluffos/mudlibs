// slj.c 云龙神龙剑决
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	int extra;
	string msg;
        string wname;
        int ap, dp;

	
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("神龙剑决只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
		
	if( (int)me->query_skill("yunlong-jian", 1) < 250 )
		return notify_fail("你的云龙剑法不够娴熟，不会使用「神龙剑决」。\n");
	                        
	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("你的云龙神功不够高。\n");

       if (((int)me->query_skill("bazhen-zhang", 1)) < 120)
               return notify_fail("你的八阵八卦掌太低了。\n");
               
       if (((int)me->query_skill("houquan", 1)) < 120)
               return notify_fail("你的猴拳太低了。\n");

       if (((int)me->query_skill("yunlong-zhua", 1)) < 120)
               return notify_fail("你的云龙爪太低了。\n");

       if (((int)me->query_skill("yunlong-shou", 1)) < 120)
               return notify_fail("你的云龙手太低了。\n");

       if (((int)me->query_skill("yunlong-shengong", 1)) < 120)
               return notify_fail("你的云龙神功太低了。\n");

       if (((int)me->query_skill("yunlong-shenfa", 1)) < 120)
               return notify_fail("你的云龙身法太低了。\n");

       if (((int)me->query_skill("baihua-cuoquan", 1)) < 120)
               return notify_fail("你的百花错拳太低了。\n");

       if (((int)me->query_skill("yunlong-jian", 1)) < 120)
               return notify_fail("你的云龙剑太低了。\n");

       if (((int)me->query_skill("wuhu-duanmendao", 1)) < 120)
               return notify_fail("你的五虎断门刀太低了。\n");

       if (((int)me->query_skill("yunlong-bian", 1)) < 120)
               return notify_fail("你的云龙鞭法太低了。\n");
               			
	if( (int)me->query("neili", 1) < 800 )
		return notify_fail("你现在内力太弱，不能使用「神龙剑决」。\n");
			
	extra = me->query_skill("yunlong-jian",1) / 15;
	extra += me->query_skill("yunlong-jian",1) /15;

	msg = HIM "$N" HIM "微微一笑，猛吸一口气，以气驭剑攻击虚虚实实的攻向$n"
              HIM "！\n" NOR;
        ap =  me->query_skill("sword");
        dp =  target->query_skill("force");
        
        if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("sword");

		me->add("neili", -180);
            
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIR "只见$N" HIR "手中剑光幻作一条金龙，腾空而"
                                           "起倏的罩向$n" HIR "，\n$p" HIR "只觉一股大力"
                                           "铺天盖地般压来，登时眼前一花，两耳轰鸣，哇的"
                                           "喷出一口鲜血！！\n" NOR;
		me->start_busy(2);
	} else
	{
		msg += CYN "可是$p" CYN "猛地向前一跃，跳出了$P"
                       CYN "的攻击范围。\n"NOR;
	}
	message_combatd(msg, me, target);             

	if (extra > 200) extra=200;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 1000);

        msg = HIG"＊风＊"NOR + "$N挥动手中$w，剑气狂风似地向$n的$l攻去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIW"＊雨＊"NOR + "$N快速移动身体，手中$w化做剑雨，将$n围在中间！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIB"＊雷＊"NOR + "$N纵身一越，手中$w雷鸣狂啸，猛向$n扑去！"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = CYN"＊电＊"NOR + "$N手中$w嗡嗡微振，幻成一条疾光刺向$n的$l"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC"＊云＊"NOR + "$N错步上前，剑意若有若无，$w淡淡地向$n的$l挥去"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIM"＊雾＊"NOR + "$N纵身轻轻跃起，剑光如轮疾转，霍霍斩向$n的$l";
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR"＊霜＊"NOR +  "$N手中$w中宫直进，无声无息地对准$n的$l刺出一剑"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = BLU"＊雪＊"NOR +  "$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，刺向$n的$l"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIY"＊天＊"NOR +  "$N手中$w斜指苍天，剑芒吞吐，对准$n的$l斜斜击出"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);




	me->add("neili",-280);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -1000);
if ((int)me->query_skill("yunlong-jian", 1)> 350)
{
       wname = weapon->name();

        damage = (int)me->query_skill("yunlong-jian", 1) / 2;
        damage += random(damage / 3);

        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");
        msg = HIG "$N" HIG "施出云龙剑法「清流剑」绝技，手中" + wname +
              HIG "随即一颤，对准$n" HIG "连攻数剑，招式凌厉无比！\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$p" HIR "奋力抵挡，却哪里招架得住，被$P"
                                           HIR "这一剑刺中要脉，鲜血四处飞溅！\n" NOR;

        } else
        {
                msg += CYN "$p" CYN "凝神聚气，硬声声将$P"
                       CYN "这一剑架开，丝毫无损。\n" NOR;
        }

        ap = me->query_skill("sword");
        dp = target->query_skill("force");
        msg += "\n" HIG "却见$N" HIG "跨步上前，手中" + wname +
               HIG "剑招陡变，又攻出一剑，剑尖顿闪出数道剑光，"
               "笼罩$n" HIG "全身！\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$p" HIR "只觉眼花缭乱，一时难以勘透其"
                                           "中奥妙，连中数剑，被削得血肉模糊！\n" NOR;
        } else
        {
                msg += CYN "可是$p" CYN "丝毫不为$P"
                       CYN "华丽的剑光所动，稳稳将这一剑架开。\n" NOR;
        }

        ap = me->query_skill("force");
        dp = target->query_skill("parry");
        msg += "\n" HIG "$N" HIG "随即一声大喝，身外化身，剑外化剑，手中"
               + wname + HIG "顿时漾起一道青芒，再次攻向$n" HIG "而去！\n"
               NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$p" HIR "运气抵挡，可只觉一股无形剑气"
                                           "透体而过，难受之极，喷出数口鲜血！\n" NOR;
        } else
        {
                msg += CYN "$p" CYN "一口气自丹田运了上来，$P"
                CYN "附体剑芒虽然厉害，却未能伤$p" CYN "分毫。\n" NOR;
        }
        me->add("neili", -80);
        message_combatd(msg, me, target);
}
	me->start_busy(4);
	return 1;
}
