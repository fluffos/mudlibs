//  /d/emei/zoulang1 走廊1
// crate by host dec,15

inherit ROOM;
void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条走廊。青石板铺成的小路，两边的柱子和栏杆都是用竹子做
成，在栏杆的一边种植了许多的花草，其中尤为突出的是杜鹃花，不仅生
长的茂盛，并且的十分艳丽。
LONG
	);

	set("exits", ([
		"east" : __DIR__"guangchang",
		"south" : __DIR__"zoulang4",
	]));

	setup();
}


