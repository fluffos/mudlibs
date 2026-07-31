
// Room: /d/ustc/bforest/road12.c

inherit ROOM;

void create()
{
    set("coor",({1050,4650,10}));
	set("short", "丛林小径");
	set("long",
"这是一片茂密的竹林,一眼望不到头,你只觉得林中充满妖气,旁边有块石头,上刻五个血红大\n"
"字 汝葬身此地 ,四周多是竹子,你似乎是迷路了!\n"
);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"eroad1",
  "west" : __DIR__"road11",
]));
        set("objects", ([ /* sizeof() == 2 */
   __DIR__"npc/crazy_dog" : 2,
]));

	setup();
	replace_program(ROOM);
}
