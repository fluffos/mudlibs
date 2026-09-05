//sanhua.c 天女散花
//by whuan@pkuxkx
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{       
        int sp, dp;      
        int k=0;
        int no,count;// 攻击的敌人数量
        int damage,skilllevel;
        object obj, *inv; 
        object *enemy; //对手
    
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("暗器射敌只能对同地方的对手使用。\n");
        if( skilllevel = (int)me->query_skill("mantian-xingyu", 1) < 80 )
                return notify_fail("你的漫天星雨还不够娴熟，不会使用「天女散花」。\n");
        if( (int)me->query_skill("bingchuan-xinfa", 1) < 80 )
                return notify_fail("你的冰川心法不够高，不能用内力发出「天女散花」的绝招。\n");
        if( (string)me->query("family/family_name") !="红花会" )
                return notify_fail("你从哪里偷学的的「天女散花」的绝招？\n");
        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("你现在内力太弱，不能发射暗器。\n");
        if( (int)me->query_temp("last_sanhua_time") > time()-15 ) //每15秒才能发一次
                return notify_fail("绝招用多了就不灵了。\n");
  
        me->set_temp("last_sanhua_time",time());

        obj=F_KUNGFU->find_throwing(me);
        if (!obj) return notify_fail("你身上没有暗器，怎能使出暗器绝技？\n");
    
        //这里是发pfm的描述
        message_vision(HIY "\n$N双手连扬，一把暗器已经脱手而出，恰如“天女散花”一般。\n" NOR, me);
        sp = me->query_skill("force") + me->query_skill("throwing");
        dp = target->query_skill("dodge");
    
        enemy = me->query_enemy();//找敌人
        no = sizeof(enemy);    //敌人的数量
    
        count = (int)me->query_skill("mantian-xingyu",1)/100;
        //计算最多同时攻击的人数，最高限制5个
        if (count >= 5) count = 5;
        if (count <= 1) count = 1;
    
        if (no>count) no = count;
        //如果敌人太多，则随机攻击其中的一些
    
        me->start_busy(3);
        me->add("neili", -100*no);
    
        for(int j=0;j<no;j++)
        {    
                if (environment(enemy[j])!=environment(me)) continue;
                
                if ( k>0 )
                  obj=F_KUNGFU->find_throwing(me);
                k++;
                if ( !obj )
                {
                   tell_object(me,"你的暗器打光了。\n");
                   return 1;
                }  
                
                if( random(sp) > random(enemy[j]->query_skill("dodge",1)))
                {
                        obj->move(enemy[j]);
                        damage = (int)(me->query_skill("throwing") * 3/2);
                        damage += obj->query("weapon_prop/damage") * 5;
                        enemy[j]->receive_damage("qi", damage, me);
                        enemy[j]->receive_wound("qi", damage/3, me);
                        tell_object(enemy[j], HIR "\n你见暗器射了过来，大脑一片空白，已无法躲避，家庭事业亲人从你眼前掠过，紧接着是疼痛加疼痛！！\n" NOR);
                        message("vision", HIR "\n结果" + enemy[j]->name() + HIR"被暗器射中，杀猪般嚎叫一声，身子一歪，退后丈许！！\n" NOR, environment(me), enemy[j]);
                        COMBAT_D->report_status(enemy[j]);
                }
                else
                {
                        destruct(obj);   
                        message_vision( HIC "\n可是$N"HIC"看到了暗器，半空中翻滚,硬从暗器网中穿出。\n" NOR, enemy[j]);
                }
        }                                    
        return 1;
}

