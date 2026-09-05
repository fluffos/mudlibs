// cjgqian.c 藏经阁一楼
// seagate@pkuxkx by 2011.02.17
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "藏经阁三楼");
	set("long", @LONG
不愧为中原佛法的总源，少林寺此处藏经之富，天下罕有其
匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人
通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。目光
及处，你看到桌上放了几本佛经。
LONG
	);

	set("exits", ([
		"west" : __DIR__"cjg3dmgbook",
		"south" : __DIR__"cjg3othbook",
		"northeast" : __DIR__"cjg3fojing",
		"north" : __DIR__"cjg3equip",
		"southwest" : __DIR__"cjg3yao",
		"northwest" : __DIR__"cjg3gjyao",
		"down" : __DIR__"cjg2"
	]));

	setup();
}