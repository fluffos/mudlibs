#include <room.h>
inherit ROOM;

void create()
{
	set("short", "汇英酒楼");
	set("long", @LONG
汇英酒楼在整个京城中，也算是小有名气的了。酒楼里面雕梁画壁，装饰
有如宫殿，你可以在这里打听到各地的风土人情。店小二里里外外忙得不可开
交，接待着南腔北调的客人。楼里桌椅洁净。座中客人衣饰豪奢，十九是富商
大贾。
LONG );
       set("exits", ([
		"north" : __DIR__"yong_1",
		"up" : __DIR__"huiyingup",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("outdoors", "beijing");
	setup();
}

