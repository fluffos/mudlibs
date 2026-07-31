// Room: /d/linzhi/by14.c

inherit ROOM;

void create()
{
	set("short", "小镇西斜路");
	set("long", @LONG
你走在小镇西斜路上，不时有过往的行人与你擦肩而过，偶
尔你也会遇上一两个汉商。西面传来叮叮当当的声响，看来是一
家铁匠铺。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"by15",
  "west" : __DIR__"smithshop",
  "northeast" : __DIR__"by13",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
