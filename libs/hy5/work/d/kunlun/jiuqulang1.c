// jiuqulang1.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "九曲廊");
		  set("long",@long
九曲廊前后共有九进，曲曲折折地盘旋在水面。一路穿花度柳，抚石依
泉，落花浮荡，水色溶溶。两边垂柳杂着桃杏，藤蔓绕柱。白石为栏，飞楼
插空，转折处皆由小亭相接。
long);
		 set("exits",([
"west" : __DIR__"tieqinju",
"east" : __DIR__"sanshengtang",
]));
setup();
replace_program(ROOM);
}
