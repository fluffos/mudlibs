//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "库房"NOR);
        set("long", 
"这里太常寺的库房。\n"

        );
        set("exits", ([

				"out" : __DIR__"taichang",
                
                
        ]));
    
        setup();
   
}

void init()
{
	add_action("do_store","store");
}

int do_store(string arg)
{
	object ob,me=this_player();
	if (!arg||arg!="gong pin")
	{
		return notify_fail("你要储存什么东西？\n");
	}
	if (me->is_busy())
	{
		return notify_fail("你正忙着呢。\n");
	}
	if (!me->query("mingpin"))
	{
		return 0;
	}
	if (me->query_temp("mingtasks/taichangsi/task")!=1)
	{
		return notify_fail("你别乱放东西啊！\n");
	}
	if (!ob=present("gong pin",me))
	{
		return notify_fail("你的任务是采买一些贡品，贡品呢？\n");
	}
	if (!ob->query("is_gongpin"))
	{
		return notify_fail("你的任务是采买一些贡品，贡品呢？\n");
	}
	me->add_temp("mingtasks/taichangsi/gongpin",1);
	message_vision("$N将$n存入库房。\n",me,ob);
	me->add_busy(random(2));
	destruct(ob);
	if (me->query_temp("mingtasks/taichangsi/gongpin")<random(8)+4)
	{
		tell_object(me,"似乎这里的贡品还不足够，你还需要再去采买一些。\n");
	}
	else
	{
		tell_object(me,"这里的贡品已经足够了，你完成了太常寺采买贡品的任务。\n"+HIC+"你的大明功勋增加了！\n"+NOR);
		me->delete_temp("mingtasks");
		me->add("ming/credit",2+random(2));
	}
	return 1;
}