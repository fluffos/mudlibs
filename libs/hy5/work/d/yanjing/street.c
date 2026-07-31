// Room: /d/yanjing/street.c

inherit ROOM;

void create()
{
	set("short", "比武招亲");
	set("long", @LONG
宽阔的大街道,靠着一边的粉墙,圈了老大一块空地,地下插了一面锦旗,
白底红花，绣着“比武招亲”四个金字.那锦旗在朔风下飘扬飞舞锦旗左侧
地下插着一杆铁枪，右侧插着两枝镔铁短戟。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/munianci.c" : 1,
  __DIR__"npc/yangtiexin.c" : 1,
  __DIR__"biwu/mu" : 1,
]));
set("no_get",1);
set("no_drop",1);
	set("no_clean_up", 0);
	set("outdoors", "yanjing");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"street1",
  "south" : __DIR__"street2",
]));

	setup();
	replace_program(ROOM);
}
