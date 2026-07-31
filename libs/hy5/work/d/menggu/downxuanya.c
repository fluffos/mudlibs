// Room: /d/menggu/downxuanya.c

inherit ROOM;

void create()
{
	set("short", "悬崖下");
	set("long", @LONG
陡峭的山崖壁立,漠北苦寒的风沙侵蚀,山崖更是光滑险峻.几柱矮
树平平从山石中伸出,铁灰色的山石愈行愈高,直与天空中的白云相接.
两头白色的大雕围绕着山崖边的一株松树鸣叫.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/baidiao.c" : 2,
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"yading",
  "east" : __DIR__"xiaolu",
]));

	setup();
	replace_program(ROOM);
}
