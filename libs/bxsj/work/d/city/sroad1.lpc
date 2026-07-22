inherit ROOM;

void create()
{
	set("short", "江南官道");
	set("long",@long
你走在一条青石大道上，人来人往非常繁忙，不时有人骑着马匆匆而过。
北面是长江下游近入海口的地方，东南面通往姑苏城。
long);
	set("outdoors", "苏州");
	set("exits",([
		"southeast" : "/d/suzhou/qsgdao6",
		"north" : __DIR__"jiangnan",
	]));
	setup();
}

void init()
{
	object me = this_player();

	if ( me->query("gb_job")){
		me->add("job_time/丐帮", me->query("gb_job"));
		me->delete("gb_job");
	}
	if ( me->query("gb_job2")){
		me->add("job_time/报效国家", me->query("gb_job2"));
		me->delete("gb_job2");
	}
}
