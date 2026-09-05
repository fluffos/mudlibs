// Room: guojingjia.c
// created by Zine 30 Aug 2010

inherit ROOM;

void create()
{
	set("short", "郭靖家");
	set("long", @LONG
这是一顶普通的蒙古包，李萍和郭靖就住在这里。房里有个水缸(gang)。
LONG
	);

	set("exits", ([
		"out" : __DIR__"menggubao5",
	]));
    set("item_desc",
        ([
        "gang":"一口大水缸，你可以喝(drink)水，也可以取(qu)一瓢水。\n",
        ]));
	set("sleep_room", "1");
	set("no_robber",1);
	set("objects", ([
        	__DIR__"npc/liping" : 1,
			__DIR__"npc/guojing" : 1,
	]));
	setup();
}

int get_arrow(object me)
{
        object gj;
        if (!me||environment(me)!=this_object())
        {
            return 1;
        }
        me->delete_temp("shediao/meetzhebie3");
        me->delete_temp("shediao/start_find_guo_arrow");
        gj=new(__DIR__"obj/gongjian");
        gj->set("owner",me->query("id"));
        gj->move(me);
        message_vision("$N找到了郭靖的小弓箭。\n",me);
        return 1;
}

void init()
{
    object me=this_player();
    add_action("do_drink","drink");
    add_action("do_qu","qu");
    if (me->query_temp("shediao/meetzhebie3")&&!me->query_temp("shediao/start_find_guo_arrow"))
    {
        me->set_temp("shediao/start_find_guo_arrow",1);
        message_vision("$N到处寻找郭靖的小弓箭。\n",me);
        me->start_busy(3);
        call_out("get_arrow",2+random(2),me);
    }
    return;
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 450);
                message("vision", me->name()+"急冲冲的跑了过来，对着水缸一阵豪饮。\n",
                        environment(me), ({me}) );
                write("你端起水缸里的瓢，喝得真爽啊。\n");
        }
        else write("你已经不渴了，还是别喝了。\n");

        return 1;
}
int do_qu()
{
    object me=this_player();
    object shui;
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (present("yipiao shui",me))
    {
        tell_object(me,"你身上不是取了一瓢水吗？\n");
        return 1;
    }
    shui=new(__DIR__"obj/shui");
    message_vision("$N拿瓢从水缸里舀出一瓢水。\n",me);
    shui->move(me);
    return 1;
}
