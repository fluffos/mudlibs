// Room: /clone/misc/shop3.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "李记布店");
	set("long", @LONG
一个掉落的招牌(zhaopai)上面写着“李记布店”四个字，看来以前这里是卖
布料和衣服的所在。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"avenue",
	]));
	set("item_desc", ([
		"zhaopai" : "招牌上写着李记布店，童叟无欺。你觉得在这里可以找(zhao)到一些衣服。\n",  
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_zhao", ({ "zhao", }));
	::init();
}

int found(object me)
{
	object ob;
	object ob1;
	
			if(random(2))
				{
                    ob = new("/biwu/xy/obj/guanfu");
                    if (ob) 
                    {
                        ob->move(me);
                        me->add_busy(random(2));
                        message_vision("$N找了半天，翻出一件崭新的官服。\n", me);
                        me->set_temp("xiangyang/guanfu", 1);
                    }
				}
			else
				{
                    ob1 = new("/biwu/xy/obj/guanfu1");
                    if (ob)
                    {
                   
                        ob1->move(me);
                        me->add_busy(random(2));
                        message_vision("$N找了半天，翻出一件皱巴巴的官服。\n", me);
                        me->set_temp("xiangyang/guanfu",1);
                    }
				}
		
	return 1;
}

int do_zhao()
{
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    if( (int)me->query_temp("xiangyang/guanfu") ) 
		{ 
			return notify_fail("你已经找到一件官服了，还要那么想开成衣店吗？\n");
		}
    else 
		{ 
			message_vision("$N发疯似的在一堆衣服里翻着寻找什么。\n", me);
            found(me);    
        }
	return 1; 
}