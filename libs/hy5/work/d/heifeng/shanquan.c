// Room: /d/heifeng/shanquan.c

inherit ROOM;

void create()
{
	set("short", "山泉");
	set("long", @LONG
这里是山间的一道泉水从上面的山崖流淌而下，泉水清澈见
底，就是这道山泉供应着黑风寨的饮水。早晚的时候都会有小喽
喽到这里来打水(fill)。
LONG
	);

	set("outdoors", "heifeng");

	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"shanya",
  "south" : __DIR__"corr08",
  "east" : __DIR__"xiaolu1",
]));

	set("resource/water", 1);

	setup();
	replace_program(ROOM);
}
