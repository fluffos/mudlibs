// Room: /d/tianshui/nroad2.c

inherit ROOM;

void create()
{
	set("short", "小镇北街");
	set("long", @LONG
北街是镇子里的繁华地段，一到晚上一派灯红酒绿，笑声、
歌声、琴声汇成一片，尤为热闹。西面店铺墙上写着一个大大的
“当”字，仔细倾听，可以听到压低的讨价还价的声音。东面则
是一片喧嚣，不时传来“开了！”“我押一百”的叫喊声。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dangpu",
  "south" : __DIR__"nroad1",
  "east" : __DIR__"duchang",
]));

	set("outdoors","tianshui");
	set("objects",([
	__DIR__"npc/beggar" : 2,
]));
	setup();
	replace_program(ROOM);
}
