inherit ROOM;

void create()
{
	set("short", "道具房");
	set("long", @LONG
这是一间道具房。摆着一些桃花弟子们常用的东西。房里好象黑
乎乎的，靠窗处有一张斑驳长桌和一把靠背椅，虽是白天还点着小油
灯。哑仆看到你进来，就使劲瞪着你，虽然口不能言，可你还是心中
惴惴。
LONG );
	set("exits", ([
		"west" : __DIR__"dating",
		"up"   : __DIR__"shufang",
	]));
	set("objects", ([
		__DIR__"npc/yapu"  : 2,
		__DIR__"obj/xiang" : 1,
		__DIR__"obj/zhuxiao" : 1,
	]) );
	setup();
}
