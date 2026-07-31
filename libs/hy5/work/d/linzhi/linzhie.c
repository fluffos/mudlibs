// Room: /d/xizang/linzhie.c

inherit ROOM;

void create()
{
	set("short", "林芝东口");
	set("long", @LONG
你来到这里，已进入林芝地区了，这里地处藏东南雅鲁藏布
江下游。该地区是门巴族、珞巴族等少数民族聚居地，民俗风情
特异。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : "/d/qingzh/xroad1",
  "west" : __DIR__"lin01",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3500);
	setup();
	replace_program(ROOM);
}
