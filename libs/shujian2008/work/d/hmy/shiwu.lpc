// /d/hmy/houhuayen.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "小石屋");
	set("long", @LONG
一间并不起眼的小石屋，里面收拾的干干净净，看来一直还是经常有人来
打扫的，你仔细一看，发现左首的墙壁有些与众不同。
LONG
	);
	set("exits", ([
		"east" :__DIR__"houhuayen",
	]));

	setup();
}

void init()
{
	add_action("do_move", "tui");
	add_action("do_open", "open");
}

int do_move(string arg)
{
	object ob, me = this_player();
	ob = present("hei yaoshi", me);

	if ( ! ob) return 0;

	if ( ! arg || arg != "qiang")
		return notify_fail("你要推什么啊？\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	message_vision(HIY"\n$N伸手一推，那墙原来是活的，露出一扇门来，里面尚有一道铁门。\n\n"NOR, me);
	me->set_temp("shiwu/tui", 1);
	return 1;
}

int do_open(string arg)
{
	object ob, me = this_player();
	ob = present("hei yaoshi", me);

	if ( !me->query_temp("shiwu/tui")) return 0;

	if ( ! ob) 
		return notify_fail("你又没有钥匙，开什么啊？\n");

	if ( ! arg || arg != "men")
		return notify_fail("你要开什么啊？\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	message_vision(HIY"\n$N拿出黑钥匙，只听见“咣当”一声，铁门慢慢的应声而开了。\n\n"NOR, me );
	destruct(ob);
	set("exits/down", __DIR__"dedao");
	me->delete_temp("shiwu");
	remove_call_out("close_passage");
	call_out("close_passage", 10);
	return 1;
}

void close_passage()
{
	if( !query("exits/down") ) return;
	message("vision", "铁门“咔咔”几声又自动合上了。\n", this_object() );
	delete("exits/down");
}
