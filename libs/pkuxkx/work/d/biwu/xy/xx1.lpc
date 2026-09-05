// Room: /clone/misc/xx2.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "空地");
	set("long", @LONG
这里是一片空地，东北方向的小巷在雾中若隐若现，飘出蓝幽幽的光，应该
是被人布下剧毒。这里其他植物都没有生存，倒长了几棵蓝色的小花(flower)。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"southeast" : __DIR__"weststreet",
	    "northwest" : __DIR__"xiaoxiang",
	]));
	set("item_desc", ([
		"flower" : "这朵小花闪烁着妖艳的色彩，你可以把它摘(zhai)下来。\n", 
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_zhai", ({ "zhai", }));
	::init();
}

int found(object me)
{
	if (random(10)>6)
		{
			object ob = new("/biwu/xy/obj/ghc");
			if (ob) 
				{
					ob->move(me);
					me->add_busy(random(2));
					message_vision("$N摘下一朵蓝色的小花。\n", me);
					me->set_temp("xiangyang/zhaied", 1);
				}
		}
	else
		{
			 message_vision("$N心里犹豫不决，不敢下手，因为花的颜色太过奇异。\n", me);
		}
	return 1;
}

int do_zhai()
{	
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    if( (int)me->query_temp("xiangyang/zhaied") ) 
		{
			return notify_fail("你已经取得勾魂草了，嫌死得不够快？\n");
		}
    else 
		{      
			message_vision("$N伸手去摘那朵蓝色的小花。\n", me);
            found(me);    
        }
	return 1; 
}