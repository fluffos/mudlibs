// Room: /d/yandang/jiudian.c

inherit ROOM;

void create()
{
	set("short", "小酒店");
	set("long", @LONG
这是一家卖茶水酒饭的小店,几张饭桌现在都空着,店就在林下,靠
近大路,左手两间瓦屋,右首空地上搭了一个松棚,放上四五张桌板凳,如
此而已,小店没有招牌,只在松林前面挑着一个'酒'字的布帘.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/girl.c" : 1,
  __DIR__"npc/tianlaodie.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanxia",
  "south" : __DIR__"xiaolu",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
