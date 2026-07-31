//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "大杆栏");
	set("long", @LONG
依着一棵大榕树，摆夷人在此建了一座相当大的杆栏。下层这里
有一满圈的十几头牛羊。旁边的楼梯修得颇宽。看来这里是本地的体
面人家。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov22",
		"up" : __DIR__"minov24",
		]));

	set("objects", ([
		__DIR__"npc/goat.c" : 3,
		__DIR__"npc/niu.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
