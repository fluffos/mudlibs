// /u/beyond/hangzhou/hubian.c 西湖边
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",GRN"西湖边"NOR);
        set("long", @LONG
杭州西湖山青水秀，碧波涟漪，湖光山色，相映成趣，泛舟湖上犹如镜
中行，漫步湖堤则如画中游。西湖之美令人陶醉。自古以来，人们常以艳、
娇、媚、秀、柔、嫩来形容她。宋代大诗人苏轼的“水光潋滟晴方好，山色
空蒙雨亦奇，欲把西湖比西子，淡妆浓抹总相宜”一诗把西湖明媚秀丽的景
色描绘的淋漓尽致。
LONG
        );
	set("objects",([
		__DIR__"npc/you" : 2,
		__DIR__"npc/dao-ke" : 1,
	]));
        set("exits", ([
		"southwest" : __DIR__"baidi",
		"south" : __DIR__"llwying",
	]));
	set("outdoors", "杭州");

	setup();
}
