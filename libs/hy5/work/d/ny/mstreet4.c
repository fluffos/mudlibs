
// Room: /d/snow/mstreet4.c

inherit ROOM;

void create()
{
    set("coor",({-100,4770,10}));
	set("short", "宁远城西街");
	set("long",
"这里宁远城西边的大街，一眼望去是笔直的宁远街道通往东边，往西是一家打铁铺子，叮叮\n"
"当当的声音大老远可以听得到，街道往北边一直通往镇外。南面隐约看见意见书塾，那儿是\n"
"一些百姓家的孩童读书识字的地方。\n"
);
	set("exits", ([ /* sizeof() == 3 */
  "east"  : __DIR__"mstreet3",
  "north" : __DIR__"smithy",
  "south" : __DIR__"school",
  "northwest" : __DIR__"nroad7",
]));
	set("no_clean_up", 0);
        set("objects", ([
              __DIR__"npc/scavenger": 2 ]) );

	setup();
}
