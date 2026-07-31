// Room: /d/linzhi/lin24.c

inherit ROOM;

void create()
{
	set("short", "红岩山路");
	set("long", @LONG
这里是高原红岩山道，山岩呈红色，山峰被白色积雪覆盖。
在阳光照射下，山体变幻着颜色。你看着看着，不禁被周围奇景
所陶醉。东南不远就是梅里雪山。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"lin20",
  "northdown" : __DIR__"lin23",
  "southwest" : __DIR__"lin25",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 5400);
	setup();
	replace_program(ROOM);
}
