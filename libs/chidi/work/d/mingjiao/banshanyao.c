// Room: banshanyao.c

inherit ROOM;

void create()
{
        set("short", "半山腰");
        set("long", @LONG
你来到了个如同世外桃源的地方，这里是半山腰，只有一块巴掌大的
地方供人落脚，更让人奇怪的是就在这个小的不能再小的地方却顽强的生
长着一棵桃树，它的根深深的扎在岩石中，让人不禁感到生命力顽强的真
谛，树上还结满了果实，让人垂涎欲滴！下面是黑黝黝的一片，依然的烟
雾腾腾，紫气环绕，诡秘异常……
LONG
        );
set("objects",([__DIR__"npc/obj/mitao" : 1,
                __DIR__"npc/obj/taoshu" : 1,
]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
           add_action("do_jumpdown", "jumpdown");
         add_action("do_jumpup", "jumpup");
}

int do_jumpdown(string arg)
{
        object me;
        me = this_player();

        message_vision("$N毫不考虑，一个纵身，跳了下去。\n", me);
                environment(me), ({me});
 me->move("/d/mingjiao/hantan.c");
message_vision("$N空中变换身形，一个空翻，轻飘飘地落在地上！\n", me);
                environment(me), me;
                return 1;
}
int do_jumpup(string arg)
{
        object me;
        me = this_player();
        message_vision("$N两膝略曲，双足一点地，提气纵身，拔地而起！\n", me);
me->move("/d/mingjiao/shanya.c");
                message_vision("空中变换身形，一个空翻，轻飘飘地落在地上！\n", me);

        return 1;
}

