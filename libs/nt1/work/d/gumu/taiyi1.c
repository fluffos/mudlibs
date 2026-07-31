// taiyi1.c
// Java Oct.10 1998
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "太乙池");
        set("long", @LONG
你眼前出现一个山间湖泊，这就是著名的太乙池 (chi)，传为唐
天宝年间地震造成，四周高峰环列，池面碧波荡漾，山光水影，风景
十分优美。
LONG
        );
        set("outdoors", "gumu");
        set("item_desc", ([
                "chi" : 
HIG"\n\n这是一个很大的山间湖，碧波荡漾，湖水清澈见底，让人忍不住想跳(jump)下去
畅游一番。\n\n"NOR
        ]));
        set("exits", ([
                "southup"   : __DIR__"shandao3",
        ]));

        setup();
}
void init()
{
        add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me = this_player(); 
        int c_exp;
        c_exp = me->query("combat_exp");
        if( !arg || arg != "chi")
        {
                write("你往哪里跳呀? \n");
                return 1;
        }

        message_vision("$N往太乙池中跳去。\n", me);
        me->move("/d/gumu/taiyi2");
        message_vision("$N跳进了太乙池中来。\n", me);
        return 1;
}
