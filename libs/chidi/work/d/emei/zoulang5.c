//  /d/emei/zoulang5 走廊5
// crate by host dec,15 1997

inherit ROOM;
void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是走廊的尽头。青石板铺成的小路，两边的柱子和栏杆都是用竹
子做成，在栏杆的一边种植了许多的花草，其中尤为突出的是杜鹃花，不仅
生长的茂盛，并且的十分艳丽。前方有一石洞，红木的大门紧紧的关闭着。
在石洞上方篆刻了三个大字『清修洞』。
LONG
	);

	set("exits", ([
		"east" : __DIR__"zoulang4",
                "south" : __DIR__"qingxiudong",
	]));

	setup();
}


