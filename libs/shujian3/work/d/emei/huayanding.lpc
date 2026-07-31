// Room: /d/emei/huayanding.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "华严顶" NOR);
	set("long", @LONG
华严顶挺拔高峭，古刹云深，殿宇孤耸，风景奇险。这里视野开阔，仰可
见金顶巍巍，俯可望群峰罗列，许多蹲伏山间的寺院也在眼底。由此向西过数
坡，即到莲花石，东下过十二盘可到万年寺。北面是一间马厩。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([
  "westup" : __DIR__"lianhuashi",
  "eastup" : __DIR__"xianfengsi",
  "north" : __DIR__"maji",
  "down" : __DIR__"shierpan4",
]));
	set("objects",([
		CLASS_D("emei") + "/li-mingxia" : 1,
]));
	setup();
}
