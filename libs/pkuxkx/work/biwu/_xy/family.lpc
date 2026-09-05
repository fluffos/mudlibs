// family.c
// create: by zine Aug 21 2010
// edit: by zine Aug 27 2010
// edit again by zine Aug 29 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "贫苦人家");
	set("long", @LONG
这里是一户贫苦人家，家里没有几样家具，全是破烂。灶台(zaotai)能好像
有东西。
LONG
	);
	set("exits", ([
		"east" : __DIR__"avenue1",
	]));
	set("item_desc", ([
		"zaotai" : "灶台能好像有一把斧头，你可以把它拿(na)出来。\n", 
	]));
	set("objects", ([
        ("/biwu/xy/obj/saoba") : 1,
    ]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_na", ({ "na", "bo"}));
	::init();
}

int bo(object me)
{
	object saobaba,ob;
	if(me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
	else 
	{
        ob = new("/biwu/xy/obj/axe");
        if (ob)
        {ob->move(me);}
		me->add_busy(random(2));
		saobaba=present("ba",me);
		if(objectp(saobaba)) 
		destruct(saobaba);
		message_vision("$N吃力的拨出了斧头，啪嗒一声，扫把把折断了。\n", me);
        return 1;
	}
		
	
}

int do_na()
{
	object me = this_player();
	if(!present("ba", me))
		{
			return notify_fail("你似乎需要一个棍状的东西来把斧头拨出来？\n");
		}
    
    else 
		{ 
			message_vision("$N伸长了手，用扫把把费力地在灶台下拨着。\n", me);
            bo(me);  
		}
	return 1; 
}

