//xuelian.c 雪中莲
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW "雪中莲" NOR, ({"xuelian", "xuelian"}));
        set("unit", "朵");
        set("long", "这是一朵生长在雪山上的雪莲，它洁白的花瓣上附着几颗晶
莹的露珠，正散发着淡淡的幽香\n");
        setup();
}

int do_eat(string arg)
{
        object me;
        me = this_player();
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if( me->query("max_neili") < 10000 ) 
        {
                me->add("max_neili",random(180));
//              this_player()->add("max_jing",random(15));
                message_vision( HIG"$N吃下一朵"NOR,me );
                message_vision( HIW"雪中莲"NOR,me );
                message_vision( HIG"，顿时觉得灵台一清，一股热气直穿任督二脉，头上冒出丝丝热气。\n"NOR,me );
        }
        else {
                message_vision( HIG"$N吃下一朵"NOR,me );
                message_vision( HIW"雪中莲"NOR,me );
                message_vision( HIG"，可是好象没有起到任何作用。\n"NOR,me );
        }
        destruct(this_object());
        return 1;
}

