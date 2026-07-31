//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "杆栏中层");
	set("long", @LONG
这里是杆栏的中层，从楼梯一上来就是祭所。南诏蛮夷大多信奉
自己部族特有的神明，家家户户都居中室设案供奉。中层的其余房间
则为寝所。
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov14",
		]));

	set("objects", ([
		__DIR__"npc/bykid.c" : 1,
		]));

	set("cost", 2);
	setup();
}
