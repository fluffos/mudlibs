// Room: /d/xingxiu/xxroad5.c

inherit ROOM;

void create()
{
	object ob;

	set("short", "星宿派储藏室");
	set("long", @LONG
这里原来是一个长在山壁上的天然溶洞，因为地点隐密而且洞中空气十分
干燥，星宿派把这里改造成了一个仓库。
LONG );
	set("exits", ([
	    "out" : __DIR__"xxroad5",
	]));
	set("objects", ([
		__DIR__"obj/hulu" : 2,
		__DIR__"obj/menghan_yao" : 1,
		__DIR__"obj/xxqingxin-san" : 1,
		"/clone/misc/muding" : 2,
		"/clone/book/dujing_1"  : 1
	]));
	set("outdoors", "xingxiu");

	ob = new("/clone/misc/xiangliao");
	ob->set_amount(200 + random(100));
	ob->move(this_object());

	setup();
}
