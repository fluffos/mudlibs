// Room: /d/huashan/jinshe/biding.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","壁顶");
	set("long", @LONG
这里是峭壁的顶端，四周怪石嶙峋，旁边有几棵柏树(shu)枝叶茂盛，一些
野藤(shuteng)缠绕的树干。在树的下隐约有个洞穴(dong)，由于年深日久，封
住洞口的泥土已经剥落。
LONG                           
        );
	set("teng_count", 3);
	set("teng_time",time());
	set("outdoors", "华山");
	set("exits", ([
		"down" : "/d/huashan/husun",
	]));
	set("item_desc", ([
		"shu" : "一棵枝叶繁茂的大树，粗粗的树干，看上去很牢固。\n",
		"shuteng": "一些不知名的野藤，紧紧缠绕的大树。\n",
		"dong": "里面黑沉沉的，什麽也看不清，不知有多深。\n",
	]));

	setup();
}

void init()
{
	add_action("do_zhe", ({"break","zhe"}));
	add_action("do_bo", ({"stick","bo"}));
	add_action("do_bian", ({"weave","bian"}));
	add_action("do_use", ({"dian","dian"}));
	add_action("do_pa", ({ "climb", "pa" }));
	add_action("do_bang", ({ "tie", "chan" }));
}

int do_zhe(string arg)
{
	object teng;
	object me; 
	me=this_player();

	if ( !arg || arg != "shuteng" )
		return notify_fail("你要折什麽？\n");

	if((time()-query("teng_time"))>900) {
		set("teng_count", 3);
		set("teng_time",time());
	}
	if (query("teng_count") > 0) {
		message_vision("$N从树干上面折断了一些树藤。\n", me);
		add("teng_count", -1);
		teng=new(__DIR__"obj/shuteng");
		teng->move(me);
	}
	else
		message_vision("树藤已经被$N折光了。\n", me);
	return 1;
}
 
int do_bian(string arg)  
{
	object kuang;
	object me;
	me = this_player();
	if (!( present("shuteng", this_player())))
		return notify_fail("你要用什麽编？\n");
	if ( !arg || arg != "kuang" )
		return notify_fail("你要编什么？\n");
	 
	message_vision("$N把折下的树藤编成了一个篮筐，又挑了一些细的拧成麻绳。\n", me);
	kuang=new(__DIR__"obj/kuang");
	kuang->move(me);
	return 1;
}

int do_use(string arg)
{ 
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if( arg=="fire" ) {
		write("\n你点燃了火折，发现离洞口一丈远的四壁布满十几个金蛇锥(zhui)，\n"+
			"你大吃一惊，出了一身冷汗。\n");
		me->set_temp("mark/zhui", 1);
		return 1;
	}
}

int do_bo(string arg)
{
	object me;
	me = this_player();

	if ( !arg || arg != "zhui" )
		return notify_fail("你要拨什麽？\n");

	if (!me->query_temp("mark/zhui"))
		return notify_fail("你要干什麽？\n");

	if (!( present("xiao shuzhi", this_player())))
		return notify_fail("你伸了伸手，显然无法够到？\n");

	message_vision("$N小心翼翼用树枝把洞壁的金蛇锥都拨落了。\n", me);
	me->delete_temp("mark/zhui"); 
	me->set_temp("mark/bo",1);
	return 1;
}

int do_pa(string arg)
{
	object me;
	me=this_player();

	if ( !arg || arg != "down" )
		return notify_fail("你要去向哪？\n");

	if (!( present("kuang", this_player())))
		return notify_fail("你想就这样跳下去吗？\n");

	if (!me->query_temp("mark/bang"))
		return notify_fail("你想就这样跳下去啊？！\n");

	message_vision("$N坐在藤篮里面，战战兢兢消失在洞口。\n", me);

	if (!(int)me->query_temp("mark/bo")) {
		message_vision(RED"黑暗之中，$N突然感觉身体一阵刺痛，眼前一黑，掉了下去。\n"NOR, me);
		message_vision(HIR"$N大叫一声，从洞口掉了下去。\n"NOR, me);
		me->set_temp("last_damage_from", "误撞机关摔");
		me->die();
		return 1;
	}
	me->move(__DIR__"dxue");
	tell_room(environment(me), me->name() + "满脸尘土钻了下来。\n", ({ me }));
	me->delete_temp("mark/bo");
	return 1;
}

int do_bang(string arg)
{      
	object me;
	me = this_player();

	if (!( present("kuang", this_player())))
		return notify_fail("你要用什么绑？\n");

	if ( !arg || arg != "shu" )
		return notify_fail("你想缠什么？\n");

	if (me->query_temp("mark/bang"))
		return notify_fail("你已经缠过了。\n");

	message_vision("$N把麻藤紧紧缠在树干上。\n", me);
	me->set_temp("mark/bang",1);
	return 1;
}
