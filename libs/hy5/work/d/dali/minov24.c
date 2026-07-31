//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "杆栏中层");
	set("long", @LONG
这个杆栏的中层面积颇大，宽敞开阔。正中的香案古色古香，贡
着的神像雕制精细，显得与众不同，大盘的贡品正飘出香味，尤其当
中的一个羊头特别抢眼。看来这里是本村的祭祀所。
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov23",
		]));

	set("objects", ([
		__DIR__"npc/byjisi.c" : 1,
		]));

	set("cost", 3);
	setup();
}
