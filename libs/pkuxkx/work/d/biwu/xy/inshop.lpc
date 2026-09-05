// Room: /clone/misc/inshop.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "雨伞店内室");
	set("long", @LONG
这是雨伞点的内室，一张大桌(desk)上面放满了各种乱七八糟的杂物。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"shop",
	]));
	set("item_desc", ([
		"desk" : "这是匠人们用来制作纸质工艺品的地方，你可以尝试做(make)点什么。\n", 
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_make", ({ "make", "zuo"}));
	::init();
}

int found(object me)
{
    int n=random(10);
	object paper,xian;
    object ob;
	object ob2;
    if (n>6)
		{
            ob = new("/biwu/xy/obj/kite");
            if (ob)
            {ob->move(me);}
			me->add_busy(random(4));
			message_vision("$N做出来一只一人大小的大风筝。\n", me);
			paper=present("paper",me);
			if(objectp(paper)) 
			destruct(paper);
			xian=present("string",me);
			if(objectp(xian)) 
			destruct(xian);
		}
	else
		{
			if (n<2)
				{
                    ob2 = new("/biwu/xy/obj/biao");
                    if (ob2)
                    {ob2->move(me);}
					me->add_busy(random(2));
					message_vision("$N做出一支很逼真的飞镖。\n", me);
					paper=present("paper",me);
					if(objectp(paper)) 
					destruct(paper);
					xian=present("string",me);
					if(objectp(xian)) 
					destruct(xian);
				}
			else
				{
					message_vision("$N忙和半天，弄了一地碎纸，什么都没做出来。\n", me);
					paper=present("paper",me);
					if(objectp(paper)) 
					destruct(paper);
				}
		}
	return 1;
}
	
int do_make()
	{
		object me = this_player();
		if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
	    if(!present("paper", me))
			{
				return notify_fail("你连纸都没有，怎么做纸工艺品？\n");
			}
		else
			{   
				if(!present("jian dao", me))
					{
						return notify_fail("你不找把剪刀来，难道要用手撕纸？\n");
					}
				else
					if(!present("string",me))
						{
							return notify_fail("你还需要一点线把你的作品连结起来。\n");
						}
					else
						{
							found(me);    
							return 1; 
						}
			}
}