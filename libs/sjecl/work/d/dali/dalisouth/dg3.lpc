// Room: /d/dali/dg3.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "游园会");
	set("long", @LONG
这里常举行游园联欢，载歌载舞，人山人海。有时还举办传统灯会，每晚
游客不下数万。中秋之夜，春城人民爱在这里赏月，楼上亭边，满缀彩灯风清
月白，滇池浮光耀金，廊外池水盈盈，树梢轻风徐来，花香飘逸，引人心醉。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
		"east" : __DIR__"dg2",
	]));

	set("objects",([
		NPC_D("kid") : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/dg3",1);
	}
}
