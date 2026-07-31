// Room: /d/linzhi/linzhiw.c

inherit ROOM;

void create()
{
	set("short", "林芝地区西部边缘");
	set("long", @LONG
这里是林芝地区最西边，地处雅鲁藏布江下游北部，由此再
向东就进入林芝地区了。路边立着一块牌子。
LONG
	);
	set("item_desc",([
          "牌子":"
                  east         八一镇
                  northwest    拉萨 \n", ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin68",
//  "southwest" : "/d/path6/qjl01",
  "northwest" : "/d/qingzh/xroad",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
