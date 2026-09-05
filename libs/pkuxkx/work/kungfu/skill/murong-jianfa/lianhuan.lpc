// Modified by iszt@pkuxkx, 2007-02-25

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me,object target)
{
 int i=me->query_skill("murong-jianfa",1)/5;
    int j=me->query_skill("canhe-zhi",1)/5;
    int d=me->query_skill("shenyuan-gong",1)/5;
        object weapon = me->query_temp("weapon");
        string msg;
        mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "murong-jianfa" ]),//高级技能名称
            ]);
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character()|| !me->is_fighting(target) )
                return notify_fail("七剑连环指只能对战斗中的对手使用。\n");


        if( (int)me->query_skill("murong-jianfa", 1) < 100 )
                return notify_fail("你的剑法还未练成，不能使用七剑连环指！\n");
        if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("你手里没有剑，无法使用七剑连环指！\n");
/*        if (me->query_skill_mapped("sword") != "murong-jianfa")
                return notify_fail("你没有用慕容剑法，无法使出七剑连环指！\n"); */
        if((int)me->query_skill("canhe-zhi", 1) < 100 )
                return notify_fail("你的指法还未练成，不能使用七剑连环指！\n");
/*        if(me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("你没有用参合指，无法使用七剑连环指！\n");  */
        if((int)me->query("neili") < 500 )
                return notify_fail("你现在内力不足，不能使用七剑连环指！\n");
        if((int)me->query_temp("lianhuan"))
                return notify_fail("你正在使用七剑连环指！\n");
        if((int)me->query_skill("sword", 1) < 100 )
                return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用七剑连环指。\n");
        if((int)me->query_skill("finger", 1) < 100 )
                return notify_fail("你的基本指法不够娴熟，不能在剑招中使用七剑连环指。\n");
        msg = MAG"\n$N"MAG"使出七剑连环指，剑锋一转，右手食指跟着弹出，只见剑花指风相辉相映，直袭$n"MAG"！\n"NOR;
        me->add("neili", -50);
        me->add("jing", -50);
//        me->set_temp("lianhuan", 2+me->query_skill("murong-jianfa", 1)/40);
        me->set_temp("lianhuan", 3);
         me->add_temp("apply/attack", (i+j)*3/4);
    	me->add_temp("apply/damage", d);
        message_vision(msg, me, target);
		me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
          call_out("check_fight", 1, me,target);
        return 1;
}

void remove_effect(object me)
{
    int i=me->query_skill("murong-jianfa",1)/5;
    int j=me->query_skill("canhe-zhi",1)/5;
    int d=me->query_skill("shenyuan-gong",1)/5;
         me->add_temp("apply/attack", - (i+j)*3/4);
    me->add_temp("apply/damage", -d);
    me->delete_temp("lianhuan");
    me->start_busy(5);
      }

void check_fight(object me, object target)
{
    string msg;
    object weapon;
    mapping attack_val1 = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "murong-jianfa" ]),//高级技能名称
            ]);
    mapping attack_val2 = ([
            "base": ([ "no_weapon" : "finger" ]),//基本功夫类型
            "skill" : ([ "no_weapon" : "canhe-zhi" ]),//高级技能名称
            ]);

    if (!me) return;
    if (!target) 
    {
    	remove_effect(me);
    	return;
    }
    weapon = me->query_temp("weapon");
    if (!me->is_fighting() || me->query_temp("lianhuan") < 1 || me->is_busy())
    {
    tell_object(me, HIY"你的「七剑连环指」绝技运行完毕，气回丹田,缓缓收功。\n"NOR);
    remove_effect(me);
    return;
    }
/*   if (me->query_skill_mapped("finger") != "canhe-zhi"
     ||me->query_skill_prepared("finger") != "canhe-zhi")
     {
   tell_object(me, HIR"你临时改换武功,决定不再使用「七剑连环指」绝技。\n"NOR);
   remove_effect(me);
   return;
    } 
    if(me->query_skill_mapped("sword") != "murong-jianfa" || !weapon)
     {
   tell_object(me, HIR"你临时改换武功,决定不再使用「七剑连环指」绝技。\n"NOR);
   remove_effect(me);
   return;
    }*/
        weapon->unequip();
     	msg = YEL"$N拿剑之手背到身后，另一只手使出参合指法，向$n点去！\n"NOR;
        message_vision(msg, me, target);
		me->set_temp("attack_val", attack_val2);
        COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
        if ( !weapon )
        {
        	remove_effect(me);
          return;
        }
        weapon->wield();
      	msg = YEL"$N收指换剑，剑尖直指$n！\n"NOR;
        message_vision(msg, me, target);
		me->set_temp("attack_val", attack_val1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        me->add_temp("lianhuan", -1);
        call_out("check_fight", 1, me, target);
}
