// Room: /d/songshan/chanyuan.c

inherit ROOM;

void create()
{
	set("short", "峻极禅院");
	set("long", @LONG
峻极禅院处嵩山绝顶，院中古柏森森，殿上并无佛像。院宇
辽阔，可容千人。
LONG );
	set("exits", ([
		"southdown" : __DIR__"junjigate",
	]));
	set("objects", ([
		__DIR__"npc/zuo" :1,
		__DIR__"npc/shi" :1,
		__DIR__"npc/di" :1,
	]));
	setup();
}

