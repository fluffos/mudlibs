// /d/chengdu/xiaonanmen.c
// By Jpei

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "小南门");
	set("long", @LONG
这是是成都的南侧门，是专门开给城郊的百姓运送货物进出城的。如果想
要入滇，可以从这里南下。城门的墙上张贴着一纸告示(gaoshi)。
LONG
	);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"north" : __DIR__"nancejie2",
	]));
        set("outdoors", "成都");
	setup();
}

string look_gaoshi()
{
 	return FINGER_D->get_killer() + "\n益州刺史\n司马远\n";
}

