//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是一条熙熙攘攘的街道，是平日门土匪消遣玩乐的所在，赌场，妓院，浴室应有尽有。土匪过的是刀口上
舔血的生活，有今日没明日的，所以花起银子来特别痛快。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		  "east" : __DIR__"zjiedao1",
		  "north": __DIR__"zyushi",
		]));
 	  set("outdoors", "tiezhang");
    setup();
    replace_program(ROOM);
}
