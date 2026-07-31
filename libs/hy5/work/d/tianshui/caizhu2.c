// Room: /u/xiaozhen/caizhu2.c

inherit ROOM;

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里就是洪家的正厅了，各种古玩琳琅满目，商周青铜、秦
砖汉瓦应有尽有，没想到一个小镇子上的财主家会这么富有。洪
百万正坐在厅中的躺椅上，慢幽幽地喝着参汤。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caizhu1",
  "south" : __DIR__"caizhu3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
