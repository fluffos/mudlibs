//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "东泸水河谷");
	set("long", @LONG
西面这一大片河谷处在碧罗雪山和高黎山之间，由东泸水冲刷而
成，地势低洼，因而气候较温暖，聚居了大量乌夷族人。乌夷先民沿
河谷开发了一些梯田。四周山高林密，男子多从事狩猎。沿着脚下的
向西直抵一个大镇子。
LONG
        );

	set("exits", ([
		"westdown" : __DIR__"minov41",
		"eastup" : __DIR__"minov49",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
