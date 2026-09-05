#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;
void create()
{
	set("short", HIG"庄门"NOR);
	set("long","顺着青石板大路来到一所大庄院前，庄子周围小河环绕，河边满是
绿柳，在甘凉一带竟能见到这等江南风景，所有人都会为之胸襟一爽。
只见庄门大开，吊桥早已放下，一位穿着男装的小姐站在门口迎接。庄
门正上方高悬匾额，写着四个大字。\n\n"
+HIC"      ◎───────────────────────◎\n"
+"      │                                              │\n"
+"      │                "HIG"绿  柳  山  庄"HIC"                │\n"
+"      │                                              │\n"
+"      ◎───────────────────────◎\n\n"NOR);
	set("outdoors", "lvliu");
	set("exits", ([
		"north" : __DIR__"dating",
	]));
	setup();
}



