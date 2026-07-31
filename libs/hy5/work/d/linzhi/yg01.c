// Room: /d/linzhi/yg01.c

inherit ROOM;

void create()
{
	set("short", "易贡茶场");
	set("long", @LONG
这里就是易贡茶场，也是本镇巴依老爷的财产。由于地形原
因，这里湿度大，日照也不强烈，土壤腐植物含量高，最适宜茶
树生长。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by12",
  "east" : __DIR__"yg02",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1900);
	setup();
	replace_program(ROOM);
}
