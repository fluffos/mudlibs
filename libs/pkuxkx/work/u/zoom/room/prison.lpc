// Room: /d/snow/herbshop1.c

inherit ROOM;

void create()
{
	set("short", "监狱");
	set("long", @LONG
这里是监狱，四周都有人把守，囚犯们个个懒散的躺在地上，他们都是犯了
大罪将要处死的人，不知道你怎么样。
LONG
	);
	


	set("exits", ([
	
	]));
	setup();
}

void init()
{
	add_action("do_none","hubo");
	add_action("do_none","goto");
	this_player()->start_busy(10);
        call_out("kickout",60,this_player());
}
int do_none()
{
        call_out("do_goto",1,this_player()); 
	return 1;
}
void do_goto(object me)
{
	if(me->query("id")!="zoom")
	{
		message_vision("哼哼，这里是你想进来就进来想出去就出去的地方么？\n",me);
                return notify_fail("哈哈，这里岂是这么容易出去的，你就老老实实呆在这里吧:(\n");
	}
	else
	{
		remove_call_out("kickout");
		message_vision("恩，你可以走了。\n",me);
		me->move("/u/zoom/wizard_room_zoom");
	}
return;		
}
void kickout(object me)
{
	object where;

	message_vision("只听牢门一阵乱响，几个衙役走进来揪住$N一脚将其踹了出去，吼道：小心点！以后别没事乱跑！\n",me);
	me->move("/d/city/guangchang");
	message_vision("$N给衙役一脚踹过来，摔了个狗啃泥！\n",me);
	me->start_busy(0);
	return;
}
