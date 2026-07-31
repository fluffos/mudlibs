
// Room: /d/ustc/bforest/road11.c

inherit ROOM;

void create()
{
    set("coor",({1000,4650,10}));
	set("short", "丛林小径");
	set("long",
"这是一片茂密的竹林,一眼望不到头,你只觉得林中充满妖气,旁边有块石头,上刻五个血红大\n"
"字 汝葬身此地 ,四周多是竹子,你似乎是迷路了!\n"
);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road12",
  "north" : __DIR__"work",
]));
	set("outdoors", "ny");

	setup();
	replace_program(ROOM);
}
