
// tmbiao.c  天魔飚
// 99.2.5 by Bless

#include <ansi.h>
inherit F_SSERVER;

int perform(object me,object target)
{
        int damage,i,j;
        string msg;     
        object ob;
        if( !target ) target = offensive_target(me);

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
            return notify_fail("你手中没有装备剑类武器！\n");

        if(!target||!target->is_character() || !me->is_fighting(target) )
            return notify_fail("〖天魔飚〗只能对战斗中的对手使用。\n");

    if (me->query("family/family_name") != "日月神教" )
        return notify_fail("你不是日月神教弟子，不能使用这项绝技！\n");
        
        if ( (int)me->query_dex() < 30 )
            return notify_fail("你的先天不足，不能领悟〖天魔飚〗！n");

        if( (int)me->query_skill("tmjian",1)<181)
            return notify_fail("你的天魔剑法不够娴熟，不会使用〖天魔飚〗。\n");

        if( (int)me->query_skill("tmdafa",1)<101)
            return notify_fail("你的天魔大法不够深厚，不会使用〖天魔飚〗。\n");
                                
        if( (int)me->query("neili")<500)
                return notify_fail("你现在内力太弱，不能使用〖天魔飚〗。\n");
                        
        me->start_busy(3);
        target->start_busy(3);

        me->add("neili",-350);
                
        damage =(target->query_skill("dodge")+target->query_skill("parry"))/2;

        if (damage==0||!damage) damage=1;
        damage = me->query_skill("tmjian",1)*400/damage;
        damage+= me->query_skill("force")*500/
                ((int)target->query_skill("force")+1);
        damage+= me->query("combat_exp")*4000/ 
                (target->query("combat_exp")+1);

        if(damage>36000) damage = 36000;
        if(damage<500 ) damage = 550;
                
        i = random(damage);
        j = me->query_skill("tmjian",1)/2+2500;
        damage = (damage/10+i/10)*j/2000+500;

        msg=YEL"\n\n$N身体突然飞速旋转，化作一阵狂飚，手中"+ob->query("name")+"挑起漫天魔影，其快无比地向着$n扑去！\n"NOR;

       if(random((int)target->query("combat_exp")/3*2) < (int)me->query("combat_exp"))
        {
if (damage >25000) damage=25000;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage);

                msg += HIY"$n大惊失色，奋力挣脱，但终究没有逃出天魔剑气的范围。！\n"NOR;      
       if((random((int)target->query("combat_exp")/3*2) > (int)me->query("combat_exp")) &&
       (random((int)target->query("combat_exp")/3) < (int)me->query("combat_exp")))
                        msg += HIY"结果$n的肩膀被$N削去一大块皮肉，血花四溅。\n"NOR;
                else if( damage < 500 ) 
                        msg += HIR"$n被$N手中"+ob->query("name")+"重重的拍在耳门，摇摇欲倒！\n"NOR;
                else 
                        msg += RED"$n眼前一暗，刹那间已被$N刺中〖檀中〗大穴，嘴角溢出几缕鲜血！\n\n\n"NOR;
        }
        else
        {
                msg += YEL"可是$p看破了$P的企图，身形一晃闪了开去。\n\n\n"NOR;
     me->start_busy(2);
        }               

        message_vision(msg, me, target);

        return 1;
}
