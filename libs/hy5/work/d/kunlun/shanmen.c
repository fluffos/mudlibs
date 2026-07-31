// shanmen.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "昆仑派山门");
		  set("long",@long
你一路走来，饱受大风黄沙之苦，渐渐树木多了起来，不时可听见枝叶
中传来的鸟鸣，路边草丛偶尔也能发现一些开着的野花。到得这里，已是绿
树红花，十分茂盛，你万万没想到深山中却有如此所在，精神大为一振。前
面是一座山门，写着“昆仑派”三个大字。
long);
		 set("exits",([
"west" : __DIR__"shanmen2",
"eastup" : __DIR__"shanlu01",
"southdown" : __DIR__"klshanlu",
]));
set("objects",([
"/clone/misc/dache" : 1 ,
            "/kungfu/class/kunlun/jiangtao" : 1,
        __DIR__"npc/kl-dizi1" :  1,
		__DIR__"npc/kl-dizi2" :  1,
]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
