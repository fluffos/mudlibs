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
		__DIR__"obj/xiang" : 5,
	]) );
//	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "桃花岛") && dir == "up"
             &&  objectp(present("ya pu", environment(me))))
           return notify_fail("哑仆说道:此处乃桃花岛禁地，请止步。\n");

        return ::valid_leave(me, dir);
}
