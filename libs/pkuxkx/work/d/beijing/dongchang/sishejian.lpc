#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"司设监"NOR);
	set("long",
HIC"大厅内摆放着各种仪式使用的器具、帷幕、大鼓等。可能是刚刚进行
完一个仪式，几个内侍太监正在整理物品，不时有人嘴里发出抱怨的声音。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"yinshoujian",
		"north" : __DIR__"shengongjian",
//		"east" : __DIR__"citang",
	]));
  set("objects", ([
               __DIR__"npc/zhenghe" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
