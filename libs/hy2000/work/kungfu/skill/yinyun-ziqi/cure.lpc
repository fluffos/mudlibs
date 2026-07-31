// cure.c绝户手疗

#include <ansi.h>
// inherit F_CLEAN_UP;

int exert(object me, string arg)
{
	object ob;

        ob = present(arg, environment(me));
        if (!userp(ob)) return notify_fail("你要帮谁运功疗伤呀！\n");
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要帮谁运功疗伤呀！\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能静下心疗伤！\n");

        if( me->is_busy() )
                return notify_fail("你正忙着呢！\n");
  
        if ((int)me->query_skill("yinyun-ziqi", 1) < 120)
                return notify_fail("你的氤氲紫气修为还不够。\n");

        if ((int)me->query_skill("taoism", 1) < 140)
                return notify_fail("你的道家心法修为还不够。\n");

        if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 2 )
                return notify_fail("你自身精元虚弱，无法运用真气！\n");

    if( ob==me ) {
        if( (int)me->query_condition("juehu_hurt") <= 0 )
                return notify_fail("你并没有受伤！\n");
        if( (int)me->query_skill("taoism",1)<150 )
                return notify_fail("你道家修为不够替自己疗伤！\n");

        write( HIW "你盘膝打坐，意守丹田，开始具结全身真气打通汇阴穴。\n" NOR);
        message("vision",
                HIR + me->name() + "盘膝打坐，脸色越来越红，大汗淋漓。\n" NOR,
                environment(me), me);
        if(me->query("neili",1)< 1400||me->query("jingli",1)<700)
        {write(RED "你突然心跳加速，呼吸困难，体内真气顿时失控，身体僵硬地倒在地上。\n" NOR);
         me->start_busy(10);
         me->add("max_neili",-20);
         me->set("neili",1);
         me->set("jingli",1);
         write(HIY "原来你体力不支，运功走火入魔!\n"NOR);
         message("vision",
                HIY + me->name() + "脸色大变，四肢僵硬，一头倒在地上，出气多吸气少。\n" NOR,
                environment(me), me);
         }
        else
        {write(RED "你丹田真气越聚越多，感觉越来越热，穴道之处有如刀割。\n啊--!你大叫一声，全身经脉终于打通，丹田暖洋洋的甚是受用!\n" NOR);
         message("vision",
                RED + me->name() + "啊--!吐出一口腥血，脸色也红润起来，两眼精光四射，不可逼视。\n" NOR,
                environment(me), me);
         me->clear_condition("juehu_hurt");
         if (me->query("genderbak")== "男性")
             me->set("gender","男性");

         me->start_busy(3);
         me->set("neili",1);
         me->set("jingli",1);
         me->add("max_neili",-(430-(int)me->query_skill("yinyun_ziqi",1)-(int)me->query_skill("taoism",1)));
         me->add("combat_exp", 10*((int)me->query_skill("yinyun_ziqi",1)+(int)me->query_skill("taoism",1)));
         }
     }
     else
     {
	if( (int)arg->query_condition("juehu_hurt") <= 0 )
            return notify_fail(ob->query("name")+"并没有受伤！\n");

        message_vision(HIY"$N把掌心放在$n的百汇穴上，运起三味真火来驱除阴寒之毒!\n"NOR,me,ob);
        if(me->query("neili",1)< 1300||me->query("jingli",1)<650)
        {write(RED "你突然心跳加速，呼吸困难，体内真气顿时失控，身体僵硬地倒在地上。\n" NOR);
         me->start_busy(10);
         me->add("max_neili",-15);
         me->add("max_jingli",-10);
         me->set("jingli",1);
         me->set("neili",1);
         write(HIY "原来你体力不支，运功走火入魔!\n"NOR);
         tell_object(ob, RED "你忽然感到由头顶传入的真气四处乱蹿，丹田阵痛，难过欲吐。\n" NOR );
         message("vision",
                HIY + me->name() + "脸色大变，四肢僵硬，一头倒在地上，出气多吸气少。\n" NOR,
                environment(me), me);
         ob->add("max_jingli",-5);
         ob->unconcious();
         }
        else
        {write(RED "你逐渐加力，真气入百汇，过任督，聚丹田，直冲汇阴穴。\n"NOR);
         tell_object(ob, RED "你感到一股热浪由百汇进入，过任督，聚丹田，直冲汇阴大穴。全身燥热难当，\n原先的阴寒之苦顿时减弱!\n"NOR );
         ob->clear_condition("juehu_hurt");
         if (ob->query("genderbak")== "男性")
             ob->set("gender","男性");
         message_vision(RED"$N啊--!吐出一口腥红的血，脸色恢复了红润。\n"NOR, ob);
         ob->add("max_jingli",-5);
         me->start_busy(3);
         me->set("jingli",1);
         me->set("neili",1);
         me->add("max_neili",-(int)(420-(int)me->query_skill("yinyun_ziqi",1)-(int)me->query_skill("taoism",1))/2);
         me->add("combat_exp", 4*((int)me->query_skill("yinyun_ziqi",1)+(int)me->query_skill("taoism",1)));
         }
     }
      return 1;
}
