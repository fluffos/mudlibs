// gate.c
inherit ROOM;

int do_knock(string arg);
void create()
{
	set("short", "梅庄大门");
	set("long", @LONG
走过一大片梅林，走上一条青石板大路，来到一座朱门白墙的大
庄院外，行到近处，见大门外写着“梅庄”两个大字，旁边署着“虞
允文题”四字。那虞允文是南宋破金的大功臣，这几个字儒雅之中透
着勃勃英气。
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
	    "south"    : __DIR__"xiaolu",
	]));
	set("item_desc",([
		"【大门】" : "一道高高的大门，门头上方写着“梅庄”两个大字。\n"
				ZJOBACTS2+ZJMENUF(2,2,8,30)"敲两下:knock 2"ZJSEP"敲三下:knock 3"ZJSEP"敲四下:knock 4"ZJSEP"敲五下:knock 5"ZJSEP"\n",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_knock", "knock");
}

int do_knock(string arg)
{
	object room, me=this_player();

	if( query("exits/north") )
	    return notify_fail("门开着这么大，敲什么敲！\n");
	if (arg == "4")
	{
message_vision("$N走上前去将门上铜环敲了四下。\n", me);
	    me->set_temp("step" ,1);
	    return 1;
	}
	if (arg == "2")
	{
message_vision("$N走上前去将门上铜环敲了两下。\n", me);
	    if (me->query_temp("step") == 1)
		 me->set_temp("step" ,2);
	    else
		 me->set_temp("step" ,0);
	    return 1;
	}
	if (arg == "5")
	{
message_vision("$N走上前去将门上铜环敲了五下。\n", me);
	    if (me->query_temp("step") == 2)
		 me->set_temp("step" ,3);
	    else
		 me->set_temp("step" ,0);
	    return 1;
	}
	if (arg == "3")
	{
message_vision("$N走上前去将门上铜环敲了三下。\n", me);
	    if (me->query_temp("step") == 3)
	    {
		 me->set_temp("step" ,0);
		 set("exits/north", __DIR__"tianjing");
message("vision", "过了半晌，大门缓缓打开。\n", this_object() );
		 if(!( room = find_object(__DIR__"tianjing")) )
		      room = load_object(__DIR__"tianjing");
		 room->set("exits/south", __FILE__);
message("vision", "门上铜环有节奏地响了四趟，大门给打开了。\n",room );
		 remove_call_out("close_passage");
		 call_out("close_passage", 10);
	    }
	    else
		 me->set_temp("step" ,0);
	    return 1;
	}
message_vision("$N走上前去将门上铜环敲了几下。\n", me);
	return 1;
}

void close_passage()
{
	object room;

	if( !query("exits/north") ) return;
message("vision", "护院把大门轻轻关上了。\n",this_object() );
	if( room = find_object(__DIR__"tianjing") )
	{
		room->delete("exits/south");
message("vision", "大门被护院轻轻关上了。\n", room );
	}
	delete("exits/north");
}

