// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chan.c 灵蛇缠身

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp,damage,lvl,count,i;
        string type;         
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「灵蛇缠身」只能对战斗中的对手使用。\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("运用「灵蛇缠身」手中必须持杖！\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("你的内功火候不够！\n");

        if ((int)me->query_skill("staff") < 80)
                return notify_fail("你的杖法还不到家，无法使用「灵蛇缠身」！\n");

        if ((int)me->query_skill("lingshe-zhangfa",1) < 280)
                return notify_fail("你的灵蛇杖法还不到家，无法使用！\n");

        if ((int)me->query_skill("xiyu-tiezheng",1) < 180)
                return notify_fail("你的西域铁筝音还不到家，无法使用！\n");

        if ((int)me->query_skill("shentuo-zhang",1) < 180)
                return notify_fail("你的神驼雪山掌还不到家，无法使用！\n");
        if ((int)me->query_skill("chanchu-bufa",1) < 180)
                return notify_fail("你的蟾蜍步法还不到家，无法使用！\n");
        if ((int)me->query_skill("hamashengong",1) < 180)
                return notify_fail("你的蛤蟆神功还不到家，无法使用！\n");
        if ((int)me->query_skill("lingshe-quan",1) < 180)
                return notify_fail("你的灵蛇拳还不到家，无法使用！\n");
        if ((int)me->query_skill("qixian-wuxingjian",1) < 180)
                return notify_fail("你的七弦无形剑还不到家，无法使用！\n");
        if ((int)me->query_skill("shexing-diaoshou",1) < 180)
                return notify_fail("你的蛇形刁手还不到家，无法使用！\n");
                                                                                                
	if ((int)me->query("neili") < 500)
		return notify_fail("你现在的真气不够！\n");
        if (target->is_busy())
                return notify_fail("对方正忙着呢，你还是加紧进攻吧！\n");
                
        if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIG "$N" HIG "手中的" + weapon->name() +
              HIG "不住的颤动，活现一条灵蛇，缠向$n" HIG "，难以捉摸。\n" NOR;

        ap =  me->query_skill("staff",1); 

        dp =  target->query_skill("dodge",1); 
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIY "$n" HIY "仓皇之下只有严守门户，无暇反击！\n" NOR;
                target->start_busy(ap / 100 + 2);
        } else 
        {
                msg += HIC "可是$p" HIC "看破了$N" HIC
                       "的虚招，巧妙的运用身法躲过了$P的攻击！" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
type="毒蛇";		
if (random(3)==0) type="怪蛇";
if (random(3)==0) type="灵蛇";
if (random(3)==0) type="毒蛇";		
message_vision(HIB"\n$N将"+weapon->name()+HIB"一抖，杖上金环当啷啷一阵乱响，一条"+type+HIB"从杖底直盘上来。\n"NOR,me);
	        ap = me->query_skill("staff");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap);
                me->add("neili", -100);
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);
                        target->add("qi",-damage+100);
                        target->add("qi",-damage/2+100);
msg =                    HIR"祗见"+weapon->name()+HIR"从$n眼前掠过，缠杖盘旋的一条"+type+HIR"吞吐伸缩，猛然张口咬中$n，狰狞诡异之极！\n"NOR;
		me->start_busy(2);
                target->start_busy(1);
	} else 
	{
		msg += CYN "$n" CYN "奋力招架，总算抵挡住了$P"
                       CYN "的攻击！\n" NOR;
                me->add("neili", -80);
		me->start_busy(2);
                target->start_busy(1);
	}
	message_combatd(msg, me, target);


      msg = HIW "$N" HIW "大喝一声，扑身上前，手中的" + weapon->name() +
              HIW "化作万道光芒，一齐射向$n" HIW "！\n" NOR;

        if (lvl / 2 + random(lvl) > target->query_skill("parry") * 2 / 3)
        {
                msg += HIY "$n" HIY "见$N" HIY "把" + weapon->name() +
                       HIY "使得活灵活现，犹如真物一般，实在是难以抵挡，只有后退。\n" NOR;
                count = lvl / 7;
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);

        } else
                count = 0;

        message_combatd(msg, me, target);
        me->add("neili", -100);
                me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 800);

        //for (i = 0; i < 7; i++)
        //{
         //       if (! me->is_fighting(target))
         //               break;
                if (random(3==0) && ! target->is_busy())
                        target->start_busy(2);
	 msg =  YEL  "$N身形加快，所到之处，狂风四起！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  YEL  "$N突如起来的从狂风中闪出，对着$n胸前就是一杖！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N御杖回身，立于$n身侧，反手一劈！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N借力打力，一个纵身，居高临下，当头又是一杖！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "人在半空，$N化虚为掌，化实为杖，朝$n点刺过去！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL "$N持杖乱舞，密不透风，使$n渐渐感到透不过气来！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = YEL "$N见有机可乘，一杖接着一杖，招招致命！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = YEL "$N聚起天地之灵气，手中的"+ weapon->name() +"卷起千层大浪朝$n挥去！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        //}

        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -800);
        me->start_busy(2);
if (random(3)==0 && (int)me->query_skill("lingshe-zhangfa",1) > 300
&& (int)me->query_skill("zhaosheshu",1) > 200
&& (int)me->query_skill("yangsheshu",1) > 200)
{
	message_combatd(
        HIW "$N用蛤蟆功射出白蛇山独门怪蛇粉，射中了$n的全身！
$n被一团蛇雾笼罩，$n心口一阵巨痛！\n" NOR, me, target);
target->apply_condition("baituo_poison",50);
}

        return 1;
}

