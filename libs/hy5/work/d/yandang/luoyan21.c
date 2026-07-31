// Room: /d/yandang/luoyan21.c

inherit ROOM;

void create()
{
	set("short", "男弟子浴室");
	set("long", @LONG
室中用大理石砌了个大浴池,你进去的时候,正有几个人泡在水池中
山庄的人都有习惯,每天练武之后,大汗淋漓,总要痛快地洗个澡才行,室
中蒸汽氲氲,舒服极了.
LONG
	);
	set("bath_room", "1");
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luoyan18",
]));

	setup();
	replace_program(ROOM);
}
