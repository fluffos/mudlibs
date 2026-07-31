#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "皇宫大殿");
	set("long", @LONG
这里便是紫禁城的正门的大殿，寻常百姓是到不了这里来的，如果你以不
正当的途径到了这里，还是赶快离开为好。
LONG NOR);
	set("exits", ([
		"north" : __DIR__"hgmen_n",
		"south" : __DIR__"hgmen_s",
		"west" : __DIR__"hg_w",
	]));
	set("objects", ([
		__DIR__"npc/yuqian1" : 2,
	]));
	set("outdoors", "beijing");
	setup();
}


