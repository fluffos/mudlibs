//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "鲁望镇");
	set("long", @LONG
这里是普麽部的鲁望镇，普麽部属台夷，领属还有附近的越州。
这是一座建在山坡上的小镇，东面和北面是高耸的群山，向西和南眺
望均可见村庄和城镇。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov80",
		"south" : __DIR__"minov79",
		"west" : __DIR__"minov64",
		"east" : __DIR__"minov78",
		]));

	set("objects", ([
		__DIR__"npc/tyshang" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
