// Room: /d/linzhi/by15.c

inherit ROOM;

void create()
{
	set("short", "小镇西斜路");
	set("long", @LONG
你走在小镇西斜路上，不时有过往的行人与你擦肩而过，偶
尔你也会遇上一两个汉商。西边帐房是一家钱庄。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by16",
  "west" : __DIR__"teashop",
  "northeast" : __DIR__"by14",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
