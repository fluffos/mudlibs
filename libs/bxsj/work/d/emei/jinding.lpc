// Room: /d/emei/jinding.c 峨嵋派 金顶

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "金顶" NOR);
	set("long", @LONG
这就是峨嵋山的主峰金顶了。此峰耸立大地，高入云表，秀丽而又壮美，
李白赞颂它：『青冥倚天开，彩错疑画出。』登上金顶，视野豁然开朗，鸟看
脚下，但见群峰涌绿叠翠，三江如丝如带；回首远眺，则见大雪山横亘天际，
贡嘎山直插苍穹。
LONG
	);
	set("outdoors", "峨嵋山");
	set("exits", ([
		"northdown" : __DIR__"wanxingan",
		"southwest" : __DIR__"woyunan",
		"southup" : __DIR__"huazangan",
	]));

	set("valid_startroom",1);

	setup();

}
