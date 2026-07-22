// /d/hmy/ryping.c
#include <ansi.h>

#define	SHIP_DOWN 	__DIR__"ryping"
#define	SHIP_UP		__DIR__"yading"

inherit ROOM;

void create()
{
	set("short", "崖中平地");
	set("long", @LONG
朱栏宝槛，曲砌峰山。奇花与丽日争妍，翠竹共青天斗碧。径铺彩石，径
这里是山崖的中部一块平地，离崖顶还有不少距离，黑木崖实在太高，中
间还有一处绞盘，再向上走还要进另一个竹篓(lou)。
LONG
	);
	set("item_desc",([
		"lou" : "一个巨大的竹篓，你大喊(yell)一声，可以供你上崖(shangya)或下崖(xiaya)。\n",
	]));
	set("outdoors", "黑木崖");
	setup();
}

void init()
{
    add_action("do_yell", "yell");
}

// up
void check_trigger()
{
	object room;
	object thisroom = this_object();

	if(!query("exits/up") ) {
		if( !(room = find_object(__DIR__"zhulou1")) )
			room = load_object(__DIR__"zhulou1");
		if( room = find_object(__DIR__"zhulou1") ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/up", __DIR__"zhulou1");
				room->set("exits/out", __FILE__);
				message("vision", "一个大竹篓缓缓地降了下来，停在你的面前。\n", thisroom);
				remove_call_out("on_board");
				call_out("on_board", 15);
			}
			else
		                message("vision", "只听得崖上隐隐传来：“别急嘛，这儿正忙着呐……”\n", thisroom);
		}
		else
			message("vision", "ERROR: zhulou not found\n", thisroom);
	}
	else 
		message("vision", "竹篓就停在你的面前, 还不赶快上去？\n", thisroom);
}


void on_board()
{
    	object room;

    	if( !query("exits/up") ) return;

    	message("vision", "铜锣三响，崖顶的绞盘开始转动，竹篓缓缓升高。\n", this_object() );

    	if( room = find_object(__DIR__"zhulou1") ) {
        	room->delete("exits/out");
        	message("vision", "铜锣三响，崖顶的绞盘开始转动，竹篓缓缓升高。\n",room);
    	}
    	delete("exits/up");

    	remove_call_out("flying");
    	call_out("flying", 10);
}

void flying()
{
    	object room;
    
    	if( room = find_object(__DIR__"zhulou1") )
        	message("vision", HIC"\n黑夜之中，仍可见到一片片轻云从头顶飘过。\n"HIB"\n再过一会，身入云雾，俯视篓底，但见黑沉沉的一片，连灯火也望不到了。。\n"NOR,room);

    	remove_call_out("arrive");
    	call_out("arrive", 10);
}

void arrive()
{
    	object room;
    
    	if( room = find_object(__DIR__"zhulou1") ) {
        	room->set("exits/out", SHIP_UP);
        	message("vision", "竹篓晃了几下，在崖中平地停了下来。\n",room);
    	}
    
    	remove_call_out("close_passage");
    	call_out("close_passage", 20);
}

void close_passage()
{
	object room, *ob;
	int i;

	if( room = find_object(__DIR__"zhulou1") ) {
		room->delete("exits/out");

		tell_room(room, "一个教众对你喝道：“站在里面干什么？还不赶快下来！”\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "教众把$N抬下了竹篓。\n", ob[i]);
				else tell_room(room, "$N听了教众的话，乖乖地下了竹篓。\n", ({ob[i]}));
				ob[i]->move(SHIP_UP);
				if (!living(ob[i])) tell_room(SHIP_UP, ob[i]->name() + "被抬下了竹篓。\n", ({ob[i]}));
				else tell_room(SHIP_UP, ob[i]->name() + "走下了竹篓。\n", ({ob[i]}));
			}
		}
		message("vision", "竹篓晃了几下，又从石屋驶向崖下。\n", room);
		room->delete("yell_trigger"); 
	}
}

