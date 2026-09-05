// milin3.c 密林
// seagate@pkuxkx 路径动态更新

inherit ROOM;

void create()
{
	set("short", "林间空地");
	set("long", 
"四周都是参天的大树，连阳光都射不进来，林间的空间上\n"
"洒落星星点点的午间阳光，吸引附近的鸟雀在这里聚集。\n"
	);
	set("exits", ([
		"enter"  : __DIR__"testroom/0_entry",
	]));
	
	setup();
}

void init()
{
	add_action("do_test","test");
	add_action("do_go","go");
//	add_action("do_clone", "cln");
}

void bind_test()
{
	tell_object(this_object(),"test\n");
	call_out("bind_test", 5);
}

int do_clone()
{
	object ob;
	ob=new("/obj/gem/gem");
	ob->set_level(9996, 10000, "yan");
	ob->move(this_player());
	return 1;
}

int do_go()
{
	function f;
	object ob;
	ob=this_player();
	printf("Test\n");
	f=bind((:bind_test:), ob);
  evaluate(f);
	return 1;
}

int do_test()
{
	this_player()->start_busy(3600);
	printf("时间 ：%s，busy：%d\n", ctime(time()),this_player()->query_busy());
	remove_call_out("bind_test");
//	call_out("testing",60,this_player());
	return 1;
}

void testing(object ob)
{
	printf("时间 ：%s，busy：%d\n", ctime(time()),ob->query_busy());
	remove_call_out("testing");
	call_out("testing",60,ob);
}