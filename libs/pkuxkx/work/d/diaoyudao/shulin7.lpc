// Room: /d/diaoyudao/shulin7.c 树林
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这里有一大片临近海滩的树林，海风轻轻吹过，树梢萧萧作响，和着林
中鸟儿的鸣叫，一种说不出的幽静、和平的感觉，使你流连忘返。
LONG
	);

	set("exits", ([
                 "east" : __DIR__"shulin6",
		"south" : __DIR__"shulin",
                 "west" : __DIR__"shulin8",
                "north" : __DIR__"shulin3",
	]));
   set("objects",([
       __DIR__"npc/maque" : 1,
   ]));
	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

