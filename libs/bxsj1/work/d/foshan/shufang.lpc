// Room: /d/fuoshan/shufang.c 
 
inherit ROOM; 
#include <wanted.h>

void create() 
{ 
	set("short", "书房");
	set("long", @LONG
这里是凤天南的书房，却没有一本书。各种古玩琳琅满目，商周青铜、唐
三彩，珍珠宝石，应有尽有，普通人只要拥有一件，就够一家大小吃上一辈子
了。东面的墙上挂着一副画(picture)。
LONG
	);

	set("exits", ([
		"north" : __DIR__"dating",
	]));
	set("item_desc", ([
		"picture" : "这是一副清秀的山水画，摆在珠光宝器之中显得特别扎眼。\n",
	]));

	setup();
}

void init()
{
	add_action("do_use","use");
	add_action("do_touch", "touch");
}

int do_touch()
{
	write("你觉得画有些异样，忍不住去触摸，感觉画的背后有些凹凸不平，你掀开\n"+
		"画，发现有一个小孔，好象能插入钥匙。\n");
	this_player()->set_temp("marks/okay",1);
	return 1;
}

int do_use(string arg)
{
	object me = this_player();
	if (is_wanted(me)) return 0;
	if( !me->query_temp("marks/okay")  ) return 0;
	if( !me->query_temp("marks/zhong") ) return 0;
	if( !arg || arg=="" ) return 0;
	if (!present("hei yaoshi", me))  return 0;
	if(arg=="hei yaoshi") {
		write("突然嘎吱嘎吱两响，地板动了起来，出现一个刚能容一人通过的洞，你连忙跳了下去\n");      
		me->move(__DIR__"mishi");
		me->delete_temp("marks/zhong");
		me->delete_temp("marks/okay");
		return 1;
	}
	else return 0;
}
