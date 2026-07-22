// Room: tianhu.c

inherit ROOM;

void create()
{
	set("short", "天湖");
	set("long", @LONG
这里是一片广阔的淡水湖，天空一望无垠，湖水清澈湛蓝，呈现出一幅独特
的高原风光。
真是：
    长风怒卷高浪，飞洒日光寒，
    无风水面琉璃滑，不觉船移，微动涟漪，惊起沙禽掠岸飞。
    一千五百年间事，只有滩声似旧时。
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu1",
                "south" : __DIR__"xiaodian",
                "southwest" : __DIR__"xiaolu1",
"north" :__DIR__"tianxi",
	]));
        set("outdoors", "雪山");
        set("objects", ([
  			       __DIR__"npc/zhimaya" : 1,
     			       __DIR__"npc/bantouyan" : 1
        ]));
	set("coor/x",-250);
  set("coor/y",140);
   set("coor/z",0);
   setup();
}
