// /d/heifeng/gate.c

inherit ROOM;

void close_cross();

void create()
{
	set("short", "山寨大门");
	set("long", @LONG
一个由竹子搭成的寨门出现在你在眼前。几个持刀的
人目露正在凶光，不停得在门口巡视着。门上横着一块匾
(sign)。你不禁犹豫着是否要凑上前去。
LONG
);

	set("item_desc", ([
		"sign": "黑风寨\n",
	]) );
        set("NONPC",1);

	
	set("exits", ([
		"north"   : __DIR__"corr",
		"south"   : __DIR__"cross",
	]) );

	set("objects", ([
		__DIR__"npc/bandit_guard" : 2,
]) );

	set("outdoors", "heifeng");
	setup();
}

void init()
{
	object ob;

	if( living(ob = previous_object()) && userp(ob) && ob->query_temp("can_enter_heifeng"))
		ob->delete_temp("can_enter_heifeng");
}

/*
void greeting(object ob)
{
	if( !ob )
		return;

	if(environment(ob) == find_object(__DIR__"cross"))
	{
		call_out("close_cross",1);
		return;
	}

	if(ob->query_temp("heifeng/come_in"))
	{
		close_cross();
		ob->delete_temp("heifeng/come_in");
		return;
	}
}

void close_cross()
{
	object ob = find_object(__DIR__"lu10");

	if(!ob)
		ob = load_object(__DIR__"lu10");

	if(ob->query("exits/north"))
	{
		tell_room(ob,"只听一阵吱吱嘎嘎的乱响，吊桥慢慢的被对面吊了起来。\n");
		ob->delete("exits/north");
	}

	if(query("exits/south"))
	{
		tell_room(__FILE__,"只听一阵吱吱嘎嘎的乱响，吊桥又被吊了起来。\n");
		delete("exits/south");
	}
}
*/
