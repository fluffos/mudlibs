// /d/hmy/zhulou.c

#define SHIP __DIR__"zhulou"

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "竹篓");
	set("long", @LONG
坐在竹篓当中，眼见轻烟薄雾从身旁飘过，仰头向黑木崖上望去，但见那
座汉玉牌楼发出耀眼的光芒。
LONG
	);
        set("no_fight", "1");
        set("no_sleep_room", 1); 
        set("side", "ryping");

	set("outdoors", "黑木崖");
	setup();
}

int arrive(string arg)
{
	object room, ob;
     
	ob = this_object();

	if(!ob->query("start")) ob->set("start", 1);
	if(!(string)ob->query("side")) set("side", "yading");
	if(stringp(arg)) set("side", arg);
	if(!(room = find_object(__DIR__+ob->query("side"))))
		room = load_object(__DIR__+ob->query("side"));
	if(room = find_object(__DIR__+ob->query("side"))){
		ob->set("exits/out", __DIR__+ob->query("side"));
		room->set("exits/enter", SHIP);
		message("vision", "\n竹篓晃了几下，在一间石屋之内停了下来。\n", ob);        
		message("vision", "\n一个大竹篓缓缓地降了下来，停在你的面前，看起来你可以跨进竹篓(enter)。\n", room);
		remove_call_out("on_board");
		call_out("on_board", 20);
	}
	return 1;
}

void flying1()
{
	object room;

	if( room = find_object(__DIR__"zhulou")) {
		if( this_object()->query("side") == "yading")
			message("vision", HIC"\n黑夜之中，仍可见到一片片轻云从头顶飘过。\n"
					HIB"\n再过一会，身入云雾，俯视篓底，但见黑沉沉的一片，连灯火也望不到了。。\n"NOR,room);
		else
			message("vision", HIY"\n竹篓不断下降，举头上望，头顶数点火星，遥不可及。\n"NOR,room);
	}
    	remove_call_out("arrive");
    	call_out("arrive", 10+random(10));
}

void flying()
{
	object room;
    
	if( room = find_object(__DIR__"zhulou")) {
		if( this_object()->query("side") == "yading")
			message("vision", HIY"\n竹篓不断上升，举头上望，头顶数点火星，遥不可及。\n"NOR,room);
		else
			message("vision", HIC"\n黑夜之中，仍可见到一片片轻云从头顶飘过。\n"
					HIB"\n再过一会，身入云雾，俯视篓底，但见黑沉沉的一片，连灯火也望不到了。。\n"NOR,room);
	}
	remove_call_out("flying1");
	call_out("flying1", 10+random(10));
}

void on_board()
{
	object room, *obj, ob;
	int i;
        
	ob = this_object();
        
	if( !query("exits/out") ) return;

	if( room = find_object(__DIR__+ob->query("side")) ){
		obj = all_inventory(ob);
		for(i = 0; i < sizeof(obj); i++) {
			if (userp(obj[i]) && obj[i]->query_temp("side") != ob->query("side")) {
				if (!living(obj[i])) message_vision("教众把$N抬下了竹篓。\n", obj[i]);
				obj[i]->move(room);
				obj[i]->delete_temp("side");
				if (!living(obj[i])) tell_room(room, obj[i]->name() + "被抬下了竹篓。\n", ({obj[i]}));
				else tell_room(room, obj[i]->name() + "跨出了竹篓。\n", ({obj[i]}));
			}
		}
		room->delete("exits/enter");
		message("vision", "\n铜锣三响，崖顶的绞盘开始转动，竹篓缓缓移动。\n", this_object());
		message("vision", "\n日月教众喊了一声“坐稳喽”，绞盘开始转动，竹篓缓缓移动。\n", room);
	}
	delete("exits/out");
	if(ob->query("side") == "yading") ob->set("side", "ryping");
	else ob->set("side", "yading");
	remove_call_out("flying");
	call_out("flying", 10+random(10));
}
