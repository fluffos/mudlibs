// guiyunzhuang/zoulang3走廊

inherit ROOM;

void create()
{
         set("short", "走廊");
        set("long", @LONG
这里是归云庄的长廊，里面不时穿梭着忙碌着的仆人。
LONG);
         set("exits", ([ /* sizeof() == 2*/
         "west" : __DIR__"dating",
         "east" : __DIR__"guan",
                  ]));
	set("objects",([__DIR__"npc/kid":2,]));
	setup();
	replace_program(ROOM);
}
