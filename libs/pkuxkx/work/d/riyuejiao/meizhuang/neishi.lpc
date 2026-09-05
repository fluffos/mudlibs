//neishi.c   内室
//by bing
#include <ansi.h>

#include <room.h>
inherit ROOM;

void create()
{
	set("short","内室");
	set("long",@LONG 这里是一间卧房，室内一床(chuang)一几(table)，陈设简单，床上挂了纱帐，甚是陈旧，
已呈黄色。几上放着一张短琴，通体黝黑，似是铁制。
LONG
	);
	set("book_count",1);

	set("exits", ([
		"south"	: __DIR__"qinshi",
	]));
	set("objects",([
		__DIR__"obj/tieqin":1,
		]));

 	   set("item_desc",([
            "table"   : "这是一张书桌，上面摆放了几本书。\n",
  	      "tong huan"	:"你可以抓着(pull)这铜环拉起铁板。\n",
		"chuang"	: "这是一张供人休息用的床榻。仔细观察可以看出上面擦痕很多，好象经常搬动。\n",
 	   ]));
	

        set("no_task", 1);
	setup();

}

void init()
{
	add_action("do_move","move");
	add_action("do_pull","pull");
	add_action("do_enter","enter");
	add_action("do_search","search");
}

int do_search(string arg)
{
	object me = this_player();
	object book;
	if (!arg || arg != "table")
		return notify_fail("你要找什么？\n");
	if (!query("book_count"))
		return notify_fail("桌上空空如也,什么也没有。\n");
	if ( me->query_temp("riyue/searched"))
		return notify_fail("找过了就别再找了！\n");
        if (random(2) == 1)
	{
		book = new(__DIR__"obj/strikebook");
		book->move(me);
		message_vision("$N从桌上拿起一本《开山掌法精要》。\n",me);
		set("book_count",0);
		me->set_temp("riyue/searched",1);
		return 1;
	}
        if (random(2) == 0)
	{
		book = new(__DIR__"obj/clawbook");
		book->move(me);
		message_vision("$N从桌上拿起一本《鹰爪功秘诀》。\n",me);
		set("book_count",0);
		me->set_temp("riyue/searched",1);
		return 1;
	}
	message_vision("$N在桌上乱翻一气，结果什么也没找着！\n",me);
	me->set_temp("riyue/searched",1);
	return 1;
}

int do_move(string arg)
{
	object me = this_player();
	if (me->query_temp("riyue/move"))
		return notify_fail("你把人家的床推来推去的干吗？\n");
	
	if (arg != "chuang")
		return notify_fail("你要推什么？\n");
    if (! ( me->query_temp("riyue/秃ok") && me->query_temp("riyue/丹ok") && me->query_temp("riyue/黄ok") && me->query_temp("riyue/黑ok") ))
    {
        message_vision("$N用力推开床榻，只听得轰隆一声响，$N掉进了陷阱之中！\n",me);
        me->move(__DIR__"meizhuang");
        me->unconcious();
        return 1;
    }
	message_vision("$N用力推开床榻，下面却是块铁板，上有铜环(tong huan)。\n",me);
	me->set_temp("riyue/move",1);
	return 1;
}

int do_pull(string arg)
{
	object me = this_player();
	if (!me->query_temp("riyue/move") || arg!="tong huan")
		return notify_fail("你要拉起什么？\n");
	if (me->query_temp("riyue/pull"))
		return notify_fail("你已经把铁板拉起来了。\n");
	message_vision("$N握住铜环，向上一提，一块四尺来阔、五尺来长的铁板应手而起，露出一个长大方洞。\n",me);
	me->set_temp("riyue/pull",1);
	return 1;
}

int do_enter()
{
	object me = this_player();
        object room,player;
        object* ob;
        int i;

        if( room = find_object(__DIR__"didao1") )
        {
write("find");
            ob = all_inventory(room);
            for (i = sizeof(ob)-1;i>=0;i--)
                if (userp(ob[i]))
                    {
                        message_vision(HIR+"$N触动了机关，只见一把长剑忽然从地道里飞出，正刺中$N的胸口！\n"+NOR,this_player());
                        this_player()->receive_damage("qi", 0, "触动梅庄机关");
                        this_player()->die();
                        return 1;
                    }
        }
        if( room = find_object(__DIR__"didao2") )
        {
            ob = all_inventory(room);
            for (i = sizeof(ob)-1;i>=0;i--)
                if (userp(ob[i]))
                    {
                        message_vision(HIR+"$N触动了机关，只见一把长剑忽然从地道里飞出，正刺中$N的胸口！\n"+NOR,this_player());
                        this_player()->receive_damage("qi", 0, "触动梅庄机关");
                        this_player()->die();
                        return 1;
                    }
        }
        if( room = find_object(__DIR__"didao3") )
        {
            ob = all_inventory(room);
            for (i = sizeof(ob)-1;i>=0;i--)
                if (userp(ob[i]))
                    {
                        message_vision(HIR+"$N触动了机关，只见一把长剑忽然从地道里飞出，正刺中$N的胸口！\n"+NOR,this_player());
                        this_player()->receive_damage("qi", 0, "触动梅庄机关");
                        this_player()->die();
                        return 1;
                    }
        }
        if( room = find_object(__DIR__"prison") )
        {
            ob = all_inventory(room);
            for (i = sizeof(ob)-1;i>=0;i--)
                if (userp(ob[i]))
                    {
                        message_vision(HIR+"$N触动了机关，只见一把长剑忽然从地道里飞出，正刺中$N的胸口！\n"+NOR,this_player());
                        this_player()->receive_damage("qi", 0, "触动梅庄机关");
                        this_player()->die();
                        return 1;
                    }
        }
	if ( me->query_temp("riyue/haveenter") )
		return notify_fail("你老钻洞干吗？\n");
         if (me->query_temp("riyue/pull") == 0)
                    return notify_fail("你要进哪里？\n");

	if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 30)
		return notify_fail("你身上背的东西太多，地道里狭窄，进不去。\n");
	me->move(__DIR__"didao1");
	me->set_temp("riyue/haveenter",1);
	return 1;
}




