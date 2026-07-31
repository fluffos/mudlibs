// Room: /d/zuojiacun/lu1.c

inherit ROOM;

void create()
{
	set("short", "华亭镇口");
	set("long", @LONG
这里就是华亭镇了，在这靠近东海湾的小村子里，多数村民
都是以捕鱼为生。一般情况下，当男人外出打鱼的时候，女人们
则在家里忙一些家务，还要为男人准备饭菜。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/jiaxing/jiaxing",
  "east" : __DIR__"lu2",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
