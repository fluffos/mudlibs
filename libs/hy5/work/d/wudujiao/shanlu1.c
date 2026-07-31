// by mayue

inherit ROOM;

void create()
{
	set("short", "山边小路");
	set("long", @LONG
一条蜿蜒的小路延着山脚向前延伸，两旁是浓密的树林，脚
下是崎岖不平的山路，前面就是可怕的黑森林了。旁边似乎有一
家山野小店，路边有一座石碑(bei)。
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"southeast" : __DIR__"xiaolu",
		"south" : __DIR__"milin1",
        "west" : __DIR__"xiaodian",
		"north" : __DIR__"road3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
   
   set("item_desc",([
    "bei":"           前方黑森林山高林密，百里之内不见人烟，\n
           有虎狼出没其中，行人请三思而后行！\n",
]));

	setup();
	replace_program(ROOM);
}

