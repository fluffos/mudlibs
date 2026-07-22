// Room: kongdi2.c 空地

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
这儿是杏子林中间的一片空地。四周的树上挂着一个个竹篓，里面有很多毒蛇
在蠕动，一个老乞丐坐在地上手里拿着条蛇。丐帮弟子可以在这里问陈长老有
关抓蛇的事。
LONG
	);
	set("outdoors", "苏州");

	set("exits", ([
		"east" : __DIR__"xinglin9",
	]));

	set("objects", ([
		CLASS_D("gaibang") + "/chen" : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();
	if ( me->query("snake_job")){
		me->add("job_time/抓蛇", me->query("snake_job"));
		me->delete("snake_job");
	}
	if( me->query("job_time/丐帮捉蛇") )
	{
		me->add("job_time/抓蛇", me->query("job_time/丐帮捉蛇") );
		me->delete("job_time/丐帮捉蛇");
	}
}
