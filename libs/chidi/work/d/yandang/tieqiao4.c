// Room: /d/yandang/tieqiao4.c

inherit ROOM;

void create()
{
	set("short", "铁索桥");
	set("long", @LONG
这是一座宽仅两尺的铁索桥,由十三根铁索组成,上面摆了一块块
木板,由于风吹日晒,年代久远,有的地方已经破缺,桥下就是万丈深谷,
据说常有人调下去.你已经走了大一半了,但你越来越无法平衡自己,你
的双脚在不由自主的颤抖,是前进还是后退?
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zaimin.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tianzhu",
  "south" : __DIR__"tieqiao3",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
