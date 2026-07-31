// Room: /u/xiaozhen/dangpu.c

#include <room.h>

inherit HOCKSHOP;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你
的面前，柜台上摆着一个木牌(mupai)，柜台后坐着唐老板，一
双精明的眼睛上上下下打量着你。 
LONG
	);
	set("item_desc", ([
	"mupai" : "客倌可以在这里典当(pawn)、卖断(sell)各种货物
公平交易，老少无欺。\n\n",
	"木牌" : "客倌可以在这里典当(pawn)、卖断(sell)各种货物
公平交易，老少无欺。\n\n",
	]) );
	set("exits", ([
  "east" : __DIR__"nroad2",
	]));

	set("objects",([
	__DIR__"npc/tang" : 1,
]));
	setup();
}
