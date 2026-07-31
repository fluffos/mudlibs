// Room: /open/dt/luzhuxiang1.c

inherit ROOM;

void create()
{
	set("short", "绿竹巷");
	set("long", @LONG
这条小巷大约有七尺多宽，巷子两边也没有种着竹子，它之
所以叫绿竹巷是因为这里原先是一片竹林，现在的这条小巷是林
中的小道。后来竹林变成了店铺，小道也就变成小巷了，但大同
人为了让后人知道原先这里还有片竹林，就把这条小巷叫做绿竹
巷了。北面是一家民居。
LONG
	);
	set("exits", ([
  "east" : __DIR__"luzhuxiang2",
  "north" : __DIR__"minju1",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
