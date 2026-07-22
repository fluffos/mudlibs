// Room: /d/emei/heilongjiangzd.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "黑龙江栈道" NOR);
	set("long", @LONG
黑龙江栈道沿黑龙江而建。这里一山中开，两崖并立，形成一道宽仅数尺，
长达几百米的深峡——白云峡。黑龙江栈道就从狭窄的白云峡中转折穿过，架
设在绝壁上。走在栈道上，只觉道窄人危；俯视深涧，急流飞旋，山静而觉动；
仰观头顶，天光如隙，崖开而欲合。这就是天开画图的「一线天」。栈道南通
千佛庵，北至清音阁。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"heilongjiangzd2",
  "northeast" : __DIR__"qingyinge",
]));
	set("no_clean_up", 0);

	setup();
}
