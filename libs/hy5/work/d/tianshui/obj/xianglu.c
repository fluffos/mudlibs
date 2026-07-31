// design by 发现号(find) . all right reserved.

// xianglu.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("香炉", ({ "xiang lu", "lu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个不小的香炉，用来让善男信女们插香(cha)许愿。\n");
                set("value", 1000);
                set("material", "gold");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();
}

void init()
{
	add_action("do_cha","cha");
}

int do_cha(string arg)
{
	object me,have_xiang;
	me = this_player();
	if( !arg || arg == "")
		return notify_fail("你要插什么在香炉里？\n");
	if( arg != "xiang" )
		return notify_fail("你要插什么在香炉里？\n");
	have_xiang = present("xiang", me);
	if( !have_xiang)
		return notify_fail("你身上没有高香。\n");
	if( !have_xiang->query("fire"))
		return notify_fail("高香还没有点燃呢，怎么用来敬佛？\n");
	message_vision("$N把高香插进香炉，拜了几拜。$N感觉到心情平静多了。\n",me);
	destruct(have_xiang);
	if( (me->query("bellicosity") > 0))
	me->add("bellicosity", -(random((int)me->query("kar")) + 50));
	return 1;
}
