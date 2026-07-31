// Room: /u/xiaozhen/simiao2.c

inherit ROOM;

void create()
{
	set("short", "侧殿");
	set("long", @LONG
这里是乾圣寺的侧殿，一位老僧正在蒲团上打坐，一个小和
尚正在向进香来的人们卖乾圣寺的特制高香。
LONG
);

	
	set("NO_NPC", 1);
	set("exits", ([
  "north" : __DIR__"simiao",
]));
	set("objects",([
	__DIR__"npc/monk" : 1,
	__DIR__"npc/monk1" : 1,
]));

	setup();
	replace_program(ROOM);
}
