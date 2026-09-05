//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后院广场");
	set("long", @LONG
这里是一个由大理石铺成的广场，面积很大，足以容纳几千人。西边是一条熙熙攘攘的街道，是平日门土匪
消遣玩乐的所在。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		  "south" : __DIR__"zguangmingdian",
		  "northup" : __DIR__"zxuanya",
		  "west" : __DIR__"zjiedao1",
		]));
 	  set("outdoors", "tiezhang");
    setup();
    replace_program(ROOM);
}
