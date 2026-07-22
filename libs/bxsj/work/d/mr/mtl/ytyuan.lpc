// /d/mr/ytyuan.c
// this is made by beyond
// update 1997.6.20
// rebuild by Lklv 2001.9.20

#include <ansi.h>
#include <room.h>
inherit ROOM;

int nokill()
{
	object ob = previous_object(1);

	if (ob == find_object("/cmds/skill/exercise")
	|| ob == find_object("/cmds/skill/respirate"))
		return 0;
	return 1;
}

void create()
{
	set("short",HIM"樱桃园"NOR);
	set("long",@long
这里是一个樱桃园，园子里种了大片大片的樱桃树，每到春天，这里的树
上都开满了粉红的樱桃花，非常漂亮。从这里向西望去，那边也是一个樱桃园。
long);
	set("outdoors","曼佗罗山庄");

	set("exits",([
		"west" : __DIR__"ytyuan2",
		"north" : __DIR__"midao",
		"south" : __DIR__"huandong",
	]));
	set("no_fight", (: nokill :));
	setup();
}
