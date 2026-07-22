// Room: /d/xiangyang/hanshui1.c

#include <ansi.h>

#define	SHIP_TO	__DIR__"hanshui2"

inherit ROOM;

void check_trigger();
void on_board();
void on_boat(object me);
void taiping_dian(object me);
void arrive(object me);
void close_passage();

void create()
{
	set("short", "汉水东岸");
	set("long", @LONG
面前是一条波涛翻滚的大江(river)。 浊流滚滚，万舟竞发。两岸渡船来
来往往，江边一长溜摆满了鱼摊，渔家就将船泊在岸边，几个破萝上面支一块
木板，板上摆满了活蹦乱跳的汉江鲤鱼。过去不远，是有名的老河口，不少过
江客都在这里等待渡船摆渡。
LONG
	);

	set("exits", ([
		"east" : __DIR__"outnroad3",
	]));

	set("item_desc", ([
		"river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
	]));

	set("outdoors", "襄阳");
	setup();
}

void init()
{
	add_action("do_yell", "yell");
	add_action("du_jiang", "dujiang");
}

void check_trigger()
{
	object room;
	object thisroom = this_object();

	if(!query("exits/enter") ) {
		if( !(room = find_object(__DIR__"duchuan")) )
			room = load_object(__DIR__"duchuan");
		if( room = find_object(__DIR__"duchuan") ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/enter", __DIR__"duchuan");
				room->set("exits/out", __FILE__);
				message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n", thisroom);
				message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上的阶梯。\n", room);
				remove_call_out("on_board");
				call_out("on_board", 15);
			}
			else
				message("vision", "只听得江面上隐隐传来：“别急嘛，这儿正忙着呐……”\n", thisroom);
		}
		else
			message("vision", "ERROR: boat not found\n", thisroom);
	}
	else
		message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n", thisroom);
}

void on_board()
{
	object room, me, *ob;

	if( !query("exits/enter") ) return;

	me = this_object();
	if( room = find_object(__DIR__"duchuan") ) {
		room->delete("exits/out");

		ob = all_inventory(room);
		if (sizeof(ob) == 1) {
			me = ob[0];
			if (userp(me) && me->query("age") < 16 && me->query("gender") == "男性" && me->query("food") < 100 && !me->query("hanshui_food") && !random(5)) {
				tell_room(room, "正要开船时，忽然一个老道大袖飘飘地跃到船中，虽然看他落势很猛，可是船身竟没有丝毫的摇晃！\n", ({}));
				new("/kungfu/class/wudang/zhang")->move(room);
			}
			else
				me = this_object();
		}
		message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向江心驶去。\n", room);
	}
	delete("exits/enter");

	remove_call_out("on_boat");
	call_out("on_boat", 10, me);
}

void on_boat(object me)
{
	object room;

	if (userp(me)) {
		if( room = find_object(__DIR__"duchuan") ) {
			tell_room(room, "\n\n忽听得江上有人叫喊，两艘江船如飞地划来。\n", ({}));
			tell_room(room, "凝目望时，只见前面一艘小船的船梢上坐着一个虬髯大汉，舱中坐着一个小男孩和一个小女孩。\n", ({}));
			tell_room(room, "后面大船上的蒙古武官和番僧弯弓搭箭，射向前面的大汉。\n", ({}));
			tell_room(room, "张三丰侠义心起，立刻将船划了过去。猛听得一声惨呼，小船中的男孩被箭射中，眼看是不活的了。\n", ({}));
			tell_room(room, "大汉一惊，也跟着中了几箭，手中木桨掉入水中。后面大船赶了上来，几个武官和番僧跳进了小船。\n", ({}));
			tell_room(room, "张三丰身子跃起，半空中扑向小船，几下就将几个武官解决了，剩余的鞑子赶忙逃回大船，急划而去。\n", ({}));
			tell_room(room, "大汉和女孩上到渡船上来。原来那位大汉是明教的常遇春，为了保护幼主而被追杀。\n", ({}));
			tell_room(room, "那女孩是渔家之女，约莫十岁左右，衣衫弊旧，赤着双足，但容颜秀丽，且有个文雅的名字，叫做周芷若。\n\n\n", ({}));
			remove_call_out("taiping_dian");
			call_out("taiping_dian", 10, me);
			return;
		}
	}
	remove_call_out("arrive");
	call_out("arrive", 10, me);
}

void taiping_dian(object me)
{
	object room;

	if (userp(me)) {
		if( room = find_object(__DIR__"duchuan") ) {
			tell_room(room, "这晚船至太平店，开饭时你竟然食不下咽，张三丰喂你也没有用，周芷若道：“道长，你先吃饭罢，我来喂这位小相公。”\n", ({}));
			tell_room(room, "周芷若将鱼骨鸡骨剔尽，再加上肉汁，细心地拿给你吃，你觉得十分香甜，吃光了一大碗。\n\n\n", ({}));
			me->set("food", me->max_food_capacity());
			me->set("water", me->max_water_capacity());
			me->set("hanshui_food", 1);
		}
	}
	remove_call_out("arrive");
	call_out("arrive", 10, me);
}

void arrive(object me)
{
	object room, ob;

	if( room = find_object(__DIR__"duchuan") )
	{
		room->set("exits/out", SHIP_TO);
		message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n", room);
		if (userp(me)) {
			tell_room(room, "常遇春拜别张三丰，自寻蝶谷医仙而去。张三丰也携周芷若走了。\n", ({}));
		}
		if (ob = present("zhang sanfeng", room))
			destruct(ob);
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room, *ob;
	int i;

	if( room = find_object(__DIR__"duchuan") ) {
		room->delete("exits/out");

		tell_room(room, "艄公轻声说道：“都下船吧，我也要回去了。”\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "艄公把$N抬下了船。\n", ob[i]);
				else tell_room(room, "$N听了艄公的话，乖乖地下了船。\n", ({ob[i]}));
				ob[i]->move(SHIP_TO);
				if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "被抬下了船。\n", ({ob[i]}));
				else tell_room(SHIP_TO, ob[i]->name() + "走下了船。\n", ({ob[i]}));
			}
		}
		message("vision", "艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
		room->delete("yell_trigger");
	}
}

int do_yell(string arg)
{
	object me = this_player();

	if (!arg) return 0;

	if (arg == "boat") arg = "船家";
	if (arg != "船家") arg = "哇";
	if (me->query("age") < 16  )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", me);
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", me);
	if (arg == "船家")
	{
		check_trigger();
		return 1;
	}
	else {
		message_vision("江面上远远传来一阵回声：“" + arg + "～～～”\n", me);
		message_vision("忽然凌空飞来一脚，将$N踢了一个跟头，一个老艄公喝道：“此处禁止喧哗！”\n", me);
	}
	return 1;
}

int du_jiang()
{
	object me = this_player();

	if (!living(me)) return 0;
	if (me->query_skill("dodge") < 80)
		return notify_fail("你的修为不够！\n");
        if (me->is_busy()|| me->is_fighting())
                return notify_fail("你正忙着呢。\n");
	tell_room(environment(me), HIG + me->name() + "捡起一段芦苇抛入水中，紧跟着飞身跃上芦苇，长袖飘飘，渡过了汉水。\n" NOR, ({me}));
	write("你使出「一苇渡江」渡过了汉水。\n");
	me->move(SHIP_TO);
	tell_room(environment(me), HIG "只见" + me->name() + "踩着一段芦苇从对岸过来，姿态潇洒地落在岸边。\n" NOR, ({me}));
	return 1;
}
