//Cracked by Roath
// Room: /d/xiangyang/kedian.c

inherit ROOM;

void create()
{
	set("short", "[1;36m襄樊客店[2;37;0m");
	set("long", @LONG
由于蒙古大军兵临襄阳城下，因此投宿客栈的客人也减少了许多，惟恐受到
波及。生意不好，又有战乱的威胁，店小二也一副愁眉苦脸的模样。店有几个
鬼鬼祟祟的家伙坐了一桌，嘀嘀咕咕地不知说些什么。墙上挂着一个牌子(paizi)
 ，已经有点破烂了。
LONG
	);
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("no_sleep_room", 1);
	set("coordinates", ([ "x" : 4, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"majiu",
  "up" : __DIR__"kedian2",
  "west" : __DIR__"jzjie1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "楼上雅房，每夜十两....后面的字因为牌子破损，看不清楚。
",
]));

	setup();
	replace_program(ROOM);
}
