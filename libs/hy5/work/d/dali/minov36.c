//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "星云湖畔");
	set("long", @LONG
星云湖又名小镜湖，方圆有十数里。东靠玉霞山，碧水清澈，风
光妩媚，乃是大理东部名景。明月之夜，皎洁的月光映照湖面，风拂
水波，摇曳生姿，如繁星落入湖中，晶亮如云，故名之。在此远眺湖
之东南岸，可见青青翠竹，似有房舍隐在其中。
LONG
        );

	set("exits", ([
		"eastup" : __DIR__"minov37",
		"north" : __DIR__"minov31",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
