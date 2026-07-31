// Room: /d/linzhi/lin19.c

inherit ROOM;

void create()
{
	set("short", "高原坡道");
	set("long", @LONG
这里是高原坡道区，起面向西迅速拔高，东面是河谷区的丘
陵地带。你走到这里，看见不远处雪山高耸，阳光照耀下，泛出
点点白光闪闪。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin18",
  "westup" : __DIR__"lin20",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
