// Room: /u/wsl/changan/ca1.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "茶庄");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八
仙桌一字排开，坐满了客人。一位老者正在堂前弹奏，几个儒生击几
而歌。的确是个悠然去处。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ca17",
]));

	setup();
	replace_program(ROOM);
}
