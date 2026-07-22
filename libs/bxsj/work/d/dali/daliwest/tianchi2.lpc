// Room: /d/dali/tianchi2.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "天池半山");
	set("long", @LONG
天池半山，森林苍翠茂密，时闻鸟鸣，偶见兽迹，清晨可登上五宝山箸看
日出，远山若海，红日冉冉升腾，分外壮观。远可望碧罗雪山，雪冠如银天池
地势高，景色幽奇，气候凉爽，野花缤纷，每逢暑月，人们多来赏。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
		"down" : __DIR__"tianchi1",
	]));

	set("objects",([
		NPC_D("caiyaoren") : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/tianchi2",1);
	}
}
