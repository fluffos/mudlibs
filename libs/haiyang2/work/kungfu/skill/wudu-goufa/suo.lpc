// suo.c  金钩锁魂
// by star
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	 object ob,weapon,myweapon;
        string msg, string1;
        int skill,myskill;
	int extra;

	if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("「金钩锁魂」只能在战斗中使用。\n");

       if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("「金钩锁魂」只能对战斗中的对手使用。\n");

 	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("「金钩锁魂」开始时必须拿着一把剑！\n");
     
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("wudu-shengong",1) < 50 )
                return notify_fail("你的五毒神功修为还不够！\n");

	if( (int)me->query_skill("sword",1) < 50 ||
	    me->query_skill_mapped("sword") != "wudu-goufa")
		return notify_fail("你的五毒钩法还不到家，无法使用金钩锁魂！\n");

	if( (int)me->query_skill("wudu-goufa",1) < 50 )
		return notify_fail("你的五毒钩法还不到家，无法使用金钩锁魂！\n");
 	if (!objectp(weapon = target->query_temp("weapon"))
 	&&(int)me->query_skill("wudu-goufa",1) >150 )
{
 weapon = me->query_temp("weapon");
	extra = me->query_skill("wudu-goufa",1) / 3;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
         msg = HIY "天蝎藏针！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "金蛇缠腕！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "神蟾九变！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "万毒至尊! \n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "灵蛇吐信！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "张牙舞爪！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
            me->add("neili",-200);
            me->start_busy(3);
return notify_fail(HIR"对方手中并没有兵器！你只能停止了攻击\n"NOR);
}
 	if (!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("对方手中并没有兵器！\n");

       weapon=target->query_temp("weapon");
       myweapon=me->query_temp("weapon");
	extra = me->query_skill("wudu-goufa",1) / 3;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
         msg = HIY "天蝎藏针！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "金蛇缠腕！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "神蟾九变！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "万毒至尊! \n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "灵蛇吐信！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
         msg = HIY "张牙舞爪！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
//message_vision(msg, me,target);
 	message_vision(HIR "\n$N虚晃一招，手中"+myweapon->query("name")+"忽的一沉，钩尖已搭在$n的"+weapon ->query("name")+HIR"上！\n" NOR,me,target);
       skill = target->query_skill("parry",1);             // 32
       myskill = me->query_skill("wudu-goufa",1);
       if(random(myskill) < random(skill/2)||me->query("max_neili") <random(target->query("max_neili"))){
	     msg = HIY "可是$n早有准备，急忙收招跳开！\n" NOR;
            message_vision(msg, me,target);
            me->start_busy(3);
            me->add("neili",-200);
            return 1; 
       }
 
	msg = HIR "只见$N顺势一绞，低喝一声：“撒手！”$n只觉得虎口一阵巨痛，\n手中"+weapon->query("name")+HIR"当啷一声掉在地上！\n" NOR;
       message_vision(msg,me,target);
	msg = "$N哈哈一笑，得理不饶人，招招进逼！\n" NOR;
       message_vision(msg, me,ob);
	me->clean_up_enemy();
	ob = me->select_opponent();
       weapon->move(environment(me));
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
               target->apply_condition("snake_poison",
                        (int)target->query_condition("snake_poison") + 50 );
               target->apply_condition("wugong_poison",
                        (int)target->query_condition("wugong_poison") + 50 );
               target->apply_condition("zhizhu_poison",
                        (int)target->query_condition("zhizhu_poison") + 50 );
               target->apply_condition("xiezi_poison",
                        (int)target->query_condition("xiezi_poison") + 50 );
               target->apply_condition("chanchu_poison",
                        (int)target->query_condition("chanchu_poison") + 50 );
	msg = HIY"$N使出了五毒大法，$n只觉得伤处一阵发麻，似乎中毒了。\n" NOR;
       message_vision(msg, me,ob);
}
	me->add("neili", -300);
	me->start_busy(3);
	return 1;
}