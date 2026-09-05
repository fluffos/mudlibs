// Room: /clone/misc/shop.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "雨伞店");
	set("long", @LONG
一家老字号雨伞店，墙上挂着各种各样的雨伞，后面的工坊堆了许多油纸(zhi)。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"northstreet",
		"south" : __DIR__"inshop",
	]));
	set("item_desc", ([
		"zhi" : "一堆油纸，不知道什么地方就会派上用场，你可以拿(na)几张。\n", 
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
	object ob;
	if (random(10)>6)
				{
                    ob = new("/biwu/xy/obj/paper");
                    if (ob) 
                    {
                        ob->move(me);
                        me->add_busy(random(2));
                        message_vision("$N找到一张崭新的油纸。\n", me);
                    }
				}
	else
				{
					me->add_busy(random(2));
					message_vision("$N找来找去，找到的都是残缺的碎纸，毫无用处。\n", me);
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
    found(me);    
    return 1; 
}
