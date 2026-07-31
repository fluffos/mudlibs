// Room: /d/linzhi/lin68.c

inherit ROOM;

void create()
{
	set("short", "高原杂道");
	set("long", @LONG
这里是高原杂道，横七坚八的地形好像都是路一样，也不知
是否走得通。你仔细的注视着，选择了一条有脚步印记较多的方
向，你走了一会，觉得方向并没有走错。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linzhiw",
  "southeast" : __DIR__"lin67",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
