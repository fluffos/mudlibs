// Room: /d/fengtian/n_gate.c

inherit ROOM;

void create()
{
	set("short", "盛京北门");
	set("long", @LONG
做为北方重镇盛京的城门高大而雄伟，这里一直是抗击关外
少数民族进犯的关口，城门上飞扬着官军的三角军旗，旗上一条
条金龙张牙舞爪，城墙上一块横匾上书三个大字盛京城，银钩铁
划，刚劲非常。
LONG
	);

	set("exits", ([
	"south" : __DIR__"guanlu4",
	"north" : __DIR__"out_fengtian_n",
]));
        set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
