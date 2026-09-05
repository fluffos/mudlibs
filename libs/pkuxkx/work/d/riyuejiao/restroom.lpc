// restroom.c	休息室
// by bing

inherit ROOM;

string* names = ({
        "/d/shaolin/obj/mala-doufu",
        "/d/shaolin/obj/bocai-fentiao",
        "/d/shaolin/obj/shanhu-baicai",
        "/d/shaolin/obj/liuli-qiezi",
});


void create()
{
	set("short", "休息室");
	set("long", 
@LONG  
这是朱雀堂所设的日月神教弟子的休息室。屋里摆着几张
大床，桌上放着一些食物。已经有一些弟子睡了，你移动的时
侯最好轻点，别把他们吵醒了。
LONG
	);
	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"zhuquetang",
	]));
        set("objects",([
                "/d/shaolin/obj/qingshui-hulu" : 1,
		__DIR__"obj/niurou" : 2,
                names[random(sizeof(names))]: 1,
        ]));

	setup();
	set("no_fight",1);
}
