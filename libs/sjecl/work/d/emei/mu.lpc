// mu.c 
// 郭襄墓

inherit ROOM;
#include <ansi.h>
void check_trigger(object);
void close_passage(object);
void reset();
int do_dig(string arg);
void create()
{
	set("short", "郭襄之墓");
	set("long",@long
这里是一座规模不大的墓，墓碑上刻着几个大字：峨嵋派祖师郭襄之墓。
原来这是峨嵋派创派祖师郭襄的墓。郭女侠乃是大侠郭靖的小女儿。她晚年
在峨嵋山定居，创立了峨嵋派，死后峨嵋弟子将她安葬在此处。这里四季如
春，常年鲜花盛开，十分幽静。
long);
	set("outdoors", "峨眉山");
	set("exits",([
		"south" : __DIR__"caodi",
		"east" : __DIR__"xiaojing2",
	]));
	set("objects", ([
		__DIR__"npc/shanyang" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_wa", "wa");
}

void check_trigger(object me)
{
	object room;
	if( (int)query("dig_trigger")==15
	 && !query("exits/down")) {
		message("vision", "墓碑后面被掘开个大洞，眼前出现了一道石门。\n", this_object() );
		set("exits/down", __DIR__"mu2");
		if( room = find_object(__DIR__"mu2") ) {
			room->set("exits/up", __FILE__);
			message("vision", "墓已经掘开了，一道大石门横在地上。\n",room );
		}
		delete("dig_trigger");
		remove_call_out("close_passage");
		call_out("close_passage", 20, me);
	}
}

void close_passage(object me)
{
	object room;
	if( !query("exits/down") ) return;
	message("vision", "忽然，门旁的泥土塌了下来，把掘开的石门给盖住了。\n", this_object() );
	if( room = find_object(__DIR__"mu2") ) {
		room->delete("exits/up");
		message("vision", "忽然，门旁的泥土塌了下来，把掘开的石门给盖住了。\n", room );
	}
	delete("exits/down");
	me->delete_temp("dig_mu");
}

int do_wa(string arg)
{
	object me, ob;
	me = this_player();

	if(! (me->query_temp("sao_mu")))
		return notify_fail("你要干什么？\n");

        if (me->is_busy() || me->is_fighting())
        	return notify_fail("你正忙着哪！\n");

	if(!(present("tie qiao", me)))
		return notify_fail("你要挖什么？\n");

	if( !arg || arg == "" || arg != "mu")
		return notify_fail("你要挖什么？\n");
	
	if( arg == "mu" ) {
		if( (int)me->query_temp("dig_mu", 1) == 1 ) {
			if(! present("shoumu dizi", environment(me))) {
				ob=new("/d/emei/npc/shoumu");
				message_vision(HIC"忽然间一个青衣女子由侧地里冲出来，厉声道：大胆盗贼，吃我一剑！\n", me);
				message_vision(HIC"你一下子满脸杀气，决定杀人灭口！\n"NOR, me);
				ob->move(this_object());  
			}
		} 
		message_vision("$N操起手中铁锹，吭吃吭吃地挖起墓来。\n", me);
		me->add_busy(1);
		me->add_temp("dig_mu", 1);
		add("dig_trigger", 1);
		check_trigger(me);
		return 1; 
	}
}

void reset()
{
	::reset();
	delete("dig_trigger");
}
