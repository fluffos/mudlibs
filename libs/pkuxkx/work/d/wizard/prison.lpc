// Room: /d/snow/herbshop1.c

inherit ROOM;

void create()
{
	set("short", "监狱");
	set("long", @LONG
这里是扬州府的监狱，四周都有人把守，囚犯们个个懒散的躺在地上，他们
都是犯了大罪将要处死的人，不知道你怎么样。
LONG);
  
  set("room_location", "/d/city/");
	setup();
}

void init()
{
	add_action("do_none","hubo");
        if (userp(this_player()))
        call_out("kickout",100,this_player());
        else
        call_out("kickout",10,this_player());
}
int do_none()
{
	write("什么？\n");
	return 1;
}
void kickout(object me)
{
	object where;

	message_vision("只听牢门一阵乱响，几个衙役走进来揪住$N一脚将其踹了出去，吼道：小心点！以后别没事就裸奔！\n",me);
	where = me->query_temp("luoben/where");
	if (objectp(where))
		me->move(where);
	else
		me->move("/d/city/guangchang");
	message_vision("$N给衙役一脚踹过来，摔了个狗啃泥！\n",me);
	me->start_busy(0);
	return;
}
