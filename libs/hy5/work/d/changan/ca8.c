// Room: /d/changan/ca8.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "打铁铺");
	set("long", @LONG
你刚走进来，就感到这里热气腾腾，四周的墙上挂着铁器，大部
分都是已经打好的铁锤，长剑，菜刀，匕首等物。中间摆着个旺盛的
火炉，一个铁匠正在火炉旁卖力的敲打着。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ca7",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
