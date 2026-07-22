// Room: /d/yandang/tieqiao1.c

inherit ROOM;

void create()
{
	set("short", "铁索桥");
	set("long", @LONG
这是一座宽仅两尺的铁索桥,由十三根铁索组成,上面摆了一块块
木板,由于风吹日晒,年代久远,有的地方已经破缺,桥下就是万丈深谷,
据说常有人调下去.你已经走了一小半了.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tieqiao2",
  "south" : __DIR__"dongyaotai",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/youke.c" : 1,
  __DIR__"npc/lanyi.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
