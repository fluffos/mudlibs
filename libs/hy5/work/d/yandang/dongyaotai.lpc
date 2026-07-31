// Room: /d/yandang/dongyaotai.c

inherit ROOM;

void create()
{
	set("short", "东瑶台");
	set("long", @LONG
此处相临绝谷,其下山石如剑,其色赤红,背靠绝壁,壁立青霄,高不
可攀.与对面的天柱峰遥遥相对.两峰间有一座宽仅两尺的铁索桥.很是
危险.向西就是灵峰七洞了.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tieqiao1",
  "west" : __DIR__"dongwai",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
