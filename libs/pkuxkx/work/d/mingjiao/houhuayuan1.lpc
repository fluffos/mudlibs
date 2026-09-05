 // houhuayuan1.c.c
// by yuer
inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是光明顶的后花园，种满了花草。几个小童正在浇花
北边有一个幽雅的小屋。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"neishi",
  "south" : __DIR__"dadian",
  "east"  : __DIR__"houhuayuan3",
  "west":__DIR__"houhuayuan2",
]));
        set("objects", ([
                __DIR__"npc/xiaozhao" : 1,
                __DIR__"obj/gang" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "mingjiao" );
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && objectp(present("xiao zhao", environment(me)))
        && living(present("xiao zhao", environment(me))))
            return notify_fail("小昭喝道：这是小姐的闺房，外人不得入内。\n");
        return ::valid_leave(me, dir);
}
