// mishi.c 密室
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","密室");
        set("long",
"这是一间密室，里面很暗，房间中间放着一张桌子，桌上一颗夜明珠
，散发着柔和的光芒，使得能依稀看到周围的一切，墙上挂着一幅山水画
（hua），墙边是一个书架，书架（shelf）上放着一些书（book）。\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"out" : __DIR__"woshi",
	]));
         set("item_desc",([
		"shelf" : "上面有一本发黄的书。\n",
          ]));
	set("book_count",1);
	setup();
}

void init()
{
	add_action("do_get","get");
	add_action("do_search","search");
	add_action("do_si","si");
}

int do_get(string arg)
{
	object ob,me=this_player();
	object where=environment(me);
	if (arg!="book from shelf") return 0;
	if (!where->query("book_count"))
		return notify_fail("书已经被人拿走了。\n");
	ob=new(__DIR__"obj/fake-book");
	ob->move(me);
	message_vision("$N拿起一本书。\n",me);
	set("book_count",0);
	return 1;
}

int do_search(string arg)
{
	object me=this_player();
	if (arg!="hua" && arg!="画") return 0;
	message_vision("$N发现画有夹层。\n",me);
	me->set_temp("marks/search",1);
	return 1;
}

int do_si(string arg)
{
	object ob,me=this_player();
	if (arg!="hua" && arg!="画") return 0;
	if (!me->query_temp("marks/search"))
		return notify_fail("你想干啥?\n");
          if (query("books"))
		return notify_fail("里面空空如也。\n");
        ob=new(__DIR__"obj/real-book");
        ob->move(me);
        message_vision("$N把画拆开，发现了一本发黄的书。\n",me);
             set("books",1);
        return 1;
}


