// shulin3.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "树林");
    set("long", @LONG
这是一片树林，林中静悄悄的，树林鸟语相间，遥相和呼，更为这寂
静的树林增添了几分神秘。树林的西边是一片坟地，除了忌奠死去的亲人
一般很少有人来到这里。
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
            "west" : __DIR__"shangang",
	    "east" : __DIR__"shulin2",
          ]));

	setup();
	replace_program(ROOM);
}   