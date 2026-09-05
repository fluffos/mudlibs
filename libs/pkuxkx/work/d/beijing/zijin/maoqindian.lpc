// Room: /d/beijing/zijin/maoqindian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"懋勤殿"NOR);
	set("long",
HIC"这是内翰林官的值班处,御用图书,文具存在
此处.康熙皇帝曾在此读书。
    每年秋季,皇帝亲自审阅裁定一些刑部经办的
重大案件也在这里进行。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"pibenchu",
  	"eastup" : __DIR__"qianqinggong",
]));

	setup();
	replace_program(ROOM);
}