// down
void check_trigger1()
{
	object room;
	object thisroom = this_object();

	if(!query("exits/down") ) {
		if( !(room = find_object(__DIR__"zhulou")) )
			room = load_object(__DIR__"zhulou");
		if( room = find_object(__DIR__"zhulou") ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/down", __DIR__"zhulou");
				room->set("exits/out", __FILE__);
				message("vision", "一个大竹篓缓缓地升了上来，停在你的面前。\n", thisroom);
				remove_call_out("on_board1");
				call_out("on_board1", 15);
			}
			else
		                message("vision", "只听得崖下隐隐传来：“别急嘛，这儿正忙着呐……”\n", thisroom);
		}
		else
			message("vision", "ERROR: zhulou not found\n", thisroom);
	}
	else 
		message("vision", "竹篓就停在你的面前, 还不赶快上去？\n", thisroom);
}


void on_board1()
{
    	object room;

    	if( !query("exits/down") ) return;

    	message("vision", "铜锣三响，崖下的绞盘开始转动，竹篓缓缓降了下去。\n", this_object() );

    	if( room = find_object(__DIR__"zhulou") ) {
        	room->delete("exits/out");
        	message("vision", "铜锣三响，崖下的绞盘开始转动，竹篓缓缓降了下去。\n",room);
    	}
    	delete("exits/down");

    	remove_call_out("flying1");
    	call_out("flying1", 5);
}

void flying1()
{
    	object room;
    
    	if( room = find_object(__DIR__"zhulou") )
        	message("vision", MAG"\n竹篓不断下降，举头上望，头顶数点火星，变的更加遥远。\n"NOR,room);

    	remove_call_out("arrive1");
    	call_out("arrive1", 5);
}

void arrive1()
{
    	object room;
    
    	if( room = find_object(__DIR__"zhulou") ) {
        	room->set("exits/out", SHIP_DOWN);
        	message("vision", "竹篓晃了几下，在崖底日月坪停了下来。\n",room);
    	}
    
    	remove_call_out("close_passage1");
    	call_out("close_passage1", 20);
}

void close_passage1()
{
	object room, *ob;
	int i;

	if( room = find_object(__DIR__"zhulou") ) {
		room->delete("exits/out");

		tell_room(room, "一个教众对你喝道：“站在里面干什么？还不赶快下来！”\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "教众把$N抬下了竹篓。\n", ob[i]);
				else tell_room(room, "$N听了教众的话，乖乖地下了竹篓。\n", ({ob[i]}));
				ob[i]->move(SHIP_DOWN);
				if (!living(ob[i])) tell_room(SHIP_DOWN, ob[i]->name() + "被抬下了竹篓。\n", ({ob[i]}));
				else tell_room(SHIP_DOWN, ob[i]->name() + "走下了竹篓。\n", ({ob[i]}));
			}
		}
		message("vision", "竹篓晃了几下，又从石屋驶向崖下。\n", room);
		room->delete("yell_trigger"); 
	}
}

void reset()
{
	object room;

	::reset();
	if (room = find_object(__DIR__"zhulou1"))
		room->delete("yell_trigger"); 
	if (room = find_object(__DIR__"zhulou"))
		room->delete("yell_trigger"); 
}

int do_yell(string arg)
{
	object me = this_player();

	if (!arg) return 0;

	if (arg == "shangya") arg = "上崖";
	if (arg == "xiaya") arg = "下崖";
	if (me->query("age") < 16  )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", me);
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", me);
	if (arg == "上崖")
		check_trigger();
	else if (arg == "下崖")
		check_trigger1();
	else {
		message_vision("崖上远远传来一阵回声：“" + arg + "～～～”\n", me);
		message_vision("忽然凌空飞来一脚，将$N踢了一个跟头，一个日月神教教众喝道：“此处禁止喧哗！”\n", me);
	}
	return 1;
}
