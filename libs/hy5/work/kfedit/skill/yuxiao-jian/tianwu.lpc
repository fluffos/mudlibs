// tianwu.c 凤凰天舞

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int dodge, parry, attack, sword, force;

        weapon = me->query_temp("weapon");

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("凤凰天舞只能对战斗中的对手使用。\n");

        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，怎能运用「凤凰天舞」？！\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");

        if( me->query_skill("yuxiao-jian",1) < 200 )
                return notify_fail("你玉箫剑法修为还不够，还未领悟「凤凰天舞」！\n");

        if( me->query_skill("bibo-shengong",1) < 180)
                return notify_fail("你的碧波神功修为火候未到，施展「凤凰天舞」只会伤及自身！\n");

        if( me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("你所用的内功与「凤凰天舞」心法相悖！\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("你的内力修为不足，劲力不足以施展「凤凰天舞」！\n");

        if( me->query("neili") < me->query("max_neili") )
                return notify_fail("你的内力不够，劲力不足以施展「凤凰天舞」！\n");

        if( me->query("jing") <= 100 )
                return notify_fail("你的精力有限，不足以施展「凤凰天舞」！\n");
        
        if( me->query("eff_qi") < me->query("max_qi"))
                return notify_fail("你的身体状况施展「凤凰天舞」，恐怕有生命危险！\n");
        
        
        dodge = target->query_skill("dodge");
        parry = target->query_skill("parry");
        attack = sword = (dodge+parry)/2;
        force = me->query_skill("force");

        message_vision(HIR"\n$N长啸一声，强运真气冲丹田，贯百会，倾刻间气走百穴，一连打通十二道生死玄关，面色殷红如血，嘴脚隐然有血丝沁出，\n",me);
        message_vision(HIG"$N四周劲风四射，身行冲天而起，犹如凤舞九天，手中"+weapon->name()+HIG"响起阵阵龙吟，攻势凌厉刚猛，无所不至，已全然不顾自身安危！\n" NOR, me);
        me->add("neili", force*20);
        me->start_busy(2);
        me->add("jiali", force/5);
        me->add_temp("apply/dodge", dodge);
        me->add_temp("apply/parry", parry);
        me->add_temp("apply/attack", attack);
        me->add_temp("apply/sword", sword);
        me->add_temp("apply/speed", dodge);
        call_out("remove_effect", sword/15, me, dodge, parry, attack, sword);

        me->set_temp("yuxiao/tianwu", 1);

        return 1;
}

void remove_effect(object me, int dodge, int parry, int attack, int sword)
{
        me->add_temp("apply/dodge", -dodge);
        me->add_temp("apply/parry", -parry);
        me->add_temp("apply/attack", -attack);
        me->add_temp("apply/sword", -sword);
        me->add_temp("apply/speed", -dodge);

        message_vision(RED"\n$N口中鲜血狂喷，脸色苍白，经脉内脏已受了极重内伤。\n" NOR, me);
        me->delete_temp("yuxiao/tianwu");
        me->start_busy(2);
        me->set("neili", 100);
        me->set("jiali", 0);
        me->add("jing", -100);
        me->receive_damage("qi", 500);
        me->receive_wound("qi", 500);
        
}
