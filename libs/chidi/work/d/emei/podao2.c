// Room: /d/emei/podao2.c 峨嵋派 坡道2

inherit ROOM;

void create()
{
	set("short", "坡道");
	set("long", @LONG
这条窄窄的上山小路，一直笔直而上。道路越见陡峭，你不由得阵阵心
寒，恐怕不小心便会跌堕到崖谷之中。你艰难行走在天然形成得一格格石阶
上，已经感到非常疲劳。
LONG
	);

	set("exits", ([
                "northdown" : __DIR__"podao1",
                "southup": __DIR__"xixiangchi",
	]));

        set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}



