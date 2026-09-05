// dianxue.c
// Created by Darken@Sj
// Modified by Numa@Sj
// Modified by keinxin@sj2 

#include <ansi.h>
#include <skill.h>
inherit F_CLEAN_UP;

int main(object target, string xuedao)
{
        object me = this_player();
        string msg,tar;
        int dex, str, bhcs, tzst, j;

        if(!xuedao)
                return notify_fail("你要点什么穴？\n");

        if(me->is_busy())
                return notify_fail("你现在正忙着呢！\n");

        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能准确的点中对方的穴道呢！\n");   

        if( sscanf(xuedao,"%s %s",tar,xuedao)!=2 )
                return notify_fail("你要点什么穴？\n");
    
        target = present(tar,environment(me));
        if (!target
        ||  environment(target)!=environment(me))
                return notify_fail("你要点谁的穴道？\n");    
    
/*
        if( !me->is_fighting() )
                return notify_fail("「隔空点穴」只能在战斗中使用。\n");
*/

        if((int)me->query_skill("force",1) < 120)
                return notify_fail("你的内功的修为不够, 不能使用隔空点穴 !\n");

        if((int)me->query_skill("dodge",1) < 120)
                return notify_fail("你的轻功修为不够, 不能使用隔空点穴！\n");
 
        if((int)me->query_skill("finger",1) < 120)
                return notify_fail("你的点穴修为不够， 目前不能使用隔空点穴! \n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");

        if (me->query_temp("thd/tz"))
                return notify_fail("你刚点完穴道，先休息一下吧。\n");
        
        dex = target->query_dex();
        str = target->query_str();
        bhcs = me->query_skill("force",1);
        tzst = me->query_skill("finger",1);

// 伏兔穴
        if (xuedao == "futu")
        {
                if (tzst < 160)
                        return notify_fail("你的点穴能力还无法准确的点中伏兔穴。\n");
                msg = HIG "$N聚气於右手食指，倏地向$n腿上伏兔穴点去！\n" NOR;
                if ((dex*2+random(21))>(me->query_skill("finger",1)-30))
                        msg += HIW "$n赶紧缩脚，才闪过这一招。\n" NOR;
                else
                {
                        msg += HIR "$n一被点中，腿一麻，身法登时迟缓了下来。\n" NOR;
                        me->set_temp("thd/tz",1);
                        target->add_temp("apply/dexerity", -tzst/10 );
                        call_out("remove_effect_futu", 10, me, target, tzst/10);
                }
                message_vision(msg, me, target);
        }

// 神门穴
        else if (xuedao == "shenmen")
        {
                if (tzst < 160)
                        return notify_fail("你的点穴能力还无法准确的点中神门穴。\n");
                msg = HIG "$N$N聚气於右手食指，倏地向$n手腕神门穴点去！\n" NOR;
                if ((dex*2+random(21))>(me->query_skill("finger",1)-40))
                        msg += HIW "$n赶紧翻转手腕，才避开了这一招。\n" NOR;
                else
                {
                        msg += HIR "$n一被点中，手腕一麻，力道弱了许多。\n" NOR;
                        me->set_temp("thd/tz",1);
                        target->add_temp("apply/strength", -tzst/10 );
                        call_out("remove_effect_shenmen", 10, me, target, tzst/10);
                }
                message_vision(msg, me, target);
        }

// 关元穴
        else if (xuedao == "guanyuan")
        {
                if (tzst < 140)
                        return notify_fail("你的点穴能力还无法准确的点中对方的关元穴。\n");
                msg = HIG "$N聚气於右手食指，倏地向$n腹部关元穴点去！\n" NOR;
                if ((dex*2+random(21))>(me->query_skill("finger",1)-50))
                        msg += HIW "$n赶紧退了一步，才闪了过去。\n" NOR;
                else
                {
                        msg += HIR "$n一被点中，一股热气直冲丹田，体内的真气被打散了开去！\n" NOR;
                        me->set_temp("thd/tz",1);
                        target->add("neili",-(bhcs+tzst));
                        call_out("remove_effect_all", 10, me);
                }
                message_vision(msg, me, target);
        }

// 玉堂穴
        else if (xuedao == "yutang")
        {
                if (tzst < 140)
                        return notify_fail("你的点穴能力还无法准确的点中对方的玉堂穴。\n");
                msg = HIG "$N聚气於右手食指，倏地向$n胸口玉堂穴点去！\n" NOR;
                if ((dex*2+random(21))>(me->query_skill("finger",1)-60))
                        msg += HIW "$n身子一侧，方躲过这一招。\n" NOR;
                else
                {
                        msg += HIR "$n一被点中，体内的真气再也不能运转自如。\n" NOR;
                        me->set_temp("thd/tz",1);
                        j = bhcs/100 + random(2);
                        target->apply_condition("no_exert",j); 
                        call_out("remove_effect_yutang", j, me, target);
                }
                message_vision(msg, me, target);
        }

// 檀中穴
        else if (xuedao == "tanzhong")
        {
                if (tzst < 120)
                        return notify_fail("你的点穴能力还无法准确的点中对方的檀中穴。\n");
                msg = HIG "$N聚气於右手食指，倏地向$n胸前檀中穴点去！\n" NOR;
                if ((dex*2+random(21))>(me->query_skill("finger",1)-70))
                        msg += HIW "$n连退两步，才闪过这一招。\n" NOR;
                else
                {
                        msg += HIR "$n一被点中，气息一窒，一时难以动弹。\n" NOR;
                        me->set_temp("thd/tz",1);
                        target->start_busy(bhcs/100+2); 
                        call_out("remove_effect_tanzhong", bhcs/10, me, target);
                }
                message_vision(msg, me, target);
        }

// 灵台穴
        else if (xuedao == "lingtai")
        {
                if (tzst < 120)
                        return notify_fail("你的点穴能力还无法准确的点中对方的灵台穴。\n");
                msg = HIG "$N聚气於右手食指，倏地向$n背後灵台穴点去！\n" NOR;
                if ((dex*2+random(21))>(me->query_skill("finger",1)-70))
                        msg += HIW "$n赶紧转身，才闪过这一招。\n" NOR;
                else
                {
                        msg += HIR "$n一被点中，脸上时红时白，看来受了内伤。\n" NOR;
                        me->set_temp("thd/tz",1);
                        target->receive_wound("qi",bhcs+tzst, me);
                        call_out("remove_effect_all", 10, me);
                }
                message_vision(msg, me, target);
        }

// 百会穴
        else if (xuedao == "baihui")
        {
                if (tzst < 180)
                        return notify_fail("你的点穴能力还无法准确的点中对方的百会穴。\n");
                msg = HIG "$N聚气於右手食指，倏地向$n头部百会穴点去！\n" NOR;
                if ((dex*2+random(21))>(me->query_skill("finger",1)-80))
                        msg += HIW "$n一仰头，才躲过这一招。\n" NOR;
                else
                {
                        msg += HIR "$n一被点中，登时天悬地转，摇摇遇坠。\n" NOR;
                        me->set_temp("thd/tz",1);
                        target->add("jingli",-(bhcs+tzst));
                        target->add("jing",-(bhcs+tzst));
                        call_out("remove_effect_all", 10, me);
                }
                message_vision(msg, me, target);
        }

// 风府穴
        else if (xuedao == "fengfu")
        {
                if (tzst < 180)
                        return notify_fail("你的点穴能力还无法准确的点中对方的风府穴。\n");
                msg = HIG "$N聚气於右手食指，倏地向$n後脑风府穴点去！\n" NOR;
                message_vision(msg, me, target);
                if ((dex*2+random(21))>(me->query_skill("finger",1)-90))
                        msg = HIW "$n赶紧低头，才闪过这一招。\n" NOR;
                else
                {
                        msg = HIR "$n一被点中，眼前陡然一黑，什么也看不到。\n" NOR;
                        me->set_temp("thd/tz",1);
                        target->add_temp("apply/dexerity", -tzst/10 );
                        target->set_temp("block_msg/all",1);
                        call_out("remove_effect_fengfu", bhcs/100 + random(2), me, target ,tzst/10);
                }
                message_vision(msg, me, target);
        }
// 未对应      
        else return notify_fail("以你目前的点穴能力还无法准确的点中这个穴道。\n");

        me->add("jingli",-400);
        me->add("neili", -400);
        me->start_busy(random(2));

        return 1;
}

