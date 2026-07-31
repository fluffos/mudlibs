
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/fengtian/guanlu4.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
进入盛京城门后是一条宽阔的官道，这条官道通向盛京新汇
路，那里是盛京北城的繁华所在。
LONG
	);

	set("exits", ([
  "south" : __DIR__"xh3",
  "north" : "/d/yanjing/gate",
]));
        set("outdoors", "fengtian");

	set("objects",([
"/clone/npc/man" : 2,
]));

	setup();

	replace_program(ROOM);
}
