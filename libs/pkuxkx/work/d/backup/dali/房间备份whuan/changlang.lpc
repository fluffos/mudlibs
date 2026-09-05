// /d/dali/changlang
// notme 2004/04/13
// 添加描述
inherit ROOM;

void create()
{
set("short", "长廊");
	set("long", @LONG
此乃天龙寺之要道，虽是寺庙可装饰也是异常华丽，足显天龙寺
皇家寺庙的风采。前方就是天龙寺方丈所在地。
LONG
	);
set("outdoors", "dali");

	set("exits", ([
"north" : __DIR__"dadian",
"southdown" : __DIR__"duanhe",
	]));
      set("objects", ([
__DIR__"npc/benchen" : 1,
__DIR__"npc/shami" : 2 ]) );
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
