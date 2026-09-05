// xuelian.c by becool 2008
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
        add_action("do_put", "put");
        add_action("do_drop", "drop");
}
void create()
{
        set_name(HIB"雪莲花"NOR, ({"xue lianhua", "lianhua"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "坨");
                set("long", "这是生长在高山雪原上的一坨罕见的蓝色雪莲花。\n");
                set("value", 0);
                set("no_pawn", 1);
                set("no_sell", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_store", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_get", 1);
                set("no_drop", 1);
        }
        setup();
}
int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))
                return notify_fail("你要吃什么?\n");
        me->add("max_neili", 50);
        me->add("max_jingli", 50);
        message_vision(NOR "$N小心翼翼的吞下一坨"HIB"雪莲花"NOR"，只觉一股极寒之气自丹田冲向四肢百骸....\n" NOR, me);
        destruct(this_object());
        return 1;
}
int do_drop(string arg)
{
        object me=this_player();
        if (!id(arg))
                return notify_fail("你要扔什么?\n");
        message_vision(NOR "$N丢下一坨"HIB"雪莲花"NOR"，只见蓝色的花瓣渐渐化做一滩蓝水，随风而逝了....\n" NOR, me);
        destruct(this_object());
        return 1;
}
