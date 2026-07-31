// Room: /d/yandang/dongwai.c

inherit ROOM;

void create()
{
	set("short", "洞外");
	set("long", @LONG
'会当凌绝顶,一览众山小',从此处望去,远山近水,无不历历在目,
远处山峦起伏,群山环翠,夕阳西照,倦鸟宿归,正是一幅神仙画卷.近处
则一石一木,无不充满灵气.令人叹为观止.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"shandong7.c",
  "west" : __DIR__"xiyaotai",
  "east" : __DIR__"dongyaotai",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
