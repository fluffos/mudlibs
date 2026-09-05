// Room: /u/cuer/emei/shandao4.c

inherit ROOM;

void create()
{
	set("short", "山道");
set("outdoors","emei");
	set("long", @LONG
这是一条山中小道，道上人迹罕至，小道在这里就
没有了，往西是来的路，往东正队着一个山洞，那山洞
就是著名的药王洞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ywdong",
  "northwest" : __DIR__"shandao3",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
    add_action("do_shai","shai");
    add_action("do_jian","jian");
}

int do_shai()
{
    object me=this_player();
    object cy;
    if (me->query_temp("emnewbiejob/jingci/task")!=1)
    {
        tell_object(me,"在人间门口干嘛呢？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!present("caoyao",me))
    {
        tell_object(me,"你要晒什么？\n");
        return 1;
    }
    cy=present("caoyao",me);
    if (!cy->query("is_caoyao"))
    {
        tell_object(me,"你要晒的是什么？\n");
        return 1;
    }
    message_vision("$N拿出一颗草药，放下来曝晒。过一会可以捡(jian)回来了。\n",me);
    destruct(cy);
    me->add_temp("emnewbiejob/jingci/cynumber",1);
    me->set_temp("emnewbiejob/jingci/task1time",time());
    return 1;
}

int do_jian()
{
    object me=this_player();
    object cy;
    if (me->query_temp("emnewbiejob/jingci/task")!=1)
    {
        tell_object(me,"在人间门口干嘛呢？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("emnewbiejob/jingci/cynumber")<=0)
    {
        tell_object(me,"你没有晒那么多草药。\n");
        return 1;
    }
    if (time()-(int)me->query_temp("emnewbiejob/jingci/task1time")<=60+random(20))
    {
        tell_object(me,"草药还没有完全晒干。\n");
        return 1;
    }
    if (time()-(int)me->query_temp("emnewbiejob/jingci/task1time")>=160+random(20))
    {
        tell_object(me,"草药已经完全枯干了，毫无价值了。\n");
        me->set_temp("emnewbiejob/jingci/cynumber",0);
        return 1;
    }
    me->add_temp("emnewbiejob/jingci/cynumber",-1);
    me->add_busy(1);
    message_vision("$N拣起一颗晒干的草药。\n",me);
    cy=new(__DIR__"npc/obj/caoyao2");
    cy->set("owner",me->query("id"));
    cy->move(me);
    return 1;
}
