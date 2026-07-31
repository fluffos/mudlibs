// xiandan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "仙品胭脂" NOR, ({ "per wan", "wan", "per" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "可以突破胭脂30容貌的存在，据说吃了可以越来越美丽，是每个女子梦寐以求的好东西。\n");
                set("value", 1);
                set("unit", "粒");
				set("tianji1", 1);
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$N一仰脖，吞下了一粒" + this_object()->name() +
                       "。\n", me);
        if (me->query("per") >= 90)
        {
                message_vision("$N忽然“哇哇”，吐了一地。\n", me);
                tell_object(me, "你觉得嘴里非常的苦。\n");
        } else
        {
                tell_object(me, HIG "你开始发觉你的容貌开始改变，变的漂亮多了。\n" NOR);
                me->add("per", 1);
        }

        destruct(this_object());
        return 1;
}

