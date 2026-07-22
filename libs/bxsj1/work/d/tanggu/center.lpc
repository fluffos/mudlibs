inherit ROOM;
void create()
{
        set("short", "中心广场");
        set("long", @LONG
这里是塘沽城中心广场，是塘沽口最繁华的所在。白天这里人声鼎沸晚上
更是灯火通明，忙碌了一天的人们晚上总喜欢到这里走一走，广场上卖各种东
西的都有，不少江湖人物混迹其中。
LONG );

        set("exits", ([
                "north" : __DIR__"stbeijie1",
		"south" : __DIR__"stnanjie2",
                "southeast" : __DIR__"kongchangdi",
		"east" : __DIR__"stdongjie1",
		"west" : __DIR__"stxijie1",
	]));

	set("outdoors", "塘沽");

	set("objects", ([
                __DIR__"npc/shuibing" : 2+random(2),
      	]));

	setup();
}
