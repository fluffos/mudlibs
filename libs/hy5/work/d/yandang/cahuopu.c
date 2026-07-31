// Room: /d/yandang/cahuopu.c

inherit ROOM;

void create()
{
	set("short", "陈家铺子");
	set("long", @LONG
这里是芙蓉镇上唯一的一家杂货铺,由于价钱公道,老板对人又和气
所以生意向来不错,店中摆着一张柜台,后面的货架上摆满了南北杂货,你
在别的地方买不到的东西,兴许就能在这买到.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jiedao",
  "enter" : __DIR__"houyuan",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chenlaoban.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
