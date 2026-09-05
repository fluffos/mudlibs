// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山林间郁郁葱葱，南边就是南昌城了。地上堆了一堆砖头(bricks)。
LONG );
	set("outdoors", "jiangzhou");
	set("no_clean_up", 0);
    set("item_desc", ([
		"bricks" : "一大堆砖头，你可以帮砖头堆(dui)在这里。\n", 
	    ]));
	set("exits", ([
		"south"     : "/d/nanchang/northgate",
        //"northeast" :
		"northwest" : __DIR__"guandaos3",
	]));
	setup();
	
}

void init()
{ 
	add_action("do_dui","dui"); 
}

int do_dui()
{
    object me=this_player();
    object brick;
    int exp=random(10)+10;
    int pot=random(8)+6;
    if (!me->query_temp("ncjob/permit")&&!me->query_temp("jn/step6a"))
    {
        return notify_fail("你想干什么？\n");
    }
    if (!present("qing zhuan",me))
    {
        return notify_fail("你身上没有砖头了，要堆什么？\n");
    }
    brick=present("qing zhuan",me);
    if (!me->query_temp("ncjob/count"))
    {
        return notify_fail("你又想浑水摸鱼吗？\n");
    }
    
    if ( time() - me->query_temp("ncjob/last_go_time") <= 3 )
    {
    	  return notify_fail("你背砖头走的太急了，歇会再堆砖头吧！\n");
    }

    if (brick->query("owner")!=me->query("id"))
    {
        return notify_fail("帮人搬砖头也有佣人帮忙？这年头！\n");
    }
    else
    {
        if (brick)
        {
            destruct(brick);
        }
        message_vision("$N把砖头重重地堆在这里，舒坦地活动了一下肩膀。\n",me);
        me->add_temp("ncjob/count",-1);
        me->add("ncjob",1);
        me->delete_temp("ncjob/permit");
        if ( me->query("ncjob") <= 5000 )
        {
          exp=REWARD_D->add_exp(me,exp);
          pot=REWARD_D->add_pot(me,pot);
          tell_object(me,sprintf("在劳动中，你获得了%d点经验，%d潜能。\n",exp,pot));
        }
        if (me->query_temp("jn/step6a"))
        {
            tell_object(me,"堆好了砖头，你可以向老白复命了。\n");
            me->delete_temp("jn/step6a");
            me->set_temp("jn/step6b",1);
        }
        if (random(me->query("ncjob"))>200+random(300)+1000*((int)me->query("jiangnan/randomskill2")))
        {
            tell_object(me,"你突然想到一个人，白老爷子莫不是……\n");
            me->set_temp("ncjob/bai",1);
        }
        return 1;
        
        
    }
}