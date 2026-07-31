// Room: /d/snow/epath.c
inherit ROOM;
void create()
{
        set("short", "僻静小巷");
        set("long", @LONG
这里是条僻静的小巷子，往西不远处通往雪亭镇的广场，小巷
的北面是一些瓦屋，围绕著高高的围墙，看来是有钱人的屋子，南
边有家小药铺，门口挂了好些晒乾的药草，小巷往东是个转角。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
              "围墙": "这间屋子的围墙看起来相当高，不过如果你跳起来的话勉强可以够得著。\n"]));
        set("outdoors","xueting");
        set("exits", ([ /* sizeof() == 3 */
                "east" : __DIR__"lane1",
                "west" : __DIR__"guangchang_e",
                "south" : __DIR__"herbshop",
        ]));
        set("objects", ([
        // __DIR__"master/master-mei" : 1,
        ]) );
        set("outdoors","xueting");
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        if( arg!="围墙" ) return 0;
        message_vision("$N用手攀上围墙，蹬了几下翻了过去。\n", this_player());
        this_player()->move(__DIR__"kitchen");
        message("vision", this_player()->name() + "从围墙的另一头爬了过来。\n",
                environment(this_player()), this_player());
        return 1;
}
