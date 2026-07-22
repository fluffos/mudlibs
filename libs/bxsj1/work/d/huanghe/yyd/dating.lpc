// 萧府大厅 dating.c
// zly 1999.06.10
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "萧府大厅");
        set("long", @LONG
这里便是萧府的大厅，气派非凡，装饰奢华，居中一张太师椅，大厅上红
烛高烧，中堂正中的绵轴上，贴着一个五尺见方的金色大“寿”字，晋阳大侠
萧半和正热情地招呼着来贺寿诞的各路英雄。
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
	]));

        setup();
}
