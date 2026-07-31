 inherit ROOM;
void create()
{
        set("short", "浸龙走廊");
        set("long", @LONG
穿过浸龙的月形拱门，前面是一人多高，只容两人并行的檀香木走廊，廊中的
两侧陈列着一些奇花异草。滚滚热气从走廊的一头冒出，将檀木地板打得又湿又滑，
你几乎要扶着栏杆才不会滑倒。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlong",
                "north" : __DIR__"jlonglang2",
        ]));
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",0);
        setup();
} 
/*
int valid_leave(object me, string dir)
{
    if(  dir == "north" && (string)me->query("gender") != "男性")
        return notify_fail("这是男人浴室，你冲进去作什么？\n");
    return 1;
} 
*/
