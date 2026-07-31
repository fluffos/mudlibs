// Room: /u/xiaozhen/gongjiang.c

inherit ROOM;

void create()
{
	set("short", "工匠家");
	set("long", @LONG
这里是镇里的工匠李大爷的家，屋子里摆满了各种工具，桌
子上摊着一张图，上面画着一些奇怪的符号，李大爷坐在桌子边。
它的小孙子正缠着他闹。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wroad2",
]));
	set("objects",([
	__DIR__"npc/sunzi" : 1,
	__DIR__"npc/grand_li" : 1,
]));
	setup();
	replace_program(ROOM);
}
