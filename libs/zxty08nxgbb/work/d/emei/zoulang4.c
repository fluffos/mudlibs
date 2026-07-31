//  /d/emei/zoulang4 走廊4
// crate by host dec,15 1997

inherit ROOM;
void create()
{
	set("short", "走廊");
	set("long", @LONG
你正走在一条走廊上。青石板铺成的小路，两边的柱子和栏杆都是用竹
子做成，在栏杆的一边种植了许多的花草，其中尤为突出的是杜鹃花，不仅
生长的茂盛，并且的十分艳丽。
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang5",
		"north" : __DIR__"zoulang2",
	]));

	setup();
}


