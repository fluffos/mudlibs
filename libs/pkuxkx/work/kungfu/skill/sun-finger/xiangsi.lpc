#include <ansi.h>
#include <combat.h>
#include <condition.h>
inherit F_SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        int temp_attack,temp_damage;
        object weapon=me->query_temp("weapon");
        
        if (!me->query("yiyangzhi/sword"))
                return notify_fail("你并没有学会使用这项绝技。\n");
        
        if(me->query("family/family_name") != "大理段家" && me->query("chushi/last_family") != "大理段家" )
          return notify_fail("「相思三剑」是段家不传之密，恐怕你现在不方便使用吧！\n");  
          
        if( !objectp(weapon) 
         || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，怎能运用「相思三剑」？！\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || target->is_corpse()
         || target==me)
                return notify_fail("你要对谁施展「相思三剑」？\n");

        if(!me->is_fighting())
                return notify_fail("「相思三剑」只能在战斗中使用！\n");
        
        if (me->query_skill_mapped("force")!="duanjia-xinfa")
                return notify_fail("「相思三剑」必须以段家心法做底子！\n");
                
        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query_skill("duanjia-xinfa", 1) < 100)
                return notify_fail("你的段家心法修为还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("qingyan-zhang", 1) < 150)
                return notify_fail("你的五罗青烟掌级别不够，根本无法体会相思之苦！\n");
                
        if((int)me->query_skill("sword", 1) < 150)
                return notify_fail("你的剑法修为还不够，使用这一招会有困难！\n");
 
        message_vision(HIR"$N想起生平所负红颜，回思种种相见、分别、缠绵、流离情事，倏然转身低眉轻叹，
        竟然不再回首，剑掌行云流水而出，方是：有“苦慰离别”之称的“相思三剑”！\n"NOR,me,target);
        me->add("neili", -250);

        temp_attack=(int)me->query_skill("duanjia-xinfa",1)/10+(int)me->query_skill("sun-finger",1)/10;
        temp_damage=(int)me->query_skill("qingyan-zhang",1)/5+(int)me->query_skill("sun-finger",1)/5;

        me->add_temp("apply/attack",temp_attack);
        me->add_temp("apply/damage",temp_damage);
        message_vision(MAG"$N举掌向后轻挥，掌力轻嫚如温婉女子，剑招坚烈充斥阳刚，缓缓吟道：“初见天人清池侧，玉手青烟挥五罗。”\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(MAG"$N嘴角泛起笑容，念道：“星眸温婉托乔木，药叉灵动矜持多。”言罢剑招掌力柔不可分，绵意悠长。\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(MAG"$N剑招忽长收短发，掌力若隐若现。面作苦痛之色，叹道：“何当白首同相聚，一解相思醉天河。”\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add_temp("apply/attack",-temp_attack);
        me->add_temp("apply/damage",-temp_damage);
        me->set_temp("no_move",1);
        me->set_temp("xiangsi_perform",time()+random(4)+4);
        call_out("remove_no_move",3+random(3),me);
        
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        message_vision(HIG"$N的「相思三剑」施展完毕，忽收剑而立，仰望天际不语，两颗清泪缓缓流下，跌落尘埃。\n"NOR,me);
        return 1;
}

void remove_no_move(object me) 
{
       if (me) me->delete_temp("no_move");
}

