#include <ansi.h>
inherit ROOM;
void create()
{
        set("long", @LONG
这里是一家马车行，挂着一个招牌(paizi)，店里的马车(che)停得满满当当
的。
LONG);
		set("item_desc",
        ([
        "che":"你可以雇车(gu)/(hire)去你想去的地方。\n",
        "paizi" : "百年老店，竭诚为新老顾客提供方便。\n",
		]));
        setup();
}
void init()
{
	add_action("do_gu","gu");
	add_action("do_gu","hire");
}

string do_gu()
{
	object ob=this_object(),me=this_player(),che,*inv;
	string area;
	if (me->is_busy()||me->is_fighting())
	{
		return "你正忙着呢。\n";
	}
	if (time()-me->query("killer/time") < 15*60)
	{
		return "你有命案在身，这时候去雇车，不是自投罗网？\n";
	}
	
	if (!ob->query("this_area"))
	{
		area=AREA_INFO->get_room_area(ob);
		ob->set("this_area",area);
	}
	inv=all_inventory(me);
	for (int i=0;i<sizeof(inv);i++)
	{
		if (userp(inv[i]))
		return "你还准备背人上车逃票？\n";
	}
	che=new("/clone/obj/mache");
	che->set("this_area",ob->query("this_area"));
	che->set("price",ob->query("price"));
	che->set("from",ob);
	me->move(che);
	message_vision("$N登上了一辆马车。\n",me);
	return "";
}