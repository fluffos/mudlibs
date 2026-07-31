//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "阳宗镇");
	set("long", @LONG
这里是强宗部的村镇，是么些蛮族的聚居区域，么些蛮族是摆夷
的一支。此处也是山间的小型平原，北面临着一片绿水，叫做明湖，
这地方略微偏远些，但有相当不少的摆夷人生活在附近。西南方有道
路通向其它村镇。
LONG
        );

	set("exits", ([
		"westup" : __DIR__"minov18",
		"northeast" : __DIR__"minov22",
		"southup" : __DIR__"minov25",
		"southwest" : __DIR__"minov26",
		]));

	set("objects", ([
		__DIR__"npc/byshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
