// modify by Lklv 2001.10.16
inherit ROOM;

void create()
{
	set("short", "天然石洞");
	set("long", @LONG
这里就是星宿派老巢的储藏处。从外面看只是一个开在石山上的普通天然
石洞，因为地点隐密，而且洞中空气十分干燥，星宿派弟子便将这里改造成了
一个绝佳的储藏库。
LONG);
	set("exits", ([
		"out" : __DIR__"xx2",
	]));
	set("objects", ([
                FOOD_D("hulu") : 2,
                MEDICINE_D("menghan_yao") : 1,
                MEDICINE_D("dujing_1") : 1,
//add by caiji                MEDICINE_D("qxs") : 1,
                ARMOR_D("armor"): 2,
		__DIR__"obj/fire" : 2+random(2),
        ]));
        setup();
}
