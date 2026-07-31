// Room: /d/heimuya/zhaoze/shanbian1.c
inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", "山边");
        set("long", @LONG
只见山边一条手臂粗细的长藤，沿峰而上。仰头上望，见山峰的上半
截隐入云雾之中，不知峰顶究有多高。
LONG
);
        set("exits", ([ 
  "south" : __DIR__"shanbian",
]));
        set("outdoors", "shanbian1");

        set("item_desc", ([
        "长藤" : "你可以顺着它爬上山去。\n",
        ]));
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg!="长藤") return notify_fail("你要爬什么？\n");
            message("vision", me->name() + "顺着长藤爬了上去。\n",
                    environment(me), ({me}) );
        me->move(__DIR__"fongdian");
            message_vision("$N气喘吁吁地爬了上来。\n", me);
        return 1;
}

