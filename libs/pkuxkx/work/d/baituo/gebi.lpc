//gebii.c
inherit ROOM;
void create()
{
        set("short", "戈壁");
        set("long",
             "这里是临近沙漠的戈壁滩，荒无人烟。东边是一望无际的大沙漠，\n"
         "西北方可以看见一座小镇。路边长着许多甘草(gancao)。\n"
        );
        set("outdoors", "baituo");
        set("item_desc", ([
		"gancao" : "甘草可以入药，一般生长在荒漠边。你可以摘(zhai)下来。\n", 
	    ]));
        set("exits", ([
                "east" : "/d/silk/shamo10",
                "northwest" : "/d/baituo/dongjie",
        ]));
        set("objects",([
             CLASS_D("btshan") + "/ouyangke" : 1,
                __DIR__"npc/whitelady" : 4,
        ]));
        setup();
        
}

void init()
{ 
	add_action("do_zhai","zhai"); 
}

int do_zhai()
{
    object me=this_player();
    object gc;
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("甘草"))
    {
        return notify_fail("甘草已经被摘完了。\n");
    }
    me->set_temp("甘草",1);
    gc=new("/d/taishan/obj/gancao");
    gc->move(me);
    message_vision("$N拣起了一颗甘草。\n",me);
    return 1;
}