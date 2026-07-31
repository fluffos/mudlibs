// sanjie cangshilang2.c

inherit ROOM;
void create()
{
        set("short", "藏尸洞");
        set("long", @LONG
        
一个古怪的山洞，隐隐觉得周围有人盯着，而且洞内臭气熏
天，像是腐烂的气味。
LONG );
        set("outdoors", 0);
        set("exits", ([
              "north" : __DIR__"cangshilang3",
 //             "northwest" : __DIR__"cangshidong1",
              "east" : __DIR__"cangshidong2",
              "southdown" : __DIR__"cangshilang1",
        ]));
        setup();
}
