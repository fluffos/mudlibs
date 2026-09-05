// out.c 矩阵迷宫（出口）
// seagate@pkuxkx by 2011.02.16

inherit ROOM;

void create()
{
	set("short", "青石小径");
	set("long", 
"在幽静的竹林中有一条青石小径通向了竹林深处。\n"
	);
	
  set("outdoors", "shaolin/cjg");	
	setup();
}

int do_lian()
{
	tell_object(this_player(), "这里太危险了，还是不要修炼武功了。\n");
	return 1;
}

void init()
{
	object me=this_player();
	add_action("do_lian","lian");
	add_action("do_lian","practice");
	add_action("do_lian","xiulian");
	if ( time()-me->query_temp("cjg/time")>=1800 )
	{
		tell_object(me, "你在竹林中滞留了太长时间了，被路过的巡逻僧兵发现了踪迹。\n");
    me->set("startroom", "/d/shaolin/jlyuan");
    me->move("/d/shaolin/jlyuan"); 
    return;
	}
}