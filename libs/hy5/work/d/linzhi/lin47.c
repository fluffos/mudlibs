// Room: /d/linzhi/lin47.c

inherit ROOM;

void create()
{
	set("short", "高原平坡道");
	set("long", @LONG
这里是高原平坡道，路面十分平整。你走在路上，看着蓝蓝
的天，白白的云，心中十分暇逸。远处一群不知什么羊正在悠闲
地吃着草，不时发出咩咩的叫声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin48",
  "southeast" : __DIR__"lin44",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
