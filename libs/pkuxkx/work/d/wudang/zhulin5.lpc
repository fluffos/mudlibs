// zhulin.c 竹林小路
// by llin

inherit ROOM;

void create()
{
	set("short", "竹林小路");
	set("long", 
"四面都是苍翠的竹林，一枝枝翠竹挺拔直立，枝叶茂盛。\n"
"清风徐徐，只听得竹林中簌簌轻响，微风过去，林中万籁俱寂，\n"
"再无一丝声音。\n"
	);
	set("exits", ([
		"south"  : __DIR__"zhulin11",
		"north"  : __DIR__"zhulin3",
		"west"   : __DIR__"zhulin1",
		"east"   : __DIR__"zhulin12",
		"southeast" : __DIR__"zhulin4",
		"southwest" : __DIR__"zhulin5",
		"northeast" : __DIR__"zhulin6",
		"northwest" : __DIR__"zhulin2",
	]));
	setup();
	replace_program(ROOM);
}

