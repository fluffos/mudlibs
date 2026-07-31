inherit ROOM;

void create()
{
    set("short","休息室");
    set("long", @LONG
这里是武馆内的休息室，屋子有点点旧，但是打扫的非常干净，一排
床铺靠墙摆着，东面过去也是一间休息室，不断的有人进来休息或醒后
离去，你悄悄的找个空铺睡了下来。
LONG);
	set("exits", ([
	    "east" : __DIR__"woshi2",
            "south" : __DIR__"lang6",
        ]));
        set("no_get_from",1);
        set("no_fight",1);
        set("sleep_room", 1);
        set("no_get", 1);
	setup();
//     replace_program(ROOM);
}
