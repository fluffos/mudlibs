// Room: /d/emei/gudelin3.c 峨嵋派 古德林3


#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "古德林");
	set("long", @LONG
你正走在一条林荫夹道上，路旁张满了楠树，株株秀挺俊拔，密实的枝叶
遮天闭日，把阳光遮得丝毫也无。厚厚的树叶已落满一地，踩上去十分的柔软。
从远方不时传来清脆的铃声。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gudelin2",
                "west" : __DIR__"dabeita",
	]));

	set("outdoors", "emei");
        setup();
}

