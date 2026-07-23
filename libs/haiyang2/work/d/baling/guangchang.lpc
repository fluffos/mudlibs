// baling/zhongxinguanchang
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "巴陵广场");
	set("long", @LONG
这里是城市的正中心，一个很宽阔的广场，铺着青石地面。一些游
手好闲的人在这里溜溜达达，经常有艺人在这里表演。中央有一棵大榕
树，盘根错节，据传已有千年的树龄，是这座城市的历史见证。南面人
声鼎沸，一派繁华景象，东边不时地传来朗朗的读书声，西边则见不到
几个行人，一片肃静。
LONG
	);
        set("outdoors", "baling");
       
	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
	]));
set("objects", ([
		__DIR__"npc/old" : 1,
                __DIR__"npc/shang" : 1,
	]));
	setup();
}

// laowuwu 99/03/28
