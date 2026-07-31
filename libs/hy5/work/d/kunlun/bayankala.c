// bayankala.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "巴颜喀拉山");
		  set("long",@long
巴颜喀拉山山势低平，西接昆仑山垭口，又与通天河支流德曲相隔，沼泽
遍布。在山脚放眼望去，随处可见一处处沼泽草甸，乃是放牧各类牲畜的好地
方。远处散布着一顶顶牧民的蒙古包。
long);
		 set("exits",([
"northdown" : __DIR__"shanlu2",
"west" : __DIR__"kekexili",
]));

	set("objects",([
			__DIR__"obj/da-shitou.c" :  1,
	]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
