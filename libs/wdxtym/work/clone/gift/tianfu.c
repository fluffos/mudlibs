

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "天赋丹" NOR, ({ "tianfu", "dan" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗可以让你转换天赋的药丸。\n");
                set("value", 5000);
                set("unit", "颗");
                set("per",10);
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{

        log_file("static/using", sprintf("%s(%s) eat 天赋丹 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);

        message("vision", "你身上的骨头啪啪的作响，似乎感觉自己的体格发生了不小的变化！\n",
                          environment(me), ({ me }));

		UPDATE_D->born_playerone(me);

        destruct(this_object());
        return 1;
}
int query_autoload() { return 1; }

