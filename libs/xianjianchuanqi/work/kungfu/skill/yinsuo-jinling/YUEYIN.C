// yufeng.c 银索金铃--「乐音绝技」
// By River

#include <ansi.h>

inherit F_SSERVER;
void check_fight(object me,object target,int count);
int perform(object me, object target)
{
        string msg ;
        object weapon,weapon1; 
        int i,j = 1;
      
        weapon = me->query_temp("weapon");

        if( !target )
             target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target))
             return notify_fail("「乐音绝技」只能对战斗中的对手使用。\n");

        if( !weapon 
         || me->query_skill_mapped("whip") != "yinsuo-jinling"
         || me->query_skill_mapped("parry") != "yinsuo-jinling"
         || weapon->query("skill_type") != "whip") 
             return notify_fail("你现在无法使用「乐音绝技」攻击对方。\n");

        if((int)me->query_skill("yunu-xinjing", 1)  < 140 )
             return notify_fail("你的玉女心经等级还不够，使不出「乐音绝技」。\n");

        if((int)me->query_skill("yinsuo-jinling",1) < 150 ) 
             return notify_fail("你的银索金铃还不够娴熟，不会使用「乐音绝技」。\n");

        if((int)me->query_skill("yunu-jianfa",1) < 150 ) 
             return notify_fail("你的玉女素心剑还不够娴熟，难以配合银索金铃的「乐音绝技」。\n");

        if((string)me->query_skill_mapped("sword") !="yunu-jianfa")
             return notify_fail("你必须将玉女素心剑作为你的剑法使用。\n");

        if((int)me->query("neili") < 1500)
             return notify_fail("你的内力不够用来「乐音绝技」。\n");

        if( target->is_busy())
             return notify_fail(target->name()+"正自故不暇，你可以放胆攻击。\n");

        if( target->query_temp("yueyin"))
             return notify_fail(target->name()+"被你的乐音所迷惑，你可以放胆攻击。\n");

        if( userp(me) && (string)me->query("family/family_name") != "古墓派")
             return notify_fail("你不是古墓派的传人，怎么会使用「乐音绝技」！\n"); 

        if ( weapon->query("id") =="jinling suo") j = 2;

        msg = HIW"\n$N手中"+weapon->name()+HIW"飘动，幻成一片竹雾，又发出玎玎声响，忽怎忽缓，忽轻忽响，竟尔如乐曲一般。\n"NOR;
        msg +=HIW"音乐乃依循天籁及人身自然节拍而组成，是故乐音则听之悦耳，嘈杂则闻之心烦。\n"NOR;

        me->add("neili", -100);
        me->add("jingli", -60);

        i = (int)me->query_skill("yinsuo-jinling", 1);
        i += (int)me->query_skill("yunu-jianfa", 1);
        i /= 9;
        if(me->query("gender") !="女性")
         i /=2;
        weapon1 = target->query_temp("weapon");

        if( weapon1 && weapon1->query("skill_type") =="sword"){
         if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2
          || !living(target)){
           msg += HIR"\n$N手中"+weapon->name()+HIR"如银蛇般四下游走，只闻叮当之声，$n手腕上中了一击，被迫放弃了手中的"+weapon1->name()+HIR"。\n"NOR;
           msg += HIR"$N顺势夺过$n的"+weapon1->name()+HIR"，乘$n情急狼狈之际，左手握住"+weapon1->name()+HIR"速攻三招。\n"NOR;
           message_vision(msg, me, target);
           weapon->unequip(); 
           weapon1->move(me);
           weapon1->wield();
           me->add("neili", -200);
           target->start_busy(2);
           me->set_temp("juan", 1);
           i *= j;
           me->add_temp("apply/damage", i);
           me->add_temp("apply/attack", i);
           me->add_temp("apply/dexerity", i);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), j);
           if (present(target,environment(me)) && me->is_fighting(target))
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), j);
           if (present(target,environment(me)) && me->is_fighting(target))
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), j);
           weapon1->unequip();
           weapon->wield();
           if((int)me->query("double_attack")){
             msg = HIY"\n紧跟着，$N右手"+weapon->name()+HIY"飞扬，卷起一团白花，身子前冲疾攻$n数招。\n"NOR;
             message_vision(msg, me, target);
             if (present(target,environment(me)) && me->is_fighting(target))
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), j);
             if (present(target,environment(me)) && me->is_fighting(target))
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), j);
             if (present(target,environment(me)) && me->is_fighting(target))
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), j);
           }
           me->add_temp("apply/damage", -i);
           me->add_temp("apply/attack", -i);
           me->add_temp("apply/dexerity", -i);
           me->delete_temp("juan");
         }
         else {
           msg +=CYN"\n$n急忙大吼一声，发出一阵嘈音来冲散乐曲，霎时间两般声音交作，忽轻忽响，或高或低。\n"NOR;
           message_vision(msg, me, target);
           me->start_busy(1);
           target->add("jingli", -60);
         }
         me->start_perform(5,"「乐音绝技」");
         return 1;
        }
        if((random(me->query_per() *j ) > target->query_kar()/2
         || random(target->query("pur")) >= 25)
         && me->is_fighting(target)
         && me->query("combat_exp") > target->query("combat_exp")/3 ){
           msg +=YEL"\n$n只听得铃声玎玎，有如乐曲，听了几下，竟便要顺著乐音出手。\n"NOR;
           message_vision(msg, me, target);
           me->add("neili", -200*j);
           i *= j;
           target->set_temp("yueyin", i);
           target->add_temp("apply/dexerity", -i);
           target->add_temp("apply/dodge", -i*2);
           target->start_busy( random(i/3)+1);
           target->apply_condition("no_perform", 1+random(2));
           call_out("check_fight", 1, me, target, i/3);
        }
        else{
           msg +=CYN"\n$n急忙大吼一声，发出一阵嘈音来冲散乐曲，霎时间两般声音交作，忽轻忽响，或高或低。\n"NOR;
           me->start_busy(1);
           message_vision(msg, me, target);
           target->add("jingli", -60);
        }
        me->start_perform(5,"「乐音绝技」");
        return 1;
}

void check_fight(object me,object target,int count)
{
        int j ;
	if(!target) return;
	j = target->query_temp("yueyin");
	if( !me
	 || !me->is_fighting(target)
	 || me->query_skill_mapped("whip") != "yinsuo-jinling"
	 || !me->query_temp("weapon")
	 || count -- < 1 ){
	   target->add_temp("apply/dexerity", j );
	   target->add_temp("apply/dodge", j*2 );
	   target->clear_condition("no_perform");
           if( target->is_busy()) target->start_busy(1);
	   target->delete_temp("yueyin");
           message_vision(HIW"\n$N心情於瞬息之间接连数变，终于恢复了明智。\n\n"NOR, target);
	   return ;
	}
	call_out("check_fight", 1, me, target, count);
}
