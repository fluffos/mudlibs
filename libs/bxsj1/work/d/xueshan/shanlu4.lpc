// Room: shanlu4.c

inherit ROOM;

void create()
{
	set("short", "入幽口");
	set("long", @LONG
此处已在群山环绕之中，山路去处就是巍峨的大雪山，抬头了望，峰顶云雾
缭绕，宛如仙境。真是：
    天山相连苍茫外，碧云去尽山无数。
    云山万重，寸心千里。
    望极天涯不见家。 

LONG
	);

	set("exits", ([
		"westup" : __DIR__"fengjiantai",
		"eastup" : __DIR__"shanlu3",
	]));
        set("outdoors", "雪山");
        set("objects", ([CLASS_D("xueshan") + "/baoxiang" : 1,]));
	set("coor/x",-290);
  set("coor/y",150);
   set("coor/z",0);
   setup();
}
