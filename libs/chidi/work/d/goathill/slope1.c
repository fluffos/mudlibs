#pragma save_binary
// Room: /d/goathill/slope1.c

inherit ROOM;

void create()
{
	set("coor",({120,5050,50}));
	set("short", "岩石坡");
	set("long",
"这里是一处岩石斜坡，斜坡上到处布满乱石及杂草，东边的岩壁\n"
"边有一间石屋，往西跟往北则可以回到铺满碎石的山路。\n"
);
	set("outdoors", "goathill");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"mroad6",
		"west" : __DIR__"mroad5",
]));

	setup();
	replace_program(ROOM);
}
