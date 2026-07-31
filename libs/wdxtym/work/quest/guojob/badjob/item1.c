
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"石灰粉"NOR, ({ "shi huifeng", "huifeng" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一包石灰粉可以(sa)。\n") ;
                set("unit", "包");
                set("value", 0);
        }
        setup();
}

void init()
{
        add_action("do_shot","sa");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;

        me = this_player();


        if( !arg ) return notify_fail("你想对谁撒石灰粉？\n");

        if( !objectp(target = present(arg, environment(me))) )
                return notify_fail("这里没有这个人。\n");


       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「石灰」只能在战斗中使用。\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");

        if(userp(target))
                return notify_fail("不能对玩家用这么下流的手法。\n");

        if( (string)this_player()->query("family/family_name")!="神龙教" ) {
                message_vision("\n$N你不能用这种下三流的手法！\n", me);
                return 1;
                }
        message_vision(HIR"\n$N一声轻笑，一大包石灰铺天盖地的撒了出来!\n"NOR,me,target);
        me->start_busy(1) ;
        if( !target->is_killing(me) ) target->kill_ob(me);
        if( random(me->query("combat_exp"))<target->query("combat_exp")/2)
        message_vision(HIW"\n$n大叫一声，猛的一个旱地拔葱身行冲起数丈来高，堪堪躲过了$N的石灰！\n"NOR,me,target);
        else {
                message_vision(HIW"\n$n躲闪不及，被石灰撒了一身！\n"NOR,me,target);
                tell_object (target, HIR "\n你只觉得脸上一黑，什么也看不见了!\n"NOR);
                target->start_busy (6);
                }
        destruct(this_object());
        return 1;
}

