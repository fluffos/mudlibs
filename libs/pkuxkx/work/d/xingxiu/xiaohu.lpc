// 小湖
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";

void create()
{
	set("short", "小湖");
	set("long", @LONG
这里是一片小湖，碧幽幽的湖水渗出丝丝寒意，让人不太敢接近。
LONG
	);
    set("normaldesc", @LONG
这里是一片小湖，碧幽幽的湖水渗出丝丝寒意，让人不太敢接近。
LONG
	);
	set("exits", ([ 
		"northwest" : __DIR__"grass6",
        "northeast" : __DIR__"grass5",
        "north" : __DIR__"grass",
		
    ]));
    set("outdoors", "xingxiuhai");

	set("objects", ([(__DIR__"npc/huangya") : 1+random(2),
    ]));
	setup();
	::create();
}

void init()
{
	add_action("do_soak", ({ "pao" }));
    add_action("do_qian", ({ "qian" }));
    add_action("do_getback", ({ "qu" }));
	::init();
}

int do_qian()
{
    object me=this_player();
    if (me->query("family/family_name")!="星宿派")
    {
        return 0;
    }
    if (me->query("xxnewbiequest"))
    {
        tell_object(me,"上天有好生之德，你老想杀鳄鱼干嘛？\n");
        return 1;
    }
    me->set("xxnewbiejob/qiantime",time());
    me->move(__DIR__"hudi1");
    tell_object(me,"你一闭气，潜入湖底。\n");
    return 1;
}

int do_getback(string arg)
{
    object me = this_player();
    object zhang;
    if (!(me->query_temp("xxnewbiejob/bpz3")))
    {		
        return 0;
    }
    if (!arg||(arg!="mu zhang"&& arg!="zhang" && arg!="木杖"))
    {
        return notify_fail("你要把取回什么？\n");
    }
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着呐！\n");
    }
    if (time()-me->query("xxnewbiejob/bpztime")<75)
    {
        return notify_fail("木杖吸收的寒气并不足够，这时还不适宜取出！\n");
    }
    else
    {
        zhang=new(__DIR__"obj/bingzhang");
        message_vision("$N从冰冷的湖水中取出了一把冰杖。\n",me);
        zhang->set("owner",me->query("id"));
        zhang->move(me);
        me->delete_temp("xxnewbiejob/bpz3");
        me->set_temp("xxnewbiejob/bpz4",1);
        return 1;
    }
}

int do_soak(string arg)
{
	object me = this_player();
	object zhang=present("mu zhang",me);
    if (!arg||(arg!="mu zhang"&& arg!="zhang" && arg!="木杖"))
    {
        return notify_fail("你要把什么浸入湖中？\n");
    }
    if (!(me->query_temp("xxnewbiejob/bpz2")))
		return notify_fail("我踏月色而来又没让你帮助制作冰魄杖，你想干吗？\n");
   
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着呐！\n");
        }
    
	if(!present("mu zhang", me))
		{
			return notify_fail("你身上有木杖吗？\n");
		}
    if (zhang->query("owner")!=me->query("id"))
    {
        return notify_fail("这根木杖又不是你做的，你想不劳而获嘛？\n");
    }
	else
		{
			destruct(zhang);
			message_vision("$N小心翼翼地将木杖浸入湖中，避免自己为湖中寒毒所侵。\n", me);
            me->delete_temp("xxnewbiejob/bpz2");
            me->set_temp("xxnewbiejob/bpz3",1);
            me->set("xxnewbiejob/bpztime",time());
            tell_object(me,"过一会，待寒气完全浸入木杖，就可以去制作冰魄杖了。\n");
            return 1;
        }
}