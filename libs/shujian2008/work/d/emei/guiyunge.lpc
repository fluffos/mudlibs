// Room: /d/emei/guiyunge.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "归云阁" NOR);
	set("long", @LONG
归云阁，原是唐代福昌达道禅师的道场。宋代绍兴年间，僧人士性又率众
重建。归云阁左有玉女峰，西上可抵纯阳殿，东下是观音堂。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ 
	  "southup" : __DIR__"yunvfeng",
	  "eastdown" : __DIR__"guanyintang",
	  "westup" : __DIR__"chunyangdian",
]));
	set("objects",([
		"/d/emei/npc/dizi2" : 2,
]));
	setup();
}
