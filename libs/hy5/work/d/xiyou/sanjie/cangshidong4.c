// sanjie cangshidong4.c

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
              "north" : __DIR__"cangshirest",
              "west" : __DIR__"cangshidong5",
              "east" : __DIR__"cangshidong6",
              "south" : __DIR__"cangshidong3",
        ]));
        setup();
}