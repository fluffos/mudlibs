// Room: /d/paiyun/lu2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
曲折的小路不断向前，两边的建筑也渐渐多起来，营房里进
出的士兵越来越多，一些村妇在生火做饭，远远的你可以看见一
些山高处的建筑。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yingfang",
  "south" : __DIR__"lu1",
  "east" : __DIR__"chaifang",
  "north" : __DIR__"dayuan",
]));
	set("outdoors", "paiyun");

	set("objects",([
	__DIR__"npc/shanfei" : 2,
	__DIR__"npc/fei_tou" : 1,
]));

	setup();
	replace_program(ROOM);
}
