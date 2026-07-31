// Room: /d/tangmen/bingqiku.c
// BY congw

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "兵器库");
	set("long", @LONG
	这里是唐门的兵器库，里面整整齐齐堆放着各种各样的暗器及刀剑，唐门弟子
可以在这儿取用。库里还有火炉和铁锤，可以自己升火打造(da)钢镖。
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"changlang4",
		"west" : __DIR__"xingtang",
		"east" : __DIR__"xiaoxiao-lou",
	]));
	set("objects", ([
                "/d/jingzhou/obj/armor": 3,
		"/d/tangmen/obj/gangbiao1": 15,
		
	]));
	setup();
}
void init()
{
	add_action("do_da", "da");
	add_action("do_sheng", "sheng");
	
}


int do_da(string arg)
{
	object me;
        object ob;
	me = this_player();

	if ( !arg || ( arg != "biao" ) )
		return notify_fail("你要干什么？\n");

	if (me->query_temp("marks/镖")){
		if (me->query("qi")<10){write("你已经太累了，休息一会儿再打吧。\n");return 1;}
	me->receive_damage("qi", 5);

	message_vision("$N满头大汗，挥舞着铁锤。\n", me);

	ob=new("/d/tangmen/obj/gangbiao1");
        ob->move(this_player());
        message_vision("$N已经打好了一枚钢镖。\n", me);
		return 1;
	}

	write("火已经熄灭了，你还是把火生起来再说吧。\n");

	return 1;
}
int do_sheng(string arg)
{
	object me;

	me = this_player();

	if ( !arg || ( arg != "huo" ) )
		return notify_fail("你要干什么？\n");
		if (me->query_temp("marks/镖"))
	{write("火已经生着了。\n");return 1;}
	message_vision("$N往炉中添了些木炭，拿起风箱开始升火。\n", me);
	message_vision(HIR"炉火熊熊燃了起来。\n"NOR,me);
	this_player()->set_temp("marks/镖",1);
        remove_call_out("fire");
        call_out("fire", 20, this_object());

	return 1;
}
void fire(object room)
{
    message("vision",HIY"只见炉火扑闪了几下，熄了。\n"NOR, room);
    this_player()->delete_temp("marks/镖");
}
