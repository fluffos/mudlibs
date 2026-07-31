// Room: /d/zuojiacun/mujiang.c

inherit ROOM;

void create()
{
	set("short", "木匠店");
	set("long", @LONG
这是村里的木匠店，屋里摆满了各种桌椅凳子，几个伙计正
在旁边忙活儿着。一个四十多岁的男人站在一边指指点点，看起
来像是老板的样子。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu16",
]));
  	set("objects",([
	__DIR__"npc/mujiang" : 1,
]));
	setup();
	replace_program(ROOM);
}
