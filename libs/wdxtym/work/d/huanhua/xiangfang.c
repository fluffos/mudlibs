//xiangfang.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这里是间不大的房子。靠墙摆着一张檀木方几。几把竹椅整齐的靠在墙
边，南面的长窗往外可以看到幽静的竹林小院，阵阵山风掠过，飘来阵
阵竹叶的清香。
LONG
	);

	set("exits", ([
                "east" : __DIR__"dating",
		]));
	set("objects", ([
		  __DIR__"npc/xiaoqiushui" : 1,
	]));

	set("coor/x",50);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",50);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
