// /u/beyond/hz/cuihezhai.c 翠合斋
#include <ansi.h>
 
inherit ROOM;
void create()
{
	set("short",HIW"翠合斋"NOR);
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜
台上摆着一个牌子(sign)，柜台后坐着位老板，一双精明的眼睛上上下下打
量着你。
LONG
	);
	set("no_sleep_room",1);
        set("no_fight",1);
	set("item_desc", ([
		"sign" : "公平交易\n",
	]));
	set("objects", ([
		__DIR__"npc/dplaoban" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"qsddao4",
	]));

	set("coor/x",110);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}

 