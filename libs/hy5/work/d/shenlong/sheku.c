// sheku.c
// 蛇窟
inherit ROOM;
void create()
{
	set("short","蛇窟");
	set("long",@long
这里整年毒雾弥漫，腥臭扑鼻，遍地都是又粗又长的毒蛇和一堆堆白骨，
时常有飞鸟被毒雾熏昏，落下来成为众蛇的美食，群蛇之间的互相吞噬也是
家常便饭，只有那些武功高强的用毒高手才能从这里生离。此处好象没有什
么出路，你可以到处走走(go)看。
long);
	/*set("exits",([
	    "northwest" : __DIR__"treen2",
          "southwest" : __DIR__"trees2",
          "east" : __DIR__"sande",
]));*/
set("objects",([
__DIR__"npc/shenlong": 1,
__DIR__"npc/dushe2" : 4,
]));
	set("outdoors", "神龙岛");
        setup();
}
	    	
void init()
{
     object me;

     me=this_player();
     if((int)me->query_skill("poison",1)<100)
     {
         me->apply_condition("snake_poison_poison", (5-((int)me->query_skill("poison",1))/20)*10);  
     }       
     add_action("do_go", "go");
     add_action("do_bo", "bo");
}

int do_bo(string arg)
{
     object me;
     object bg;
     object she;
     object * ob;
     int i,j;

     me = this_player();
       
     if(!living(me) ) return 0;
     if (me->is_busy() || me->is_fighting())
     	return 0;

if (!present("shenlong", this_object()))
return notify_fail("这里什么也没有啊!\n");
     if(!arg || arg!="白骨")
	return 0;
     if(random(10)<2)
     {
	if(objectp(bg=new(__DIR__"npc/obj/baogou")))
	{
		tell_room(this_object(),"忽然有什么东西从一堆白骨中掉了出来。\n");
		bg->move(this_object());
	}
     }
     else if(random(10)>6)
     {
	ob = all_inventory(this_object());
	j=0;
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query("id")=="shenlong")
			j=j+1;
	}
	if(j>=5)
		return 0;
	tell_room(this_object(),"突然从白骨下面窜出一条比刚才更加粗的巨蛇！\n");
	she=new(__DIR__"npc/shenlong");
	she->set("combat_exp", 500000+random(3000001));
	set("max_qi",26000+random(4001));
        set("max_jing",26000+random(4001));

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 800+random(501));
	set_temp("apply/damage", 480+random(21));
	set_temp("apply/armor", 800+random(501));
 	she->move(this_object());
    }
    else
	return 0;
    return 1;
}

int do_go(string arg)
{
     object me;

     me = this_player();
       
     if(!living(me) ) return 0;
     if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");

     if( !arg || arg == "" || (arg != "west" && arg != "east" && arg != "north" && arg != "south" ))
        return notify_fail("你要往哪里去？\n");
     if(random(10)>=5)
         me->move(__DIR__"treen1");
     return 1;
}
