// /u/beyond/mr/anbian4.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>

#define SHIP_TO "/d/mr/mtl/anbian1"
#define	BOAT	"/d/mr/zhou5"

inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();
void create()
{       set("short",HIW"岸边"NOR);
        set("long", @long
从这里乘船可以到达曼佗罗山庄，一位上了年纪的老船夫正在岸边休息，
你可以呼喊一声(yell)，船家就会摆船过来。
long);
	set("outdoors", "慕容");
	set("exits",([
		"east" : __DIR__"shuixie",
	]));
	setup();
}

void init()
{
	add_action("do_yell", "yell");
//	add_action("do_yue", "yue");
}

void check_trigger()
{
	object room;

	if(!query("exits/enter") ) {
		if( !(room = find_object(BOAT)) )
			room = load_object(BOAT);
		if( room = find_object(BOAT) ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/enter", BOAT);
				room->set("exits/out", __FILE__);
				message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n", this_object() );
	                	message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上的阶梯。\n", room);
				remove_call_out("on_board");
				call_out("on_board", 15);
			}
			else
				message("vision", "只听得湖面不远处隐隐传来：“别急嘛，这儿正忙着呐……”\n",this_object() );
		}
		else
	            message("vision", "ERROR: boat not found\n", this_object() );
	}
	else 
		message("vision", "岸边一只小舟上的老艄公说道：正等着你呢，上来吧。\n", this_object() );
}


void on_board()
{
	object room;

	if( !query("exits/enter") ) return;

	message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向湖中驶去。\n", this_object() );

	if( room = find_object(BOAT)){
		room->delete("exits/out");
		message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向湖中驶去。\n", room );
	}
	delete("exits/enter");

	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;
	if( room = find_object(BOAT)){
		room->set("exits/out", SHIP_TO);
		message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n",room );
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room, *ob;
        int i;

	if( room = find_object(BOAT) ) {
		tell_room(room, "艄公轻声说道：“都下船吧，我也要回去了。”\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "艄公把$N抬下了船。\n", ob[i]);
				else tell_room(room, "$N听了艄公的话，乖乖地下了船　n", ob[i]);
				ob[i]->move(SHIP_TO);
				if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "被抬下了船。\n", ({ob[i]}));
				else tell_room(SHIP_TO, ob[i]->name() + "走下了船。\n", ({ob[i]}));
			}
		}
		room->delete("exits/out");
		message("vision","艄公把踏脚板收起来，把扁舟驶向湖中。\n", room);
		room->delete("yell_trigger"); 
	}
}

int do_yell(string arg)
{
	if( !arg || arg=="" ) return 0;

	if( arg=="boat" ) arg = "船家";
	if (arg != "船家") arg = "哇";
	if( (int)this_player()->query("age") < 16 )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", this_player());
	else if( (int)this_player()->query("neili") > 500 )
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", this_player());
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", this_player());
	if( arg=="船家") {
		check_trigger();
		return 1;
	}
	else
		message_vision("湖面上远远传来一阵回声：“" + arg + "～～～”\n", this_player());
	return 1;
}

void reset()
{
	object room;

	::reset();
	if( room = find_object(BOAT) )
		room->delete("yell_trigger"); 
}
/*
int do_yue(string arg)
{ 
       object me;
       me = this_player(); 

        if(!arg) return notify_fail("你要干什么？\n");
        if(arg != "hu") return notify_fail("你要干什么？\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢！\n");
        if (me->query_skill("dodge") < 400) 
                return notify_fail("你的修为不够！\n");
        if (me->query("max_neili") < 4000)
                return notify_fail("你的内力修为不够，怎能支持！？\n");
        if (me->query("neili") < 2000)
                return notify_fail("你的真气不够了！\n");
        if (me->query("jingli") < 1500)
                return notify_fail("你的精力不够了！\n");
        me->receive_damage("neili", 300);
        me->receive_damage("jingli", 150);
          tell_room(environment(me), HIY+me->name()+"向手心吐了两口吐沫，紧了紧腰带，施展「一苇渡江」绝技纵身跃过湖面！\n" NOR, ({me}));
          write("你向手心吐了两口吐沫，紧了紧腰带，施展「一苇渡江」绝技纵身跃过湖面！\n");
        me->move(__DIR__"testmatou1");
        me->start_busy(3);
        tell_room(environment(me), HIY+me->name()+"飞身从湖对面跃起，在湖心当中芦苇上一点，从湖对面串了过来！\n" NOR, ({me}));
                return 1;
}
*/
