// room1 标准房间
// by augx@sj  3/19/2002

inherit ROOM;
#include <ansi.h>

void create()
{
	/* short */	set("short", "");
	set("long", @LONG
这是一个江湖中人金盆洗手之后开的一个镖局，这的镖师最讲信誉，你托
付他的事，无一不是按时完成。这里待遇丰厚，很多江湖中人都愿意替这里做
事。
LONG
	);

	set("indoors", "扬州");

	set("exits", ([
		"south" : "/d/city/dongmen",
	]));

	set("objects", ([
		__DIR__"npc/biaotou" : 1,
	]));


	set("ingroup",1);
	setup();
}

