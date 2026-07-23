// shop.c 燕原集

inherit ROOM;

void create()
{
        set("short", "燕原集");
        set("long", @LONG
这是草原中的一个大集市，这里也是草原中各样货物的集散地，只
问货物的好坏，不问货物的来源，虽然说是个集市多是由客商的帐篷所
组成。
LONG);
        set("exits", ([            
						"southwest":__DIR__"dongmen",
            "east" : __DIR__"room1",
            "northwest" : __DIR__"room2",
            "southeast" : __DIR__"caoyuan3",
        ]));        
          set("objects",([
          __DIR__"npc/shang":1,
          __DIR__"npc/ji":3,
          ]));

        set("outdoors", "dingxiang");
        
        setup();
        replace_program(ROOM);
}
