// qudu.c for huagong-dafa by jpei 
// added xxx_poison 12/16/2008
#include <ansi.h>

int exert(object me, object target)
{
        int con1, con2, con3, con4, con5, con6,con7,con8,con9,con10,level;
        con1 = me->query_condition("snake_poison");// 蛇毒
        con2 = me->query_condition("san_poison");// 断肠散
        con3 = me->query_condition("xx_poison");// 星宿掌毒
        con4 = me->query_condition("bt_poison");// 西域灵蛇毒
        con5 = me->query_condition("xxx_poison");// 冰魄寒毒
        con6 = me->query_condition("xx-poison-palsy2");//新加的阵发的busy
        con7 = me->query_condition("xx-poison-palsy");//新加的阵发的busy
        con8 = me->query_condition("xxfog-poison");//星宿毒雾
        con9 = me->query_condition("xx-poison-hocus");//星宿抽搐
        con10 = me->query_condition("xx-poison-control");//星宿蛊毒
        if( me->is_fighting() )
                return notify_fail("战斗中运功驱毒？找死吗？\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 4 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        if ((int)me->query_skill("huagong-dafa", 1) < 100)
                return notify_fail("你的化功大法修为还不够，无法化解体内毒素！\n");

        if ((int)me->query_skill("poison", 1) < 100)
                return notify_fail("你的毒计等级太低，无法化解体内毒素！\n");
 
        level = (int)(me->query_skill("huagong-dafa", 1)/20+me->query_skill("poison", 1)/10)+1;
        if (con1 > 0){
                if (con1 < level){
                        me->clear_condition("snake_poison");
                        write( HIW "你运功把蛇毒驱除干净了。\n" NOR);
                }
                else{
                        me->apply_condition("snake_poison", con1 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除蛇毒。\n" NOR);
                }
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口金灿灿的瘀血，一滴滴黑血从伤口慢慢渗出。\n" NOR, 
                    environment(me), me);                
        }
        else if (con2 > 0){
                if (con2 < level){
                        me->clear_condition("s_poison");
                        write( HIW "你运功把断肠散毒驱除干净了。\n" NOR);
                }
                else{
                        me->apply_condition("s_poison", con2 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除断肠散毒。\n" NOR);
                }
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口瘀血，苍白的脸上多了点血色。\n" NOR,  
                    environment(me), me); 
        }
        else if (con3 > 0){
                if (con3 < level){
                        me->clear_condition("xx_poison");
                        write( HIW "你运功把星宿掌毒驱除干净了。\n" NOR);
                }
                else{
                        me->apply_condition("xx_poison", con3 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除星宿掌毒。\n" NOR);
                } 
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口紫血，苍白的脸上多了点血色。\n" NOR, 
                    environment(me), me);
        }
        else if (con4 > 0){ 
                if (con4 < level){
                        me->clear_condition("bt_poison");
                        write( HIW "你运功把西域灵蛇毒驱除干净了。\n" NOR);                 }
                else{
                        me->apply_condition("bt_poison", con4 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除西域灵蛇毒。\n" NOR);
                } 
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,
                    environment(me), me);
        }
        else if (con5 > 0){ 
                if (con5 < level){
                        me->clear_condition("xxx_poison");
                        write( HIW "你运功把冰魄寒毒驱除干净了。\n" NOR);                 }
                else{
                        me->apply_condition("xxx_poison", con5 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除冰魄寒毒。\n" NOR);
                } 
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,
                    environment(me), me);
        }
        else if (con6 > 0){ 
                if (con6 < level){
                        me->clear_condition("xx-poison-palsy2");
                        write( HIW "你运功把体内奇怪的毒素清理干净了。\n" NOR);                 }
                else{
                        me->apply_condition("xx-poison-palsy2", con6 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除体内奇怪的毒素。\n" NOR);
                } 
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,
                    environment(me), me);
        }
        else if (con7 > 0){ 
                if (con7 < level){
                        me->clear_condition("xx-poison-palsy");
                        write( HIW "你运功把体内奇怪的毒素清理干净了。\n" NOR);                 }
                else{
                        me->apply_condition("xx-poison-palsy", con7 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除体内奇怪的毒素。\n" NOR);
                } 
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,
                    environment(me), me);
        }
        else if (con8 > 0){ 
                if (con8 < level){
                        me->clear_condition("xxfog-poison");
                        write( HIW "你运功把体内残留的毒雾之毒清理干净了。\n" NOR);                 }
                else{
                        me->apply_condition("xxfog-poison", con8 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除体内残留的毒雾之毒。\n" NOR);
                } 
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,
                    environment(me), me);
        }
        /*else if (con6 > 0){ 
                if (con6 < level){
                        me->clear_condition("xx-poison-palsy2");
                        write( HIW "你运功把体内奇怪的毒素清理干净了。\n" NOR);                 }
                else{
                        me->apply_condition("xx-poison-palsy2", con6 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除体内奇怪的毒素。\n" NOR);
                } 
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,
                    environment(me), me);
        }*/
        else if (con10 > 0){ 
                if (con10 < level){
                        me->clear_condition("xx-poison-control");
                        write( HIW "你运功把体内的蛊毒给逼出来了。\n" NOR);                 }
                else{
                        me->apply_condition("xx-poison-control", con10 - level);
                        write( HIW "你全身放松，坐下来开始运功驱除体内的蛊毒。\n" NOR);
                } 
                me->start_busy(2);
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,
                    environment(me), me);
        }
        else    write( HIW "你好象没中毒,或者是中了一种你不知道的毒。\n" NOR);

        me->add("neili", -200);
        me->set("jiali", 0);

        return 1;
}

