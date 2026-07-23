// Room: /d/jindezheng/shulin1.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
一片杂树林,地上铺了厚厚一层落叶.有一条小径隐约穿过树林,前
方似乎还升起一缕青烟.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/d/kaifeng/yanqing",
  "north" : __DIR__"street3",
  "southwest" : __DIR__"shulin2",
]));
	set("outdoors", "/d/jindezheng");

	setup();
//	replace_program(ROOM);
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
