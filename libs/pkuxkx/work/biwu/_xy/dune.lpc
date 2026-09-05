// Room: /clone/misc/dune.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "沙堆");
	set("long", @LONG
一大堆的黄沙。不知道做什么用途。旁边竖着一个牌子(paizi)。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"weststreet",
	]));
	set("item_desc", ([
		"paizi" : "所有民伕必须努力干活，装(zhuang)不满者，重打四十大板。\n", 
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_zhuang", ({ "zhuang", }));
	::init();
}

int fullbag(object me)
{
	object madai,ob = new("/biwu/xy/obj/shadai");
	if (ob)
		{
			if(me->is_busy() || me->is_fighting())
			return notify_fail("你正忙着哪！\n");
			else 
				{
					ob->move(me);
					me->add_busy(random(2));
					madai=present("madai",me);
					if(objectp(madai)) 
					destruct(madai);
					message_vision("$N用沙子把麻袋装得满满的。\n", me);
					me->set_temp("xiangyang/shadai", 1);
				}
		}
	return 1;
}

int do_zhuang()
{
	object me = this_player();
    if(!present("madai", me))
		{
			return notify_fail("你身上什么口袋都没有，要往哪装沙子？\n");
		}
    else 
		{  
			if( (int)me->query_temp("xiangyang/shadai") ) 
				{
					return notify_fail("你的麻袋里已经装满沙子，还要怎么装？\n");
				}
			else 
				{
					message_vision("$N把沙子往麻袋里装去，反反复复，麻袋越来越重。\n", me);
					fullbag(me);  
                    return 1; 
				}
          
              
		}
	
}