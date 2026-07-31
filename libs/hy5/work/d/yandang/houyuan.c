// Room: /d/yandang/houyuan.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
杂货铺的后院里还正停着几辆货车,几个小伙计正忙着卸东西,看
来刚从外地进了一批货,院中的大槐树下拴着几头驴,看你进来还都抬
着头看你,你心想,还是别打扰人家,出去吧!
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"cahuopu",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
