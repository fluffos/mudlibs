// Zine 26 Sep 2010 史可法任务房间配置

inherit ROOM;

void create()
{
	set("no_task",1);
    set("outdoors", "city");

}

void init()
{
    object me=this_player();
	set("no_die",1);
    this_player()->listen_to_die(this_object());
	add_action("do_dig", ({ "wa", }));
    if (userp(me)&&!wizardp(me) && !me->query("skf/jobasked"))
    {
        tell_object(me,"此地危险重重，不宜久留！\n");
        me->move(__DIR__"beimen");
    }
}

int found(object me)
{
	object ob = new("/d/city/obj/tudou");
	if (ob) 
		{
			if (random(10)>5)
			{
				ob->move(me);
				me->add_busy(random(1));
				message_vision("$N在路边地里刨了半天，找到一块土豆。\n", me);
			}
			else
			{
				message_vision("$N在路边地里刨了半天，除了十指的鲜血，其他什么也没得到。\n", me);
			}
		}
	return 1;
}

int do_dig()
{
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    if(present("tu dou", me)) 
		{ 
			return notify_fail("你是来帮助转移难民的还是专业挖土豆的？\n");
		}
    else 
		{ 
			found(me);    
        }
	return 1; 
}

