// Room: /d/emei/maji.c

inherit ROOM;

void create()
{
        set("short", "马厩");
        set("long", @LONG
这是一间马厩，常年供应新鲜草料。此地民风淳朴，马夫们把马牵到马厩
好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到客人离店上路。
马厩中堆放著几堆草料，正中有一口泔槽(gancao)。
LONG
        );
        set("outdoors", "峨眉山");
        set("item_desc", ([ 
            "gancao" : "    这是一口泔槽，看来使点劲可以搬(move)开。\n",
]));
        set("exits", ([
  "south" : __DIR__"huayanding",
]));
//        set("no_clean_up", 0);

        setup();
}

void init()
{
    add_action("do_xian", ({"xian", "move"}));
    add_action("do_zuan", ({"zuan", "enter"}));
}             

int do_xian(string arg)
{
    object me = this_player();
    if (me->query_temp("marks/zuan"))
	return notify_fail("你吃饱了撑的？泔槽不是掀开了吗？\n");
    if (!arg) return 0;
    if (arg != "泔槽" && arg != "gancao" )
	return 0;
    message_vision("$N掀开了泔槽，弄得遍地泔水。\n", me);
    tell_object(me, "你发现泔槽下面有一个洞口可以钻进去。\n");
    me->set_temp("marks/zuan", 1);
    return 1;
}

int do_zuan(string arg)
{
    object me = this_player();
    if (!arg) return 0;
    if ( arg != "hole" && arg != "洞" && arg != "dong" && arg != "洞口" && arg != "dongkou")
	return 0;
    if (!me->query_temp("marks/zuan"))
	return 0;
    message_vision("$N一头钻进了泔槽的洞口。\n", me);
    me->delete_temp("marks/zuan");
    me->move(__DIR__"houshanxl");
    return 1;
}

