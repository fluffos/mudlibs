// Room: /d/xingxiu/shashan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "鸣沙山");
	set("long", @LONG
这是一座黄沙堆积形成的山。微风吹动，沙山发出嗡嗡的响声。
故而当地人称之为鸣沙山。沙土中似乎有一种虫子在蠕动。
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shachong" : 3,
]));
	set("no_new_clean_up", 0);
	set("outdoors", "xingxiuhai");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"silk3",
  "west" : __DIR__"yueerquan",
]));

	setup();
	replace_program(ROOM);
}
