//来去若无形 wuying.c
// by godzilla 99.03.06

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

//inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
        int extra;
        string msg;
        object obj;//对方兵器

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「分身无影」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("「分身无影」必须用剑才能施展。\n");

        if( (int)me->query_skill("wuying-jian", 1) < 150 )
                return notify_fail("你的「少林无影剑」不够娴熟，不会使用「分身无影」。\n");

        if( (int)me->query("neili") < 300  ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("wuying-jian", 1);
        extra = me->query_skill("wuying-jian",1) / 5;
        extra += me->query_skill("wuying-jian",1) / 5;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        //显示perform具体情况
        //me->set_temp("combat_env",me->query("env/skip_combat"));
        //me->set("env/skip_combat",0);
        //target->set_temp("combat_env",target->query("env/skip_combat"));
        //target->set("env/skip_combat",0);
        
        msg = HIG "$N身行突变，瞬间犹如分出无数身影闪电般的向$n攻去！\n"NOR;
        message_vision(msg, me, target);

        me->add("neili", -extra);

        msg = HIR"VV来字决！\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIY"VVVV去字决！\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIG"VVVVVV若字决！\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIB"VVVVVVVV无字决！\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIW"VVVVVVVVVV形字决！\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);

        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);

        if (skill< 800 )me->start_busy(3+random(2));
        else me->start_busy(2+random(2));
        //增加特效，砍兵器
        if (random(me->query("combat_exp"))>target->query("combat_exp")/2 
         && random(me->query_skill("sword"))>target->query_skill("dodge")/2
         && me->query_skill("wuying-jian",1)>500 
         && me->query_skill("yijin-jing",1)>500
         && objectp(target->query_temp("weapon"))){
                obj=target->query_temp("weapon");
                obj->unequip();
                message_vision(HIW "\n$N无影剑法使得兴起，剑气纵横捭阖，$n顿感无法招架！" NOR, me,target);
                message_vision(HIW "\n只听见「嚓」地一声，$N手中的" + obj->name()+ "已被砍成两段！\n" NOR, target);
                if ( obj->query("no_get") )
                  obj->move(environment(target));
                else
                {
                  obj->set("value", 0);
                  obj->set("name", "断掉的" + obj->query("name"));
                  obj->set("weapon_prop", 0);
                  obj->move(environment(target));
                }
                if (!target->is_busy()) target->start_busy(2);
                call_out("remove_broken_cloth",random(300)+60,obj);                     
        }
        //恢复combat设置                                                  
        //me->set("env/skip_combat",me->query_temp("combat_env"));        
        //target->set("env/skip_combat",target->query_temp("combat_env"));        
        return 1;
}


void remove_broken_cloth(object obj)
{
        if(obj && environment(obj)) {
                tell_object(environment(obj),"一阵微风吹过，"+obj->name()+"化为片片尘土，消失不见了。\n");
                destruct(obj);
        }
}

