//Cracked by Roath
// Room: /d/xiangyang/qilidian.c

inherit ROOM;

void create()
{
	set("short", "七店");
	set("long", @LONG
檀溪由此蜿蜒绕过，两岸耸起壁立，水驶如箭，谚：“有风七，无风七
十。”言舟行难於牵挽，惟视风为迟速也。这四通八达，为四周乡贩集所
聚，故名七店。从此往东不远便是襄阳城，西北可至武当山。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : -14, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"guangde",
  "northeast" : __DIR__"shanlu",
  "northwest" : __DIR__"wjiejing",
  "east" : __DIR__"xushuzai",
]));

	setup();
	replace_program(ROOM);
}
