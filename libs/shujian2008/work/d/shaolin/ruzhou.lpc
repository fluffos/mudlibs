// Room: /d/shaolin/ruzhou.c

inherit ROOM;
void create()
{
	set("short", "汝州城");
	set("long", @LONG
汝州城是本府的大城，立来是兵家必争之地。故州治在此驻扎重兵，盘查
南来北往的行人，并负责翦灭附近山上的草寇。城内一队队官兵来来去去，一
派森严气象。再折向西，就是五岳之一的嵩山。
LONG
	);
	set("outdoors", "汝州");
	set("exits", ([
		"south" : "/d/nanyang/yidao3",
		"west" : __DIR__"shijie1",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
                CLASS_D("gaibang/qnqigai") : 1,
        ]));
	setup();
}
