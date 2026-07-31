// Room: /d/linzhi/lin63.c

inherit ROOM;

void create()
{
	set("short", "山林阶石道");
	set("long", @LONG
你来到一片林区，只见中间整整齐齐地铺着一条石阶，不时
由西边还传来阵阵钟声。西边是一座雄伟的寺庙。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin62",
  "west" : __DIR__"pg_temple",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
