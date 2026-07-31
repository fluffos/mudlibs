//caiji@SJ 8/24/2000

inherit ROOM;

void create ()
{
	set ("short", "毒虫谷");
	set ("long", @LONG
一片平坦谷地，四周是大山环绕。四周阴沉沉的，气氛十分恐怖。谷内
瘴气四起，各种毒物，不计其数，地下都是陈年腐草败叶烂成的软泥。寒风
从山谷通道中刮进来，吹得你肌肤隐隐生疼。
LONG);

	set("exits", 
	([
		"northwest" : __DIR__"duchonggu"+random(5)*10,
	]));
	
	set("outdoors", "xingxiuhai");
	set("coor/x",-290);
        set("coor/y",190);
        set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_yell", "yell");
	add_action("do_yell", "han");
}

int do_yell(string arg)
{
	object me;
	
	me=this_player();

	if( !arg || (arg != "快关门" && arg != "open" && arg != "快开门" && arg != "开门"&&arg!="关门"&&arg!="close") )
		return notify_fail("你要喊什么？\n");       

	if(arg == "open" || arg == "快开门" || arg == "开门")call_out("open_out", 1);
	else call_out("close_out",1);
	return 1; 
}

void open_out()
{
	object uproom; 

	if( uproom = find_object(__DIR__"rukou") ) 
	{
		set("exits/south", __DIR__"rukou");
		uproom->set("exits/north", __FILE__);
		message("vision", "大门发出轧轧的声音，慢慢打开，你现在可以进去了。\n", uproom );
		message("vision", "大门发出轧轧的声音，慢慢打开，你现在可以出去了。\n", this_object() );
	}

	call_out("close_out", 20);
}

void close_out()
{
	object uproom;

	if( !query("exits/south") ) return;

	message("vision", "大门发出轧轧的声音，重新又关上了。\n", this_object() );

	if( uproom = find_object(__DIR__"rukou") ) 
	{
		message("vision", "大门发出轧轧的声音，重新又关上了。\n", uproom );
		uproom->delete("exits/north");
	}

	delete("exits/south");
}

int valid_leave(object me, string dir)
{
	int time;
	if(dir == "northwest"){

        if (me->query("combat_exp")<3000)
        return notify_fail("这里面太危险，你还是不要进去了。\n");
        
        time = 10+random(10);
        me->apply_condition("xx_catch",time);
        me->set_temp("xx/catch_time",time);
        me->delete_temp("xx_zuji");
        }
//      if(dir == "south")
//	me->clear_condition("xx_catch");

        return ::valid_leave(me, dir);
}