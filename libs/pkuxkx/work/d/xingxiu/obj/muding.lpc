#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"神木王鼎"NOR,({ "shenmu wangding", "wangding", "shenmu" }) );
        set_weight(30000000);
        set("unit", "只");
        set("long", "一只雕琢而成的暗黄色小木鼎, 木理之间隐隐泛出红丝。鼎侧有五个铜钱大的圆孔，木鼎齐颈出有一道细缝，似乎上下分为两截。\n");
        set("value", 5);
        set("muding/remaining", 10);
}

void init()
{
        add_action("do_suck", "suck");
}

int do_suck(string arg)
{
        object me = this_player();

        if ( arg != "blood" || !living(this_player()))
                return notify_fail("你要吸什么？\n");
        if(query("muding/remaining") < 1)
                return notify_fail("木鼎中没有血水了。\n");
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成, 不能运功练毒。\n");
        if ( me->is_fighting())
                return notify_fail("你在战斗中不能运功练毒。\n");
        if ( me->query("neili") < 100)
               return notify_fail("你内力无法融合木鼎中的毒素。\n");

        message_vision("$N伸掌将血液接住，盘膝运功，将血液吸入掌内。\n", me);
        me->add("neili", -10);
        add("muding/remaining", -1);

        if ((int)me->query_skill("huagong-dafa", 1) < 100){
		F_POISON->poison_attack(this_object(),me,"xx_poison", 5);
              return 1;
        }

        if(random(10) > 6){
         switch(random(3)) {
                  case 0:
                  me->improve_skill("poison", me->query_skill("huagong-dafa")*(int)(me->query("con")/10));
                  write (RED"你只觉掌中微微一凉，一股阴气顺着脉络侵入脑髓。\n"NOR"你对基本毒技的领会又加深了一些！\n");
                  break;
            case 1:
                  me->improve_skill("xingxiu-duzhang", me->query_skill("huagong-dafa")*(int)(me->query("con")/10));
                  write (RED"你只觉掌中微微一痒，一股毒气自掌沿手臂上升。\n"NOR "你对抽髓掌的领会又加深了一些！\n");
                  break;
            case 2:
                  me->improve_skill("huagong-dafa", me->query_skill("huagong-dafa")*(int)(me->query("con")/10));
                  write (RED"你只觉掌中微微一痒，一股阴毒之气自掌沿手臂上升，直达丹田。\n"NOR "你对化功大法的领会又加深了一些！\n");
                  break;
          }
         }
         return 1;
}

