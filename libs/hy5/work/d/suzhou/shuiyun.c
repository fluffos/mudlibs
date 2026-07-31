// Room: /d/suzhou/shuiyun.c

inherit ROOM;

void create()
{
	set("short", "水云间");
	set("long", @LONG
这里是太湖边的隐居人士，一切都只是个迷啊。
LONG);
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
  "east" : "/d/mr/matou",
]));
	setup();
//	replace_program(ROOM);
}