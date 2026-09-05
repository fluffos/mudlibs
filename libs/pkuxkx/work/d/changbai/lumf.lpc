
// Room: lumf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "鹿鸣峰");
	set("long", @LONG
这里已是长白主峰之一，又叫芝盘峰，位于天池的西北面。峰顶有一草
甸子，圆形如盘，每到严寒的冬季，其它各峰已是积雪覆盖时，唯有此峰还
露在白雪之外，因此也是进山的参客辨别位置的重要标记。据说在这周围的
杂草之中就生长着人参，不知道搜索一下能否有所发现。
LONG	);
	set("exits", ([
              "westdown" : __DIR__"jiglz",
              "southeast" : __DIR__"yuzf",
        ]));
/*
        set("objects",([
		__DIR__"npc/laohu" : 1,
	]));
*/
        set("outdoors", "changbai");

        set("count", random(3) + 1);
        set("beast", random(5) + 1);

	setup();
}
