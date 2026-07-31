// Room: /d/linzhi/lin23.c

inherit ROOM;

void create()
{
	set("short", "高原红岩山道");
	set("long", @LONG
这里是高原红岩山道，山岩呈红色，山峰被白色积雪覆盖。
在阳光照射下，山体变幻着颜色。你看着看着，不禁被周围奇景
所陶醉。休息一下吧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin22",
  "southup" : __DIR__"lin24",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
