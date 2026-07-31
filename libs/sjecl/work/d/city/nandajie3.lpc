// Room: /d/city/nandajie3.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
南大街乃是扬州城里的繁华地段，一到晚上，一派灯红酒绿，尤为热闹。
笑声、歌声、琴声、箫声，汇成一片送入了你的耳朵，你不禁心猿意马，很想
就此停步享受一番。东北边是一个热闹的广场。西边是一片喧嚣，夹杂着“一
五一十”的数钱声，原来那里是方圆千里之内最大的一家赌场。
LONG
	);
        set("outdoors", "扬州");
	set("exits", ([
		"east" : __DIR__"guangchangnan",
		"south" : __DIR__"nandajie2",
		"west" : __DIR__"duchang",
	        "north" : __DIR__"guangchangxi",
	]));

        set("objects", ([
                CLASS_D("gaibang/xqigai") : 1,
                CLASS_D("gaibang/lqigai") : 1,
        ]));
	set("incity",1);
	setup();
}
