// Room: /d/linzhi/lin61.c

inherit ROOM;

void create()
{
	set("short", "雅鲁藏布江岸崖壁");
	set("long", @LONG
这里是雅鲁藏布江江岸崖壁，放眼看去，江水滚滚而下，发
出轰轰的声响。崖壁下面就是雅鲁藏布江江边，那里长满了热带
和亚热带植物，据说到处是毒虫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin60",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
