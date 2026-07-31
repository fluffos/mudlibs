//lianwuchang.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这是浣花剑派的练武场，浣花弟子每天总是在这里勤练武功，有时连萧
秋水也亲自到这里来指导派中子弟，所以每天这里都是人头簇拥、热闹
非凡，景况甚为壮观。
LONG
	);

	set("exits", ([
		"south" :__DIR__"changlang3",
		]));
	set("objects", ([
    "/adm/npc/renou" : 1,	
	]));

	set("outdoors", "mingjiao");
	set("coor/x",100);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
