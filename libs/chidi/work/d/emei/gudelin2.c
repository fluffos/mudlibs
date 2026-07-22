// Room: /d/emei/gudelin2.c 峨嵋派 古德林2


#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "古德林");
	set("long", @LONG
一条林荫夹道，张满了楠树，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，
密实的枝叶遮天闭日，把阳光遮得丝毫也无。厚厚的树叶已落满一地，踩上去
十分的柔软。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gudelin",
                "west" : __DIR__"gudelin3",
	]));

	set("outdoors", "emei");
        setup();
}

