// 佛轮转
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
	int extra;
        int count;
	object *inv;
	int skill, ap, dp, equip,damage;
	int neili_wound, qi_wound ;
  if( !target ) target = offensive_target(me);
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("兵器不是这个！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("huoyan-dao", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

       if( !wizardp(me) &&(int)me->query_skill("riyue-lun", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("longxiang", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "longxiang")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

        msg = HBWHT "$N贯通雪山武学，使出了雪山的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);   
	extra = me->query_skill("riyue-lun",1);
        me->add_temp("apply/strength", extra/3);
	me->add_temp("apply/attack", extra/2);	
	me->add_temp("apply/damage", extra);
	msg = HIY "$N纵跃退後，立时呜呜、嗡嗡、轰轰之声大作，金光闪闪，银光烁烁，五只轮子从五个不同方位飞袭出来！" NOR;
	damage = (int)me->query_skill("longxiang", 1);
	if (random(2)==0) target->start_busy(3);
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	                 target->receive_wound("qi", random(damage));
	 msg =  HIC  "$N伸手搭在法轮上往斜里一拨，法轮在空中划出一道弧线，向$n飞去。" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 	         target->receive_wound("qi", random(damage));
	 msg =  HIR  "$N吐气发力，双掌齐推，法轮去势劲急，呜的一声冲向$n。 " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	                 target->receive_wound("qi", random(damage));
	 msg =  YEL  "$N双手箕张，拦在$n身前，法轮在空中旋转而回，袭向$n的后脑。 " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		          target->receive_wound("qi", random(damage));
	msg =  BLU   "$N霹雳般一声断喝，侧身单拳硬生生击在法轮上，法轮方向猛的一转，直追向$n。" NOR;
	                 target->receive_wound("qi", random(damage));
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	                 target->receive_wound("qi", random(damage));              
        me->add_temp("apply/strength", -extra/3);
	me->add_temp("apply/attack", -extra/2);
	me->add_temp("apply/damage", -extra);
        message_vision(RED"\n$N祭起火焰刀之「红莲火」绝技，精纯的内力呈红色缓缓涌出，于身前三尺之处，便即停住不动，
将这飘荡无定的真气定在半空，它虽是虚无缥缈，不可捉摸，却能杀人于无形，实是厉害不过！\n"NOR,me);

        msg = HIC "$N聚气于掌，使出一招「焚心以火」，向$n的胸口击去。\n"NOR;

	ap = me->query("combat_exp") + skill * 200;
	dp = target->query("combat_exp") / 3;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{


		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		
                qi_wound = target->query("qi") - 100;
if (qi_wound <100) qi_wound=100;
if (neili_wound <100) neili_wound=100;
		target->receive_damage("qi", qi_wound/3);
		target->receive_wound("qi", qi_wound/3);
		target->add("neili", -neili_wound/3);

		inv = all_inventory(target);
msg += HIR "$n只觉得眼前一黑，一阵热焰扑面而来，“哇”的一声喷出一口鲜血！\n"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
msg += HIR "$n闻到一股焦味，发现身上的"+inv[equip]->query("name")+HIR"已被烧得残破不堪，掉在了地上！\n"NOR;
			inv[equip]->unequip();
			inv[equip]->reset_action();
			inv[equip]->move(environment(target));
			inv[equip]->set("name", inv[equip]->query("name") + "的碎片");
			inv[equip]->set("value", 0);
			inv[equip]->set("armor_prop", 0);
			inv[equip]->set("long", "一堆破碎物事，好象是布片铁片什么的。\n");
			}
		}
	}
	else
	{
msg += HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;

	}
	message_combatd(msg, me, target);
	me->start_busy(4);
	return 1;
}
