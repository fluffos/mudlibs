// Room: /d/xingxiu/jyge.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "南城门");
	set("long", @LONG
这是就是兰州的南城门。再往北就进城了，这儿有军队驻扎，不时盘问来
往行人。你小心翼翼，急步离开这是非之地。出关向南，是通往青城镇的大道。
城门的墙上张贴着一纸告示(gaoshi)。
LONG);

	set("outdoors", "兰州");

	set("exits", ([
		"north" : __DIR__"lanzhou",
		"south" : __DIR__"sroad1",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n全国通缉。\n";
}
