// Room: /d/menggu/caoyuan1.c

inherit ROOM;

void create()
{
	set("short", "蒙古草原");
	set("long", @LONG
远处烟尘起处,一队队蒙古铁骑列队来往操练.西边夕阳如血,混圆的
残阳下是连绵的营帐和牛羊,那就是铁木真的部落.东面的树林边几个小孩
正在玩耍,树林后面是座荒山.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tujiu.c" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shulin",
  "south" : __DIR__"shulin5",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
