// kuijiaku
// edit by zine Aug 21 2010

string* obj = ({
      
       __DIR__"obj/baihukai",
	   __DIR__"obj/jinsijia",
	   __DIR__"obj/lianhuanjia",
	   __DIR__"obj/qinglongjia",
	   __DIR__"obj/suozijia",
	   __DIR__"obj/tianyi",
	   __DIR__"obj/zhuquekai",
	   __DIR__"obj/xuanwujia",
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
			me->add_busy(random(2));
			message_vision("$N找了半天，终于找到了" + ob->query("name") + "。\n", me);
			me->set_temp("xiangyang/foundarmor", 1);
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
    if( (int)me->query_temp("xiangyang/foundarmor") ) 
		{
			return notify_fail("你已经拿了东西了，走吧。\n");
		}
    else 
		{      
			message_vision("$N在盔甲库里寻找着什么。\n", me);
            found(me);    
        }
	return 1; 
}