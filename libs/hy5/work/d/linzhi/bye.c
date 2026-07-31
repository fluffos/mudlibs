// Room: /d/linzhi/bye.c

inherit ROOM;

void create()
{
	set("short", "八一镇东口");
	set("long", @LONG
这里是八一镇东口，向西就进八一镇了。八一镇是林芝地区
最繁华的村镇了，人口虽然不多，但附近的藏民们一般都来此买
卖一些必要的生活用品或货物。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lin10",
  "west" : __DIR__"by01",
]));

  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/cityguard" : 3,  	
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
