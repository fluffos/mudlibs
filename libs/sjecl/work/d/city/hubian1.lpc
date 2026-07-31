// /d/city/hubian.c 瘦西湖边

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",GRN"瘦西湖边"NOR);
	set("long", @LONG
瘦西湖湖山青水秀，碧波涟漪，湖光山色，相映成趣，泛舟湖上犹如镜中
行，漫步湖堤则如画中游。西湖之美令人陶醉。自古以来，人们常以艳、娇、
媚、秀、柔、嫩来形容她。
LONG
	);
	set("objects",([
		NPC_D("youke") : 2,
	]));
	set("exits", ([
		"west" : __DIR__"lxs",
		"south" : __DIR__"dhq",
	]));
	set("outdoors", "扬州");
	set("incity",1);
	setup();
}
