
// Room: /d/snow/herbshop.c

inherit ROOM;

void create()
{
    set("coor",({-70,4800,10}));
	set("short", "林家铺子");
	set("long",
"这里是一间规模不小的药铺，奇怪的是，在这里你闻不到一丝药铺应有的药味，有的只是一\n"
"股淡淡的檀香，令人觉得心旷神怡，药铺的柜台就在店□靠北的一面，柜台後是一个巨大的\n"
"药柜(cabinet)，上面的小抽屉只怕有七、八百个之多，但是全部没有贴标签，药铺的出口\n"
"在东边。\n"
);
	set("item_desc", ([ /* sizeof() == 1 */
  "cabinet" : "一座巨大的杉木药柜，从它暗红色的纹理跟几处磨得发亮的痕迹，
这个药柜年代想必相当久远了，有一点很特殊的是，药柜和墙壁似乎贴
得非常紧密，看不出丝毫缝隙。
",
]));
	set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"mstreet3",
	]));
	set("objects", ([
		__DIR__"npc/herbalist": 1,
		__DIR__"npc/woodcutter": 1,
	]) );

	setup();
	replace_program(ROOM);
}
