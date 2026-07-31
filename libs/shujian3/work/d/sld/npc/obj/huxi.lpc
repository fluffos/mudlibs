// huxi.c

#include <ansi.h>
#include <combat.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("护膝", ({"hu xi", "huxi"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("long","这是一副神龙弟子所特有的玄铁护膝。\n");
                set("material", "steel");
                set("armor_prop/armor", 30);        
        }
        setup();
}

void init()
{
//          add_action("do_zhuiming","zhuiming");
}

int do_zhuiming()
{
        object me , target;
        int i,times ,hits,str;

        me = this_player();
        if ( !objectp(me->query_temp("zhuiming/target"))) return 0;

        target = me->query_temp("zhuiming/target");

        times = time()-(int)me->query_temp("zhuiming/time");

        if( times < 10) return notify_fail("你还在聚集真气呢。\n");

        if( times >= 10 && me->is_fighting(target) && times < 60){
                if( times > 60) times = 60;
                me->delete_temp("zhuiming/time");
                me->delete_temp("zhuiming/target");
                hits = 2 + times/10;
                str = 40 + hits * 4;

                me->add_temp("apply/strength",str);
                me->add_temp("apply/attack", me->query_skill("leg")/6);

                if (wizardp(me) ) tell_object(me,sprintf("str:%d\n",str));
        
                target->start_busy(2);
                message_vision(HIY+"\n\n$N猛然大喝一声，以聚集的真气激荡自己的筋脉，陡然提高了数倍的威力，\n"+
                                   "身形腿影如追命般扫向$n，顿时把$n淹没在连绵不尽的神龙追命腿中！\n",me,target);
                for( i=1; i<=hits; i++){
                   message_vision(HIY+"\n神龙追命第"+CHINESE_D->chinese_number(i)+"腿！"NOR,me);
                   COMBAT_D->do_attack(me, target, 0, TYPE_QUICK);
                }
                me->add_temp("apply/strength", -str);
                me->add_temp("apply/attack", -(me->query_skill("leg")/6) );
        }
        else {
                return notify_fail("使用「神龙追命腿」需要首先聚气！\n");
        }
        return 1;       
}
