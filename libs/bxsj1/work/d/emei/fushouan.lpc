// Room: /d/emei/fushouan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",YEL "福寿庵" NOR);
	set("long", @LONG
福寿庵在神水庵南，是一个名叫天性的僧人建造的。庵前有九曲渠、流杯
池，古人曾据在此饮酒流杯，观景赋诗，歌咏兴叹，不知夕日。庵旁有株大海
棠树，数百苍龄，高达十余丈。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ 
	  "north" : __DIR__"shenshuian",
	  "enter" : __DIR__"lingwenge",
]));
	set("objects",([
		CLASS_D("emei") + "/jing-zhen" : 1,
		"/d/emei/npc/dizi" : 1,
]));
	setup();
}
