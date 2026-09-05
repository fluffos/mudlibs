// File		: bridgee.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", YEL"桥头"NOR);
	set("long", @LONG
深谷之上，一条铁索连接了两边的峭壁。铁索长倒不长，只是架在这高寒之
地，不由得不让人心惊胆寒。桥头立了一块石碑(shibei)，还有一座小屋，想来
是为过往行人提供一个存马的所在。
LONG);

	set("outdoors", "凌霄城");
	set("no_sleep_room", 1);
	set("item_desc", ([
		"shibei" : "这块石碑乃是天然形成，上面刻着「"HIR"一线索"NOR"」几个字。\n",
	]));
	set("exits", ([
		"south" : __DIR__"xuedi5",
		"west" : __DIR__"yixiansuo",
		"northeast" : __DIR__"xiaowu",
		"east" : __DIR__"machehang",
	]));

	setup();
	replace_program(ROOM);
}
