// Room: /d/linzhi/lin48.c

inherit ROOM;

void create()
{
	set("short", "高原平坡叉道");
	set("long", @LONG
这里是高原坡叉道，路面十分平整。你走在路上，看着蓝蓝
的天，白白的云，心中十分暇逸。远处一群不知什么羊正在悠闲
地吃着草，不时发出咩咩的叫声。东去不远就是八一镇了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"byw",
  "northwest" : __DIR__"lin49",
  "southeast" : __DIR__"lin47",
  "south" : __DIR__"lin69",	
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3500);
	setup();
	replace_program(ROOM);
}
