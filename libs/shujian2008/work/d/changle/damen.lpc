// Room: /d/changle/damen.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "大门");
	set("long", @long
这里便是威镇江南的长乐帮总舵所在。长乐帮在江湖上声势非同小可，近
年来更是日渐兴旺。两扇红漆大门上钉着狰狞的虎头，几个满脸横肉的帮众站
在两侧。门上有一个大匾(bian)，两盏气死风灯来回摇摆。旁边有一座碑，上
面刻着一些文字。
long
	);

	set("exits", ([
		"enter" : __DIR__"dating",
		"south" : __DIR__"xiaolu",
	]));

	set("item_desc",([
		"bian" : HIY"
            ※※※※※※※※※※※※※※※※※※
            ※※※※　　　　　　　　　　※※※※
            ※※※※　                  ※※※※
            ※※※※   长    乐    帮   ※※※※
            ※※※※　                  ※※※※
            ※※※※　　　　　　　　　　※※※※
            ※※※※※※※※※※※※※※※※※※\n"NOR,
	]));

	set("objects", ([
		__DIR__"npc/bangzhong" : 2,
		__DIR__"npc/qiu": 1,
	]));

	set("outdoors", "长乐帮");

	setup();
}
