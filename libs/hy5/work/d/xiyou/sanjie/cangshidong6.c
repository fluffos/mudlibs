// sanjie cangshidong6.c

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
              "west" : __DIR__"cangshidong4",
        ]));
        set("objects", ([
                __DIR__"npc/guiming": 1 ]) );
        setup();
}