// sanjie cangshidong6.c

inherit ROOM;
void create()
{
        set("short", "藏尸洞");
        set("long", @LONG
        
一个古怪的山洞，隐隐觉得周围有人盯着，而且洞内臭气熏
天，像是腐烂的气味，摆着一些干草。
LONG );
        set("outdoors", 0);
        set("no_clean_up", 1);
  	set("sleep_room",1);
  	set("if_bed",1);
        set("exits", ([
              "south" : __DIR__"cangshidong4",
        ]));
        setup();
        replace_program(ROOM);
}