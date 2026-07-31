// Room: /d/yanjing/hualou1.c

inherit ROOM;

void create()
{
	set("short", "画楼二层");
	set("long", @LONG
画楼南边一排镂花的阁窗,窗下是青青果树,曲折回廊,对着窗的不远摆
了张小矮几,一副尚未完工的工笔牡丹摊开在上面,墙上挂了支白玉长萧.几
幅工笔山水,花鸟占据了剩下的墙面.
LONG
	);
//	set("objects", ([ /* sizeof() == 1 */
//..  __DIR__"npc/clone/clothbaiyuxiao.c" : 1,
//]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hualou",
]));

	setup();
	replace_program(ROOM);
}