int remove_effect_futu(object me, object target, int i)
{
        string msg;
        
        if (!target)
        {me->delete_temp("thd/tz");
                return 1;}
        target->add_temp("apply/dexerity",i);
        me->delete_temp("thd/tz");
        msg = HIY"$n腿上的伏兔穴血脉已经行开，身法已复。\n" NOR;
        message_vision(msg, me, target);
        return 1; 
}


int remove_effect_shenmen(object me, object target, int i)
{
        string msg;
        
        if (!target)
        {me->delete_temp("thd/tz");
                return 1;}
        target->add_temp("apply/strength",i);
        me->delete_temp("thd/tz");
        msg = HIY "$n手腕的神门穴血脉已经行开，力道恢复了。\n" NOR;
        message_vision(msg, me, target);
        return 1;
}

int remove_effect_tanzhong(object me, object target)
{
        string msg;
        
        if (!target)
        {me->delete_temp("thd/tz");
                return 1;}
        msg = HIY "$n胸口的檀中穴血脉已经行开，行动恢复了。\n" NOR;
        me->delete_temp("thd/tz");
        message_vision(msg, me, target);
        return 1;
}

int remove_effect_yutang(object me, object target)
{
        string msg;
        
        if (!target)
        {me->delete_temp("thd/tz");
                return 1;}
        msg = HIY "$n胸口的玉堂穴血脉已经行开，内息恢复了正常。\n" NOR;
        me->delete_temp("thd/tz");
        message_vision(msg, me, target);
        return 1;
}


int remove_effect_fengfu(object me, object target, int i)
{
        string msg;
        
        if (!target)
        {me->delete_temp("thd/tz");
                return 1;}
        target->add_temp("apply/dexerity",i);
        target->delete_temp("block_msg/all");
        me->delete_temp("thd/tz");
        msg = HIY "$n後脑的风府穴血脉已经行开，视线复原了。\n" NOR;
        message_vision(msg, me, target);
        return 1;
}

void remove_effect_all(object me)
{
        me->delete_temp("thd/tz");
}
