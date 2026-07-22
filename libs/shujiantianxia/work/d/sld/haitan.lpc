//haitan.c
//wzfeng

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "海滩");
	set("long", @LONG
这里是东海之滨的一个小海滩。放眼望去，一片无际的的茫茫大海，远处
海天一线，你隐隐看到几只海鸥在海上飞翔。海滩的四周稀稀落落的有一些长
得颇为茂盛的树木(tree)。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"xiaolu",
//		"southeast" : __DIR__"haitan1",
	]));

	set("sld_boat", 1);

	set("objects",([
		__DIR__"npc/shangren" : 1,
	]));
	set ("item_desc", ([
		"tree":"一些长得颇为茂盛的树木，你可以砍(chop)。\n",  
	]));
	set("outdoors", "塘沽");
	setup();
}

void init()
{
	add_action("do_kan", "chop");
}

int do_kan(string arg)
{
	object me,weapon1,wood;
	me = this_player();
	
	if( !arg || arg=="" ) return 0;
	
	if(arg!="tree")
		return notify_fail("你要砍什么？\n");

	if(!(weapon1=me->query_temp("weapon")))
		return notify_fail("你好象没有武器，拿手砍？\n");

        if( weapon1->query("flag") != 4 )
                return notify_fail("你手上这件兵器无锋无刃，如何能砍树啊？\n");

	if(present("mu tou", environment(me)))
		return notify_fail("这里不是已经有木头了吗？不要随意砍伐树木!!!\n");

	message_vision( HIR "只见$N大喝一声，运起内力挥舞手中$n"HIR"向周围的树木砍去 ....\n" NOR, me,weapon1);
	message_vision( HIR "只听“咔嚓”一声，周围的几棵大树已被$N用$n"HIR"砍成几截。\n"NOR,me,weapon1);
	wood = new(__DIR__"npc/obj/mutou");
        wood->move(environment(me));
        return 1;
}
