// Room: lot.c
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "军资库");
	set("long", @LONG
当年的军方重地，现在连一个看守的人都不在了。各种军械也被一扫而空，
只有几只麻袋(madai)放在地上，也许因为并不值钱，所以没人理会。
LONG
	);
	set("item_desc", ([
		"madai" : "一堆破破烂烂的麻袋，被丢弃在这里。你可以把它拿(na)起来。\n", 
	]));
	set("exits", ([ 
		"north" : __DIR__"weststreet",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_na", ({ "na", }));
	::init();
}

int found(object me)
{
	object ob = new("/biwu/xy/obj/madai");
	if (ob) 
		{
			ob->move(me);
			me->add_busy(random(2));
			message_vision("$N比较了半天，终于决定拿这个稍微结实一点的麻袋。\n", me);
			me->set_temp("xiangyang/madai", 1);
		}
	return 1;
}

int do_na()
{
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    if( (int)me->query_temp("xiangyang/madai") ) 
		{ 
			return notify_fail("你已经拿过麻袋了，还要找什么？\n");
		}
    else 
		{ 
			message_vision("$N在一堆麻袋里翻着，似乎要寻找一个新一点的麻袋。\n", me);
            found(me);    
        }
	return 1; 
}