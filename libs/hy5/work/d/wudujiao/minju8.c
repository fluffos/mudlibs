// by mayue


inherit ROOM;

void create()
{
	set("short", "灶房");
	set("long", @LONG
这是一个简陋的灶房，四壁都被烟火熏的黑糊糊的，灶台旁的墙上
贴着一张发黄的黄裱纸，旁边挂着一些风干的兽肉。灶台铁锅旁的水缸
上摆着几只粗瓷大碗，屋的一角堆着一大堆麦秸。 
LONG
	);
//        set("outdoors", "wudujiao");

	set("exits", ([
//		"out" : __DIR__"cun7",
//		"south" : __DIR__"minju1",
		"east" : __DIR__"minju3",
//		"north" : __DIR__"wdsl6",
	]));
        set("objects", ([
                  __DIR__"obj/qhcwan": 2,
                  __DIR__"obj/shourou2": 1,
                  __DIR__"obj/shourou1": 1,
	]));
       set("resource", ([ /* sizeof() == 1 */
              "water" : 1,
       ]));   
    set("item_desc",([
    "黄裱纸":"         木人到此一游。。。\n",
]));
	setup();
	replace_program(ROOM);
}

