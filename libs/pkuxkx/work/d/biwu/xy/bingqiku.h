// bingqiku.h Zine Oct 30 2010

string* obj = ({

       __DIR__"obj/zijinchui",
	   __DIR__"obj/yuchang-jian",
	   __DIR__"obj/yanyuedao",
	   __DIR__"obj/yanlingdao",
	   __DIR__"obj/whip",
	   __DIR__"obj/taie-jian",
	   __DIR__"obj/staff",
	   __DIR__"obj/qixing-jian",
	   __DIR__"obj/qiankun-jian",
	   __DIR__"obj/pishuidao",
	   __DIR__"obj/lanyu-jian",
	   __DIR__"obj/kunwu-jian",
	   __DIR__"obj/kanshandao",
	   __DIR__"obj/jiuhuandao",
	   __DIR__"obj/guitoudao",
	   __DIR__"obj/bishou",
     
});


void init()
{
	add_action("do_find", "find");
    add_action("do_find", "zhao");
    add_action("do_find", "fan");
	::init();
}

int found(object me)
{
	object ob = new( obj[random(sizeof(obj))] );
	if (ob) 
		{
			ob->move(me);
			message_vision("$N找了半天，终于找到了" + ob->query("name") + "。\n", me);
			me->add_busy(random(2));
			me->set_temp("xiangyang/found", 1);
		}
	return 1;
}

int do_find()
{
	object me = this_player();
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
    if( (int)me->query_temp("xiangyang/found") ) 
		{
			return notify_fail("你已经拿了东西了，走吧。\n");
		}
	else 
		{      
			message_vision("$N在兵器库里寻找着什么。\n", me);
            found(me);    
        }
	return 1; 
}