
inherit ROOM;

void create()
{
	set("short", "汝州城");
	set("long", @LONG
汝州城是本府的大城，立来是兵家必争之地。故州治在此驻扎重
兵，盘查南来北往的行人，并负责翦灭附近山上的草寇。由于这里是
北上京城的必经之道，官兵盘查也十分严格。从这里向西出城门，可
以到五岳之中的嵩山了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaozheng",
      "north" : "/d/city2/road9",
		"west" : __DIR__"wangxi-lu",
		"east" : __DIR__"hong-damen",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



