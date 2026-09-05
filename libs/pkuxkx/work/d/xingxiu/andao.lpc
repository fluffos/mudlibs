// Modified by iszt@pkuxkx, 2007-03-30

#include <ansi.h>

inherit ROOM;

void init();
int close_gate();
int do_open();

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是一条极其秘密的地下通道，侧面有个门(door)。
LONG);
	set("exits", ([
		"up" : __DIR__"xiaoyao",
	]));
//	set("outdoors", "xingxiu");
	set("item_desc",([
		"door" : "这扇铁门很重，看来不是一般人能推开(push)的。\n",
	]));

        set("no_task",1);
	setup();
}
void init()
{
	add_action("do_push", "push");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"mishi")) )
		room = load_object(__DIR__"mishi");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision", "吱呀一声，小门被风关上了。\n", this_object());
		room->delete("exits/south");
		message("vision", "小门吱呀一声被风吹上了。\n", room);
	}
	else message("vision", "ERROR: gate not found(close).\n", room);
	return 1;
}

int do_push(string arg)
{
	object room, me = this_player();

	if (query("exits/north"))
		return notify_fail("大门已经是开着的了。\n");
	if (!arg || (arg != "door" && arg != "north"))
		return notify_fail("你要推什么？\n");
	if ((int)me->query("neili")<400)
	{
	 	me->set("neili",0);
		return notify_fail("你用力推了推门，结果没能推开。\n");
	}
	if(!( room = find_object(__DIR__"mishi")) )
		room = load_object(__DIR__"mishi");
	if(objectp(room))
	{
		set("exits/north", __DIR__"mishi");
		message_vision("$N运上内力，使劲推门，只听门「吱呀」一声开了。\n",me);
		room->set("exits/south", __FILE__);
		me->set("neili",(int)(me->query("neili")-400));
		message("vision", "外面有人用力把门打开。\n", room);

		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
