#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后洞");
        set("long", @LONG

    这是间极简陋的石室，想是张殷夫妇捕鱼打猎之余，烧陶作碗，
    堆土为灶，诸般日用物品，次第粗具。

LONG
        );
        set("no_sleep_room",1);
        set("no_fight", 1);
        set("objects", ([
                __DIR__"obj/qs-book":1,
        ] ) );
        setup();
}
void init()
{
        add_action("do_out","out");
}

int do_out()
{
        object me;
        me = this_player();
        if ( ( me->query_skill("qishang-quan",1) > 0 )  )
        {
                tell_object(me,"进来容易出去难啊。\n");
        }
        else
        {
                me->move(__DIR__"shidong");
                me->delete_temp("marks/hole");
        }
        return 1; 
}

