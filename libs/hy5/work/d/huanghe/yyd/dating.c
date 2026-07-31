// 萧府大厅 dating.c
// zly 1999.06.10
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "萧府大厅");
        set("long", @LONG
这里便是萧府的大厅，气派非凡，装饰奢华，居中一张太师椅，大厅
上红烛高烧，中堂正中的绵轴上，贴着一个五尺见方的金色大“寿”字
，晋阳大侠萧半和正热情地招呼着来贺寿诞的各路英雄。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ 
            "north" : __DIR__"houyuan",
            "west" : __DIR__"chufang",
            "south" : __DIR__"damen",
            "east" : __DIR__"shufang"
]));

        set("objects", ([
            __DIR__"npc/xiao" : 1,
            __DIR__"npc/linyl" : 1,
            __DIR__"npc/renfy" : 1,
]));

        setup();
        //replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("ren feiyan", environment(me))) && 
		dir == "north")
		return notify_fail("任飞燕拦住了你的去路。\n");

	if ( objectp(present("lin yulong", environment(me))) && 
		dir == "north")
		return notify_fail("林玉龙拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}
