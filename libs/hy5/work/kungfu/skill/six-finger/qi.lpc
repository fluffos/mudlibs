// qi.c 无形剑气

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("无形剑气只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("force") < 360)
                return notify_fail("你的内功火候不够，使不出无形剑气。\n");

        if ((int)me->query_skill("six-finger", 1) < 180)
                return notify_fail("你的六荬神剑不够熟练，不会使用无形剑气。\n");

        if (me->query("max_neili") < 8000)
                return notify_fail("你的内力修为还不足以使出如此犀利的无形剑气。\n");
        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("你的枯荣禅功太低。\n");
        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法使用无形剑气。\n");

        if (me->query_skill_mapped("finger") != "six-finger")
                return notify_fail("你没有激发六脉神剑，无法使用无形剑气。\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIC "$N" HIC "中指一按，一股凌厉无伦的无形剑气直奔$n" HIC "胸前射去。\n" NOR;  

        ap = me->query_skill("force");
        dp = target->query_skill("force");
        weapon = target->query_temp("weapon");
        me->start_busy(2);
if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        { 
                damage = ap*2+200;
                me->add("neili", -200);
                if (! objectp(weapon) || weapon->query("skill_type") == "pin")
{
	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage*2,me);
                msg +=HIR "只觉得胸前一阵剧痛，鲜血"
                                                   "自创口激射而出，眼前顿时一黑！\n" NOR;
 }
                else
                if (weapon->query("ownmake") || weapon->query("damage") > 800 ||
                    weapon->query("skill_type") == "hammer")
{
	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage*2,me);
                msg +=HIR "$p" HIR "横" + weapon->name() + HIR "试图招架，"
                                                   HIR "怎奈这股剑气如此犀利，透过" + weapon->name() +
                                                   HIR "直震得$p" HIR "狂吐鲜血，五脏六腑都要翻转过来！\n" NOR;
}
                else
                {
                	if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
target->receive_damage("qi", damage*2,me);
target->receive_wound("qi", damage*2,me);
                msg +=HIR "$p" HIR "横转" + weapon->name() + HIR "，挡在胸"
                                                   "前，只听啪啦一声，" + weapon->name() +
                                                   HIR "碎成数截，激飞上天！\n$n" HIR "连退"
                                                   "几步，“哇”的吐了一口鲜血，脸色变的惨白。\n" NOR;
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{

                        weapon->move(environment(me));
}
                }
        } else
        {
                msg += CYN "可是$p" CYN "内功颇为深厚，轻轻将这道剑气化解于无形。\n" NOR;
        }
        message_combatd(msg, me, target);


me->add_temp("apply/attack",150);
	me->add_temp("apply/damage",2200);
	weapon = me->query_temp("weapon");

        msg = CYN "$N心思涣乱，朝$n隔空遥指了几下，不料却使出了六脉剑法的精髓"HIY"[六脉惊神]"CYN"！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------------------------少商剑！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = GRN   "-------------------------------商阳剑！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  MAG  "-------------------------------中冲剑！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL   "-------------------------------关冲剑！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT   "-------------------------------少泽剑！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU   "-------------------------------少冲剑！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-150);
	 me->add_temp("apply/damage",-2200);


        return 1;
}

