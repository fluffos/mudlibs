//jianyi.c 太级剑意

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
private int remove_effect(object me,object weapon);

int exert(object me, object target)
{
        object weapon;
        int skill, skill1; 

        if( me->query_temp("jianyi") )
                 return notify_fail("你已在使用太极剑意了！\n");

        if( !objectp(weapon = me->query_temp("weapon") ) )
                 return notify_fail("你未持武器，如何能够以太极剑意附注剑身？\n");

        if( me->query_skill("force") < 150 )
                 return notify_fail("你的太极神功境界未到，无法领会太级剑意！\n");

        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够施展两仪剑意！\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够施展两仪剑意！\n");

        skill = me->query_skill("force");
        skill1 = skill;

        message_vision(HIR "\n$N剑交左手，在身前划了两个圆圈。$n挥舞，却听不到丝毫金刃劈风之声，足见剑劲之柔韧已达于化境。\n" NOR, me, weapon);
        me->set_temp("jianyi", 1);
        weapon->set("no_get", "这样东西不能离开那儿。\n");
        weapon->set("no_drop","这样东西不能离开你。\n");
        weapon->unequip();

        if ( weapon->query("rigidity") < 100 ) {
                weapon->add("rigidity", 300+skill);
                weapon->set_temp("jianyi", 1);
        }
        else if ( weapon->query("rigidity") < 500 ) {
                weapon->add("rigidity", 200+skill);
                weapon->set_temp("jianyi", 2);
        }
        else if ( weapon->query("rigidity") < 1000 ) {
                weapon->add("rigidity", 100+skill);
                weapon->set_temp("jianyi", 3);        }
        else {
                weapon->add("rigidity", 50+skill);
                weapon->set_temp("jianyi", 4);
        }

        if ( skill1 > 150 ) {
                skill1 = 150;
        }
        if ( skill1 > weapon->query("weapon_prop/damage"))
                skill1 = weapon->query("weapon_prop/damage");

        weapon->add("weapon_prop/damage", skill1/2);
        weapon->set_temp("rig", skill);
        weapon->set_temp("dam", skill1);
        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/parry",  skill/3);

        call_out("checking", 1, me, weapon);
        me->add("neili", -skill*3/2);
        me->add("jingli", -skill/3);
        weapon->wield();

        return 1;
}

void checking(object me, object weapon)
{
        if ( me->query_temp("jianyi") < (int)me->query_skill("force")/8 ) {
           if ( environment(weapon) != me || weapon != me->query_temp("weapon") ) {
                remove_effect(me, weapon);
                tell_object(me, HIW "\n你放弃手中的"+weapon->name()+"，缓缓向前划出成一弧形,气纳丹田，意随心收。\n\n" NOR);
                return;
           }
           else if ( weapon->query("weapon_prop") == 0 ) {
                remove_effect(me, weapon);
                 tell_object(me, HIR "\n你的"+weapon->name()+"已毁，太极剑意无存。\n\n" NOR);
                return;
           }
           else if ( me->query_skill_mapped("force") != "taiji-shengong" ) {
                remove_effect(me, weapon);
                 tell_object(me, HIR "\n你中途改用其他内功心法，太极不在，剑意不存！\n\n" NOR);
                return;
           }

           me->add_temp("jianyi", 1);
           call_out("checking", 1, me, weapon);
        }
        else {
           remove_effect(me, weapon);
            message_vision(HIR "\n$N的太极剑意周期已过，意随心收。$n微微轻抖，招式轻浮。\n\n" NOR, me, weapon);
        }
}       

private int remove_effect(object me, object weapon)
{
        int amount, amount1,amount3,skill;
        
        amount = weapon->query_temp("rig");
        amount1 = weapon->query_temp("dam");
        skill = me->query_skill("force");
        amount3=skill/3;         
        if ( weapon == me->query_temp("weapon") ) {
                weapon->unequip();
                me->set_temp("equip_weapon", 1);
        }
        
        weapon->add("weapon_prop/damage", -amount1/2 );
        
        if ( weapon->query_temp("jianyi") == 1 ) {
                weapon->add("rigidity", -(300+amount));
        }
        else if ( weapon->query_temp("jianyi") == 2 ) {
                weapon->add("rigidity", -(200+amount));
        }
        else if ( weapon->query_temp("jianyi") == 3 ) {
                weapon->add("rigidity", -(100+amount));
        }
        else {
                weapon->add("rigidity", -(50+amount));
        }
        me->add_temp("apply/attack", -amount3);
        me->add_temp("apply/parry", -amount3);
        weapon->delete_temp("jianyi");
        weapon->delete_temp("rig");
        weapon->delete_temp("dam");
        weapon->delete("no_drop");
        weapon->delete("no_get");

        if ( me->query_temp("equip_weapon") ) {
                weapon->wield();
                me->delete_temp("equip_weapon");
        }
        
        me->delete_temp("jianyi");
      
      return 1;
}
