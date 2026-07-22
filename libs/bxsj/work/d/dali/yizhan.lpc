// Modify By River 98/12/

inherit ROOM;

void create()
{
	set("short", "驿站");
	set("long", @LONG
这是大理驿站，负责传送和大宋国及武林各大门派的公文，密函。这里戒
备森严，静悄悄的，只见不时有人进来领命，又急急忙忙地离开。门口的木柱
上边立了一快牌子（sign)。
LONG
	);
	set("no_fight",1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"sign": "请用\"ask wanli about 送信 \" 领取任务。\n",
	]));

	set("exits", ([
		"west" : __DIR__"qsjie2",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/zhuwanli" : 1,
	]));
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/yizhan",1);
	}
	if ( me->query("dali_job")){
		me->add("job_time/大理", me->query("dali_job"));
		me->delete("dali_job");
	}
}
