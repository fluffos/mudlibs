// Room: /d/china/junying/xiaozhen/xianjing.c

inherit ROOM;

void create()
{
	set("short", "世外桃源");
	set("long", @LONG
走到这里你眼前豁然开朗，没想到深山之中没有这般地方，
遍地奇花、异草、古树，其间百鸟鸣唱。右手有一间草屋，一位
须发皆白的老翁正悠哉游哉的坐在草屋前，蔚蓝的天上几朵白云
飘过，真是一方人间仙境。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xianjing_entry",
]));

	

	set("objects",([
	__DIR__"npc/xiaoyao_weng" : 1,
]));
	setup();
	replace_program(ROOM);
}
