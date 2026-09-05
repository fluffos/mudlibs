// shanfang.c 膳房
// by llin

inherit ROOM;

void create()
{
	set("short", "膳房");
	set("long", 
"这儿是武当弟子用餐的地方，屋正中摆着一张紫檀色大方\n"
"桌，几个武当弟子围坐在桌旁，慢条斯理的吃着饭。菜虽清淡，\n"
"却也是烹饪精巧，色泽诱人。\n"
	);
        set("exits", ([
		"west"  : __DIR__"houtang",
		"east"  : __DIR__"xiangji",
	]));
        set("objects",
		([ __DIR__ "obj/huagu" : 1,
		__DIR__ "obj/hulu" : 2,
		__DIR__"obj/baicai" : 1,
		__DIR__"obj/zhou"  : 3,
		]));
	setup();
}

