// Room: /d/dali/hg2.c
// bbb 1997/06/10
// cool 98.3.17
// Modify By River 98/12
// Update by Lklv 2001.10.17

inherit ROOM;

void create()
{
	set("short", "海埂南");
	set("long", @LONG
这里三面云山，一湖秀水，碧波浩荡，白帆点点，出没天际；斜坡缓舒形
成细软白沙铺底的海滩，水绿沙白，清幽可爱，是附近最佳的天然游泳场。每
当盛夏，这里游人如织，柳树丛中，沙滩上，到处都会挤满一群群，一伙伙来
消夏的游人。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([
		"north" : __DIR__"hg1",
	]));
        set("objects",([
		"/d/dali/npc/qiaozi" : 1,
        ]));
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/hg2",1);
	}
}
