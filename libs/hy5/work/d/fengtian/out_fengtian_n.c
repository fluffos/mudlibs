// Room: /d/fengtian/out_fengtian_n.c

inherit ROOM;

void create()
{
	set("short", "盛京府北门外");
	set("long", @LONG
这里盛京城的北门外。南面是盛京府的北门，几个官军在盘
查着过往的行人。向北面远远望去是光秃秃的群山，由于气候苦
寒，人烟稀少。
LONG
	);
	set("exits", ([
  "south" : __DIR__"n_gate",
  //"north" : "/d/northft/ftn1",
]));

	set("outdoors", "fengtian");
	setup();
}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob)
	&& !wizardp(ob)
	&& (dir == "north") )
	{
		inv = filter_array(deep_inventory(ob),
			(: $1->is_character()
			&& ( $1->query("attitude") == "killer"
			|| $1->query("attitude") == "aggressive" ) :));

		if(sizeof(inv))
			return notify_fail(sprintf("突然从边上跳出两个卫士说道：敢带%s进城害人，活的不耐烦啦！\n",
				inv[0]->query("name")));
	}
	return ::valid_leave(ob,dir);
}
