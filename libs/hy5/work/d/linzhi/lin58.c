// Room: /d/linzhi/lin58.c
// Room: /d/linzhi/lin56.c

inherit ROOM;

void create()
{
	set("short", "高原巨柏林区");
	set("long", @LONG
这里就是林芝地区的古柏林了，林中长满了高大的古柏树。
古柏林是当地藏族人民心目中的圣地，传说笨教开山祖师辛饶米
保的生命树即是古柏树，所以树林中到处是玛尼堆，那些最大最
古老的树上还缠挂着风马。不由得你心中充满诚意，边走边注意
着方向。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin57",
  "south" : __DIR__"lin59",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}

