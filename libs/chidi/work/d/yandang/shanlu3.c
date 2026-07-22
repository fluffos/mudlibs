// Room: /d/yandang/shanlu3.c

inherit ROOM;

void create()
{
	set("short", "双笋峰");
	set("long", @LONG
又名蜡烛峰,两峰拔地而起,高约七八十米,形长圆而尖,象双笋并
立,这就是'瑶笋千年生一芽'的双笋峰.在夜幕降临时,远观又象老僧送
客,步移景移,一时却又象老妪.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu4",
  "southdown" : __DIR__"shanlu2",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
