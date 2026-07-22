// Room: /d/yandang/xiyaotai.c

inherit ROOM;

void create()
{
	set("short", "西瑶台");
	set("long", @LONG
这是一片平平整整的石地,面临深谷,背靠绝壁,在悬崖边上,有此处
唯一的一棵古松,枝叶繁茂,树下掉满了松子和松针,还有几只松鼠在树
上来回蹦跳.向东可到天柱峰.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dongwai",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/baiyi_ren.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
