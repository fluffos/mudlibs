// qudu.c

#include <ansi.h>

int exert(object me, object target)
{
        int con1, con2, con3, con4, con5, a, b, c, d, pflv;
        con1 = me->query_condition("snake_poison");//蛇毒
        con2 = me->query_condition("san_poison");//断肠散
        con3 = me->query_condition("xx_poison");//星宿掌毒
        con4 = me->query_condition("bt_poison");//白驼蛇毒
		con5 = me->query_condition("btgs_poison");//白驼怪蛇毒
		
		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "白驼山") 
			pflv=0;

        if( me->is_fighting() )
                return notify_fail("战斗中运功驱毒？找死吗？\n");
        if( (int)me->query("neili") < 150 )
                return notify_fail("你的真气不够。\n");
        if( pflv<3 && (int)me->query("eff_qi") < (int)me->query("max_qi") / 4 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        if ((int)me->query_skill("hamagong", 1) < 20)
                return notify_fail("你的蛤蟆功修为还不够。\n");

        a = (int)me->query_skill("hamagong", 1);
        b = (int)me->query_skill("poison", 1) ;
        c = (int)(a/10+b/10)+1;
		if (pflv>=3)
			c += (2*pflv-5)*c/5;

        if (con1 > 0) {
                if (con1 < c){
                        me->clear_condition("snake_poison");
                        write( HIW "你运功把蛇毒驱除干净了。\n" NOR);
                }
                else{
                        me->apply_condition("snake_poison", con1 - c);
                        write( HIW "你全身放松，坐下来开始运功驱除蛇毒。\n" NOR);
                }
                d = 0 ;
                message("vision", HIY+me->name()+"吐出一口金灿灿的瘀血，一滴滴黑血从伤口慢慢渗出。\n" NOR, environment(me), me);
        }
        else if (con2 > 0){
                if ((int)me->query_skill("hamagong", 1) < 30)
                        return notify_fail("你的蛤蟆功修为还不够。\n");
                if (con2 < c){
                        me->clear_condition("s_poison");
                        write( HIW "你运功把断肠散毒驱除干净了。\n" NOR);
                }
                else{
                        me->apply_condition("s_poison", con2 - c);
                        write( HIW "你全身放松，坐下来开始运功驱除断肠散毒。\n" NOR);
                }
                d = 30;
                message("vision", HIY+me->name()+"吐出一口瘀血，苍白的脸上多了点血色。\n" NOR,  environment(me), me);
        }
        else if (con3 > 0){
                if ((int)me->query_skill("hamagong", 1) < 50)
                        return notify_fail("你的蛤蟆功修为还不够。\n");
                if (con3 < c){
                        me->clear_condition("xx_poison");
                        write( HIW "你运功把星宿掌毒驱除干净了。\n" NOR);
                }
                else{
                        me->apply_condition("xx_poison", con3 - c);
                        write( HIW "你全身放松，坐下来开始运功驱除星宿掌毒。\n" NOR);
                }
                d = 50;
                message("vision", HIY+me->name()+"吐出一口紫血，苍白的脸上多了点血色。\n" NOR,   environment(me), me);
        }
        else if (con4 > 0){
                if ((int)me->query_skill("hamagong", 1) < 80)
                        return notify_fail("你的蛤蟆功修为还不够。\n");
                if (con4 < c){
                        me->clear_condition("bt_poison");
                        write( HIW "你运功把白驼蛇毒驱除干净了。\n" NOR);
                }
                else{
                        me->apply_condition("bt_poison", con4 - c);
                        write( HIW "你全身放松，坐下来开始运功驱除白驼蛇毒。\n" NOR);
                }
                d = 100;
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,  environment(me), me);
        }
        else if (con5 > 0){
                if ((int)me->query_skill("hamagong", 1) < 120)
                        return notify_fail("你的蛤蟆功修为还不够。\n");
                if (con5 < c){
                        me->clear_condition("btgs_poison");
                        write( HIW "你运功把西域怪蛇毒驱除干净了。\n" NOR);
                }
                else{
                        me->apply_condition("btgs_poison", con5 - c);
                        write( HIW "你全身放松，坐下来开始运功驱除西域怪蛇毒。\n" NOR);
                }
                d = 200;
                message("vision", HIY+me->name()+"吐出一口带有恶臭的瘀血，苍白的脸上多了点血色。\n" NOR,  environment(me), me);
        }
        else write( HIW "你好象没中毒，或者是中了一种你不知道的毒。\n" NOR);

        me->add("neili", -50-d);
        me->set("jiali", 0);
		if (pflv>=3)
		{
			if (pflv<5)
				me->start_busy(5-pflv);
		}
		else
			me->start_busy(4);

        return 1;
}

