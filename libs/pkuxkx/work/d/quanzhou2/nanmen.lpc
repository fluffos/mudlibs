// Room: /d/quanzhou/zhongxin.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "南门");
	set("long", @LONG
这里是泉州的南门，一切都是那么静谧安详。这里的北面是泉州的中心，
南面并没有明显的道路。但是你向南远眺，总觉得有什么不对的地方。
冥冥之中，似乎有一种神秘的力量在远方。
LONG
	);

	set("exits", ([
                "north" : __DIR__"zhongxin",
                  "south" : "/d/xiakedao/nanhaibin",
                	]));

	set("item_desc", ([
	"yuanfang" : "你向远处眺望，突然，一个声音在你耳边响起，好象是----穿越时空？？\n",
	"远方" : "你向远处眺望，突然，一个声音在你耳边响起，好象是----穿越时空？？\n",
	]));

	set("outdoors", "quanzhou");
	setup();
}

void init()
{
//         add_action("do_chuanyue", "chuanyue");
}

int do_chuanyue(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="shenlong" ) 
	{
		message("vision",
			me->name() + "四周出现一圈耀眼的光环，紧接着突然一切都消失了！\n",
			environment(me), ({me}) );
                me->move("/d/shenlongdao/haitan");
                message("vision",
			"一道闪电过后，"+me->name() + "突然出现在你面前！\n",
                	environment(me), ({me}) );
		return 1;
	}

}	

