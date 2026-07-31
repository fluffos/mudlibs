// Room: /open/dt/yamen.c

inherit ROOM;

void create()
{
	set("short", "巡抚衙门");
	set("long", @LONG
正中的墙上端正地挂着一块匾，上书“明镜高悬”四个大字，
正堂壁上绘着一副怒海腾蛟图，把大堂衬托得十分威严。大同巡
抚张顺中是大将军李如风的私交好友，为人刚正不阿，他与李如
风一将一相，将大同府治理得井井有条。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jinyangjie3",
]));

	setup();
	replace_program(ROOM);
}
