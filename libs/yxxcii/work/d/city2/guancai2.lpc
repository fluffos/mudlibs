//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	object me;
	me = this_player();
	
	set("short", "棺材店内室");
	set("long",@LONG
这里是棺材店的内室，一进门，一股腐臭让你几乎要窒息了，屋里满
是棺材(guancai)，棺材上还写着一些名字(name)。
LONG	
);
	set("exits", ([
		"west" : __DIR__"guancai1",
	]));
	set("item_desc", ([
		"guancai" : "\n棺材板很结实，上面积了些灰尘。\n" ,
		"name":     "只见棺材上面写着一个名字："+ me->query("name")+"("+ me->query("id")+")\n",
	]));

	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_move", "move");
	add_action("do_move", "open");
	add_action("do_knock", "knock");
}


int do_move(string arg)
{
	object me;
	me = this_player();
	if (!arg||arg!="guancai") return notify_fail("你要移开什么？\n");
	message_vision("你移开棺材盖，只见棺材里躺着一具尸体，仔细一看，那不是$N的尸体吗？\n",me);
	message_vision("你越看越惧怕，冷汗猛的飙，接着……\n",me);
	this_player()->unconcious();
	return 1;
}

int do_knock(string arg)
{
	object me,hole;
	string dir;
	me = this_player();
	if (!arg||arg=="") return 0;
	if( arg=="guancai" ) {
		message_vision("\n$N试著敲了敲棺材板，咚咚，里面似乎是空的。\n", this_player());
	}
	if( sscanf(arg, "guancai %s", dir)==1 ) 
	{
		if( dir=="3" || dir=="three") {
		if(!objectp(present("hole", environment(me))))
		{
		message_vision("\n$N在棺材板上咚咚咚敲了三下，只听吱呀一声，\n"+"里边伸出一双手把棺材板掀开了。\n", this_player());
		hole = new("/d/city2/obj/hole");
		hole->move("/d/city2/guancai2");
		}
		}   
		else return notify_fail("\n你胡乱敲了棺材板几下，结果什么也没发生。\n");
	}		
	return 1;
}

int do_enter(string arg)
{
	if( !arg || arg!="guancai" ) return 0;
	return notify_fail(" 想穿棺材板啊？你不会奇门遁甲。\n");
	return 1;
}	

