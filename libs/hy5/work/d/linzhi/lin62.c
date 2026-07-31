// Room: /d/linzhi/lin62.c

inherit ROOM;

void create()
{
	set("short", "山林阶石道");
	set("long", @LONG
你来到一片林区，只见中间整整齐齐地铺着一条石阶，不时
由西边还传来阵阵钟声。看来不远处应该是一座寺庙。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin55",
  "west" : __DIR__"lin63",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
